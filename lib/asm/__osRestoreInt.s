.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

# There are more notes in "__osDisableInt.s". See this file for better understanding.


# Restore all interrupts
glabel __osRestoreInt
	mfc0  $t0, $12             # move cp0 status reg $12 to $t0
	or    $t0, $t0, $a0        # $t0 = $t0 | $a0
	mtc0  $t0, $12             # move $t0 to cp0 status reg $12
	nop   
	nop   
	jr    $ra                  # return to caller
	 nop   

	nop   

