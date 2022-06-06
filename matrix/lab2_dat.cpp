// lab2_dat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"matrix_class.h"
#include"Functions.h"
int main()
{
	matrix a = getSize();
	a.getMatrix();
	a.print();
	double constant{};
	std::cout << "Enter constant :a*";
	std::cin >> constant;
	matrix b = a * constant;
	std::cout << "Matrix b = a*" << constant << std::endl;
	b.print();
	std::cout << "Transposition:" << std::endl;
	b.trans().print();
	std::cout << "Inversion:" << std::endl;
	b.inv().print();
	b.saveCsv();
	b.saveTxt();
	return 0;
}


