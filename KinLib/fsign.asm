.686P
.XMM
.MODEL FLAT, C
.DATA
	neg1 dq 0bff0000000000000r
	zero dq 00000000000000000r
	pos1 dq 03ff0000000000000r

.CODE 
; FSIGN 
; Determines the sign of a floating point number
; Written in assembly because this is a very simple method and it should be made as fast as possible by manually writing SIMD instructions and ensuring frame pointer omission
; Prefer CDECL convention because that speeds up code *within* the called function.
; Arguments: 
;	[esp+4] - value whose sign to determine
; Returns:
;	-1.0, 0.0 or 1.0 corresponding to the sign of the argument. 
fsign PROC
		movsd xmm0, qword ptr [esp+4]
		ucomisd xmm0, qword ptr zero
		lahf
		test ah, 044h
		jp non_zero
		fld qword ptr [esp+4]
		jmp quit_fsign
	non_zero:
		movsd xmm0, qword ptr [esp+4]
		comisd xmm0, qword ptr zero
		jbe ret_neg1
		fld1
		jmp quit_fsign
	ret_neg1:
		fld qword ptr neg1
	quit_fsign:
		add esp, 4
		jmp dword ptr [esp-4]
fsign ENDP
END