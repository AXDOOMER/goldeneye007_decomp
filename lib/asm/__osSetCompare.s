.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

# Sets the compare register so that when the compare register will equal the count register, an interrupt will be generated
glabel __osSetCompare
	mtc0  $a0, $11             # Move $0a to cp0's compare register: https://en.wikichip.org/wiki/mips/coprocessor_0
	jr    $ra                  # return control to the caller: https://chortle.ccsu.edu/AssemblyTutorial/Chapter-26/ass26_6.html
	 nop   

	nop   

