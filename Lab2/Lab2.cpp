#include <iostream>
#include<cmath>

int first_ass(int num);
int first_cpp(int num);

int second_ass(int num);
int second_cpp(int num);

int third_ass(int num);
int third_cpp(int num);

int ones(int num);



int main()
{
    std::cout << "Hello World!\n";
    //1010
    int num;
    std::cin >> num;
    std::cout << first_ass(num) << " = " << first_cpp(num) << std::endl;
    std::cout << second_ass(num) << " = " << second_cpp(num) << std::endl;
    std::cout << third_ass(num) << " = " << third_cpp(num) << std::endl;


}


int first_ass(int num) {
    // (x^5 + 2 * (x^2 – 4) + x) / x^3 = (x^5 + 2*x^2 - 8 + x) / x^3
    int output;
    int two = 2;
    __asm{
        mov EAX, num;
        mov EBX, num;
        mul EAX;
        mov ECX, EAX;//ECX = x^2
        mul EAX;
        mul EBX;
        mov EBX, EAX;//EBX = x^5

        mov EAX, ECX;
        mul two;// EAX = 2*x^2

        add EBX, EAX;// EBX = x^5 + 2*x^2
        sub EBX, 8; //EBX = x^5 + 2*x^2 - 8
        mov ECX, num;
        add EBX, ECX;// EBX = x^5 + 2*x^2 - 8 + x

        mov EAX, num;
        mul EAX;
        mul ECX;
        mov ECX, EAX;

        mov EAX, EBX;
        div ECX;

        mov output, EAX;
    }
    return output;
}

int first_cpp(int num) {
    return (num*num*num*num*num + 2 * num*num - 8 + num) / (num*num*num);
}

int ones(int num) {
    __int32 ten = 0b1010;
    __int32 output;
    std::cin >> num;
    __asm {

        mov EAX, num
        mov ECX, 10;

        div EBX;
        cmp EDX, 0;

        mul ECX;
        inc EAX;
        mov output, EAX;
    }
    return output;
}

int second_ass(int num) {
    //(2 * x – 1) * (2 * x + 1) * (x + 3) / (2 * x) = (4x^2 - 1)(x + 3)/2x = (4x^3 + 12x^2 - x + 3)/2x
    int twelve(12), four(4), three(3), two(2), output;
    __asm {
        mov EAX, num;
        mul EAX;
        mov ECX, EAX;//ECX = x^2
        mul num;
        mul four;
        mov EBX, EAX;//EBX = 4x^3

        mov EAX, ECX;
        mul twelve;//EAX = 12x^2

        mov ECX, num;//ECX = x
        
        add EAX, EBX;// 4x^3 + 12x^2
        sub EAX, ECX;// 4x^3 + 12x^2 - x
        add EAX, three;// 4x^3 + 12x^2 - x + 3

        div ECX;//( 4x^3 + 12x^2 - x + 3)/2x^3
        mov EDX, 0;
        div two;//( 4x^3 + 12x^2 - x + 3)/2


        mov output, EAX;
    }
    return output;
}

int second_cpp(int num) {
    return (4*num*num*num + 12*num*num - num + 3)/2/num;
}

int third_ass(int num) {
    // (4 * x – 1) * (4 * x + 1) / 4 = (16x^2 - 1) / 4 = 4x^2 - 1/4
    int output;
    __asm {
        mov EAX, num;
        mov EBX, 4;
        mul EAX;// EAX = x^2
        mul EBX;// EAX = 4x^2
        mul EBX;// EAX = 16x^2


        mov ECX, EAX;// ECX = 4x^2
        mov EAX, 1;// EAX = 1
        sub ECX, EAX;// ECX = 4x^2 - 1/4
        mov EAX, ECX;
        div EBX;

        mov output, EAX;
    }
    return output;
}

int third_cpp(int num) {
    return num*num*4 - 0.25;
}

