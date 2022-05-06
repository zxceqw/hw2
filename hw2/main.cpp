#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int* (*check(int* arr, unsigned SIZE))(int*, unsigned);
int* invert(int* arr, unsigned SIZE);
int* nondecrease(int* arr, unsigned SIZE);
int* nonincrease(int* arr, unsigned SIZE);


template <typename T1, typename T2>
void Sum(T1 a, T2 b)
{
	cout <<  a + b << " - Sum of elements" << endl;
}

template <typename T1, typename T2>
void Sub(T1 a, T2 b)
{
	cout << a - b << " - Sub o elements" << endl;
}

template <typename T1, typename T2>
void Mult(T1 a, T2 b)
{
	cout << a * b << " - Multiply of elements" <<  endl;
}

template <typename T1, typename T2>
void Div(T1 a, T2 b)
{
	cout << a / b << " - Division of elements" << endl;
}



int main()
{

	cout << "2.1" << endl;
	int x;
	bool z = 1;
	double a, b;
	cout << "Enter two numbers to do some operations with them: " << endl;
	cin >> a >> b;
	while (z) {
		cout << "For sum enter 1" << endl << "For sub enter 2" << endl << "For multiply enter 3" << endl << "For division enter 4" << endl << "For exit enter 5" << endl << endl;
		cin >> x;

		switch (x)
		{
		case (1):
			Sum(a, b);
			break;
		case (2):
			Sub(a, b);
			break;
		case (3):
			Mult(a, b);
			break;
		case (4):
			Div(a, b);
			break;
		case (5):
			z = !z;
		default:
			cout << "End" << endl;
			break;
		}
	}
	

	cout << "2.1" << endl;
	int x;
	bool z = 1;
	double a, b;
	cout << "Enter two numbers to do some operations with them: " << endl;
	cin >> a >> b;
	while (z) {
		cout << "For sum enter 1" << endl << "For sub enter 2" << endl << "For multiply enter 3" << endl << "For division enter 4" << endl << "For exit enter 5" << endl << endl;
		cin >> x;

		switch (x)
		{
		case (1):
			Sum(a, b);
			break;
		case (2):
			Sub(a, b);
			break;
		case (3):
			Mult(a, b);
			break;
		case (4):
			Div(a, b);
			break;
		case (5):
			z = !z;
		default:
			cout << "End" << endl;
			break;
		}
	}
	

	cout << "//////////////////////////////////////////" << endl << "2.2" << endl;

	const int SIZE = 10;
	int arr[SIZE];
	srand((unsigned int)time(NULL));
	arr[0] = rand() % 40 + 30;
	for (int i = 1; i < SIZE; i++)
	{
		arr[i] = rand() % 10;
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	cout <<  " initial array" << endl;
	int* (*call)(int*, unsigned) = check(arr, SIZE);
	call(arr, SIZE);
	cout << " changed array";

	return 0;
}



int* (*check(int* arr, unsigned SIZE))(int*, unsigned)
{
	int* (*res[])(int* arr, unsigned size) = { invert, nondecrease, nonincrease };
	int sum = 0;
	for (int i = 1; i < SIZE; i++)
	{
		sum += arr[i];
	}
	cout << sum << " - Sum of elements in array" << endl;

	if (sum == arr[0])  return res[0]; 
	if (sum > arr[0])	return res[1];
	if (sum < arr[0])	return res[2];
}



int* invert (int* arr, unsigned SIZE)
{
	int i = 0;
	int j = SIZE - 1;
	int tmp = 0;
	while (i < j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	return arr;
}

int* nondecrease(int* arr, unsigned SIZE)
{
	int tmp = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (arr[j] >= arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	return arr;
}

int* nonincrease(int* arr, unsigned SIZE)
{
	int tmp = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (arr[j] <= arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	return arr;
}




