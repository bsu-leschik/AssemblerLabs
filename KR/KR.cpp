#include <iostream>
#include <bitset>

int main()
{
    const int length = 4;
    int l = length;
    int lInt = length * 4;
    int arr[length];

    arr[0] = 0b00010000000000010000000000000000;
    arr[1] = 0b00100000000000001000000000000000;
    arr[2] = 0b01000000000000000000001000000000;
    arr[3] = 0b10000000000000000000000010000000;

    __asm {
        mov ECX, 0;
        

    _start:
        xor EAX, EAX;
        xor EBX, EBX;

            mov EAX, [arr + ECX];
            mov EBX, [arr + ECX];
        
            SHL EAX, 19;
            SHR EAX, 26;
        
            SHL EBX, 5;
            SHR EBX, 20;
            SHL EBX, 6;

            or EBX, EAX;

            mov [arr + ECX], EBX;

            add ECX, 4;

            cmp ECX, lInt;
        jl _start;

        
        xor EAX, EAX;
        xor EBX, EBX;
        xor ECX, ECX;
        xor EDX, EDX;

        mov ECX, l;
        add EDX, 4;
        

    _sortStart:
        xor EDX, EDX;
    _loop:
            sub EDX, 4;

            mov EAX, [arr + EDX];
            add EDX, 4;
            mov EBX, [arr + EDX];

            cmp EAX, EBX;
            jle _check;

            sub EDX, 4;
            mov[arr + EDX], EBX;
            add EDX, 4;
            mov[arr + EDX], EAX;

        _check:
            add EDX, 4;
            cmp EDX, lInt;
            jl _loop;
    loop _sortStart;
    }
    for (int i = 0; i < length; i++){
        std::cout << std::bitset<32>(arr[i]) << std::endl;
    }
    
}
