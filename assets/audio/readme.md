# Audio Asset Readme

This folder contains music and sound assets. There are five base files extracted from the ROM

- sfx.ctl
- sfx.tbl
- instruments.ctl
- instruments.tbl
- music.sbk

These files are used directly in the build process; the main build will not regenerate these. If you want to change sound effects or music you will need to rebuild these once to make the above files available to the build process.

# Background

Sounds are stored in two files, .ctl and .tbl.

The .ctl file contains meta information about the sound effect. The .tbl file contains actual audio data. Sound effects and music instruments each have a pair of these files.

Music track information is based on MIDI format, and is stored in a (compiled) soundbank file, music.sbk.

Waveform data is stored in AIFF format using custom compression; these are .aifc files. Extracting .aifc files from .tbl container is fully reversible, but decompressing the audio waveform data is not. Therefore, the provided scripts will only convert to .aifc, but this readme will explain how to convert to .wav and back to .aifc.

See header documentation or gaudio documentation for further details on audio formats.

# Script summary

These will be discussed in more detail below. The included helper scripts are

- `extract_baserom_audio.u.sh`: Extracts the five base audio files into the assets/audio directory.
- `extract_midi.sh`: (*assuming `music_names` is unchanged*) Extracts compressed game music sequence files, inflates, and converts to MIDI.
- `extract_instruments_to_aifc.sh`: (*assuming `music_names` is unchanged*) Extracts music sound samples to .aifc and create associated .inst file.
- `extract_sfx_to_aifc.sh`: (*assuming `sfx_names` is unchanged*) Extracts sound effect samples to .aifc and create associated .inst file.
- `build_soundbank.sh`: Convert midi files to compressed sequence format and build music.sbk according to `music_names`.
- `build_instrumentsfrom_aifc.sh`: Compile music sample sounds listed in associated .inst file and build instruments.ctl and instruments.tbl.
- `build_sfx_from_aifc.sh`: Compile sound effect samples listed in associated .inst file and build sfx.ctl and sfx.tbl.

# Source code and Building

The project wraps the five base audio files in an assembly .s file. This will make the following addresses globablly accessible. These are the start and end address for each file compiled into the rom.

- music.s: `_musicSbkSegmentRomStart`, `_musicSbkSegmentRomEnd`
- instruments.ctl.s: `_instrumentsctlSegmentRomStart`, `_instrumentsctlSegmentRomEnd`
- instruments.tbl.s: `_instrumentstblSegmentRomStart`, `_instrumentstblSegmentRomEnd`
- sfx.ctl.s: `_sfxctlSegmentRomStart`, `_sfxctlSegmentRomEnd`
- sfx.tbl.s: `_sfxtblSegmentRomStart`, `_sfxtblSegmentRomEnd`

The above .s files will be compiled by the main Makefile into an object file. Because the .s files never change, the Makefile won't rebuild audio automatically when one of the five base files changes. Instead run `make audioclean` to clear existing audio object files then rebuild.

# Sounds -- Sound Effects

This section covers extracting sound effects, changing sound effects, and rebuilding the "sfx" containers.

### Extract to AIFC

A convenience shell script `extract_sfx_to_aifc.sh` is provided to extract sound effects from the base soundbank file. This step uses the `sfx_names` file to determine what to name each file extracted from the .tbl. This will result in .aifc files placed in the `aifc_sfx/` folder. The .aifc files are in compressed format. This is fully reversible to the .ctl and .tbl files, with an appropriate .inst file. Extracting also generates an .inst file which captures how the files were originally sorted in the .ctl and .tbl files. This is required to rebuild a matching ROM.

### Compile sfx container

A convenience shell script `build_sfx_from_aifc.sh` is provided to compile the sound effects into `sfx.ctl` and `sfx.tbl` files. This requires the .aifc files extracted above, and an .inst file to explain which files to use. See gaudio documentation for further details on .inst file format.

### Converting between AIFC and WAV

Note: N64 playback applies a number of effects (like reverb), so the resulting wav files will not sound the same on PC as in the game.

To convert an .aifc to .wav, use the gaudio tool `aifc2wav`. See gaudio documentation for further details on available command line options.

Note that the sound effects are generally stored at various sampling rates. This means the sound effect will need to be "detuned" (or retuned rather) to the correct frequency. This information is captured in the .inst file, under the "detune" and "keybase" properties in a keymap. `aifc2wav` happens to support extracting this information from an .inst file when converting to wav. Here is an example to convert the rocket launch sound effect to wav. This example is run from the audio/assets folder, and it uses the sound effect names from the "sfx_names" file:

```
../../tools/gaudio/bin/aifc2wav --in aifc_sfx/Rocket_Launch.aifc --out aifc_sfx/Rocket_Launch.wav --inst-file=aifc_sfx/sfx.inst --inst-search=use --inst-val="aifc_sfx/Rocket_Launch.aifc"
```

Wav files can be converted to .aifc files for use in the project. These must be signed 16 bit mono wav files. In order to convert from .wav to .aifc using the standard compression algorithm, suitable "coefficents" must be found. The gaudio tool `tabledesign` can do this; note this depends on the GNU Scientific Library being installed. Following is an example to replace the Rocket Launch sound effect with a file called "ont.wav". This example is run from assets/audio folder, and uses a file called "ont.wav" in the assets/audio/wav folder.

**Step 1:**  

Convert wav file to 16 bit mono. Take note of the sampling frequency. In this example, the file has a sample rate of 22050 Hz, approximately 2.4 seconds long.

**Step 2:**  

Search for compression coefficients using `tabledesign`:  

```
../../tools/gaudio/bin/tabledesign --in wav/ont.wav
```

A file named "ont.coef" should now exist in the `wav/` folder.

**Step 3:**  

Convert from wav to aifc, and place output in `aifc_sfx/` folder  

```
../../tools/gaudio/bin/wav2aifc --in=wav/ont.wav --coef=wav/ont.coef --out=aifc_sfx/ont.aifc
```

**Step 4:**  

Update .inst file (file path)  

Search the sfx.inst file for a line that says `use ("aifc_sfx/Rocket_Launch.aifc");`. Change the file path to the .aifc file just created. It should now look like

```
sound Sound0000 {
    metaCtlWriteOrder = 1;
    use ("aifc_sfx/ont.aifc");

    pan = 64;
    volume = 100;
    envelope = Envelope0000;
    keymap = Keymap0000;
}
```

**Step 5:**  

Update .inst file (detune)  

The game plays back sound effects at a rate of 22050 Hz. If the sample rate of the audio file is different from playback, then a "detune" parameter needs to be specified in the .inst file. This is specified by the "keybase" (one MIDI note), and "detune" (one hundredth of a note). The formula to convert between sample rate <-> keybase and detune is

```
hw_sample_rate / 2^( (60 - (keybase + detune/100))/12 )
```

The "keybase" and "detune" parameter are specified in the `keymap` defined in the `sound`. In the example above, the `sound` object is named `Sound0000`, and the `keymap` object is named `Keymap0000`. Find the `Keymap0000` in the .inst file:

```
keymap Keymap0000 {
    metaCtlWriteOrder = 38;
    velocityMin = 0;
    velocityMax = 0;
    keyMin = 1;
    keyMax = 0;
    keyBase = 54;
    detune = 40;
}
```

The Rocket Launch sound effect is applying a keybase of 54 and detune of 40. Applying this in the above formula

```
22050 / 2^( (60 - (54 + 40/100))/12 ) = 15956
```

So the Rocket Launch sound effect sampling rate is 15956 Hz. Back to the "ont" example, this has a sample rate of 22050 Hz. Because this is the same as playback, set the keybase to the "natural" value (60=middle C4), and detune to 0. It should now look like

```
keymap Keymap0000 {
    metaCtlWriteOrder = 38;
    velocityMin = 0;
    velocityMax = 0;
    keyMin = 1;
    keyMax = 0;
    keyBase = 60;
    detune = 0;
}
```

**Step 6:**  

Update .inst (playback time)

The .inst file describes how long the it takes to play the sound effect, and the volume it should be played at. There three durations that need to be specified and two volumes. There is attack time, which is the amount of time it takes to ramp from 0 to the "attack volume." There is decay time, which is the amount of time it takes to go from the "attack volume" to "decay volume." Then there is the release time, which is the amount of time it takes to go from the "decay volume" to zero.

```
[start] -> (attack time) to [attack volume] -> (decay time) to [decay volume] -> (release time) to zero volume
```

The .inst file specifies these times and volumes in the `envelope` of a sound. Times are in units of micro seconds. Volume can range from 0 (silent) to 127 (full volume).

Find the `envelope` for the rocket launch sound effect. This is `Envelope0000`. Looking at the current settings, the sound effect instantly starts at full volume. It plays for 0.933830 seconds ending at full volume. Then it fades to zero volume over 0.002 seconds. Since the audio sample in this example is 2.4 seconds long, change the decayTime to 2300000 (microseconds). The `envelope` should now look like

```
envelope Envelope0000 {
    metaCtlWriteOrder = 127;
    attackTime = 0;
    attackVolume = 127;
    decayTime = 2300000;
    decayVolume = 127;
    releaseTime = 2000;
}
```

**Step 7:**  

compile  

Save the .inst changes above. Run the `build_sfx_from_aifc.sh` script. This should warn about checksums not matching. Rebuild the project.

```
cd ../..
make audioclean
cd assets/audio
./build_sfx_from_aifc.sh
make -j4
```

Demo of the above on everdrive on real console: [https://www.youtube.com/watch?v=vO2vf10bBu8](https://www.youtube.com/watch?v=vO2vf10bBu8)


# Sounds -- Instruments

This section assumes you have read the sound effect section above.

Instrument sounds are very similar to sound effect sounds in how data is treated. The keybase and detune parameters are perhaps more natural when converting from .wav to .aifc.

An instrument can use multiple waveform files for a single sound effect. This allows, for example, using one sample for high notes and a separate sample for low notes. This should specify the MIDI key notes that the waveform should be used for; the minimum MIDI note should be given by keyMin and the max by keyMax in the related `keymap`. For example, `Instrument0011` specifies it should use 8 sounds. The sound `Sound0022` is used for midi keys between 45 (A2) and 46 (A#2). Here is a partial listing from the instruments .inst file:

```
keymap Keymap0022 {
    metaCtlWriteOrder = 21;
    velocityMin = 0;
    velocityMax = 127;
    keyMin = 45;
    keyMax = 46;
    keyBase = 57;
    detune = 0;
}

sound Sound0022 {
    metaCtlWriteOrder = 18;
    use ("aifc_instruments/snd_0020.aifc");

    pan = 64;
    volume = 110;
    envelope = Envelope0000;
    keymap = Keymap0022;
}

keymap Keymap0023 {
    metaCtlWriteOrder = 22;
    velocityMin = 0;
    velocityMax = 127;
    keyMin = 47;
    keyMax = 47;
    keyBase = 59;
    detune = 0;
}

sound Sound0023 {
    metaCtlWriteOrder = 19;
    use ("aifc_instruments/snd_0021.aifc");

    pan = 64;
    volume = 120;
    envelope = Envelope0000;
    keymap = Keymap0023;
}

instrument Instrument0011 {
    volume = 127;
    pan = 64;
    priority = 5;
    bendRange = 200;

    sound [0] = Sound0016;
    sound [1] = Sound0017;
    sound [2] = Sound0018;
    sound [3] = Sound0019;
    sound [4] = Sound0020;
    sound [5] = Sound0021;
    sound [6] = Sound0022;
    sound [7] = Sound0023;
}
```

### Extract to AIFC

A convenience shell script `extract_instruments_to_aifc.sh` is provided to extract instrument sounds from the base soundbank file. This will result in .aifc files placed in the `aifc_instruments/` folder. The .aifc files are in compressed format. This is fully reversible to the .ctl and .tbl files, with an appropriate .inst file. Extracting also generates an .inst file which captures how the files were originally sorted in the .ctl and .tbl files. This is required to rebuild a matching ROM.

### Compile instruments container

A convenience shell script `build_instruments_from_aifc.sh` is provided to compile the instruments sounds into `instruments.ctl` and `instruments.tbl` files. This requires the .aifc files extracted above, and an .inst file to explain which files to use. See gaudio documentation for further details on .inst file format.

# Sounds bulk export

Conversion to wav is not reversible, so no helper scripts are included by default. If you want to bulk convert aifc samples to wav the following might be helpful.

This will convert the instrument sounds to wav. It will include "smpl" chunk to capture loop information. These will not be freequency adjusted

```
#!/bin/bash
for file in test_data/instruments/*.aifc
do
    OUTPUT_FILENAME=$(echo "${file}" | sed -e 's/\.aifc$/\.wav/')
    if [ "${file}" = "${OUTPUT_FILENAME}" ]; then
        echo "cannot determine what to rename file: ${file}"
        break
    fi
    bin/aifc2wav --in="${file}" --out="${OUTPUT_FILENAME}" --debug --inst-file=test_data/instruments.inst --inst-search=use --inst-val="${file}" --write-smpl --no-freq-adjust
    #GZ=../gzipsrc/gzip ../1172inflate.sh "${file}" "${OUTPUT_FILENAME}"
    retVal=$?
    if [ $retVal -ne 0 ]; then
        echo "fatal error, exit code $retVal"
        exit $retVal
    fi
done
```

A similar script could be run for sound effects, but the last two options (`--write-smpl --no-freq-adjust`) should be excluded.

# Music Tracks

This section covers extracting music tracks (not instruments), changing music tracks, and building the sound bank file.

### Extract to MIDI

A convenience shell script `extract_midi.sh` is provided to extract .midi tracks from the base soundbank file. This will split the soundbank into individual compressed tracks in the `seqrz/` folder. This step uses the `music_names` file to determine what to name each file extracted from the soundbank. Then it will inflate each .seq.rz into a .seq file and place that into the `seq/` folder. Finally, each .seq file will be converted to MIDI format and placed in the `midi/` folder. This script also extracts the original seq pattern markers used in the .seq file for compression. These are saved with the same filename but `.pattern` extension in the `midi/` folder. These .pattern files are required when compiling the sound bank file in order to build a matching ROM. If you aren't interested in building a matching ROM then the .pattern file isn't required; gaudio will generally recreate the same data.

Note: running the `extract_midi.sh` will print a number of messags to stderr such as

```
bad seq loop start. seq track 13, offset 162, absolute time 49152, delta 24576, loop number 0
```

These are error messages about invalid seq events included in the retail version of the game, so these error messages are expected.

### Compile to sound bank

To compile the music tracks into a soundbank, a convenience shell script `build_soundbank.sh` is provided. This will first convert every .midi file in the `midi/` folder to a .seq file in the `seq/` folder (overwriting any existing file). Each file will use an existing .pattern file in the `midi/` folder if it exists (required for a matching ROM). After converting, the gaudio `sbc` script is invoked. This requires a "system" implemntation of gzip. The version included with decomp will not build a matching soundbank. The `sbc` also rquires a "names" file, which is the same `music_names` file used to extract to MIDI files. The "names" file explains both which files to include in the soundbank, and the order they should be included. The `build_soundbank.sh` script will print some information as it processes each track, including some expected output to stderr about not being able to resolve some destination tracks, then end with a message that checksums match:

```
run midi2cseq on "midi/Wind.midi"
destination track not resolved, assuming midi track 0
Processed 63 music tracks.
Wrote 126666 bytes to "music.sbk", metadata size=504, compressesd data size=126158
checksums match: music.sbk
```

### Changing music tracks

The source code mapping for stages to music tracks is located in `src/game/music_0D2720.c` in variable `music_setup_entries`. This has four fields, the first is an `enum LEVELID` and the second is an `enum MUSIC_TRACKS`. The second field sets the (main) background music for that stage.

The soundbank file contains all the music files/tracks used in the game, so modifying this file will alter what music is loaded, similar to modifying the underlying value of a pointer. The `music_names` list is used to specify how the soundbank should be built with the `build_soundbank.sh` script. For example, here is how to change the music on Dam to the Surface 1 track by changing the soundbank file. Starting in the root folder of the project:

```
make audioclean
cd assets/audio
./extract_baserom_audio.u.sh
./extract_midi.sh
 # edit music_names, replace the "Dam" line with "Surface1"
./build_soundbank.sh
cd ../..
make
```

### Adding music tracks with new instruments

Adding a new music track with new instruments is not for the faint of heart, but I will do my best to outline the steps required.

For this example, I will be using a MIDI track from gaudio test data, located in `gaudio/test_cases/midi/entertainer_short.midi`. I copied this to the `assets/audio/midi/` folder. This example will use one external instrument; I borrowed the `44_grand_piano.aiff` sample from Super Mario 64 and resampled to 22050 Hz, converted to wav file (and renamed to `piano.wav`), and placed the file in `assets/audio/aifc_instruments`.

The general out will be:

- Convert instrument samples to .aifc
- Assemble metadata about instrument samples into the .inst file
- Adjust MIDI file to reference the instrument sample
- Add loop markers like a wizard
- Convert the MIDI file to .seq
- Update game references to use the new music

I tried to make a video version of this tutorial, which also demos the music track working correctly on everdrive. Available at [https://www.youtube.com/watch?v=01AOi7LkxUI](https://www.youtube.com/watch?v=01AOi7LkxUI).

**Convert instrument samples to .aifc**

See the outline for converting .wav to .aifc above, this is the same. The example `piano.wav` was resampled to 44100 Hz (up one octave). The original was assumed to be C4, and the new sample at C5, so named `piano_c5.wav`.

```
# from audio/assets folder
../../tools/gaudio/bin/tabledesign --in aifc_instruments/piano.wav
../../tools/gaudio/bin/wav2aifc --in=aifc_instruments/piano.wav --coef=aifc_instruments/piano.coef --out=aifc_instruments/piano.aifc
../../tools/gaudio/bin/tabledesign --in aifc_instruments/piano_c5.wav
../../tools/gaudio/bin/wav2aifc --in=aifc_instruments/piano_c5.wav --coef=aifc_instruments/piano_c5.coef --out=aifc_instruments/piano_c5.aifc
```

Note: loop points within samples are not covered in this tutorial, but gaudio supports .wav "smpl" chunk to specify loop points. See gaudio documentation for more info.

**Assemble metadata about instrument samples into the .inst file**

The last instrument in the .inst file is `Instrument0074`. A new instrument will need to be added, which I'll call `ent_inst_0075`. The instrument will need a child sound record, I'll name it `ent_sound_0131`. And the sound record will need a keymap and envelope record. The naming is not really particular, the only that matters is that references are unique within the .inst file (but don't mess up array indeces).

The sequence player restricts the audio sample to within one octave of the keybase. This is why the original piano sample was resampled to 44100 Hz above. Each one will require it's own keymap. The base sample will have a keybase of C4, with max value of B4. The second sample will have a keybase of C5 with max value of B5. The programmer manual says that keymap ranges should not overlap, as the sequence player will choose the first keymap valid for the range.

The .inst file should have the following text added

```
# Instrument0074, nothing changed about this
instrument Instrument0074 {
    volume = 127;
    pan = 64;
    priority = 5;
    bendRange = 200;

    sound [0] = Sound0129;
    sound [1] = Sound0130;
}

# keymap for new sound c4
keymap ent_keymap_c4 {
    metaCtlWriteOrder = 115;
    velocityMin = 0;
    velocityMax = 127;
    keyMin = 0;
    keyMax = 71;
    keyBase = 60;
    detune = 0;
}

# keymap for new sound c5
keymap ent_keymap_c5 {
    metaCtlWriteOrder = 116;
    velocityMin = 0;
    velocityMax = 127;
    keyMin = 72;
    keyMax = 83;
    keyBase = 72;
    detune = 0;
}

# here's a new sound
sound ent_sound_c4 {
    metaCtlWriteOrder = 132;
    use ("aifc_instruments/piano.aifc");

    pan = 127;
    volume = 127;
    envelope = Envelope0000;
    keymap = ent_keymap_c4;
}

# here's a new sound
sound ent_sound_c5 {
    metaCtlWriteOrder = 133;
    use ("aifc_instruments/piano_c5.aifc");

    pan = 127;
    volume = 127;
    envelope = Envelope0000;
    keymap = ent_keymap_c5;
}

# here's the new instrument
instrument ent_inst_0075 {
    volume = 127;
    pan = 64;
    priority = 5;
    bendRange = 200;

    # sound for everything below B4
    sound [0] = ent_sound_c4;
    # sound for C5 - B5
    sound [1] = ent_sound_c5;
}

bank Bank0000 {
    sampleRate = 22050;
    instrument [0] = Instrument0000;
    instrument [1] = Instrument0001;
    # ...
    # skipped a bunch of lines to keep this short
    # ...
    instrument [73] = Instrument0073;
    # Instrument0074 hasn't changed
    instrument [74] = Instrument0074;

    # this line is new:
    instrument [75] = ent_inst_0075;
}

```

Rebuild the instruments container. If there is a syntax error in the .inst file, this will fail, so this is a good thing to check now.

```
# from audio/assets folder
./build_instruments_from_aifc.sh
```

**MIDI processing**

Use your favorite MIDI editor to adjust the instrument used in the MIDI file to the sound sample just added. The example MIDI uses channel zero. The new instrument is index 75. The gaudio `miditool` can be used to adjust the instrument (below).

It is required that the channel of an event is the same as the track number. The gaudio `miditool` can update events to force the channel number to be the same as the track number.

```
cp ../../tools/gaudio/test_cases/midi/entertainer_short.midi midi/
# make sure all event channel are the same as track number
../../tools/gaudio/bin/miditool --in=midi/entertainer_short.midi --action=make-channel-track
# change the program control event in track 1 (channel 1) to the new instrument
../../tools/gaudio/bin/miditool --in=midi/entertainer_short.midi --action=set-channel-instrument --channel=1 --instrument=75
# which should give the following output:
destination track not resolved, assuming midi track 0
Changing MIDI "Program Change" event in track index 1, from 0 to 75
```

Note: gaudio tools only support MIDI events as used by N64. If the MIDI file contains "key signature" or "time signature" or "text" events, or any other unsupported events, this will result in error.


**MIDI track loop**

MIDI loops are specified using custom controller values. Each loop will be described using three events, a start event, count event, and end event. The start and end loop event will have one parameter which is the loop number. The loop count event has one parameter which is the loop count.

Controller 102: loop start, value is loop number  
Controller 103: loop end, value is loop number
Controller 104: loop count (0-127), value is loop count
Controller 105: loop count (128-255), value is loop count

Loop count values must be between 0-127. Controller event 105 will add 128 to the loop count.

The gaudio `miditool` can be used to insert a basic loop around a track. This will create a start event before the first Note On event, and an end event after the last Note Off (or implicit Note Off) event. The loop count will be set to the max allowed value.

```
../../tools/gaudio/bin/miditool --in=midi/entertainer_short.midi --action=add-note-loop --loop-number=0 --track=1
```

**Convert the MIDI file to .seq**
Once MIDI file is in the final state, it can be converted to seq format.

```
../../tools/gaudio/bin/midi2cseq --in=midi/entertainer_short.midi --out=seq/entertainer_short.seq
```

**Update game references to use the new music**

It's important that the array indeces for the following operations match. This example will be adding a new music track as array index 62, before the "end something" record.

Edit `src/bondconstants.h` and add a new enum in `enum MUSIC_TRACKS` for the new track. This will be placed at the end of the list, but before the `M_END_SOMETHING` enum. The end of the definition should now look like

```
    M_SURFACE2X,
    M_SURFACE2END,
    M_STATUEPART,
    M_ENTERTAINER,     // this is the new entry
    M_END_SOMETHING
```

Add a new entry at the end of `music_names` file for the new music track, before "End_Something". Reminder, this is the list of files used to compile the soundbank. The end of the file should look like

```
# previously 60-62, now 60-63
Surface2end    
Statuepart

# here is the new line:
entertainer_short

# same as before:
End_Something
```

Edit `src/music.h` and update the `NUM_MUSIC_TRACKS` definition to add one track. It should now look like

```
#define NUM_MUSIC_TRACKS  64
```

Edit `src/music.c` and update the global `g_musicDefaultTrackVolume`. Between index 61 (statuepart) and index 62, add an entry for the new track. The end of the array should now look like

```
/**
* Index 61, M_STATUEPART.
*/
0x6665,

/**
* new Index 62, M_ENTERTAINER.
*/
0x6665,

/**
* old Index 62, M_END_SOMETHING.
*/
0x7332,
```

Change the stage music mapping in `music_setup_entries` from `src/game/music_0D2720.c` to use the new music track. Here I'm changing runway:

```
struct music_setup music_setup_entries[] = {
    ...
    { LEVELID_FACILITY,    M_FACILITY,       0xFFFF,   M_FACILITYX },
    { LEVELID_RUNWAY,      M_ENTERTAINER,    0xFFFF,   M_RUNWAYPLANE },
    { LEVELID_SURFACE,     M_SURFACE1,       0xFFFF,   M_WIND },
    ...
```

**Build the project**

Work is done. Time to test.

```
# starting in assets/audio
cd ../..
make audioclean
cd assets/audio
./build_instruments_from_aifc.sh
./build_soundbank.sh
cd ../..
make -j4
```

**Tips**

- `music_names` and `sfx_names` are used both for extraction and rebuilding, so be careful if you changed one of those and are trying to reset to a working state.
- The Nintendo 64 imposes an upper limit on the keyMax value of one octave more than the keyBase. This is a hard upper limit on how high frequency audio can detune, any value above this will simply play at the max value instead.
- Keymap ranges should not overlap. The manual states the sequence player will choose the first matching keymap if multiple are available.
- The sequence player does not seem to like if the MIDI event channel is different from the track number. This resulted in bad DMA request / hard crash for me.
- The programming manual states MIDI/sequence loop value of zero will loop forever, but a value of zero seems to only play once.

# Limitations

### Limitations of converting between file formats

Music (track) conversion is fully reversible. That is, converting between a music .seq and .midi format is fully reversible. Note that this is MIDI format, so no audio waveform data is included. Also note, the retail version of the game has a number of invalid MIDI events which make reversible conversion difficult. System Exclusive MIDI event was used to encode some of these bad events to be recovered later. If you are having software problems reading the converted MIDI file, try removing the `--export-invalid-loop` command line flag. See gaudio documentation for further details on conversion.

Audio data or waveform conversion is not reversible. That is, it is not possible to include a .wav file and build a matching ROM. It is possible to extract .aifc and convert that back into .ctl and .tbl for a matching ROM, but this is perhaps not so interesting.

### Changing object sound effect via source code

The state of decomp is not advanced enough to be able to change the sound effect used by objects in code. This effectively means new sound effects can not be added. Only the underlying sound (.aifc) can be changed by overwriting an existing sound effect.
