// GCC for SUNPLUS u'nSP version 1.0.23
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.2D\toolchain\cc1.exe C:\Users\geeknimo\AppData\Local\Temp\cc8scaaa.i -fkeep-inline-functions -quiet -dumpbase libgloss.c -mglobal-var-iram -O2 -Wall -o .\Release/libgloss.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

// GCC inline ASM start
	.code
.public _printf_hook
_printf_hook: .proc
  retf
  .endp

// GCC inline ASM end
.code
.public _printf_init
_printf_init:	.proc
	// total=0, vars=0
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	BP=SP+1


	POP BP from [SP]
	RETF
	.endp	// end of printf_init

.code
.public _printf_end
_printf_end:	.proc
	// total=0, vars=0
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	BP=SP+1


	POP BP from [SP]
	RETF
	.endp	// end of printf_end

.code
.public _putchar
_putchar:	.proc
	// total=0, vars=0
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	BP=SP+1

	R1=[BP+3]	// QImode move

	POP BP from [SP]
	RETF
	.endp	// end of putchar

.code
.public __malloc_lock
__malloc_lock:	.proc
	// total=0, vars=0
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	BP=SP+1


	POP BP from [SP]
	RETF
	.endp	// end of _malloc_lock

.code
.public __malloc_unlock
__malloc_unlock:	.proc
	// total=0, vars=0
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	BP=SP+1


	POP BP from [SP]
	RETF
	.endp	// end of _malloc_unlock

	.end
