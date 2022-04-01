.model flat, C 
.const
	ten real8 10.0;
	two DWORD 2;
.code
	fifth_task PROC, power: DWORD

		xor EDX, EDX;
		mov ECX, 0;
		xor EBX, EBX;
		mov EAX, power;
		FLD1;

	_start:
		xor EDX, EDX;
		div two;
		cmp EDX, 0;
		je _even;
		FLD ten;
		FMUL;
		mov EAX, power;
		dec EAX;
		jmp _start;
	_even:
		inc ECX;
		cmp EAX, 1;
		je _pow;
		jg _start;

	_zero:
		FLD1;
		FMUL;
		jmp _out;

		_pow:
		FLD ten;

		_strtloop:
			FMUL st(0), st(0);
		loop _strtloop;
		FMUL;
	_out:
		ret;
	fifth_task ENDP
end