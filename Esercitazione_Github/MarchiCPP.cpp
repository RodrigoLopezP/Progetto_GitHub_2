#include "MarchiH.h"

unsigned __stdcall Marchi_Ordina(void * data)
{
	int x = 0;
	Struttura* strStruttura = (Struttura*)data;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strStruttura->vett[j] > strStruttura->vett[j + 1])
			{
				WaitForSingleObject(strStruttura->sem, 2000);
				x = strStruttura->vett[j];
				strStruttura->vett[j] = strStruttura->vett[j + 1];
				strStruttura->vett[j + 1] = x;
				ReleaseSemaphore(strStruttura->sem, 1, 0);
			}
		}
	}
	return 0;
}