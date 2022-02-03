#include <ultra64.h>
#include "chrai.h"
#include "cleanup_alarms.h"


void cleanupAlarms(void) {
    stop_alarm();
    check_deactivate_gas_sound();
}


