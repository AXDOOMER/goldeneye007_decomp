.rsp

.create CODE_FILE, 0x04001000

    j     boot_04001064
     addi  at, zero, 0x0fc0
boot_04001008:
    lw    v0, 0x0010(at)
    addi  v1, zero, 0x0f7f
    addi  a3, zero, 0x1080
    mtc0  a3, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN
boot_04001020:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, boot_04001020
     nop
    jal   boot_0400103c
     nop
    jr    a3
     mtc0  zero, SP_SEMAPHORE
boot_0400103c:
    mfc0  t0, SP_STATUS
    andi  t0, t0, 0x0080
    bne   t0, zero, boot_04001050
     nop
    jr    ra
boot_04001050:
     mtc0  zero, SP_SEMAPHORE
    ori   t0, zero, 0x5200
    mtc0  t0, SP_STATUS
    break
    nop
boot_04001064:
    lw    v0, 0x0004(at)
    andi  v0, v0, 0x0002
    beq   v0, zero, boot_0400108c
     nop
    jal   boot_0400103c
     nop
    mfc0  v0, DPC_STATUS
    andi  v0, v0, 0x0100
    bgtz  v0, boot_0400103c
     nop
boot_0400108c:
    lw    v0, 0x0018(at)
    lw    v1, 0x001c(at)
    addi  v1, v1, -0x0001
boot_04001098:
    mfc0  s8, SP_DMA_FULL
    bne   s8, zero, boot_04001098
     nop
    mtc0  zero, SP_MEM_ADDR
    mtc0  v0, SP_DRAM_ADDR
    mtc0  v1, SP_RD_LEN
boot_040010b0:
    mfc0  a0, SP_DMA_BUSY
    bne   a0, zero, boot_040010b0
     nop
    jal   boot_0400103c
     nop
    j     boot_04001008
     nop
    nop

.close // CODE_FILE
