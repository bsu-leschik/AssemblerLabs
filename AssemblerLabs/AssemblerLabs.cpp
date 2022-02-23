// AssemblerLabs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<bitset>

int main()
{
    std::cout << "Enter your numbers between 1 and 281 474  976 710 755\n";
    __int64  a(0), b(0);
    std::cin >> a >> b;

    unsigned __int16 a3(0), a2(0), a1(0);  
    a1 = a;
    a2 = a >> 16;
    a3 = a >> 32;

    unsigned __int16 b3(0), b2(0), b1(0); 
    b1 = b;
    b2 = b >> 16;
    b3 = b >> 32;
    unsigned __int16 c3(0), c2(0), c1(0);
    __asm {

        mov AX, a1
        adc AX, b1
        mov c1, AX

        mov AX, a2
        adc AX, b2
        mov c2, AX

        mov AX, a3
        add AX, b3
        mov c3, AX
    }

    __int64 c;
    c = c3;
    c <<= 16;
    c += c2;
    c <<= 16;
    c += c1;

    std::cout << std::bitset<16>(a3) << "  " << std::bitset<16>(a2) << "  " << std::bitset<16>(a1) << std::endl;
    std::cout << std::bitset<16>(b3) << "  " << std::bitset<16>(b2) << "  " << std::bitset<16>(b1) << std::endl;
    std::cout << std::bitset<16>(c3) << "  " << std::bitset<16>(c2) << "  " << std::bitset<16>(c1) << std::endl;

    std::cout << std::endl;

    std::cout << a3 << "  " << a2 << "  " << a1 << std::endl;
    std::cout << b3 << "  " << b2 << "  " << b1 << std::endl;
    std::cout << c3 << "  " << c2 << "  " << c1 << std::endl;

    std::cout<< "Final answer: 0b" << std::bitset<64>(c) << " = " << c << std::endl;


}