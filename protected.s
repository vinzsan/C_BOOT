	.file	"protected.c"
	.text
.Ltext0:
	.file 0 "/home/vinz/Code/initframs/OS_TEST" "protected.c"
#APP
	.global pmode_entry

#NO_APP
	.globl	pmode_entry
	.type	pmode_entry, @function
pmode_entry:
.LFB0:
	.file 1 "protected.c"
	.loc 1 5 23 view -0
	.cfi_startproc
	.loc 1 6 5 view .LVU1
#APP
# 6 "protected.c" 1
	mov $0x10,%ax
	mov %ax,%ds
	mov %ax,%es
	mov %ax,%fs
	mov %ax,%gs
	mov %ax,%ss
	mov $0x90000,%esp
	call kernel_entry

# 0 "" 2
#NO_APP
.L2:
	.loc 1 17 5 discriminator 1 view .LVU2
	.loc 1 17 13 discriminator 1 view .LVU3
#APP
# 17 "protected.c" 1
	hlt
# 0 "" 2
	.loc 1 17 10 discriminator 1 view .LVU4
#NO_APP
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	pmode_entry, .-pmode_entry
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x35
	.value	0x5
	.byte	0x1
	.byte	0x4
	.long	.Ldebug_abbrev0
	.uleb128 0x1
	.long	.LASF2
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF3
	.byte	0x1
	.byte	0x5
	.byte	0x6
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF3:
	.string	"pmode_entry"
.LASF2:
	.string	"GNU C17 12.2.0 -m32 -mtune=generic -march=i686 -g -Os -fno-pic -ffreestanding -fasynchronous-unwind-tables"
	.section	.debug_line_str,"MS",@progbits,1
.LASF0:
	.string	"protected.c"
.LASF1:
	.string	"/home/vinz/Code/initframs/OS_TEST"
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
