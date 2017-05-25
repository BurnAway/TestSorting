
#include "stdafx.h"
#include "SortDll.h"
#include <iostream>
#include <conio.h>
#include <ctime>

using std::cout;
using std::cin;

void FillingArray(int* array, int size)
{
	cout << "\n�������� ������: \n";
	cout << "1 - ������������� �� �����������\n";
	cout << "2 - ������������� �� ��������\n";
	cout << "3 - ��������� ������������������\n";
	
	int number = 0;
	cin >> number;

	switch (number)
	{
	case 1:
		for (int i = 0; i < size; i++)
		{
			array[i] = i;
		}
		break;

	case 2:
		for (int i = 0; i < size; i++)
		{
			array[i] = size - i;
		}
		break;

	case 3:
		for (int i = 0; i < size; i++)
		{
			array[i] = rand();
		}
		break;

	default:
		break;
	}

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int *arr = NULL;
	int number = 0;
	int size = 1024;

	unsigned int searchTimeBubbleSort = 0;
	unsigned int searchTimeQuickSort = 0;
	unsigned int startTime = 0;
	unsigned int endTime = 0;

	arr = new int[size];
	
	FillingArray(arr, size);

	cout << "\n�������� ����� ����������: \n";
	cout << "1 - ���������� ���������\n";
	cout << "2 - ������� ����������\n";

	cin >> number;

	switch (number)
	{
	case 1:
		startTime = clock();
		BubbleSort(arr, size);
		endTime = clock();
		searchTimeBubbleSort = endTime - startTime;
		break;

	case 2:
		startTime = clock();
		QuickSort(arr, size, 0, size - 1);
		endTime = clock();
		searchTimeQuickSort = endTime - startTime;
		break;

	default:
		break;
	}

	cout << "\nTime of Bubble Sorting" << searchTimeBubbleSort / 1000.0;
	cout << "\nTime of Quick Sorting" << searchTimeQuickSort / 1000.0;


	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	delete arr;
	_getch();
	return 0;
}