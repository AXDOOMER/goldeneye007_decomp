#include <ultra64.h>
#include "chrai.h"
#include "explosions.h"
#include <fr.h>

void cleanupExplosions(void)
{
    s32 i;
  
    numExplosionEntries = 0;
    viShake(0.0);

    if (ptr_explosion_buf != NULL)
    {
        for (i = 0; i<EXPLOSION_BUFFER_LEN; i++)
        {
            if (ptr_explosion_buf[i].prop != NULL)
            {
                sub_GAME_7F03A538(ptr_explosion_buf[i].prop);
                propDisable(ptr_explosion_buf[i].prop);
                propFree(ptr_explosion_buf[i].prop);
                ptr_explosion_buf[i].prop = NULL;
            }
        }
    }

  
    if (ptr_smoke_buf != NULL)
    {
        for (i = 0; i<SMOKE_BUFFER_LEN; i++)
        {
            if (ptr_smoke_buf[i].prop != NULL)
            {
                sub_GAME_7F03A538(ptr_smoke_buf[i].prop);
                propDisable(ptr_smoke_buf[i].prop);
                propFree(ptr_smoke_buf[i].prop);
                ptr_smoke_buf[i].prop = NULL;
            }
        }
    }
}
