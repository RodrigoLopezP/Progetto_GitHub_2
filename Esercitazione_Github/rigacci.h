#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include <iostream>
using namespace std;

void rigacci(void* data) {
	int *V = (int*)data;
	for (int i = 0; i < 5; i++)
	{
		int min = i;
		for (int j = i + 1; j < 5; j++)
			if (V[j] < V[min]) 
				min = j;
		int temp = V[min];
		V[min] = V[i];
		V[i] = temp;
	}
}
