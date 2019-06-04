#!/bin/bash

OBJDUMP="${MIPS_BINUTILS_PREFIX}objdump -D -bbinary -mmips -EB"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom.z64 > baserom.dump
$OBJDUMP $OPTIONS ge007.u.z64 > ge007.u.dump
diff baserom.dump ge007.u.dump
