#pragma once

#include <string>
#include <math.h>
using namespace std;

#define POLINOMIAL_BASIS_H

string revers_big_string(string str, int str_length)
{
	int temp, i, j;
	for (i = 0, j = str_length - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}


int str_char_to_bin(char symbol_of_str)
{
	if (symbol_of_str == '0')
	{
		return 0;
	}
	if (symbol_of_str == '1')
	{
		return 1;
	}
}

int* convert_str_to_bin(string vector, int* arrey)
{
	int vector_length = vector.length();
	for (int i = 0; i < vector_length; i++)
	{
		arrey[i] = str_char_to_bin(vector[i]);
	}
	return arrey;
}

string bin_to_string(int symbol_of_string)
{
	if (symbol_of_string == 0)
	{
		return "0";
	}
	if (symbol_of_string == 1)
	{
		return "1";
	}
}

string revers_output(int* arrey, int size_arrey)
{
	string result = "";
	for (int i = size_arrey - 1; i > -1; i--)
	{
		result = result + (bin_to_string(arrey[i]) + " ");
	}
	return result;
}

int* copy_array(int* arrey1, int* arrey2, int size_of_arrey2)
{
	for (int i = 0; i < size_of_arrey2; i++)
	{
		arrey1[i] = arrey2[i];
	}
	return arrey1;
}



// Algorithms for our lab

int* element_null(int* arrey, int max)
{
	for (int i = 0; i < max; i++)
	{
		arrey[i] = 0;
	}
	return arrey;
}

int* element_one(int* arrey, int max)
{
	for (int i = 0; i < max; i++)
	{
		arrey[i] = 1;
	}
	return arrey;
}

int* add_vector(int* vector_1, int* vector_2, int* result, int size)
{
	for (int i = 0; i < size; i++)
	{
		result[i] = (vector_1[i] + vector_2[i]) % 2;
	}
	return result;
}

int* long_shift_digits_to_high(int* arrey, int max, int shiftBy, string direction)
{
	/*cout << "Вектор, который сдвигаем:" << endl;
	for (int i = 0; i < max; i++)
	{
		cout << arrey[i] << "  ";
	}
	cout << endl;*/
	int* result = new int[max];
	element_null(result, max);
	if (shiftBy == 0)
	{
		for (int i = 0; i < max; i++)
		{
			result[i] = arrey[i];
		}
		return result;
	}
	//int* arrey1 = new int[shiftBy];
	int j = 0;
	if (direction == "r")
	{
		for (int i = 0; i < shiftBy; i++)
		{
			result[j] = arrey[max - shiftBy + i];
			j++;
		}
		for (int i = shiftBy; i < max; i++)
		{
			result[i] = arrey[i-shiftBy];
		}
	}
	else if (direction == "l")
	{
		cout << "Копируем символы, которые переносятся в конец:" << endl;
		for (int i =0; i < shiftBy; i++)
		{
			result[max - shiftBy+j] = arrey[i];
			cout << "result[" << max - shiftBy + j << "] = " << result[max - shiftBy + j] << endl;
			cout << "arrey[" << i << "] = " << arrey[i] << endl;
			j++;
		}
		cout << "Сдвигаем остальные символы:" << endl;
		for (int i = 0; i < max-shiftBy; i++)
		{
			result[i] = arrey[max-i-1];
			cout << "result[" << i << "] = " << result[i] << endl;
			cout << "arrey[" << max - i - 1 << "] = " << arrey[max - i - 1] << endl;
		}
	}
	cout << endl << endl;
	//delete[] arrey1;
	return result;
}

int deg(int* vector, int size)
{
	int temp = size - 1;
	while (vector[temp] == 0)
	{
		temp--;
	}
	return temp;
}


int DivPrimeNumber(int a, int prime_num)
{
	int result;
	if (a < 0 && -a<=prime_num)
	{
		result = prime_num + a;
	}
	else if (a<0 && -a>prime_num)
	{
		int temp = (-a)/prime_num;
		result = -a + temp * prime_num;
	}
	else if (a == 0)
	{
		result = 0;
	}
	else
	{
		result = a % prime_num;
	}
	return result;
}

int* MulVectors(int* vector1, int* vector2, int* result, int size)
{
	int p = 2 * size + 1;
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	for (int i = 0; i < size; i++) // ввод элементов матрицы Лямбда0
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < size; i++) // ввод элементов матрицы Лямбда0
	{
		for (int j = 0; j < size; j++)
		{
			int a1 = pow(2, i) + pow(2, j);
			int a2 = pow(2, i) - pow(2, j);
			int a3 = -pow(2, i) + pow(2, j);
			int a4 = -pow(2, i) - pow(2, j);
			cout << "a1 = 2^" << i << " + 2^" << j << " = " << a1 << " mod "<<p<<" = "<< DivPrimeNumber(a1, p)<< endl;
			cout << "a1 = 2^" << i << " - 2^" << j << " = " << a2 << " mod " << p << " = " << DivPrimeNumber(a2, p) << endl;
			cout << "a1 = -2^" << i << " + 2^" << j << " = " << a3 << " mod " << p << " = " << DivPrimeNumber(a3, p) << endl;
			cout << "a1 = -2^" << i << " - 2^" << j << " = " << a4 << " mod " << p << " = " << DivPrimeNumber(a4, p) << endl;
			if (DivPrimeNumber(a1, p) == 1 || DivPrimeNumber(a2, p) == 1 || DivPrimeNumber(a3, p) == 1 || DivPrimeNumber(a4, p) == 1)
			{
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int* result2 = new int[size];
	element_null(result2, size);
	for (int k = 0; k < size; k++)
	{
		string direction = "l";
		int*shift_vec1 = long_shift_digits_to_high(vector1, size, k, direction);
		int* shift_vec2 = long_shift_digits_to_high(vector2, size, k, direction);
		cout << "Сдвинутый первый вектор:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << shift_vec1[i] << "  ";
		}
		cout << endl;
		cout << "Сдвинутый второй вектор:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << shift_vec2[i] << "  ";
		}
		cout << endl;
		int* result1 = new int[size];
		element_null(result1, size);
		//result = long_shift_digits_to_high(vector1, size, k);
		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size; i++)
			{
				result1[j] = (result1[j] + shift_vec1[i] * matrix[i][j]) % 2;
			}
			cout << "result1[" << j << "] = " << result1[j] << endl;
		}
		cout << "Результат умножения вектора 1 на матрицу Лямбла0:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << result1[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			result[k] = (result[k] + result1[i]*shift_vec2[i]) % 2;
		}
		cout << "result[" << k << "] = " << result[k] << endl;
	}
	/*int* result1 = new int[2 * size + 1];
	element_null(result1, 2 * size + 1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result1[i + j] = (result1[i + j] + vector1[i] * vector2[j]) % 2;
		}
	}
	//mod_generator(result1, generator, result, 2 * size + 1, size + 1);*/
	//delete[] result1;
	return result;
}

int* elevation_to_square(int* vector, int* result, int size)
{
	int* copy_vector = new int[size];
	element_null(copy_vector, size);
	copy_vector = copy_array(copy_vector, vector, size);
	for (int i = 1; i < size; i++)
	{
		result[i] = copy_vector[i-1];
	}
	result[0] = copy_vector[size - 1];
	return result;
}

int* elevation_to_huge_degree(int* vector, int* degree, int* result, int size)
{
	int* _result = new int[size]; 
	element_one(_result, size);

	for (int i = 0; i < size; i++)
	{

		if (degree[i] == 1)
		{
			MulVectors(_result, vector, result, size);
			copy_array(_result, result, size); element_null(result, size);
		}

		int* result_ = new int[size];
		elevation_to_square(vector, result_, size);
		copy_array(vector, result_, size);
		delete[] result_;
	}

	copy_array(result, _result, size);
	delete[] _result;
	return result;
}


int trace_normal(int* vector, int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result = (result + vector[i]) % 2;
	}
	return result;
}


/*int* inverse_vector(int* vector, int* generator, int* result, int size)
{
	int* degree = new int[size]; element_null(degree, size);

	degree[0] = 0;

	for (int i = 1; i < size; i++)
	{
		degree[i] = 1;
	}

	elevation_to_huge_degree(vector, degree, generator, result, size);

	delete[] degree;

	return result;
}*/

int* inverse_vector(int* vector, int* generator, int* result, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (vector[i] == 1)
		{
			result[i] = 0;
		}
		else if (vector[i] == 0)
		{
			result[i] = 1;
		}
	}
	return result;
}


