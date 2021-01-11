#include <iostream>
#include "Normal basis.h"
#include <ctime>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "ru_RU");
	string vec1;
	string vec2;
	string gener;
	string vector1;
	string vector2;
	string generator;
	int expansion;
	cout << "������� ������ 1:" << endl;
	cin >> vector1;
	//vector1 = revers_big_string(vec1, vec1.length());
	cout << "������� ������ 2:" << endl;
	cin >> vector2;
	//vector2 = revers_big_string(vec2, vec2.length());
	/*cout << "������� ���������:" << endl;
	cin >> gener;
	generator = revers_big_string(gener, gener.length());*/
	expansion = vector1.length();
	cout << endl << "������� ���������� ����: " << expansion << endl;
	cout << "������������ ������ � ������ �����:" << endl;
	//������������ ������ 1
	int* _vector_1 = new int[expansion - 1];
	element_null(_vector_1, expansion - 1);
	convert_str_to_bin(vector1, _vector_1);
	for (int i = 0; i < expansion; i++)
	{
		cout << _vector_1[i] << " ";
	}
	cout << endl;
	string vector11;
	for (int i = 0; i < expansion; i++)
	{
		vector11 = vector11 + bin_to_string(_vector_1[i]);
	}
	cout << "������ 1:" << endl;
	cout << vector11 << endl;
	//������������ ������ 2
	int* _vector_2 = new int[expansion - 1];
	element_null(_vector_2, expansion - 1);
	convert_str_to_bin(vector2, _vector_2);
	for (int i = 0; i < expansion; i++)
	{
		cout << _vector_1[i] << " ";
	}
	cout << endl;
	//������������ ���������
	/*int* _generator = new int[expansion];
	element_null(_generator, expansion);
	convert_str_to_bin(generator, _generator);
	cout << endl << "������ ������ (reversed):" << endl;
	for (int i = 0; i < expansion; i++)
	{
		cout << _vector_1[i] << " ";
	}
	cout << endl;
	//cout << revers_output(_vector_1, expansion - 1);
	cout << endl << "������ ����� (reversed):" << endl;
	for (int i = 0; i < expansion; i++)
	{
		cout << _vector_2[i] << " ";
	}
	cout << endl;
	//cout << revers_output(_vector_2, expansion - 1);
	cout << endl << "��������� (reversed):" << endl;
	for (int i = 0; i < expansion; i++)
	{
		cout << _generator[i] << " ";
	}
	cout << endl;
	//cout << revers_output(_generator, expansion);*/

	cout << endl;
	cout << "����� �������� �� ������ ���������:" << endl;
	cout << endl;
	cout << "[0]   ����������� 0;" << endl;
	cout << "[1]   ����������� 1;" << endl;
	cout << "[+]   �����;" << endl;
	cout << "[*]   ���������;" << endl;
	cout << "[^]   ���������� � �������;" << endl;
	cout << "[s]   ���������� � �������;" << endl;
	cout << "[i]   �������� �������;" << endl;
	cout << "[t]   ����;" << endl;
	cout << "������� ���� �����:" << endl;
	char answer;
	cin >> answer;
	cout << "��� ���������:" << endl;

	switch (answer)
	{
	case'0':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		cout << revers_output(element_null(result, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ ��������� ������������ �������� �� ������������ : " << d1 << endl;
		//delete[] result;
	}
	break;

	case'1':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		cout << revers_output(element_one(result, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ ��������� ������������ ��������  �� ��������� -- 1: " << d1 << endl;
		//delete[] result;
	}
	break;

	case'+':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		element_null(result, expansion);
		result = add_vector(_vector_1, _vector_2, result, expansion);
		for (int i = 0; i < expansion; i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ �������� + : " << d1 << endl;
		//delete[] result;
	}
	break;

	case'*':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		element_null(result, expansion);
		cout << revers_output(multiplicative_vector(_vector_1, _vector_2, result, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ �������� * : " << d1 << endl;
		//delete[] result;
	}
	break;

	case'^':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		string deg;
		cout << "������� ������� � �������� ����:" << endl;
		cin >> deg;

		string degree = revers_big_string(deg, deg.length());
		int size_degree = degree.length();
		//������������ ������� � ����� �����
		int* _degree = new int[size_degree];
		element_null(_degree, size_degree);
		convert_str_to_bin(degree, _degree);


		cout << endl << "���������� ������� ������� � �������:" << endl;

		int* result = new int[expansion - 1];
		element_null(result, expansion);
		//cout << revers_output(elevation_to_huge_degree(_vector_1, _degree, _generator, result, expansion), expansion) << endl;
		//delete[] result;


		cout << endl << "���������� ������� ������� � �������:" << endl;

		int* result_ = new int[expansion - 1];
		element_null(result_, expansion);
		//cout << revers_output(elevation_to_huge_degree(_vector_2, _degree, _generator, result_, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ �������� ���������� � ������� ������� ��� ���� �������� : " << d1 << endl;
		//delete[] result_;
		//delete[] _degree;
	}
	break;

	case's':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		cout << endl << "������ ������ � ��������:" << endl;

		int* result = new int[expansion - 1];
		element_null(result, expansion);
		result = elevation_to_square(_vector_1, result, expansion);
		for (int i = 0; i < expansion; i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
		//delete[] result;

		cout << endl << "������ ������ � ��������:" << endl;

		int* result_ = new int[expansion - 1];
		element_null(result_, expansion);
		result_= elevation_to_square(_vector_2, result_, expansion);
		for (int i = 0; i < expansion; i++)
		{
			cout << result_[i] << " ";
		}
		cout << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ �������� ^ ��� ���� �������� : " << d1 << endl;
		//delete[] result_;
	}
	break;

	case't':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result1 = new int[expansion - 1];
		int* result2 = new int[expansion - 1];
		int number_of_one1 = 0;
		int number_of_one2 = 0;
		for (int i = 0; i < expansion; i++)
		{
			if (_vector_1[i] == 1)
			{
				number_of_one1++;
			}
			if (_vector_2[i] == 1)
			{
				number_of_one2++;
			}
		}
		cout << "���������� ������ � ������� 1: " << number_of_one1 << endl;
		cout << "���������� ������ � ������� 2: " << number_of_one2 << endl;
		cout << endl << "���� ������� �������:" << trace_normal(_vector_1, expansion ) << endl;
		cout << endl << "���� ������� �������:" << trace_normal(_vector_2, expansion ) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ �������� ���������� ����� �������� : " << d1 << endl;
	}
	break;

	case'i':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		cout << endl << "�������� � ������� ������:" << endl;
		int* result = new int[expansion - 1];
		element_null(result, expansion);
		//cout << revers_output(inverse_vector(_vector_1, _generator, result, expansion), expansion) << endl;
		//delete[] result;

		cout << endl << "�������� �� ������� ������:" << endl;
		int* result_ = new int[expansion - 1];
		element_null(result_, expansion);
		//cout << revers_output(inverse_vector(_vector_2, _generator, result_, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "����� ������ �������� ������ ��������� ��������: " << d1 << endl;
		//delete[] result_;
	}
	break;

	default:
		cout << "������ ������� ��� ����� ������������!" << endl;
		break;

	}
	cout << "=======================================================================" << endl;
	cout << "�������� (a+b)+c=a+(b+c)" << endl;
	string vec3;
	string vector3;
	cout << "������� ������ 3:" << endl;
	cin >> vec3;
	vector3 = revers_big_string(vec3, vec3.length());
	int* _vector_3 = new int[expansion - 1];
	element_null(_vector_3, expansion - 1);
	convert_str_to_bin(vector3, _vector_3);
	int* resultAdd1 = new int[expansion - 1];
	element_null(resultAdd1, expansion);
	cout << "��������� (a+b):" << endl;
	cout << revers_output(add_vector(_vector_1, _vector_2, resultAdd1, expansion), expansion) << endl;
	int* resultAdd2 = new int[expansion - 1];
	element_null(resultAdd2, expansion);
	cout << "��������� (a+b)+c:" << endl;
	cout << revers_output(add_vector(resultAdd1, _vector_3, resultAdd2, expansion), expansion) << endl;
	cout << "������� a+(b+c):" << endl;
	int* resultAdd3 = new int[expansion - 1];
	element_null(resultAdd3, expansion);
	cout << "��������� (b+c):" << endl;
	cout << revers_output(add_vector(_vector_2, _vector_3, resultAdd3, expansion), expansion) << endl;
	int* resultAdd4 = new int[expansion - 1];
	element_null(resultAdd4, expansion);
	cout << "��������� a+(b+c):" << endl;
	cout << revers_output(add_vector(resultAdd3, _vector_1, resultAdd4, expansion), expansion) << endl;
	//delete[]resultAdd1;
	//delete[]resultAdd2;
	//delete[]resultAdd3;
	//delete[]resultAdd4;
	cout << "�������� a+b+0=0+a+b=a+b";
	cout << "������� a+b+0:" << endl;
	int* resultAdd5 = new int[expansion - 1];
	element_null(resultAdd5, expansion);
	cout << "��������� a+b:" << endl;
	cout << revers_output(add_vector(_vector_1, _vector_2, resultAdd5, expansion), expansion) << endl;
	int* resultAdd6 = new int[expansion - 1];
	element_null(resultAdd6, expansion);
	int* null = new int[expansion - 1];
	element_null(null, expansion);
	cout << "��������� a+b+0:" << endl;
	cout << revers_output(add_vector(resultAdd5, null, resultAdd6, expansion), expansion) << endl;
	cout << "������� 0+a+b:" << endl;
	int* resultAdd7 = new int[expansion - 1];
	element_null(resultAdd7, expansion);
	cout << "��������� 0+a:" << endl;
	cout << revers_output(add_vector(null, _vector_1, resultAdd7, expansion), expansion) << endl;
	int* resultAdd8 = new int[expansion - 1];
	element_null(resultAdd8, expansion);
	cout << "��������� 0+a+b:" << endl;
	cout << revers_output(add_vector(resultAdd7, _vector_2, resultAdd8, expansion), expansion) << endl;
	int* resultAdd9 = new int[expansion - 1];
	element_null(resultAdd9, expansion);
	cout << "��������� a+b:" << endl;
	cout << revers_output(add_vector(_vector_1, _vector_2, resultAdd9, expansion), expansion) << endl;
	//delete[]resultAdd5;
	//delete[]resultAdd6;
	//delete[]resultAdd7;
	//delete[]resultAdd8;
	//delete[]resultAdd9;
	//delete[] _generator;
	//delete[] _vector_2;
	//delete[] _vector_1;
	return 0;
}

