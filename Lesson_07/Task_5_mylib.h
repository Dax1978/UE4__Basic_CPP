#pragma once

namespace MyLib
{
	// ������� ������ ������������ ����� ������ n
	float* makeArr(const int n);

	// ������ �������
	void printArr(float* arr, int n);

	// ������ ���������� ������������� � ������������� ���������
	void calcPositiveNegative(float* arr, int n);
}