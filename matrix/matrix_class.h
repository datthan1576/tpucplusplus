#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include<string>
#include<iostream>
#include<math.h>
#include<fstream>
#include<iomanip>
#include<cstdlib>
class matrix
{
public:
	matrix();
	matrix(int r, int c);
	~matrix();
	void getMatrix();
	void setMatrix();
	matrix& trans();
	matrix& minor(int,int);
	double det();
	double detLU();
    matrix& inv();
	void print();
	void saveTxt() ;
	void saveCsv() ;
	friend matrix& operator*(matrix&, double);	
private:
	int cols;
	int rows;
	double** p;
	std::string fileName;
};

#endif 
