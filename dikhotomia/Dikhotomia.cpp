
#include <iostream>
#include<math.h>

struct Index
{
    double a3;
    double a2;
    double a1;
    double a0;
};//структура коэффициентов функции
struct Interval
{
    double a;
    double b;
};
Index setIndex()
{
    Index tempID ;
    std::cout << "Function: y=a3*x^3+a2*x^2+a1*x+a0" << std::endl;
    std::cout << "Enter a3,a2,a1,a0 :"<<std::endl;
    std::cin >> tempID.a3 >> tempID.a2 >> tempID.a1 >> tempID.a0;
    return tempID;
}
Interval setInterval()
{
    Interval tempIn;
    std::cout << "\tInterval [a,b]" << std::endl;
    std::cout << "Enter a:";
    std::cin>> tempIn.a;
    std::cout << "Enter b:";
    std::cin >> tempIn.b;
    return tempIn;
}
double f(double x,struct Index ind)
{
    return (ind.a3*x * x * x +ind.a2 * x * x + ind.a1*x+ind.a0);
}//функции y
void swap(double &a,double& c,double &b)
{
    a = c;
    c = (a + b)/2;
}
void findRoot(double &a,double &b,Index &ind)
{
    double c{ (a + b) / 2 };
    static int iterations{};
    while (abs(a - b) > 0.001)
    {
        if (f(a, ind) * f(c, ind) > 0)
        {
            swap(a, c, b);
        }
        else
        {
            swap(b, c, a);
        }
        iterations++;
    } 
   
    if (abs(f(c, ind)) >0.1 )
    {
        std::cout << "No roots!!";
    }
    else
    {
        std::cout << "Number of iterations =" << iterations << std::endl;
        std::cout << "Root =" << c;
    }
}
int main()
{  
    Index index = setIndex();
    Interval interval = setInterval();  
    findRoot(interval.a,interval.b,index);
    return 0;
}


