#include <Becucci.h>

unsigned __stdcall Becucci_Ordina(void* data)
{
	int x;
	Struttura_Becucci* Struct = (Struttura_Becucci*)data;
	int *V = Struct->vett;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX j++)
		{
			if (V[i] < V[j])
			{
				WaitForSingleObject(Struct->sem, 2000);

				x = V[i];
				V[i] = V[j];
				V[j] = x;

				ReleaseSemaphore(Struct->sem, 1, 0);
			}
		}
	}

	return 0;
}
