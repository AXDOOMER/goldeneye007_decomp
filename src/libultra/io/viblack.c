#include "libultra_internal.h"

extern OSViContext *__osViNext;

// TODO: name magic constants

/**
 * When Nintendo 64 powers on, the boot code sets the timing to NTSC, PAL,
 * or MPAL and blanks out the video. The call to osCreateViManager initializes
 * the video to LAN1 (in either NTSC, PAL, or MPAL mode) and also blanks
 * out the video. The first time video is enabled is when osViSetMode is
 * called. To keep the screen blank until after the first use of
 * osViSwapBuffer, call osViBlack(TRUE) immediately after the osViSetMode
 * call. Then call osViBlack(FALSE) right before the first call to osViSwapBuffer.
 * 
 * Based on the active flag setting, which can be TRUE (enabled, screen
 * black) or FALSE (disabled), the osViBlack function can black out the
 * screen and still generate vertical retrace signals. You can only use
 * osViBlack when the YScale factor for the video mode is 1.0. Using it
 * for YScale factors that are not 1.0 creates the potential for the video
 * interface to malfunction and enter a state that cannot be exited without
 * resetting the system.
 * 
 * source: /Functions Reference Manual/os/osViBlack.html
 */
void osViBlack(u8 active) {
    register u32 int_disabled = __osDisableInt();
    if (active) {
        __osViNext->unk00 |= 0x20;
    } else {
        __osViNext->unk00 &= ~0x20;
    }
    __osRestoreInt(int_disabled);
}
