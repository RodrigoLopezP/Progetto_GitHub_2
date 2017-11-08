#include "Raddi.h"

unsigned __stdcall Raddi_Ordina(void* data)
{
	int temp = 0;
	Struttura *V = (Struttura *)data;
	int* d = V->vettore;
	for (int i = 0; i < (MAX - 1); i++)
	{
		if (d[i] > d[i + 1])
		{
			WaitForSingleObject(V->semaphore, INFINITE);
			temp = d[i + 1];
			d[i + 1] = d[i];
			d[i] = temp;
			i = -1;
			ReleaseSemaphore(V->semaphore, 1, 0);
		}
	}
	return 0;
}