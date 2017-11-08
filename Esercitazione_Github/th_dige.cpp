#include<iostream>
#include"dige.h"
using namespace std;

void main()
{
	int temp;
	dige_struct* strStruct = (dige_struct*) data;
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = 0; j < MAX - 1; j++)
		{
			WaitForSingleObject(strStruct->sem, 500);
				if (strStruct->vett[j] > strStruct->vett[j + 1])
				{
					temp = strStruct->vett[j];
					strStruct->vett[j] = strStruct->vett[j + 1];
					strStruct->vett[j + 1] = temp;
				}
			ReleaseSemaphore(strStruct->sem, 1, 0);
		}
	}
}
