.model flat, C 
.const
    two real4 2.0;
.data
    upper real4 10.0
    lower real4 -10.0
    fLower real8 0.0;
    fUpper real8 0.0;
.code
    first_task PROC, a:REAL8, b:REAL8, d:REAL8
        FLD upper; {u}
        FMUL b; {b* u}
        FLD upper; {u, b* u}
        FMUL upper; {u ^ 2, b* u}
        FMUL a; {a* u ^ 2, b* u}
        FLD upper; {u, a* u ^ 2, b* u}
        FMUL upper; {u ^ 2, a* u ^ 2, b* u}
        FMUL upper; {u ^ 3, a* u ^ 2, b* u}
        FADD d; {u ^ 3 + d, a* u ^ 2, b* u}
        FADDP st(1), st(0); {u ^ 3 + d + a * u ^ 2, b* u}
        FADDP st(1), st(0); {u ^ 3 + d + a * u ^ 2 + b * u}
        FSTP fUpper; fUpper = u ^ 3 + d + a * u ^ 2 + b * u, {}

        FLD lower; {l}
        FMUL b; {b* l}
        FLD lower; {l, b* l}
        FMUL lower; {l ^ 2, b* l}
        FMUL a; {a* l ^ 2, b* l}
        FLD lower; {l, a* l ^ 2, b* l}
        FMUL lower; {l ^ 2, a* l ^ 2, b* l}
        FMUL lower; {l ^ 3, a* l ^ 2, b* l}
        FADD d; {l ^ 3 + d, a* l ^ 2, b* l}
        FADDP st(1), st(0); {l ^ 3 + d + a * l ^ 2, b* l}
        FADDP st(1), st(0); {l ^ 3 + d + a * l ^ 2 + b * l}
        FSTP fLower; flower = l ^ 3 + d + a * l ^ 2 + b * l, {}

        FLD fLower;
        FLD fUpper;
        FMUL;
        

        mov EAX, 0;
        FTST;
        FSTSW AX;
        TEST AX, 4500h;
        jz _out;

        FADDP st(0), st(0);
        FLD upper; {u}
        FLD lower; {l, u}

    _start:
        FADD; {l + u}
        FDIV two; {(l + u) / 2}

        FLD two; {2, (l + u) / 2}
        FLD upper; {2, 2, (l + u) / 2}
        FXCH st(2); {(l + u) / 2, 2, 2}
        FST st(1); {(l + u) / 2, (l + u) / 2, 2}
        FST st(2); {(l + u) / 2, (l + u) / 2, (l + u) / 2}

        FMUL st(1), st(0); {(l + u) / 2, ((l + u) / 2) ^ 2, (l + u) / 2}
        FMUL st(2), st(0); {(l + u) / 2, ((l + u) / 2) ^ 2, ((l + u) / 2) ^ 2}
        FMUL st(2), st(0); {(l + u) / 2, ((l + u) / 2) ^ 2, ((l + u) / 2) ^ 3}

        FMUL b; {b* (l + u) / 2, ((l + u) / 2) ^ 2, ((l + u) / 2) ^ 3}
        FXCH st(1); {((l + u) / 2) ^ 2, b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FMUL a; {a* ((l + u) / 2) ^ 2, b* (l + u) / 2, ((l + u) / 2) ^ 3}

        FADD d; {a* ((l + u) / 2) ^ 2 + d, b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FADD st(0), st(1); {a* ((l + u) / 2) ^ 2 + d + b * (l + u) / 2, b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FADD st(0), st(2); {a* ((l + u) / 2) ^ 2 + d + b * (l + u) / 2 + ((l + u) / 2) ^ 3, b* (l + u) / 2, ((l + u) / 2) ^ 3}

        mov EAX, 0;
        FTST;
        FSTSW AX;
        TEST AX, 4000h;
        jnz _out;

        FMUL fLower; {fL* (a * ((l + u) / 2) ^ 2 + d + b * (l + u) / 2 + ((l + u) / 2) ^ 3), b* (l + u) / 2, ((l + u) / 2) ^ 3}
        mov EAX, 0;
        FTST;
        FSTSW AX;
        TEST AX, 0100h;
        jnz _neg;

        FDIV fLower;
        FST fLower;

        FADDP st(0), st(0); {b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FADDP st(0), st(0); {b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FADDP st(0), st(0); {b* (l + u) / 2, ((l + u) / 2) ^ 3}

        FLD upper; {u}
        FLD lower; {l, u}
        FADD upper; {l + u, u}
        FDIV two; {(l + u) / 2, u}
        FST lower; lower = (l + u) / 2
            jmp _start;

    _neg:
        FDIV fLower;
        FST fUpper;

        FADDP st(0), st(0); {b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FADDP st(0), st(0); {b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FADDP st(0), st(0); {b* (l + u) / 2, ((l + u) / 2) ^ 3}

        FLD lower; {l}
        FLD upper; {u, l}
        FADD lower; {u + l, l}
        FDIV two; {(u + l) / 2, l}
        FST upper;
        jmp _start;

    _out:
        FADDP st(0), st(0); {b* (l + u) / 2, ((l + u) / 2) ^ 3}
        FXCH st(1); {((l + u) / 2) ^ 3, b* (l + u) / 2}
        FADDP st(0), st(0); {b* (l + u) / 2}
        FDIV b; {(l + u) / 2}
        
        ret;
    first_task ENDP
end