#pragma once
#ifndef HEADER_H
#define HEADER_H
#include"matrix_class.h"

matrix& getSize()
{
	std::ifstream input("C:/Users/datth/Desktop/12.txt");
	std::string fileIn{};
	std::getline(input, fileIn, '\0');
	int R = 0;//number of rows
	int N = 0;//number of elements
	int C = 0;//number of cols
	int i = 0;//index of char in file
	while (i < fileIn.length())
	{
		if (fileIn[i] == '\n')
		{
			R++;
		}
		if ((fileIn[i]!=' '&&fileIn[i]!='\n')&&(fileIn[i+1]=='\n' ||fileIn[i+1] ==' '))
		{
			N++;
		}
		i++;
	}
	C = N / R;	
	matrix* temp = new matrix(R, C);
	input.close();
	return *temp;
}
matrix& operator*(matrix& m, double v)
{
	matrix* temp = new matrix(m.rows, m.cols);
	for (int i = 0; i < temp->rows; i++)
	{
		for (int j = 0; j < temp->cols; j++)
		{
			temp->p[i][j] = m.p[i][j] * v;
		}
	}
	return *temp;
}
#endif