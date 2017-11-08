#include "Dangelo.h"

unsigned __stdcall Dangelo_Ordina(void* data)
{
	int app = 0;
	Dangelo *v = (Dangelo *)data;
	WaitForSingleObject(v->sem, 2000);
	for (int i = 0; i < (MAX ); i++)
	{
		for (int j = 0; j < (MAX - 1); j++)
		{
			if (v->vett[j] > v->vett[j + 1])
			{
				app = v->vett[j];
				v->vett[j] = v->vett[j + 1];
				v->vett[j + 1] = app;
			}
		}
	}

	ReleaseSemaphore(v->sem, 1, 0);
	return 0;
}
