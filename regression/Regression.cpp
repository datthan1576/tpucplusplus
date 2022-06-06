

#include <iostream>
#include<cmath>

double cost_function(double x1[9], double x2[9], double y[9], double w[3])
{
    double cost{ 0 };
    for (int i = 0; i < 9; i++)
    {
        cost += pow(w[0] + w[1] * x1[i] + w[2] * x2[i] - y[i], 2);
    }
    return cost;
}

void gradient_descent(double x1[9], double x2[9], double y[9], double w[3], double alpha)
{
    double error1{ 0 };
    for (int j = 0; j < 9; j++)
    {
        error1 += (w[0] + w[1] * x1[j] + w[2] * x2[j] - y[j]) * x1[j];
    }
    double error2{ 0 };
    for (int j = 0; j < 9; j++)
    {
        error2 += (w[0] + w[1] * x1[j] + w[2] * x2[j] - y[j]) * x2[j];
    }
    double error{ 0 };
    for (int j = 0; j < 9; j++)
    {
        error += (w[0] + w[1] * x1[j] + w[2] * x2[j] - y[j]);
    }
    w[0] -= (alpha / 9) * error;
    w[2] -= (alpha / 9) * error2;
    w[1] -= (alpha / 9) * error1;
}

int main()
{
    // y = c + b.x + a.x^2 = w0.x0 + w1.x1 + w2.x2  (x0=1)
    double x0 = 1;
    double x1[9] = { 0,1,2,3,4,5,6,7,8 };        // x1 = x
    double x2[9] = { 0,1,4,9,16,25,36,49,64 };   //  x2 = x^2
    double y[9] = { 6.45,4.06,2.53,2.05,2.48,3.97,6.57,9.94,14.45 };  // y
    double w[3]{};
    for (int i = 0; i < 20000; i++)
    {
        std::cout << "w0 = " << w[0] << " w1 = " << w[1] << " w2= " << w[2] << std::endl;
        std::cout << "Cost function ( " << i << " th ) :";
        std::cout << cost_function(x1, x2, y, w) << std::endl;
        gradient_descent(x1, x2, y, w, 0.002);
        std::cout << std::endl;
    }
    return 0;
}



