#include <iostream>
#include <vector>

int firstTask(int a);
int secondTask(int a, int b);
void thirdTask();
void fourthTask(int a, int b);

int main()
{
    int a, b;
    std::cout << "Enter a b:";
    std::cin >> a >> b;
    std::cout << std::endl;
    firstTask(a);
    secondTask(a, b);
    thirdTask();
    fourthTask(int a, int b);
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
    return a;
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
    }
    count /= 4;
    std::cout << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << o[i] << " ";
    }
    int i = 1;

    std::vector<int> answers;
    for (; i < 50; i++)
    {
        if (50 <= a * i) {
            break;
        }
        int t = 50 - a * i;
        double temp1 =(double) t / b;
        int temp2 = (50 - a * i) / b;
        if ((double)(temp1 - temp2) == 0)
        {
            answers.push_back((50 - a * i) / b);
        }
    }
    std::cout << std::endl;
    std::cout << answers.size() << std::endl;
    for(int num : answers)
    {
        std::cout << num << " ";
    }
    return a;
}

void thirdTask() {
    int outAsm;
    unsigned int fibonachi[50];
    int amount;
    fibonachi[0] = 0;
    fibonachi[1] = 1;
    fibonachi[2] = 1;
    __asm {
        mov EAX, 1;
        mov EBX, 1;
        mov ECX, 12;
        mov EDX, 0;
    strt:
        mov EDX, EAX;
        add EAX, EBX;
        jo nd;
        mov EBX, EDX;
        mov fibonachi[ECX], EAX;
        add ECX, 4;
        jmp strt;
    nd:
        mov amount, ECX;
    }
    amount /= 4;
    std::cout << amount << std::endl;
    for (int i = 0; i < amount; i++)
    {
        std::cout << fibonachi[i] << " ";
    }
    int a = 1, b = 0, c = 0;
    std::cout << std::endl;
    std::cout << "c++: ";
    std::cout << b << " " << a << " ";
    for (int i = 0; i < 47; i++)
    {
        c = a;
        a += b;
        std::cout << a << " ";
        b = c;

    }
}

void fourthTask(int a, int b) {
    // a/b

}