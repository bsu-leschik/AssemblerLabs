.model flat, C 
.code
	third_task PROC, precesion: DWORD, x: real8
		mov ECX, precesion;
		mov EAX, 1;for internal loop calculating (x + 1)^k

		FLDZ;{sum}
		FLD1;{k , sum}
		FLD1;{1^(k+1), k, sum}
		FLD1;{k, 1^(k+1), k, sum}
		
	_start:
		FLD x;{x, k, 1^(k+1), k, sum}
		FLD1;{1, x, k, 1^(k+1), k, sum}
		FSUBP st(1), st(0);{x-1, k, 1^(k+1), k, sum}
	_powx:
		FMUL st(0), st(0);
		dec EAX;
		cmp EAX, 0;
		jne _powx;{(x-1)^k, k, 1^(k+1), k, sum}
		
		FDIV st(0), st(1);{((x-1)^k)/k, k, 1^(k+1), k, sum}
		FMUL st(0), st(2);{1^(k+1)*((x-1)^k)/k, k, 1^(k+1), k, sum}
		FADDP st(4), st(0);{k, 1^(k+1), k, sum}

		FLD1;{1, k, 1^(k+1), k, sum}
		FADDP st(1), st(0);{k + 1, 1^(k+1), k, sum}

		FXCH st(1);{1^(k+1), k + 1, k, sum}
		FCHS;{1^(k+2), k + 1, k, sum}
		FXCH st(1);{k + 1, 1^(k+2), k, sum}
		loopd _start;

		FXCH st(3);
		ret;
	third_task ENDP
end
