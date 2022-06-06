#include"matrix_class.h"

//Constructor
matrix::matrix() :cols{ 0 }, rows{ 0 }, p{ nullptr } {}
//Destructor
matrix::~matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete p[i];
	}
	delete[] p;
	cols = 0; rows = 0;
}
//Constructor with parameters
matrix::matrix(int r, int c)
{
	rows = r; 
	cols = c;
	p = new double* [r];
	for (int j = 0; j < r; j++)
	{
		p[j] = new double[c];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			p[i][j] = 0;
	}
}
//Set matrix
void matrix::setMatrix()
{
	std::cout << "Enter rows:";
	std::cin >> rows;
	std::cout << "Enter cols:";
	std::cin >> cols;
	p = new double* [rows];
	for (int j = 0; j < rows; j++)
	{
		p[j] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << "Enter p[" << i << "][" << j << "] :";
			std::cin>>p[i][j];
		}
	}
}
//Function returns reference to transposition matrix of matrix
matrix& matrix::trans()
{
	matrix *temp=new matrix(cols, rows);
	for(int i=0;i<temp->rows;i++)
		for (int j = 0; j < temp->cols; j++)
		{
			temp->p[i][j] = p[j][i];
		}
	return *temp;
}
//Function returns determinant of matrix
double matrix::det()
{
	double d{ 0 };
	if (rows != cols)
	{
		std::cout << "\tCan not find determinant because it's not a square matrix!\n";
		exit(0);
	}
	else if (rows == 1)
	{
		return p[0][0];
	}
	else if (rows == 2)
	{
		return p[0][0] * p[1][1] - p[0][1] * p[1][0];
	}
	else
		for (int j = 0; j < cols; j++)
		{
			d += pow(-1, 0 + j) * p[0][j] * (this->minor(0, j)).det();
		}
	return d;
}
//Function returns reference to minor of square matrix
matrix& matrix::minor(int I, int J)
{
	matrix* temp_minor = new matrix(rows - 1, cols - 1);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == I || j == J)
				continue;
			else
				temp_minor->p[i-(i>I)][j-(j>J)] = p[i][j];
		}
	}
	return *temp_minor;
}
//Print matrix
void matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout<<std::setprecision(4)<<std::setw(9) <<this->p[i][j]<<";";
		}
		std::cout << std::endl;
	}
}
//Function returns inverse matrix of matrix
matrix& matrix::inv()
{
	if (rows != cols)
	{
		std::cout << "\tCan not find inversion because it's not a square matrix!\n";
		exit(0);
	}
	else
	{
		double d = this->detLU();
		if (d == 0)
		{
			std::cout << "Determinant =0,inversion doesn't exist!\n" << std::endl;
			exit(0);
		}
		else
		{
			matrix* temp_inv = new matrix(cols, rows);
			for (int i = 0; i < temp_inv->rows; i++)
				for (int j = 0; j < temp_inv->cols; j++)
					temp_inv->p[i][j] = (1 / d) * (this->minor(j,i).detLU())*pow(-1,i+j);
			return *temp_inv;
		}
	}
}
//Save result to file .txt
void matrix::saveTxt() 
{
	std::cout << "Enter file name (.txt) to save :";
	std::cin >> fileName;
	std::cout << "File is saved in C:/Users/datth/Desktop/txt" << fileName<<".txt" << std::endl;
	std::ofstream filem("C:/Users/datth/Desktop/txt"+fileName+".txt");
	if (filem.fail())
		std::cout << "Failed to open this file!" << std::endl;
	else
	{
	filem << "Matrix " << std::endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				filem << std::setprecision(5) << std::setw(10) << p[i][j] << " ";
			}
			filem << std::endl;
		}
		filem << "Determinant " << this->detLU() << std::endl;
		filem << "Inversion" << std::endl;
		matrix _inv = this->inv();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				filem <<std::setprecision(5) << std::setw(10) << _inv.p[i][j] << " ;";
			}
			filem << std::endl;
		}
		filem << "Transposition" << std::endl;
		matrix _trans = this->trans();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				filem <<std::setprecision(5) << std::setw(10) << _trans.p[i][j] << " ;";
			}
			filem << std::endl;
		}
	}
	filem.close();
}
//Save data to file .csv
void matrix::saveCsv()
{
	std::cout << "Enter file name (.csv) to save:";
	std::cin >> fileName;
	std::cout << "File is saved in C:/Users/datth/Desktop/csv" << fileName<<".csv"<< std::endl;
	std::ofstream filem("C:/Users/datth/Desktop/csv" + fileName + ".csv");
	if (filem.fail())
		std::cout << "Failed to open this file!" << std::endl;
	else
	{
		filem << "Matrix" << std::endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				filem << std::setprecision(5) << std::setw(10)<< p[i][j] << " ,";
			}
			filem << std::endl;
		}
		filem << "Determinant " << this->detLU() << std::endl;
		filem << "Inversion" << std::endl;
		matrix _inv = this->inv();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				filem << std::setprecision(5) << std::setw(10)<< _inv.p[i][j] << " ,";
			}
			filem << std::endl;
		}
		filem << "Transposition" << std::endl;
		matrix _trans = this->trans();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				filem << std::setprecision(5) << std::setw(10) << _trans.p[i][j] << " ,";
			}
			filem << std::endl;
		}
	}
	filem.close();
}
//get Matrix from file txt
void matrix::getMatrix()
{
	std::ifstream input("C:/Users/datth/Desktop/12.txt");
	std::string fileIn{};
	std::getline(input, fileIn, '\0');
	std::string::size_type sz{0};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{			
			p[i][j] = std::stod(fileIn,&sz);
			fileIn.erase(0, sz);
		}
	}
	input.close();
}
//LU decomposition
double matrix::detLU()
{
	matrix l(rows, cols);
	matrix u(rows,cols);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (j < i)
				l.p[j][i] = 0;
			else
			{
				l.p[j][i] = this->p[j][i];
				for (k = 0; k < i; k++)
				{
					l.p[j][i] = l.p[j][i] - l.p[j][k] * u.p[k][i];
				}
			}
		}
		for (j = 0; j < rows; j++)
		{
			if (j < i)
				u.p[i][j] = 0;
			else if (j == i)
				u.p[i][j] = 1;
			else
			{
				u.p[i][j] = this->p[i][j] / l.p[i][i];
				for (k = 0; k < i; k++)
				{
					u.p[i][j] = u.p[i][j] - ((l.p[i][k] * u.p[k][j]) / l.p[i][i]);
				}
			}
		}
	}
	double d{1};
	for (int i = 0; i < rows;i++)
	{
		d *= u.p[i][i] * l.p[i][i];
	}
	return d;
}
