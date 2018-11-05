/*OUTPUT_FORMAT ("elf32-bigmips")*/
OUTPUT_ARCH (mips)

SECTIONS
{
    __romPos = 0;

	rom_start = .;
   /* header */
   .header __romPos : AT(__romPos) {
      build/rom_header.o(.data);
   }
   __romPos += SIZEOF(.header);

   /* boot */
   .boot 0x04000040 : AT(__romPos) {
      build/bootcode.o(.text);
   }
   __romPos += SIZEOF(.boot);

   __ramPos = 400;
   /* 0x80000400, 0x80000450 */
   .text_start 0x80000400 : AT(__romPos) {
      build/_start.o (.text);
   }
   __romPos += SIZEOF(.text_start);
   __ramPos += SIZEOF(.text_start);

   /* 0x70000450, 0x70020D90 001050-021990 */
   .text_code 0x70000450 : AT(__romPos) {
      build/boot.o (.text);
      build/code/init.o (.text);
      build/code/sched.o (.text);
      build/code/osMapTLB.o (.text);
      build/code/tlb_manage.o (.text);
      build/code/tlb_random.o (.text);
      build/code/tlb_resolve.o (.text);
      build/code/audi.o (.text);
      build/code/speed_graph.o (.text);
      build/code/video.o (.text);
      build/code/deb.o (.text);
      build/code/debug_getlastRA.o (.text);
      build/code/ramrom.o (.text);
      build/code/boss.o (.text);
      build/code/music.o (.text);
      build/code/sfx.o (.text);
      build/code/memp.o (.text);
      build/code/mema.o (.text);
      build/code/random.o (.text);
      build/code/token.o (.text);
      build/code/stringhandler.o (.text);
      build/code/sprintf.o (.text);
      build/code/pi.o (.text);
      build/code/vi.o (.text);
      build/code/debugmenu.o (.text);
      build/code/joy.o (.text);
      build/code/joy_rumble.o (.text);
      build/code/rmon.o (.text);
      build/libultra/libultra.o (.text);
   }
   __romPos += SIZEOF(.text_code);
   __ramPos += SIZEOF(.text_code);
   
   .c_data __romPos : AT(__romPos) {
      * (.c_data);
   }
   __romPos += SIZEOF(.c_data);
   
   /* (0x70200000, 0x702029BC, 0x701CCA70), // 033590-035F4D [29BD] */
   .text_rarezip 0x70200000 : AT(__romPos) {
      build/rarezip/rarezip.o (.text);
      build/rarezip/rarezip.o (.data);
   }
   __romPos += SIZEOF(.text_rarezip);
   
   /* (0x7F000000, 0x7F0E2D50, 0x7EFCB4D0), // 034B30-117881 [E2D51] */
   .text_tlbcode 0x7F000000 : AT(__romPos) {
      build/game/initgamedata.o (.text);
      build/game/initweaponanigroups.o (.text);
      build/game/initactorpropstuff.o (.text);
      build/game/initnull_0009D0.o (.text);
      build/game/initunk_0009E0.o (.text);
      build/game/initanitable.o (.text);
      build/game/initunk_000B60.o (.text);
      build/game/setguscale.o (.text);
      build/game/initnull_000BC0.o (.text);
      build/game/initimages.o (.text);
      build/game/initintromatrices.o (.text);
      build/game/initmenus.o (.text);
      build/game/initguards.o (.text);
      build/game/deb_loadallmodels.o (.text);
      build/game/initobjects.o (.text);
      build/game/prop.o (.text);
      build/game/objective.o (.text);
      build/game/ejectedcartridges.o (.text);
      build/game/initBondDATA.o (.text);
      build/game/initunk_005450.o (.text);
      build/game/initunk_005520.o (.text);
      build/game/initcameraandthrown.o (.text);
      build/game/inititemslots.o (.text);
      build/game/initBondDATAdefaults.o (.text);
      build/game/initpathtablesomething.o (.text);
      build/game/initpathtablelinks.o (.text);
      build/game/initexplosioncasing.o (.text);
      build/game/initunk_007180.o (.text);
      build/game/initunk_007290.o (.text);
      build/game/initunk_0072B0.o (.text);
      build/game/initmttex.o (.text);
      build/game/initunk_0073B0.o (.text);
      build/game/initunk_007460.o (.text);
      build/game/cleanup_alarms.o (.text);
      build/game/cleanup_objects.o (.text);
      build/game/cleanup_objectives.o (.text);
      build/game/sfxunk_007700.o (.text);
      build/game/playerstats_007770.o (.text);
      build/game/unk_007800.o (.text);
      build/game/unk_007920.o (.text);
      build/game/null_007970.o (.text);
      build/game/unk_007980.o (.text);
      build/game/intro_logos.o (.text);
      build/game/mainmenu.o (.text);
      build/game/blood_animation.o (.text);
      build/game/blood_decrypt.o (.text);
      build/game/eeprom.o (.text);
      build/game/actor.o (.text);
      build/game/actionblock.o (.text);
      build/game/loadobjectmodel.o (.text);
      build/game/objective_status.o (.text);
      build/game/sin.o (.text);
      build/game/unk_057FD0.o (.text);
      build/game/unk_05A9E0.o (.text);
      build/game/convertangleusinginverse.o (.text);
      build/game/unk_05AB70.o (.text);
      build/game/unk_05ACB0.o (.text);
      build/game/unk_05AE00.o (.text);
      build/game/unk_05B1E0.o (.text);
      build/game/truncf.o (.text);
      build/game/unk_05C440.o (.text);
      build/game/bondview.o (.text);
      build/game/objecthandler.o (.text);
      build/game/othermodemicrocode.o (.text);
      build/game/bond.o (.text);
      build/game/unk_08DBB0.o (.text);
      build/game/debugmenu_08FE00.o (.text);
      build/game/unk_091080.o (.text);
      build/game/cheat_buttons_objectrelated.o (.text);
      build/game/unk_092890.o (.text);
      build/game/unk_092E50.o (.text);
      build/game/unk_093880.o (.text);
      build/game/unk_09B600.o (.text);
      build/game/unk_09B740.o (.text);
      build/game/unk_09B7A0.o
      build/game/unk_09C250.o (.text);
      build/game/unk_0A1DA0.o (.text);
      build/game/watch.o (.text);
      build/game/textrelated.o (.text);
      build/game/stan.o (.text);
      build/game/unk_0B3200.o (.text);
      build/game/bg.o (.text);
      build/game/fog.o (.text);
      build/game/lightfixture.o (.text);
      build/game/unk_0BC530.o (.text);
      build/game/ob.o (.text);
      build/game/dyn.o (.text);
      build/game/lvl.o (.text);
      build/game/unk_0C0A70.o (.text);
      build/game/mp_music.o (.text);
      build/game/lvl_text.o (.text);
      build/game/mp_watch.o (.text);
      build/game/radar.o (.text);
      build/game/mp_weapon.o (.text);
      build/game/image.o (.text);
      build/game/image_bank.o (.text);
      build/game/unk_0CC4C0.o (.text);
      build/game/decompress.o (.text);
      build/game/zlib.o (.text);
      build/game/rsp.o (.text);
      build/game/indy_comms.o (.text);
      build/game/indy_0D0180.o (.text);
      build/game/game_debug.o (.text);
      build/game/compiletime.o
      build/game/unk_0D1AC0.o (.text);
      build/game/viewport.o (.text);
      build/game/music_0D2720.o (.text);
      build/game/spectrum.o (.text);
   }
   __romPos += SIZEOF(.text_tlbcode);
   
   .romfiles 0x117880 : AT(__romPos) {
      * (.romfiles);
      * (.ramrom);
      * (.font);
      * (.music);
      * (.musiccompressed);
   }
   __romPos += SIZEOF(.text_tlbcode);

   .ob_seg 0x438660 : AT(__romPos) {
      * (.ob_seg);
   }
   __romPos += SIZEOF(.ob_seg);

   .images : AT(__romPos) {
      * (.images);
   }
   __romPos += SIZEOF(.ob_seg);

   __csegtempPos = 0xC00000;
   __ramPos += 0x80000000;
   .csegment __ramPos : AT(__csegtempPos){
      build/rspboot.o (.text);
      build/gspboot.o (.text);
      build/aspboot.o (.text);
      build/boot.o (.data);
      build/code/init.o (.data);
      build/code/sched.o (.data);
      build/code/osMapTLB.o (.data);
      build/code/tlb_manage.o (.data);
      build/code/tlb_random.o (.data);
      build/code/tlb_resolve.o (.data);
      build/code/audi.o (.data);
      build/code/speed_graph.o (.data);
      build/code/video.o (.data);
      build/code/deb.o (.data);
      build/code/debug_getlastRA.o (.data);
      build/code/ramrom.o (.data);
      build/code/boss.o (.data);
      build/code/music.o (.data);
      build/code/sfx.o (.data);
      build/code/memp.o (.data);
      build/code/mema.o (.data);
      build/code/random.o (.data);
      build/code/token.o (.data);
      build/code/stringhandler.o (.data);
      build/code/sprintf.o (.data);
      build/code/pi.o (.data);
      build/code/vi.o (.data);
      build/code/debugmenu.o (.data);
      build/code/joy.o (.data);
      build/code/joy_rumble.o (.data);
      build/code/rmon.o (.data);
      build/libultra/libultra.o (.data);
      build/boot.o (.rodata);
      build/code/init.o (.rodata);
      build/code/sched.o (.rodata);
      build/code/osMapTLB.o (.rodata);
      build/code/tlb_manage.o (.rodata);
      build/code/tlb_random.o (.rodata);
      build/code/tlb_resolve.o (.rodata);
      build/code/audi.o (.rodata);
      build/code/speed_graph.o (.rodata);
      build/code/video.o (.rodata);
      build/code/deb.o (.rodata);
      build/code/debug_getlastRA.o (.rodata);
      build/code/ramrom.o (.rodata);
      build/code/boss.o (.rodata);
      build/code/music.o (.rodata);
      build/code/sfx.o (.rodata);
      build/code/memp.o (.rodata);
      build/code/mema.o (.rodata);
      build/code/random.o (.rodata);
      build/code/token.o (.rodata);
      build/code/stringhandler.o (.rodata);
      build/code/sprintf.o (.rodata);
      build/code/pi.o (.rodata);
      build/code/vi.o (.rodata);
      build/code/debugmenu.o (.rodata);
      build/code/joy.o (.rodata);
      build/code/joy_rumble.o (.rodata);
      build/code/rmon.o (.rodata);
      build/libultra/libultra.o (.rodata);
      build/game/initgamedata.o (.data);
      build/game/initweaponanigroups.o (.data);
      build/game/initactorpropstuff.o (.data);
      build/game/initnull_0009D0.o (.data);
      build/game/initunk_0009E0.o (.data);
      build/game/initanitable.o (.data);
      build/game/initunk_000B60.o (.data);
      build/game/setguscale.o (.data);
      build/game/initnull_000BC0.o (.data);
      build/game/initimages.o (.data);
      build/game/initintromatrices.o (.data);
      build/game/initmenus.o (.data);
      build/game/initguards.o (.data);
      build/game/deb_loadallmodels.o (.data);
      build/game/initobjects.o (.data);
      build/game/prop.o (.data);
      build/game/objective.o (.data);
      build/game/ejectedcartridges.o (.data);
      build/game/initBondDATA.o (.data);
      build/game/initunk_005450.o (.data);
      build/game/initunk_005520.o (.data);
      build/game/initcameraandthrown.o (.data);
      build/game/inititemslots.o (.data);
      build/game/initBondDATAdefaults.o (.data);
      build/game/initpathtablesomething.o (.data);
      build/game/initpathtablelinks.o (.data);
      build/game/initexplosioncasing.o (.data);
      build/game/initunk_007180.o (.data);
      build/game/initunk_007290.o (.data);
      build/game/initunk_0072B0.o (.data);
      build/game/initmttex.o (.data);
      build/game/initunk_0073B0.o (.data);
      build/game/initunk_007460.o (.data);
      build/game/cleanup_alarms.o (.data);
      build/game/cleanup_objects.o (.data);
      build/game/cleanup_objectives.o (.data);
      build/game/sfxunk_007700.o (.data);
      build/game/playerstats_007770.o (.data);
      build/game/unk_007800.o (.data);
      build/game/unk_007920.o (.data);
      build/game/null_007970.o (.data);
      build/game/unk_007980.o (.data);
      build/game/intro_logos.o (.data);
      build/game/mainmenu.o (.data);
      build/game/blood_animation.o (.data);
      build/game/blood_decrypt.o (.data);
      build/game/eeprom.o (.data);
      build/game/actor.o (.data);
      build/game/actionblock.o (.data);
      build/game/loadobjectmodel.o (.data);
      build/game/objective_status.o (.data);
      build/game/sin.o (.data);
      build/game/unk_057FD0.o (.data);
      build/game/unk_05A9E0.o (.data);
      build/game/convertangleusinginverse.o (.data);
      build/game/unk_05AB70.o (.data);
      build/game/unk_05ACB0.o (.data);
      build/game/unk_05AE00.o (.data);
      build/game/unk_05B1E0.o (.data);
      build/game/truncf.o (.data);
      build/game/unk_05C440.o (.data);
      build/game/bondview.o (.data);
      build/game/objecthandler.o (.data);
      build/game/othermodemicrocode.o (.data);
      build/game/bond.o (.data);
      build/game/unk_08DBB0.o (.data);
      build/game/debugmenu_08FE00.o (.data);
      build/game/unk_091080.o (.data);
      build/game/cheat_buttons_objectrelated.o (.data);
      build/game/unk_092890.o (.data);
      build/game/unk_092E50.o (.data);
      build/game/unk_093880.o (.data);
      build/game/unk_09B600.o (.data);
      build/game/unk_09B740.o (.data);
      build/game/unk_09B7A0.o
      build/game/unk_09C250.o (.data);
      build/game/unk_0A1DA0.o (.data);
      build/game/watch.o (.data);
      build/game/textrelated.o (.data);
      build/game/stan.o (.data);
      build/game/unk_0B3200.o (.data);
      build/game/bg.o (.data);
      build/game/fog.o (.data);
      build/game/lightfixture.o (.data);
      build/game/unk_0BC530.o (.data);
      build/game/ob.o (.data);
      build/game/dyn.o (.data);
      build/game/lvl.o (.data);
      build/game/unk_0C0A70.o (.data);
      build/game/mp_music.o (.data);
      build/game/lvl_text.o (.data);
      build/game/mp_watch.o (.data);
      build/game/radar.o (.data);
      build/game/mp_weapon.o (.data);
      build/game/image.o (.data);
      build/game/image_bank.o (.data);
      build/game/unk_0CC4C0.o (.data);
      build/game/decompress.o (.data);
      build/game/zlib.o (.data);
      build/game/rsp.o (.data);
      build/game/indy_comms.o (.data);
      build/game/indy_0D0180.o (.data);
      build/game/game_debug.o (.data);
      build/game/compiletime.o
      build/game/unk_0D1AC0.o (.data);
      build/game/viewport.o (.data);
      build/game/music_0D2720.o (.data);
      build/game/spectrum.o (.data);
      build/game/initgamedata.o (.rodata);
      build/game/initweaponanigroups.o (.rodata);
      build/game/initactorpropstuff.o (.rodata);
      build/game/initnull_0009D0.o (.rodata);
      build/game/initunk_0009E0.o (.rodata);
      build/game/initanitable.o (.rodata);
      build/game/initunk_000B60.o (.rodata);
      build/game/setguscale.o (.rodata);
      build/game/initnull_000BC0.o (.rodata);
      build/game/initimages.o (.rodata);
      build/game/initintromatrices.o (.rodata);
      build/game/initmenus.o (.rodata);
      build/game/initguards.o (.rodata);
      build/game/deb_loadallmodels.o (.rodata);
      build/game/initobjects.o (.rodata);
      build/game/prop.o (.rodata);
      build/game/objective.o (.rodata);
      build/game/ejectedcartridges.o (.rodata);
      build/game/initBondDATA.o (.rodata);
      build/game/initunk_005450.o (.rodata);
      build/game/initunk_005520.o (.rodata);
      build/game/initcameraandthrown.o (.rodata);
      build/game/inititemslots.o (.rodata);
      build/game/initBondDATAdefaults.o (.rodata);
      build/game/initpathtablesomething.o (.rodata);
      build/game/initpathtablelinks.o (.rodata);
      build/game/initexplosioncasing.o (.rodata);
      build/game/initunk_007180.o (.rodata);
      build/game/initunk_007290.o (.rodata);
      build/game/initunk_0072B0.o (.rodata);
      build/game/initmttex.o (.rodata);
      build/game/initunk_0073B0.o (.rodata);
      build/game/initunk_007460.o (.rodata);
      build/game/cleanup_alarms.o (.rodata);
      build/game/cleanup_objects.o (.rodata);
      build/game/cleanup_objectives.o (.rodata);
      build/game/sfxunk_007700.o (.rodata);
      build/game/playerstats_007770.o (.rodata);
      build/game/unk_007800.o (.rodata);
      build/game/unk_007920.o (.rodata);
      build/game/null_007970.o (.rodata);
      build/game/unk_007980.o (.rodata);
      build/game/intro_logos.o (.rodata);
      build/game/mainmenu.o (.rodata);
      build/game/blood_animation.o (.rodata);
      build/game/blood_decrypt.o (.rodata);
      build/game/eeprom.o (.rodata);
      build/game/actor.o (.rodata);
      build/game/actionblock.o (.rodata);
      build/game/loadobjectmodel.o (.rodata);
      build/game/objective_status.o (.rodata);
      build/game/sin.o (.rodata);
      build/game/unk_057FD0.o (.rodata);
      build/game/unk_05A9E0.o (.rodata);
      build/game/convertangleusinginverse.o (.rodata);
      build/game/unk_05AB70.o (.rodata);
      build/game/unk_05ACB0.o (.rodata);
      build/game/unk_05AE00.o (.rodata);
      build/game/unk_05B1E0.o (.rodata);
      build/game/truncf.o (.rodata);
      build/game/unk_05C440.o (.rodata);
      build/game/bondview.o (.rodata);
      build/game/objecthandler.o (.rodata);
      build/game/othermodemicrocode.o (.rodata);
      build/game/bond.o (.rodata);
      build/game/unk_08DBB0.o (.rodata);
      build/game/debugmenu_08FE00.o (.rodata);
      build/game/unk_091080.o (.rodata);
      build/game/cheat_buttons_objectrelated.o (.rodata);
      build/game/unk_092890.o (.rodata);
      build/game/unk_092E50.o (.rodata);
      build/game/unk_093880.o (.rodata);
      build/game/unk_09B600.o (.rodata);
      build/game/unk_09B740.o (.rodata);
      build/game/unk_09B7A0.o
      build/game/unk_09C250.o (.rodata);
      build/game/unk_0A1DA0.o (.rodata);
      build/game/watch.o (.rodata);
      build/game/textrelated.o (.rodata);
      build/game/stan.o (.rodata);
      build/game/unk_0B3200.o (.rodata);
      build/game/bg.o (.rodata);
      build/game/fog.o (.rodata);
      build/game/lightfixture.o (.rodata);
      build/game/unk_0BC530.o (.rodata);
      build/game/ob.o (.rodata);
      build/game/dyn.o (.rodata);
      build/game/lvl.o (.rodata);
      build/game/unk_0C0A70.o (.rodata);
      build/game/mp_music.o (.rodata);
      build/game/lvl_text.o (.rodata);
      build/game/mp_watch.o (.rodata);
      build/game/radar.o (.rodata);
      build/game/mp_weapon.o (.rodata);
      build/game/image.o (.rodata);
      build/game/image_bank.o (.rodata);
      build/game/unk_0CC4C0.o (.rodata);
      build/game/decompress.o (.rodata);
      build/game/zlib.o (.rodata);
      build/game/rsp.o (.rodata);
      build/game/indy_comms.o (.rodata);
      build/game/indy_0D0180.o (.rodata);
      build/game/game_debug.o (.rodata);
      build/game/compiletime.o
      build/game/unk_0D1AC0.o (.rodata);
      build/game/viewport.o (.rodata);
      build/game/music_0D2720.o (.rodata);
      build/game/spectrum.o (.rodata);
      build/gspboot.o (.data);
      build/aspboot.o (.data);
   }
   __ramPos += SIZEOF(.csegment);
   __csegtempPos += SIZEOF(.csegment);
   .bss __ramPos : AT(__csegtempPos){
      build/boot.o (.bss);
      build/code/init.o (.bss);
      build/code/sched.o (.bss);
      build/code/osMapTLB.o (.bss);
      build/code/tlb_manage.o (.bss);
      build/code/tlb_random.o (.bss);
      build/code/tlb_resolve.o (.bss);
      build/code/audi.o (.bss);
      build/code/speed_graph.o (.bss);
      build/code/video.o (.bss);
      build/code/deb.o (.bss);
      build/code/debug_getlastRA.o (.bss);
      build/code/ramrom.o (.bss);
      build/code/boss.o (.bss);
      build/code/music.o (.bss);
      build/code/sfx.o (.bss);
      build/code/memp.o (.bss);
      build/code/mema.o (.bss);
      build/code/random.o (.bss);
      build/code/token.o (.bss);
      build/code/stringhandler.o (.bss);
      build/code/sprintf.o (.bss);
      build/code/pi.o (.bss);
      build/code/vi.o (.bss);
      build/code/debugmenu.o (.bss);
      build/code/joy.o (.bss);
      build/code/joy_rumble.o (.bss);
      build/code/rmon.o (.bss);
      build/libultra/libultra.o (.bss);
      build/game/initgamedata.o (.bss);
      build/game/initweaponanigroups.o (.bss);
      build/game/initactorpropstuff.o (.bss);
      build/game/initnull_0009D0.o (.bss);
      build/game/initunk_0009E0.o (.bss);
      build/game/initanitable.o (.bss);
      build/game/initunk_000B60.o (.bss);
      build/game/setguscale.o (.bss);
      build/game/initnull_000BC0.o (.bss);
      build/game/initimages.o (.bss);
      build/game/initintromatrices.o (.bss);
      build/game/initmenus.o (.bss);
      build/game/initguards.o (.bss);
      build/game/deb_loadallmodels.o (.bss);
      build/game/initobjects.o (.bss);
      build/game/prop.o (.bss);
      build/game/objective.o (.bss);
      build/game/ejectedcartridges.o (.bss);
      build/game/initBondDATA.o (.bss);
      build/game/initunk_005450.o (.bss);
      build/game/initunk_005520.o (.bss);
      build/game/initcameraandthrown.o (.bss);
      build/game/inititemslots.o (.bss);
      build/game/initBondDATAdefaults.o (.bss);
      build/game/initpathtablesomething.o (.bss);
      build/game/initpathtablelinks.o (.bss);
      build/game/initexplosioncasing.o (.bss);
      build/game/initunk_007180.o (.bss);
      build/game/initunk_007290.o (.bss);
      build/game/initunk_0072B0.o (.bss);
      build/game/initmttex.o (.bss);
      build/game/initunk_0073B0.o (.bss);
      build/game/initunk_007460.o (.bss);
      build/game/cleanup_alarms.o (.bss);
      build/game/cleanup_objects.o (.bss);
      build/game/cleanup_objectives.o (.bss);
      build/game/sfxunk_007700.o (.bss);
      build/game/playerstats_007770.o (.bss);
      build/game/unk_007800.o (.bss);
      build/game/unk_007920.o (.bss);
      build/game/null_007970.o (.bss);
      build/game/unk_007980.o (.bss);
      build/game/intro_logos.o (.bss);
      build/game/mainmenu.o (.bss);
      build/game/blood_animation.o (.bss);
      build/game/blood_decrypt.o (.bss);
      build/game/eeprom.o (.bss);
      build/game/actor.o (.bss);
      build/game/actionblock.o (.bss);
      build/game/loadobjectmodel.o (.bss);
      build/game/objective_status.o (.bss);
      build/game/sin.o (.bss);
      build/game/unk_057FD0.o (.bss);
      build/game/unk_05A9E0.o (.bss);
      build/game/convertangleusinginverse.o (.bss);
      build/game/unk_05AB70.o (.bss);
      build/game/unk_05ACB0.o (.bss);
      build/game/unk_05AE00.o (.bss);
      build/game/unk_05B1E0.o (.bss);
      build/game/truncf.o (.bss);
      build/game/unk_05C440.o (.bss);
      build/game/bondview.o (.bss);
      build/game/objecthandler.o (.bss);
      build/game/othermodemicrocode.o (.bss);
      build/game/bond.o (.bss);
      build/game/unk_08DBB0.o (.bss);
      build/game/debugmenu_08FE00.o (.bss);
      build/game/unk_091080.o (.bss);
      build/game/cheat_buttons_objectrelated.o (.bss);
      build/game/unk_092890.o (.bss);
      build/game/unk_092E50.o (.bss);
      build/game/unk_093880.o (.bss);
      build/game/unk_09B600.o (.bss);
      build/game/unk_09B740.o (.bss);
      build/game/unk_09B7A0.o
      build/game/unk_09C250.o (.bss);
      build/game/unk_0A1DA0.o (.bss);
      build/game/watch.o (.bss);
      build/game/textrelated.o (.bss);
      build/game/stan.o (.bss);
      build/game/unk_0B3200.o (.bss);
      build/game/bg.o (.bss);
      build/game/fog.o (.bss);
      build/game/lightfixture.o (.bss);
      build/game/unk_0BC530.o (.bss);
      build/game/ob.o (.bss);
      build/game/dyn.o (.bss);
      build/game/lvl.o (.bss);
      build/game/unk_0C0A70.o (.bss);
      build/game/mp_music.o (.bss);
      build/game/lvl_text.o (.bss);
      build/game/mp_watch.o (.bss);
      build/game/radar.o (.bss);
      build/game/mp_weapon.o (.bss);
      build/game/image.o (.bss);
      build/game/image_bank.o (.bss);
      build/game/unk_0CC4C0.o (.bss);
      build/game/decompress.o (.bss);
      build/game/zlib.o (.bss);
      build/game/rsp.o (.bss);
      build/game/indy_comms.o (.bss);
      build/game/indy_0D0180.o (.bss);
      build/game/game_debug.o (.bss);
      build/game/compiletime.o
      build/game/unk_0D1AC0.o (.bss);
      build/game/viewport.o (.bss);
      build/game/music_0D2720.o (.bss);
      build/game/spectrum.o (.bss);
   }   
   __ramPos += SIZEOF(.csegment);
   __csegtempPos += SIZEOF(.csegment);

   .room_model_buffer 0x8008E360 : {
      * (.room_model_buffer);
   }

   .BONDdata1 0x800D2060 : {
      * (.BONDdata1);
   }

   .BONDdata2 0x800D4AE0 : {
      * (.BONDdata2);
   }

   .DL_buffer 0x800D7560 : {
      * (.DL_buffer);
   }

   .image_buffer_start 0x80122560 : {
      * (.image_buffer_start);
   }

   .ASCII_font 0x80176DE0 : {
      * (.ASCII_font);
   }

   .nintlogo_gelogo_walletbond_objdata 0x8017C7D0 : {
      * (.nintlogo_gelogo_walletbond_objdata);
   }

   .main_image_bank 0x801C5000 : {
      * (.main_image_bank);
   }

   .rom_0x2AE280_0x2AE840 0x801C6400 : {
      * (.rom_0x2AE280_0x2AE840);
   }

   .rom_0x2A4D50_0x2BF2D0 0x801C6BD0 : {
      * (.rom_0x2A4D50_0x2BF2D0);
   }

   .BG_File 0x801CCB50 : {
      * (.BG_File);
   }

   .clipping_file 0x801CE0E0 : {
      * (.clipping_file);
   }



   .framebuffer_1 0x803B5000 : {
      * (.framebuffer_1);
   }

   .framebuffer_2 0x803DA800 : {
      * (.framebuffer_2);
   }

   /*move em to end, out of the way*/
   /DISCARD/ : {
      * (.MIPS.abiflags);
      * (.musicdecompressed);
   }
}
