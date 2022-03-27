#include <iostream>
#include <iomanip>
#include <bitset>

extern "C" double first_task(double, double, double);

double task1(double a, double b, double d);
double task2();
double task3();
double task4();

int main()
{

    double a = 1, b = 1, c = -24.375;

    std::cout << "Enter a,b,c for first task: ";
    std::cin >> a >> b >> c;
    std::cout << std::endl;
    std::cout << "Task1: " << std::fixed << std::setprecision(6) << task1(a, b, c) << std::endl <<
        "Task2: " << task2() << std::endl <<
        "Task3: " << task3() << std::endl <<
        "Task4: " << task4() << std::endl;

}

double task1(double a, double b, double d) {
    // x3+ax2+bx+c=0  (-10, 10)
    double answer;
    answer = first_task(a, b, d);
    return answer;
}

double task2() {
    return 0;
}

double task3() {
    return 0;
}

double task4() {
    return 0;
}