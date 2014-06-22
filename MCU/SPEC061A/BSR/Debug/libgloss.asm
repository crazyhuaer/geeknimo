// GCC for SUNPLUS u'nSP version 1.0.23
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.2D\toolchain\cc1.exe C:\Users\geeknimo\AppData\Local\Temp\ccgZcaaa.i -fkeep-inline-functions -quiet -dumpbase libgloss.c -mglobal-var-iram -gstabs -Wall -o .\Debug/libgloss.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.debug
	.dw '.stabs "F:/Code/geeknimo/MCU/SPEC061A/BSR/",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.debug
	.dw '.stabs "F:/Code/geeknimo/MCU/SPEC061A/BSR/libgloss.c",0x64,0,3,',0,0,offset Ltext0,seg Ltext0,0x0d,0x0a
.code
.code
Ltext0:
.debug
	.dw '.stabs "int:t1=r1;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "char:t2=r2;0;127;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long int:t3=r3;-2147483648;2147483647;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "unsigned int:t4=r4;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long unsigned int:t5=r5;0;4294967295;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long long int:t6=r6;-2147483648;2147483647;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long long unsigned int:t7=r7;0;4294967295;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "short int:t8=r8;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "short unsigned int:t9=r9;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "signed char:t10=r10;-32768;32767;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "unsigned char:t11=r11;0;65535;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "float:t12=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "double:t13=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "long double:t14=r1;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex int:t15=s2real:1,0,16;imag:1,16,16;;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex float:t16=r16;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex double:t17=r17;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "complex long double:t18=r18;2;0;",128,0,0,0',0x0d,0x0a
.CODE
.debug
	.dw '.stabs "void:t19=19",128,0,0,0',0x0d,0x0a
.CODE
// GCC inline ASM start
	.code
.public _SemiPrintf
.public _printf_hook
_printf_hook: .proc
  nop
_SemiPrintf:
  retf
  .endp

// GCC inline ASM end
.code
.debug
	.dw '.stabs "printf_init:F19",36,0,0,',0,0,offset _printf_init,seg _printf_init,0x0d,0x0a
.CODE
.public _printf_init
_printf_init:	.proc
.debug
	.dw '.stabn 0x44,0,27,',0,0
	.dd LM1-_printf_init
	.dw 0x0d,0x0a
.code
LM1:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,28,',0,0
	.dd LM2-_printf_init
	.dw 0x0d,0x0a
.code
LM2:
	PC=L2	// jump
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM3-_printf_init
	.dw 0x0d,0x0a
.code
LM3:
.debug
	.dw '.stabn 0x44,0,29,',0,0
	.dd LM4-_printf_init
	.dw 0x0d,0x0a
.code
LM4:
L2:

	POP BP from [SP]
	RETF
	.endp	// end of printf_init

.debug
	.dw '.stabs "x:p1",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME1-_printf_init
	.dw 0x0d,0x0a
.code
LME1:
.code
.debug
	.dw '.stabs "printf_end:F19",36,0,0,',0,0,offset _printf_end,seg _printf_end,0x0d,0x0a
.CODE
.public _printf_end
_printf_end:	.proc
.debug
	.dw '.stabn 0x44,0,31,',0,0
	.dd LM5-_printf_end
	.dw 0x0d,0x0a
.code
LM5:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,32,',0,0
	.dd LM6-_printf_end
	.dw 0x0d,0x0a
.code
LM6:
	PC=L3	// jump
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM7-_printf_end
	.dw 0x0d,0x0a
.code
LM7:
.debug
	.dw '.stabn 0x44,0,33,',0,0
	.dd LM8-_printf_end
	.dw 0x0d,0x0a
.code
LM8:
L3:

	POP BP from [SP]
	RETF
	.endp	// end of printf_end

.debug
	.dw '.stabf ',0,0
	.dd LME2-_printf_end
	.dw 0x0d,0x0a
.code
LME2:
.code
.debug
	.dw '.stabs "putchar:F1",36,0,0,',0,0,offset _putchar,seg _putchar,0x0d,0x0a
.CODE
.public _putchar
_putchar:	.proc
.debug
	.dw '.stabn 0x44,0,38,',0,0
	.dd LM9-_putchar
	.dw 0x0d,0x0a
.code
LM9:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R2=BP+3
.debug
	.dw '.stabn 0x44,0,39,',0,0
	.dd LM10-_putchar
	.dw 0x0d,0x0a
.code
LM10:
	R1=R2	// QImode move
	R3=[R1]	// QImode move
	R1=R3	// QImode move
	PC=L4	// jump
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM11-_putchar
	.dw 0x0d,0x0a
.code
LM11:
.debug
	.dw '.stabn 0x44,0,40,',0,0
	.dd LM12-_putchar
	.dw 0x0d,0x0a
.code
LM12:
L4:

	POP BP from [SP]
	RETF
	.endp	// end of putchar

.debug
	.dw '.stabs "c:p1",160,0,0,3',0x0d,0x0a
.CODE
.debug
	.dw '.stabf ',0,0
	.dd LME3-_putchar
	.dw 0x0d,0x0a
.code
LME3:
.code
.debug
	.dw '.stabs "_malloc_lock:F19",36,0,0,',0,0,offset __malloc_lock,seg __malloc_lock,0x0d,0x0a
.CODE
.public __malloc_lock
__malloc_lock:	.proc
.debug
	.dw '.stabn 0x44,0,45,',0,0
	.dd LM13-__malloc_lock
	.dw 0x0d,0x0a
.code
LM13:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,46,',0,0
	.dd LM14-__malloc_lock
	.dw 0x0d,0x0a
.code
LM14:
	PC=L5	// jump
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM15-__malloc_lock
	.dw 0x0d,0x0a
.code
LM15:
.debug
	.dw '.stabn 0x44,0,47,',0,0
	.dd LM16-__malloc_lock
	.dw 0x0d,0x0a
.code
LM16:
L5:

	POP BP from [SP]
	RETF
	.endp	// end of _malloc_lock

.debug
	.dw '.stabf ',0,0
	.dd LME4-__malloc_lock
	.dw 0x0d,0x0a
.code
LME4:
.code
.debug
	.dw '.stabs "_malloc_unlock:F19",36,0,0,',0,0,offset __malloc_unlock,seg __malloc_unlock,0x0d,0x0a
.CODE
.public __malloc_unlock
__malloc_unlock:	.proc
.debug
	.dw '.stabn 0x44,0,49,',0,0
	.dd LM17-__malloc_unlock
	.dw 0x0d,0x0a
.code
LM17:
	// total=0, vars=0
	// frame_pointer_needed: 1
.debug
	.dw '.stabn 0xa6,0,0,0',0x0d, 0x0a
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=BP+3
.debug
	.dw '.stabn 0x44,0,50,',0,0
	.dd LM18-__malloc_unlock
	.dw 0x0d,0x0a
.code
LM18:
	PC=L6	// jump
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM19-__malloc_unlock
	.dw 0x0d,0x0a
.code
LM19:
.debug
	.dw '.stabn 0x44,0,51,',0,0
	.dd LM20-__malloc_unlock
	.dw 0x0d,0x0a
.code
LM20:
L6:

	POP BP from [SP]
	RETF
	.endp	// end of _malloc_unlock

.debug
	.dw '.stabf ',0,0
	.dd LME5-__malloc_unlock
	.dw 0x0d,0x0a
.code
LME5:
	.end
