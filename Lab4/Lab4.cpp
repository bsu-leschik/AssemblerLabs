#include <iostream>
#include <iomanip>
#include <bitset>

extern "C" double first_task(double, double, double);
extern "C" double second_task(int);
extern "C" double third_task(int);
extern "C" double fifth_task(int);

double task1(double a, double b, double d);
double task2(int precesion);
double task3(int precesion);
double task4(int precesion);

int main()
{

    double a = 1, b = 1, c = -24.375;
    int precesion = 5;

    std::cout << "Enter a,b,c for first task: ";
    std::cin >> a >> b >> c;
    std::cout << std::endl;
    std::cout << "Enter precison for second and third tasks: ";
    std::cin >> precesion;
    std::cout << std::endl;
    std::cout << "Task1: " << std::fixed << std::setprecision(10) << task1(a, b, c) << std::endl <<
        "Task2: " << task2(precesion) << std::endl <<
        "Task3: " << task3(precesion) << std::endl <<
        "Task4: " << task4(precesion) << std::endl;

}

double task1(double a, double b, double d) {
    // x3+ax2+bx+c=0  (-10, 10)
    double answer;
    answer = first_task(a, b, d);
    return answer;
}

double task2(int precesion) {
    double answer;
    answer = second_task(precesion);
    return answer;
}

double task3(int precesion) {
    return 0;
}

double task4(int precesion) {
    return 0;
}