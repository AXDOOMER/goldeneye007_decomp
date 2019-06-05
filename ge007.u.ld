/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
    __romPos = 0;

	rom_start = .;
   /* header */
   .header 0x04000000 : AT(__romPos) {
      build/src/rom_header.o(.data);
   }
   __romPos += SIZEOF(.header);

   /* boot */
   .boot 0x04000040 : AT(__romPos) {
      build/src/bootcode.o(.text);
   }
   __romPos += SIZEOF(.boot);


   /* 0x80000400, 0x80000450 */
   _startSegmentStart = ADDR(.start);
   _startSegmentRomStart = 0x1000;
   .start 0x80000400 : AT(__romPos) {
      build/src/_start.o (.text);
   }
   _startSegmentEnd = ADDR(.start) + SIZEOF(.start);
   _startSegmentRomEnd = 0x1000 + SIZEOF(.start);
   __romPos = 0x1050;


   /* 0x70000450, 0x70020D90 001050-021990 */
   _codeSegmentStart = ADDR(.code);
   _codeSegmentRomStart = 0x1050;
   .code 0x70000450 : AT(0x1050) SUBALIGN(16) {
      build/src/boot.o (.text);
      build/src/init.o (.text);
      build/src/sched.o (.text);
      build/src/osMapTLB.o (.text);
      build/src/tlb_manage.o (.text);
      build/src/tlb_random.o (.text);
      build/src/tlb_resolve.o (.text);
      build/src/tlb_hardware.o (.text);
      build/src/audi.o (.text);
      build/src/speed_graph.o (.text);
      build/src/video.o (.text);
      build/src/deb.o (.text);
      build/src/debug_stuff_split.o (.text);
      build/src/debug_getlastRA.o (.text);
      build/src/ramrom.o (.text);
      build/src/boss.o (.text);
      build/src/music.o (.text);
      build/src/sfx.o (.text);
      build/src/memp.o (.text);
      build/src/mema.o (.text);
      build/src/random.o (.text);
      build/src/token.o (.text);
      build/src/stringhandler.o (.text);
      build/src/sprintf.o (.text);
      build/src/pi.o (.text);
      build/src/vi.o (.text);
      build/src/debugmenu.o (.text);
      build/src/joy.o (.text);
      build/src/joy_rumble.o (.text);
      build/src/rmon.o (.text);
      build/libultra/libultra.o (.text);
   }
   _codeSegmentEnd = ADDR(.code) + SIZEOF(.code);
   _codeSegmentRomEnd = 0x1050 + SIZEOF(.code);
   __romPos = 0x21990;



   _cdataSegmentStart = ADDR(.cdata);
   _cdataSegmentRomStart = 0x21990;
   .cdata 0x21990 : AT(0x21990) {
      build/src/c_data_filler.o (.data);
   }
   _cdataSegmentEnd = ADDR(.cdata) + SIZEOF(.cdata);
   _cdataSegmentRomEnd = 0x21990 + SIZEOF(.cdata);
   __romPos = 0x033590;
   


   /* (0x70200000, 0x702029BC, 0x701CCA70), // 033590-035F4D [29BD] */
   _rarezipSegmentStart = ADDR(.rarezip);
   _rarezipSegmentRomStart = 0x033590;
   .rarezip 0x70200000 : AT(__romPos) {
      build/src/rarezip/rarezip.o (.text);
      build/src/rarezip/rarezip.o (.data);
   }
   _rarezipSegmentEnd = ADDR(.rarezip) + SIZEOF(.rarezip);
   _rarezipSegmentRomEnd = 0x033590 + SIZEOF(.rarezip);
   __romPos = 0x034B30;


   
   
   /* (0x7F000000, 0x7F0E2D50, 0x7EFCB4D0), // 034B30-117881 [E2D51] */
   _gameSegmentStart = ADDR(.game);
   _gameSegmentRomStart = 0x034B30;
   .game 0x7F000000 : AT(__romPos) {
      build/src/game/initgamedata.o (.text);
      build/src/game/initweaponanigroups.o (.text);
      build/src/game/initactorpropstuff.o (.text);
      build/src/game/initnull_0009D0.o (.text);
      build/src/game/initunk_0009E0.o (.text);
      build/src/game/initanitable.o (.text);
      build/src/game/initunk_000B60.o (.text);
      build/src/game/setguscale.o (.text);
      build/src/game/initnull_000BC0.o (.text);
      build/src/game/initimages.o (.text);
      build/src/game/initintromatrices.o (.text);
      build/src/game/initmenus.o (.text);
      build/src/game/initguards.o (.text);
      build/src/game/deb_loadallmodels.o (.text);
      build/src/game/initobjects.o (.text);
      build/src/game/prop.o (.text);
      build/src/game/objective.o (.text);
      build/src/game/ejectedcartridges.o (.text);
      build/src/game/initBondDATA.o (.text);
      build/src/game/initunk_005450.o (.text);
      build/src/game/initunk_005520.o (.text);
      build/src/game/initcameraandthrown.o (.text);
      build/src/game/inititemslots.o (.text);
      build/src/game/initBondDATAdefaults.o (.text);
      build/src/game/initpathtablesomething.o (.text);
      build/src/game/initpathtablelinks.o (.text);
      build/src/game/initexplosioncasing.o (.text);
      build/src/game/initunk_007180.o (.text);
      build/src/game/initunk_007290.o (.text);
      build/src/game/initunk_0072B0.o (.text);
      build/src/game/initmttex.o (.text);
      build/src/game/initunk_0073B0.o (.text);
      build/src/game/initunk_007460.o (.text);
      build/src/game/cleanup_alarms.o (.text);
      build/src/game/cleanup_objects.o (.text);
      build/src/game/cleanup_objectives.o (.text);
      build/src/game/cleanupSFXRelated.o (.text);
      build/src/game/playerstats_007770.o (.text);
      build/src/game/unk_007800.o (.text);
      build/src/game/unk_007920.o (.text);
      build/src/game/null_007970.o (.text);
      build/src/game/unk_007980.o (.text);
      build/src/game/intro_logos.o (.text);
      build/src/game/mainmenu.o (.text);
      build/src/game/unk_01B0E0.o (.text);
      build/src/game/unk_01B240.o (.text);
      build/src/game/unk_01BAE0.o (.text);
      build/src/game/blood_animation.o (.text);
      build/src/game/blood_decrypt.o (.text);
      build/src/game/eeprom.o (.text);
      build/src/game/actor.o (.text);
      build/src/game/actionblock.o (.text);
      build/src/game/loadobjectmodel.o (.text);
      build/src/game/objective_status.o (.text);
      build/src/game/sin.o (.text);
      build/src/game/unk_057FD0.o (.text);
      build/src/game/unk_05A9E0.o (.text);
      build/src/game/convertangleusinginverse.o (.text);
      build/src/game/unk_05AB70.o (.text);
      build/src/game/unk_05ACB0.o (.text);
      build/src/game/unk_05AE00.o (.text);
      build/src/game/unk_05B1E0.o (.text);
      build/src/game/truncf.o (.text);
      build/src/game/unk_05C440.o (.text);
      build/src/game/bondview.o (.text);
      build/src/game/objecthandler.o (.text);
      build/src/game/objecthandler_2.o (.text);
      build/src/game/othermodemicrocode.o (.text);
      build/src/game/bond.o (.text);
      build/src/game/unk_08DBB0.o (.text);
      build/src/game/debugmenu_08FE00.o (.text);
      build/src/game/debugmenu_090490.o (.text);
      build/src/game/unk_091080.o (.text);
      build/src/game/cheat_buttons_objectrelated.o (.text);
      build/src/game/unk_092890.o (.text);
      build/src/game/unk_092E50.o (.text);
      build/src/game/unk_093880.o (.text);
      build/src/game/unk_09B600.o (.text);
      build/src/game/unk_09B740.o (.text);
      build/src/game/unk_09B7A0.o (.text);
      build/src/game/unk_09C250.o (.text);
      build/src/game/unk_0A1DA0.o (.text);
      build/src/game/watch.o (.text);
      build/src/game/textrelated.o (.text);
      build/src/game/stan.o (.text);
      build/src/game/unk_0B3200.o (.text);
      build/src/game/bg.o (.text);
      build/src/game/fog.o (.text);
      build/src/game/lightfixture.o (.text);
      build/src/game/unk_0BC530.o (.text);
      build/src/game/ob.o (.text);
      build/src/game/dyn.o (.text);
      build/src/game/lvl.o (.text);
      build/src/game/lvl_2.o (.text);
      build/src/game/unk_0C0A70.o (.text);
      build/src/game/mp_music.o (.text);
      build/src/game/lvl_text.o (.text);
      build/src/game/mp_watch.o (.text);
      build/src/game/radar.o (.text);
      build/src/game/mp_weapon.o (.text);
      build/src/game/image.o (.text);
      build/src/game/image_bank.o (.text);
      build/src/game/unk_0CC4C0.o (.text);
      build/src/game/decompress.o (.text);
      build/src/game/zlib.o (.text);
      build/src/game/rsp.o (.text);
      build/src/game/indy_comms.o (.text);
      build/src/game/indy_0D0180.o (.text);
      build/src/game/game_debug.o (.text);
      build/src/game/compiletime.o (.text);
      build/src/game/unk_0D1AC0.o (.text);
      build/src/game/viewport.o (.text);
      build/src/game/music_0D2720.o (.text);
      build/src/game/spectrum.o (.text);
   }

   _gameSegmentEnd = ADDR(.game) + SIZEOF(.game);
   _gameSegmentRomEnd = 0x034B30 + SIZEOF(.game);
   __romPos = 0x117880;


   _romfiles_117880SegmentStart = ADDR(.romfiles_117880);
   _romfiles_117880SegmentRomStart = 0x117880;
   .romfiles_117880 0x117880 : AT(__romPos) {
      build/assets/romfiles.o (.romfiles);
      build/assets/ramrom/ramrom.o (.ramrom);
      build/assets/font/font.o (.font);
      build/assets/music/music.o (.music);
      build/assets/music/music.o (.musiccompressed);
   }
   _romfiles_117880SegmentEnd = ADDR(.romfiles_117880) + SIZEOF(.romfiles_117880);
   _romfiles_117880SegmentRomEnd = 0x117880 + SIZEOF(.romfiles_117880);
   __romPos = 0x438660;



   _obsegSegmentStart = ADDR(.obseg);
   _obsegSegmentRomStart = 0x438660;
   .obseg 0x438660 : AT(0x438660) {
      build/assets/obseg/ob_seg.o (.ob_seg);
   }
   _obsegSegmentEnd = ADDR(.obseg) + SIZEOF(.obseg);
   _obsegSegmentRomEnd = 0x438660 + SIZEOF(.obseg);

   __romPos = 0x8F7DF0;


   _imagesSegmentStart = ADDR(.images);
   _imagesSegmentRomStart = 0x8F7DF0;
   .images 0x8F7DF0 : AT(0x8F7DF0) {
      build/assets/images/images.o (.images);
   }
   _imagesSegmentEnd = ADDR(.images) + SIZEOF(.images);
   _imagesSegmentRomEnd = 0x8F7DF0 + SIZEOF(.images);

   __romPos = 0xBE6D10;

   __csegtempPos = 0xC00000;
   __ramPos = 0x80020d90;
   _csegmentSegmentStart = ADDR(.csegment);
   _csegmentSegmentRomStart = __csegtempPos;
   .csegment 0x80020d90 : AT(__csegtempPos) {
      build/src/rspboot.o (.text);
      build/src/gspboot.o (.text);
      build/src/aspboot.o (.text);
      build/src/boot.o (.data);
      build/src/init.o (.data);
      build/src/sched.o (.data);
      build/src/osMapTLB.o (.data);
      build/src/tlb_manage.o (.data);
      build/src/tlb_random.o (.data);
      build/src/tlb_resolve.o (.data);
      build/src/tlb_hardware.o (.data);
      build/src/audi.o (.data);
      build/src/speed_graph.o (.data);
      build/src/video.o (.data);
      build/src/deb.o (.data);
      build/src/debug_stuff_split.o (.data);
      build/src/debug_getlastRA.o (.data);
      build/src/ramrom.o (.data);
      build/src/boss.o (.data);
      build/src/music.o (.data);
      build/src/sfx.o (.data);
      build/src/memp.o (.data);
      build/src/mema.o (.data);
      build/src/random.o (.data);
      build/src/token.o (.data);
      build/src/stringhandler.o (.data);
      build/src/sprintf.o (.data);
      build/src/pi.o (.data);
      build/src/vi.o (.data);
      build/src/debugmenu.o (.data);
      build/src/joy.o (.data);
      build/src/joy_rumble.o (.data);
      build/src/rmon.o (.data);
      build/libultra/libultra.o (.data);

      build/src/aspboot.o (.rodata);
      build/src/boot.o (.rodata);
      build/src/init.o (.rodata);
      build/src/sched.o (.rodata);
      build/src/osMapTLB.o (.rodata);
      build/src/tlb_manage.o (.rodata);
      build/src/tlb_random.o (.rodata);
      build/src/tlb_resolve.o (.rodata);
      build/src/tlb_hardware.o (.rodata);
      build/src/audi.o (.rodata);
      build/src/speed_graph.o (.rodata);
      build/src/video.o (.rodata);
      build/src/deb.o (.rodata);
      build/src/debug_stuff_split.o (.rodata);
      build/src/debug_getlastRA.o (.rodata);
      build/src/ramrom.o (.rodata);
      build/src/boss.o (.rodata);
      build/src/music.o (.rodata);
      build/src/sfx.o (.rodata);
      build/src/memp.o (.rodata);
      build/src/mema.o (.rodata);
      build/src/random.o (.rodata);
      build/src/token.o (.rodata);
      build/src/stringhandler.o (.rodata);
      build/src/sprintf.o (.rodata);
      build/src/pi.o (.rodata);
      build/src/vi.o (.rodata);
      build/src/debugmenu.o (.rodata);
      build/src/joy.o (.rodata);
      build/src/joy_rumble.o (.rodata);
      build/src/rmon.o (.rodata);
      build/libultra/libultra.o (.rodata);

      build/src/game/initgamedata.o (.data);
      build/src/game/initweaponanigroups.o (.data);
      build/src/game/initactorpropstuff.o (.data);
      build/src/game/initnull_0009D0.o (.data);
      build/src/game/initunk_0009E0.o (.data);
      build/src/game/initanitable.o (.data);
      build/src/game/initunk_000B60.o (.data);
      build/src/game/setguscale.o (.data);
      build/src/game/initnull_000BC0.o (.data);
      build/src/game/initimages.o (.data);
      build/src/game/initintromatrices.o (.data);
      build/src/game/initmenus.o (.data);
      build/src/game/initguards.o (.data);
      build/src/game/deb_loadallmodels.o (.data);
      build/src/game/initobjects.o (.data);
      build/src/game/prop.o (.data);
      build/src/game/objective.o (.data);
      build/src/game/ejectedcartridges.o (.data);
      build/src/game/initBondDATA.o (.data);
      build/src/game/initunk_005450.o (.data);
      build/src/game/initunk_005520.o (.data);
      build/src/game/initcameraandthrown.o (.data);
      build/src/game/inititemslots.o (.data);
      build/src/game/initBondDATAdefaults.o (.data);
      build/src/game/initpathtablesomething.o (.data);
      build/src/game/initpathtablelinks.o (.data);
      build/src/game/initexplosioncasing.o (.data);
      build/src/game/initunk_007180.o (.data);
      build/src/game/initunk_007290.o (.data);
      build/src/game/initunk_0072B0.o (.data);
      build/src/game/initmttex.o (.data);
      build/src/game/initunk_0073B0.o (.data);
      build/src/game/initunk_007460.o (.data);
      build/src/game/cleanup_alarms.o (.data);
      build/src/game/cleanup_objects.o (.data);
      build/src/game/cleanup_objectives.o (.data);
      build/src/game/cleanupSFXRelated.o (.data);
      build/src/game/playerstats_007770.o (.data);
      build/src/game/unk_007800.o (.data);
      build/src/game/unk_007920.o (.data);
      build/src/game/null_007970.o (.data);
      build/src/game/unk_007980.o (.data);
      build/src/game/intro_logos.o (.data);
      build/src/game/mainmenu.o (.data);
      build/src/game/unk_01B0E0.o (.data);
      build/src/game/unk_01B240.o (.data);
      build/src/game/unk_01BAE0.o (.data);
      build/src/game/blood_animation.o (.data);
      build/src/game/blood_decrypt.o (.data);
      build/src/game/eeprom.o (.data);
      build/src/game/actor.o (.data);
      build/src/game/actionblock.o (.data);
      build/src/game/loadobjectmodel.o (.data);
      build/src/game/objective_status.o (.data);
      build/src/game/sin.o (.data);
      build/src/game/unk_057FD0.o (.data);
      build/src/game/unk_05A9E0.o (.data);
      build/src/game/convertangleusinginverse.o (.data);
      build/src/game/unk_05AB70.o (.data);
      build/src/game/unk_05ACB0.o (.data);
      build/src/game/unk_05AE00.o (.data);
      build/src/game/unk_05B1E0.o (.data);
      build/src/game/truncf.o (.data);
      build/src/game/unk_05C440.o (.data);
      build/src/game/bondview.o (.data);
      build/src/game/objecthandler.o (.data);
      build/src/game/objecthandler_2.o (.data);
      build/src/game/othermodemicrocode.o (.data);
      build/src/game/bond.o (.data);
      build/src/game/unk_08DBB0.o (.data);
      build/src/game/debugmenu_08FE00.o (.data);
      build/src/game/debugmenu_090490.o (.data);
      build/src/game/unk_091080.o (.data);
      build/src/game/cheat_buttons_objectrelated.o (.data);
      build/src/game/unk_092890.o (.data);
      build/src/game/unk_092E50.o (.data);
      build/src/game/unk_093880.o (.data);
      build/src/game/unk_09B600.o (.data);
      build/src/game/unk_09B740.o (.data);
      build/src/game/unk_09B7A0.o (.data);
      build/src/game/unk_09C250.o (.data);
      build/src/game/unk_0A1DA0.o (.data);
      build/src/game/watch.o (.data);
      build/src/game/textrelated.o (.data);
      build/src/game/stan.o (.data);
      build/src/game/unk_0B3200.o (.data);
      build/src/game/bg.o (.data);
      build/src/game/fog.o (.data);
      build/src/game/lightfixture.o (.data);
      build/src/game/unk_0BC530.o (.data);
      build/src/game/ob.o (.data);
      build/src/game/dyn.o (.data);
      build/src/game/lvl.o (.data);
      build/src/game/lvl_2.o (.data);
      build/src/game/unk_0C0A70.o (.data);
      build/src/game/mp_music.o (.data);
      build/src/game/lvl_text.o (.data);
      build/src/game/mp_watch.o (.data);
      build/src/game/radar.o (.data);
      build/src/game/mp_weapon.o (.data);
      build/src/game/image.o (.data);
      build/src/game/image_bank.o (.data);
      build/src/game/unk_0CC4C0.o (.data);
      build/src/game/decompress.o (.data);
      build/src/game/zlib.o (.data);
      build/src/game/rsp.o (.data);
      build/src/game/indy_comms.o (.data);
      build/src/game/indy_0D0180.o (.data);
      build/src/game/game_debug.o (.data);
      build/src/game/compiletime.o (.data);
      build/src/game/unk_0D1AC0.o (.data);
      build/src/game/viewport.o (.data);
      build/src/game/music_0D2720.o (.data);
      build/src/game/spectrum.o (.data);

      build/src/game/initgamedata.o (.rodata);
      build/src/game/initweaponanigroups.o (.rodata);
      build/src/game/initactorpropstuff.o (.rodata);
      build/src/game/initnull_0009D0.o (.rodata);
      build/src/game/initunk_0009E0.o (.rodata);
      build/src/game/initanitable.o (.rodata);
      build/src/game/initunk_000B60.o (.rodata);
      build/src/game/setguscale.o (.rodata);
      build/src/game/initnull_000BC0.o (.rodata);
      build/src/game/initimages.o (.rodata);
      build/src/game/initintromatrices.o (.rodata);
      build/src/game/initmenus.o (.rodata);
      build/src/game/initguards.o (.rodata);
      build/src/game/deb_loadallmodels.o (.rodata);
      build/src/game/initobjects.o (.rodata);
      build/src/game/prop.o (.rodata);
      build/src/game/objective.o (.rodata);
      build/src/game/ejectedcartridges.o (.rodata);
      build/src/game/initBondDATA.o (.rodata);
      build/src/game/initunk_005450.o (.rodata);
      build/src/game/initunk_005520.o (.rodata);
      build/src/game/initcameraandthrown.o (.rodata);
      build/src/game/inititemslots.o (.rodata);
      build/src/game/initBondDATAdefaults.o (.rodata);
      build/src/game/initpathtablesomething.o (.rodata);
      build/src/game/initpathtablelinks.o (.rodata);
      build/src/game/initexplosioncasing.o (.rodata);
      build/src/game/initunk_007180.o (.rodata);
      build/src/game/initunk_007290.o (.rodata);
      build/src/game/initunk_0072B0.o (.rodata);
      build/src/game/initmttex.o (.rodata);
      build/src/game/initunk_0073B0.o (.rodata);
      build/src/game/initunk_007460.o (.rodata);
      build/src/game/cleanup_alarms.o (.rodata);
      build/src/game/cleanup_objects.o (.rodata);
      build/src/game/cleanup_objectives.o (.rodata);
      build/src/game/cleanupSFXRelated.o (.rodata);
      build/src/game/playerstats_007770.o (.rodata);
      build/src/game/unk_007800.o (.rodata);
      build/src/game/unk_007920.o (.rodata);
      build/src/game/null_007970.o (.rodata);
      build/src/game/unk_007980.o (.rodata);
      build/src/game/intro_logos.o (.rodata);
      build/src/game/mainmenu.o (.rodata);
      build/src/game/unk_01B0E0.o (.rodata);
      build/src/game/unk_01B240.o (.rodata);
      build/src/game/unk_01BAE0.o (.rodata);
      build/src/game/blood_animation.o (.rodata);
      build/src/game/blood_decrypt.o (.rodata);
      build/src/game/eeprom.o (.rodata);
      build/src/game/actor.o (.rodata);
      build/src/game/actionblock.o (.rodata);
      build/src/game/loadobjectmodel.o (.rodata);
      build/src/game/objective_status.o (.rodata);
      build/src/game/sin.o (.rodata);
      build/src/game/unk_057FD0.o (.rodata);
      build/src/game/unk_05A9E0.o (.rodata);
      build/src/game/convertangleusinginverse.o (.rodata);
      build/src/game/unk_05AB70.o (.rodata);
      build/src/game/unk_05ACB0.o (.rodata);
      build/src/game/unk_05AE00.o (.rodata);
      build/src/game/unk_05B1E0.o (.rodata);
      build/src/game/truncf.o (.rodata);
      build/src/game/unk_05C440.o (.rodata);
      build/src/game/bondview.o (.rodata);
      build/src/game/objecthandler.o (.rodata);
      build/src/game/objecthandler_2.o (.rodata);
      build/src/game/othermodemicrocode.o (.rodata);
      build/src/game/bond.o (.rodata);
      build/src/game/unk_08DBB0.o (.rodata);
      build/src/game/debugmenu_08FE00.o (.rodata);
      build/src/game/debugmenu_090490.o (.rodata);
      build/src/game/unk_091080.o (.rodata);
      build/src/game/cheat_buttons_objectrelated.o (.rodata);
      build/src/game/unk_092890.o (.rodata);
      build/src/game/unk_092E50.o (.rodata);
      build/src/game/unk_093880.o (.rodata);
      build/src/game/unk_09B600.o (.rodata);
      build/src/game/unk_09B740.o (.rodata);
      build/src/game/unk_09B7A0.o (.rodata);
      build/src/game/unk_09C250.o (.rodata);
      build/src/game/unk_0A1DA0.o (.rodata);
      build/src/game/watch.o (.rodata);
      build/src/game/textrelated.o (.rodata);
      build/src/game/stan.o (.rodata);
      build/src/game/unk_0B3200.o (.rodata);
      build/src/game/bg.o (.rodata);
      build/src/game/fog.o (.rodata);
      build/src/game/lightfixture.o (.rodata);
      build/src/game/unk_0BC530.o (.rodata);
      build/src/game/ob.o (.rodata);
      build/src/game/dyn.o (.rodata);
      build/src/game/lvl.o (.rodata);
      build/src/game/lvl_2.o (.rodata);
      build/src/game/unk_0C0A70.o (.rodata);
      build/src/game/mp_music.o (.rodata);
      build/src/game/lvl_text.o (.rodata);
      build/src/game/mp_watch.o (.rodata);
      build/src/game/radar.o (.rodata);
      build/src/game/mp_weapon.o (.rodata);
      build/src/game/image.o (.rodata);
      build/src/game/image_bank.o (.rodata);
      build/src/game/unk_0CC4C0.o (.rodata);
      build/src/game/decompress.o (.rodata);
      build/src/game/zlib.o (.rodata);
      build/src/game/rsp.o (.rodata);
      build/src/game/indy_comms.o (.rodata);
      build/src/game/indy_0D0180.o (.rodata);
      build/src/game/game_debug.o (.rodata);
      build/src/game/compiletime.o (.rodata);
      build/src/game/unk_0D1AC0.o (.rodata);
      build/src/game/viewport.o (.rodata);
      build/src/game/music_0D2720.o (.rodata);
      build/src/game/spectrum.o (.rodata);

      build/src/gspboot.o (.data);
      build/src/aspboot.o (.data);
   }
   _csegmentSegmentEnd = ADDR(.csegment) + SIZEOF(.csegment);
   _csegmentSegmentRomEnd = 0xC00000 + SIZEOF(.csegment);

   __ramPos += SIZEOF(.csegment);
   __csegtempPosEnd =  (__csegtempPos + SIZEOF (.csegment));

   _bssSegmentStart = ADDR(.bss);
   _bssSegmentRomStart = __csegtempPosEnd;
   .bss 0x8005D2E0 : AT(__csegtempPosEnd){
      build/src/boot.o (.bss);
      build/src/init.o (.bss);
      build/src/sched.o (.bss);
      build/src/osMapTLB.o (.bss);
      build/src/tlb_manage.o (.bss);
      build/src/tlb_random.o (.bss);
      build/src/tlb_resolve.o (.bss);
      build/src/audi.o (.bss);
      build/src/speed_graph.o (.bss);
      build/src/video.o (.bss);
      build/src/deb.o (.bss);
      build/src/debug_stuff_split.o (.bss);
      build/src/debug_getlastRA.o (.bss);
      build/src/ramrom.o (.bss);
      build/src/boss.o (.bss);
      build/src/music.o (.bss);
      build/src/sfx.o (.bss);
      build/src/memp.o (.bss);
      build/src/mema.o (.bss);
      build/src/random.o (.bss);
      build/src/token.o (.bss);
      build/src/stringhandler.o (.bss);
      build/src/sprintf.o (.bss);
      build/src/pi.o (.bss);
      build/src/vi.o (.bss);
      build/src/debugmenu.o (.bss);
      build/src/joy.o (.bss);
      build/src/joy_rumble.o (.bss);
      build/src/rmon.o (.bss);
      build/libultra/libultra.o (.bss);
      build/src/game/initgamedata.o (.bss);
      build/src/game/initweaponanigroups.o (.bss);
      build/src/game/initactorpropstuff.o (.bss);
      build/src/game/initnull_0009D0.o (.bss);
      build/src/game/initunk_0009E0.o (.bss);
      build/src/game/initanitable.o (.bss);
      build/src/game/initunk_000B60.o (.bss);
      build/src/game/setguscale.o (.bss);
      build/src/game/initnull_000BC0.o (.bss);
      build/src/game/initimages.o (.bss);
      build/src/game/initintromatrices.o (.bss);
      build/src/game/initmenus.o (.bss);
      build/src/game/initguards.o (.bss);
      build/src/game/deb_loadallmodels.o (.bss);
      build/src/game/initobjects.o (.bss);
      build/src/game/prop.o (.bss);
      build/src/game/objective.o (.bss);
      build/src/game/ejectedcartridges.o (.bss);
      build/src/game/initBondDATA.o (.bss);
      build/src/game/initunk_005450.o (.bss);
      build/src/game/initunk_005520.o (.bss);
      build/src/game/initcameraandthrown.o (.bss);
      build/src/game/inititemslots.o (.bss);
      build/src/game/initBondDATAdefaults.o (.bss);
      build/src/game/initpathtablesomething.o (.bss);
      build/src/game/initpathtablelinks.o (.bss);
      build/src/game/initexplosioncasing.o (.bss);
      build/src/game/initunk_007180.o (.bss);
      build/src/game/initunk_007290.o (.bss);
      build/src/game/initunk_0072B0.o (.bss);
      build/src/game/initmttex.o (.bss);
      build/src/game/initunk_0073B0.o (.bss);
      build/src/game/initunk_007460.o (.bss);
      build/src/game/cleanup_alarms.o (.bss);
      build/src/game/cleanup_objects.o (.bss);
      build/src/game/cleanup_objectives.o (.bss);
      build/src/game/cleanupSFXRelated.o (.bss);
      build/src/game/playerstats_007770.o (.bss);
      build/src/game/unk_007800.o (.bss);
      build/src/game/unk_007920.o (.bss);
      build/src/game/null_007970.o (.bss);
      build/src/game/unk_007980.o (.bss);
      build/src/game/intro_logos.o (.bss);
      build/src/game/mainmenu.o (.bss);
      build/src/game/unk_01B0E0.o (.bss);
      build/src/game/unk_01B240.o (.bss);
      build/src/game/unk_01BAE0.o (.bss);
      build/src/game/blood_animation.o (.bss);
      build/src/game/blood_decrypt.o (.bss);
      build/src/game/eeprom.o (.bss);
      build/src/game/actor.o (.bss);
      build/src/game/actionblock.o (.bss);
      build/src/game/loadobjectmodel.o (.bss);
      build/src/game/objective_status.o (.bss);
      build/src/game/sin.o (.bss);
      build/src/game/unk_057FD0.o (.bss);
      build/src/game/unk_05A9E0.o (.bss);
      build/src/game/convertangleusinginverse.o (.bss);
      build/src/game/unk_05AB70.o (.bss);
      build/src/game/unk_05ACB0.o (.bss);
      build/src/game/unk_05AE00.o (.bss);
      build/src/game/unk_05B1E0.o (.bss);
      build/src/game/truncf.o (.bss);
      build/src/game/unk_05C440.o (.bss);
      build/src/game/bondview.o (.bss);
      build/src/game/objecthandler.o (.bss);
      build/src/game/objecthandler_2.o (.bss);
      build/src/game/othermodemicrocode.o (.bss);
      build/src/game/bond.o (.bss);
      build/src/game/unk_08DBB0.o (.bss);
      build/src/game/debugmenu_08FE00.o (.bss);
      build/src/game/debugmenu_090490.o (.bss);
      build/src/game/unk_091080.o (.bss);
      build/src/game/cheat_buttons_objectrelated.o (.bss);
      build/src/game/unk_092890.o (.bss);
      build/src/game/unk_092E50.o (.bss);
      build/src/game/unk_093880.o (.bss);
      build/src/game/unk_09B600.o (.bss);
      build/src/game/unk_09B740.o (.bss);
      build/src/game/unk_09B7A0.o (.bss);
      build/src/game/unk_09C250.o (.bss);
      build/src/game/unk_0A1DA0.o (.bss);
      build/src/game/watch.o (.bss);
      build/src/game/textrelated.o (.bss);
      build/src/game/stan.o (.bss);
      build/src/game/unk_0B3200.o (.bss);
      build/src/game/bg.o (.bss);
      build/src/game/fog.o (.bss);
      build/src/game/lightfixture.o (.bss);
      build/src/game/unk_0BC530.o (.bss);
      build/src/game/ob.o (.bss);
      build/src/game/dyn.o (.bss);
      build/src/game/lvl.o (.bss);
      build/src/game/lvl_2.o (.bss);
      build/src/game/unk_0C0A70.o (.bss);
      build/src/game/mp_music.o (.bss);
      build/src/game/lvl_text.o (.bss);
      build/src/game/mp_watch.o (.bss);
      build/src/game/radar.o (.bss);
      build/src/game/mp_weapon.o (.bss);
      build/src/game/image.o (.bss);
      build/src/game/image_bank.o (.bss);
      build/src/game/unk_0CC4C0.o (.bss);
      build/src/game/decompress.o (.bss);
      build/src/game/zlib.o (.bss);
      build/src/game/rsp.o (.bss);
      build/src/game/indy_comms.o (.bss);
      build/src/game/indy_0D0180.o (.bss);
      build/src/game/game_debug.o (.bss);
      build/src/game/compiletime.o (.bss);
      build/src/game/unk_0D1AC0.o (.bss);
      build/src/game/viewport.o (.bss);
      build/src/game/music_0D2720.o (.bss);
      build/src/game/spectrum.o (.bss);
   }
   _bssSegmentEnd = ADDR(.bss) + SIZEOF(.bss);
   _bssSegmentRomEnd = 0xc3c550 + SIZEOF(.bss);

__ramPos += SIZEOF(.bss);

   /*move em to end, out of the way*/
   /DISCARD/ : {
      * (.MIPS.abiflags);
      * (.musicdecompressed);
      * (.options);
      * (.gnu.attributes);
      * (.pdr);
      * (.mdebug);
      * (.gptab.bss);
      * (.gptab.data);
      * (.reginfo);
      
      build/assets/romfiles.o (.text);
      build/assets/romfiles.o (.data);
      build/assets/ramrom/ramrom.o (.text);
      build/assets/ramrom/ramrom.o (.data);
      build/assets/font/font.o (.text);
      build/assets/font/font.o (.data);
      build/assets/music/music.o (.text);
      build/assets/music/music.o (.data);
      build/assets/obseg/ob_seg.o (.text);
      build/assets/obseg/ob_seg.o (.data);
      build/assets/images/images.o (.text);
      build/assets/images/images.o (.data);
      build/src/rom_header.o (.text);
      build/src/bootcode.o (.data);
      build/src/_start.o (.data);
      build/src/rspboot.o (.data);
      build/src/_start.o (.rodata);
      build/src/rspboot.o (.rodata);
      build/src/gspboot.o (.rodata);
}
}
