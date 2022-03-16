#include <iostream>

int firstTask(int a);
int secondTask(int a, int b);

int main()
{
    int a, b;
    std::cout << "Enter a b:";
    std::cin >> a >> b;
    std::cout << std::endl;
    firstTask(a);
    secondTask(a, b);
}

int firstTask(int a) {
    int sum = a, a1 = a;
    // 0-2 1-4 2-8 3-16
    for (int i = 0; i < 4; i++)
    {
        a *= a;
        if (i == 2) {
            sum += a;
        }
    }
    sum += a;

    __asm {
        mov EAX, a1;
        mul EAX;
        mul EAX;
        mul EAX;
        mov EBX, EAX;
        mul EAX;
        add EAX, EBX;
        mov ECX, a1;
        add EAX, ECX;
        mov a1, EAX;
    }
    std::cout << "c++: " << sum << " assembler: " << a1 << std::endl;
}

int secondTask(int a, int b) {
    //50 = a*x + b*y
    int o[50] = {0};
    int count;
    __asm {
        mov EAX, a;//EAX = a

        cmp EAX, 49;
        jge skip;
        cmp b, 49;
        jge skip;

        mov ECX, 1;
        mov EBX, 0;
    lstrt:
        mov EDX, 0;
        mul ECX;//EAX = a*x
        cmp EAX, 50;
        jge lnd;

        mov EDX, 50;
        sub EDX, EAX;//50-a*x

        mov EAX, EDX;
        mov EDX, 0;
        div b;//EAX = (50-a*x)/b

        cmp EDX, 0;
        jne notint;
        push EAX;
        inc EBX;
    notint:
        mov EAX, a;
        inc ECX;
        
        jmp lstrt;
    lnd:
        mov ECX, EBX;
        cmp ECX, 0;
        je skip;
        mov EAX, 0;
    lstack:
        pop EBX;
        mov o[EAX], EBX;
        add EAX, 4;
        loop lstack;
        mov count, EAX;
    skip:
        mov count, 0;
    }
    count /= 4;
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << o[i] << " ";
    }

}