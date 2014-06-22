// GCC for SUNPLUS u'nSP version 1.0.23
// Command: D:\PROGRA~1\Sunplus\UNSPID~1.2D\toolchain\cc1.exe C:\Users\geeknimo\AppData\Local\Temp\ccGocaaa.i -fkeep-inline-functions -quiet -dumpbase main.c -mglobal-var-iram -O2 -Wall -o .\Release/main.asm
	.external __sn_func_ptr_sec

// gcc2_compiled.:

.public _gActivated
.iram
_gActivated:
	.dw 0
.public _gTriggerRespond
.iram
_gTriggerRespond:
	.dw 9
	.dw 10
	.dw 9
.public _gComm2Respond
.iram
_gComm2Respond:
	.dw 11
	.dw 12
	.dw 13
.public _PlayFlag
.iram
_PlayFlag:
	.dw 0
.code
.public _PlayRespond2
_PlayRespond2:	.proc
	// total=2, vars=2
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=[BP+5]	// QImode move
	[BP]=R1	// QImode move
	CALL _BSR_StopRecognizer	// call without return value
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _SACM_A2000_Initial	// call with return value
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	CALL _SACM_A2000_Play	// call with return value
	SP = SP + 4	//SP
	PC=L3	// jump
L5:
	CALL _SACM_A2000_ServiceLoop	// call with return value
	CALL _ClearWatchDog	// call without return value
L3:
	CALL _SACM_A2000_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L5	//QImode NE
	[BP+1]=R2	// QImode move
	CALL _SACM_A2000_Stop	// call with return value
	R2=[BP+1]	// QImode move
	[SP--]=R2	// QImode move
	CALL _BSR_InitRecognizer	// call with return value
	CALL _BSR_EnableCPUIndicator	// call without return value
	SP = SP + 1	//SP

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of PlayRespond2

.code
.public _PlayRespond
_PlayRespond:	.proc
	// total=2, vars=2
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	SP-=2
	BP=SP+1

	R1=[BP+5]	// QImode move
	[BP]=R1	// QImode move
	CALL _BSR_StopRecognizer	// call without return value
	R1=1	// QImode move
	[SP--]=R1	// QImode move
	CALL _SACM_S480_Initial	// call with return value
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	[SP--]=R1	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	CALL _SACM_S480_Play	// call with return value
	SP = SP + 4	//SP
	PC=L9	// jump
L11:
	CALL _SACM_S480_ServiceLoop	// call with return value
	CALL _ClearWatchDog	// call without return value
L9:
	CALL _SACM_S480_Status	// call with return value
	R2=R1&1
	CMP R2,0	// QImode test
	NSJNZ L11	//QImode NE
	[BP+1]=R2	// QImode move
	CALL _SACM_S480_Stop	// call with return value
	R2=[BP+1]	// QImode move
	[SP--]=R2	// QImode move
	CALL _BSR_InitRecognizer	// call with return value
	CALL _BSR_EnableCPUIndicator	// call without return value
	SP = SP + 1	//SP

	SP+=2
	POP BP from [SP]
	RETF
	.endp	// end of PlayRespond

.code
.public _TrainWord
_TrainWord:	.proc
	// total=1, vars=1
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	SP-=1
	BP=SP+1

	R1=BP+4
	R2=[BP+4]	// QImode move
	[BP]=R2	// QImode move
	R1 = [++R1]
	[SP--]=R1	// QImode move
	PC=L32	// jump
L18:
	R1=R1+6
	CMP R1,5	// QImode compare
	NSJA L17	//QImode GTU
	R1=R1+L28
	PC=[R1]	// tablejump
.text
L28:
	.dw L35
	.dw L24
	.dw L35
	.dw L22
	.dw L21
	.dw L20
.code
L20:
	R1=5	// QImode move
	PC=L33	// jump
L21:
	R2=4	// QImode move
	[SP--]=R2	// QImode move
L32:
	CALL _PlayRespond	// call without return value
	SP = SP + 1	//SP
	PC=L17	// jump
L22:
	R1=14	// QImode move
L33:
	[SP--]=R1	// QImode move
	CALL _PlayRespond	// call without return value
	R1=(-1)	// QImode move
	SP = SP + 1	//SP
	PC=L14	// jump
L24:
	R2=[BP]	// QImode move
	CMP R2,256	// QImode compare
	NSJNZ L25	//QImode NE
	R1=6	// QImode move
	[SP--]=R1	// QImode move
	PC=L34	// jump
L25:
	R2=7	// QImode move
	[SP--]=R2	// QImode move
L34:
	CALL _PlayRespond	// call without return value
	SP = SP + 1	//SP
L35:
	R1=(-1)	// QImode move
	PC=L14	// jump
L17:
	R1=0	// QImode move
	[SP--]=R1	// QImode move
	R2=[BP]	// QImode move
	[SP--]=R2	// QImode move
	CALL _BSR_Train	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L18	//QImode NE
L14:

	SP+=1
	POP BP from [SP]
	RETF
	.endp	// end of TrainWord

.code
.public _main
_main:	.proc
	// total=3, vars=3
	// frame_pointer_needed: 1
.code
	PUSH BP to [SP]
	SP-=3
	BP=SP+1

	R1=0	// QImode move
	[BP]=R1	// QImode move
	[BP+1]=R1	// QImode move
	[SP--]=R1	// QImode move
	CALL _BSR_DeleteSDGroup	// call with return value
	R2=[BP]	// QImode move
	[SP--]=R2	// QImode move
	CALL _PlayRespond	// call without return value
	SP = SP + 2	//SP
L42:
	R3=1	// QImode move
	[SP--]=R3	// QImode move
	R1=256	// QImode move
	[SP--]=R1	// QImode move
	CALL _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L42	//QImode NE
L45:
	R2=2	// QImode move
	[SP--]=R2	// QImode move
	R3=257	// QImode move
	[SP--]=R3	// QImode move
	CALL _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L45	//QImode NE
L48:
	R1=3	// QImode move
	[SP--]=R1	// QImode move
	R2=258	// QImode move
	[SP--]=R2	// QImode move
	CALL _TrainWord	// call with return value
	SP = SP + 2	//SP
	CMP R1,0	// QImode test
	NSJNZ L48	//QImode NE
	[SP--]=R1	// QImode move
	CALL _BSR_InitRecognizer	// call with return value
	CALL _BSR_EnableCPUIndicator	// call without return value
	R3=8	// QImode move
	[SP--]=R3	// QImode move
	CALL _PlayRespond	// call without return value
	SP = SP + 2	//SP
L51:
	R1=[BP+1]	// QImode move
	R1=R1+1
	[BP+1]=R1	// QImode move
	CMP R1,2	// QImode compare
	NSJNG L52	//QImode LE
	R2=0	// QImode move
	[BP+1]=R2	// QImode move
L52:
	CALL _BSR_GetResult	// call with return value
	CMP R1,0	// QImode test
	NSJNG L53	//QImode LE
	R2=[_gActivated]	// QImode move
	NSJZ L54	//QImode EQ
	R3=0	// QImode move
	[BP]=R3	// QImode move
	CMP R1,257	// QImode compare
	NSJZ L57	//QImode EQ
	NSJG L61	//QImode GT
	CMP R1,256	// QImode compare
	NSJZ L56	//QImode EQ
	PC=L51	// jump
L61:
	CMP R1,258	// QImode compare
	NSJZ L58	//QImode EQ
	PC=L51	// jump
L56:
	R1=[BP+1]	// QImode move
	R2=_gTriggerRespond	// QImode move
	R1 = R1 + R2	//addqi3
	R1=[R1]
	[SP--]=R1	// QImode move
	CALL _PlayRespond	// call without return value
	SP = SP + 1	//SP
	PC=L51	// jump
L57:
	R3=1	// QImode move
	[_PlayFlag]=R3	// QImode move
	R1=[BP]	// QImode move
	[SP--]=R1	// QImode move
	CALL _PlayRespond2	// call without return value
	R2=[BP]	// QImode move
	[_PlayFlag]=R2	// QImode move
	[_gActivated]=R2	// QImode move
	SP = SP + 1	//SP
	PC=L51	// jump
L58:
	R3=[BP+1]	// QImode move
	R1=R3+_gComm2Respond
	R1=[R1]
	[SP--]=R1	// QImode move
	CALL _PlayRespond	// call without return value
	R1=[BP]	// QImode move
	[_gActivated]=R1	// QImode move
	SP = SP + 1	//SP
	PC=L51	// jump
L54:
	CMP R1,256	// QImode compare
	NSJNZ L51	//QImode NE
	R1=[BP+1]	// QImode move
	R3=_gTriggerRespond	// QImode move
	R1 = R1 + R3	//addqi3
	R1=[R1]
	[SP--]=R1	// QImode move
	[BP+2]=R2	// QImode move
	CALL _PlayRespond	// call without return value
	R1=1	// QImode move
	[_gActivated]=R1	// QImode move
	R2=[BP+2]	// QImode move
	[BP]=R2	// QImode move
	SP = SP + R1	//SP
	PC=L51	// jump
L53:
	R1=[_gActivated]	// QImode move
	NSJZ L51	//QImode EQ
	R2=[BP]	// QImode move
	R2=R2+1
	[BP]=R2	// QImode move
	CMP R2,450	// QImode compare
	NSJNG L51	//QImode LE
	R3=5	// QImode move
	[SP--]=R3	// QImode move
	CALL _PlayRespond	// call without return value
	R1=0	// QImode move
	[_gActivated]=R1	// QImode move
	[BP]=R1	// QImode move
	SP = SP + 1	//SP
	PC=L51	// jump

	SP+=3
	POP BP from [SP]
	RETF
	.endp	// end of main

.external _BSR_GetResult
.external _BSR_DeleteSDGroup
.external _BSR_Train
.external _SACM_S480_Stop
.external _SACM_S480_ServiceLoop
.external _SACM_S480_Status
.external _SACM_S480_Play
.external _SACM_S480_Initial
.external _BSR_EnableCPUIndicator
.external _BSR_InitRecognizer
.external _SACM_A2000_Stop
.external _ClearWatchDog
.external _SACM_A2000_ServiceLoop
.external _SACM_A2000_Status
.external _SACM_A2000_Play
.external _SACM_A2000_Initial
.external _BSR_StopRecognizer
	.end
