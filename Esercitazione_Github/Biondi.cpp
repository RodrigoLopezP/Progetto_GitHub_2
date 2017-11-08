#include "Biondi.h"

/*
@author leonardo biondi
@date 6/11/2017
@version 1.0.0
@param data puntatore di tipo void
@return 0
*/
unsigned __stdcall Biondi_Ordina(void * data)
{
	int x;
	strutturaBiondi *ptr = (strutturaBiondi*)data;
	int* v = ptr->vett;
	for (int i = 0; i < (MAX - 1); i++)
	{
		if (v[i] > v[i + 1])
		{
			WaitForSingleObject(ptr->sem, INFINITE);
			x = v[i + 1];
			v[i + 1] = v[i];
			v[i] = x;
			i = -1;
			ReleaseSemaphore(ptr->sem, 1, 0);
		}
	}
	return 0;
}