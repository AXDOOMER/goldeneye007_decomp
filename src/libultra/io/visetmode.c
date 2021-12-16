#include "include/PR/os.h"
#include "ultra64.h"
#include "viint.h"

extern __OSViContext *__osViNext;

/**
 * Currently, there is a global VI mode table (osViModeTable) that contains register settings for
 * all 42 modes. You can use the osViSetMode function to register one of these modes with the VI
 * to be used at the next vertical retrace. This function simply overwrites all the VI registers
 * with data from the location pointed to by the mode argument, which is a pointer into
 * osViModeTable. All previous settings (such as XY scaling and gamma correction) are reset. For
 * example, to register the NTSC, low resolution, anti-aliased, non-interlaced, 16-bit mode with
 * the VI, use this code:
 * 
 *      osViSetMode(osViModeTable[OS_VI_NTSC_LAN1]);
 * 
 * For storage efficiency, the global VI mode table is divided into 42 separate mode structures
 * with each structure globally defined in a separate source file. These structures are
 * externally declared in <os.h>. To gain access to the equivalent mode mentioned above, use
 * this code:
 * 
 *      osViSetMode(osViModeNtscLan1);
 * 
 * When Nintendo 64 powers on, the boot code sets the timing to NTSC, PAL, or MPAL and blanks
 * out the video. The call to osCreateViManager initializes the video to LAN1 (in either NTSC,
 * PAL, or MPAL mode) and also blanks out the video. The first time video is enabled is when
 * osViSetMode is called. To keep the screen blank until after the first use of osViSwapBuffer,
 * call osViBlack(TRUE) immediately after the osViSetMode call. Then call osViBlack(FALSE) right
 * before the first call to osViSwapBuffer.
 * 
 * Notes
 * The VI manager must be started at the beginning of the program so that vertical retrace
 * interrupts can be serviced as quickly as possible. Note that osViSetMode resets all current
 * settings such as X-Y scaling and special features such as gamma to the default values
 * defined in the global mode table.
 * 
 * The video back-end filter can only execute an anti-aliasing filter or a dither filter, but
 * not both simultaneously. This is especially visible on "billboard" cutouts in texture edge
 * mode during magnification in the region of the cutout where alpha goes from 1 to 0. In this
 * region, the dither pattern is visible because the back-end filter executes an anti-alias
 * filter (due to partial coverage) and turns off the dither filter.
 * 
 * This problem also occurs on anti-aliased silhouette edges of polygons, but it is not
 * obvious due to the small width of the partially covered region. 
 * 
 * source: /Functions Reference Manual/os/osViSetMode.html
 */
void osViSetMode(OSViMode *mode) {
    register u32 int_disabled = __osDisableInt();
    __osViNext->modep = mode;
    __osViNext->state = 1;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    __osRestoreInt(int_disabled);
}
