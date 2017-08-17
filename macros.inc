.macro get_value name, value
.global get_\name
get_\name:
 lui   $v0, %hi(\value)
 jr    $ra
 addiu $v0, $v0, %lo(\value)
.endm

.macro jump_via_reg location, register=$a3
.global jump_\location
jump_\location:
 lui   \register, %hi(\location)
 addiu \register, \register, %lo(\location)
 jr    \register
 nop
.endm


.macro debug_handler_table_entry sp, string
.word \sp
.word \string
.endm

.macro file_entry index, string, file
.word \index
.word \string
.word \file
.endm

 # enum	image_format, mappedto_2
.set rgba, 0
.set yuv, 1
.set ci, 2
.set ia, 3
.set i, 4

 # ---------------------------------------------------------------------------

 # enum	image_bitdepth,	mappedto_3
.set D_4BIT, 0
.set D_8BIT, 1
.set D_16BIT, 2
.set D_32BIT, 3

 # ---------------------------------------------------------------------------

 # enum	cm_flags, mappedto_4
.set clamp, 1
.set mirror, 2

.macro texture_entry index, width, height, level, format, depth, flagsS, flagsT, pad
.word \index
.byte \width
.byte \height
.byte \level
.byte \format
.byte \depth
.byte \flagsS
.byte \flagsT
.byte \pad
.endm
