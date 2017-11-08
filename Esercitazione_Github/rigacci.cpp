#include "rigacci.h"

unsigned __stdcall rigacci(void* data)
{
	int temp;
	Struttura *V = (Struttura *)data;
	int* d = V->vett;
	for (int i = 0; i < (MAX - 1); i++)
	{
		if (d[i] > d[i + 1])
		{
			WaitForSingleObject(V->sem, INFINITE);
			temp = d[i + 1];
			d[i + 1] = d[i];
			d[i] = temp;
			i = -1;
			ReleaseSemaphore(V->sem, 1, 0);
		}
	}
	return 0;
}
