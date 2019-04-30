.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

# The status register, cp0 register 12, is used both to configure interrupts and get more information about the exception that occurred.
# http://www.it.uu.se/education/course/homepage/os/vt18/module-1/mips-coprocessor-0/

# Disable all interrupts
glabel __osDisableInt
  mfc0  $t0, $12               # move data from cp0 register $12 (status register) to general purpose register $t0
  and   $t1, $t0, -2           # $t1 = $t0 & ...11111110 so this means the first bit (rightmost) enables or disables interrupts
  mtc0  $t1, $12               # cp0 $12 (status register) = $1
  andi  $v0, $t0, 1            # $v0 = $t0 & ...00000001 (it puts the value of the first bit into the result register $v0)
  nop   
  jr    $ra                    # return to caller
   nop   

