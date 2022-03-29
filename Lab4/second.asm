.model flat, C 
.const
	twelwe real4 12.0;
.code
	second_task PROC, precesion: DWORD
		mov ECX, precesion;
		FLDZ;{sum}
		FLD1;{1, sum}
		FLD1;{1, k, sum}
		FLD1;{k, 1, k, sum}

	_start:
		FMUL st(0), st(0);{k^2, (-1)^(k + 1), k, sum}
		FMUL st(0), st(1);{(-1)^(k + 1)*k^2, (-1)^(k + 1), k, sum}
		FLD1;{1, (-1)^(k + 1)*k^2, (-1)^(k + 1), k, sum}
		FDIV st(0), st(1);{1/((-1)^(k + 1)*k^2), k^2, (-1)^(k + 1), k, sum}
		FADDP st(4), st(0);{(-1)^(k + 1)*k^2, (-1)^(k + 1), k, sum}

		FADDP st(0), st(0);{(-1)^(k + 1), k, sum}
		FCHS;{(-1)^(k + 2), k, sum}

		FXCH st(1);{k, (-1)^(k + 2), sum}
		FLD1;{1, k, (-1)^(k + 2), sum}
		FADDP st(1), st(0);{k + 1, (-1)^(k + 2), sum}
		FXCH st(1);{(-1)^(k + 2), k + 1, sum}}

		FLDZ;{0, (-1)^(k + 2), k, sum}
		FADD st(0), st(2);{k, (-1)^(k + 2), k, sum}

		loopd _start;

		FADDP st(0), st(0);
		FADDP st(0), st(0);
		FADDP st(0), st(0);
		FMUL twelwe;
		FSQRT;
		ret;
	second_task ENDP
end