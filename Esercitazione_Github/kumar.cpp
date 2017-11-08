#include"kumar.h"
using namespace std;

inline unsigned __stdcall Kumar_Funzione_Ordinamento(void * data)
{
	int i = 0, app;
	Struttura_Kumar *S = (Struttura_Kumar *)data;

	WaitForSingleObject(S->sem, INFINITE);
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (S->vett[i] > S->vett[j])
			{
				app = S->vett[i];
				S->vett[i] = S->vett[i + 1];
				S->vett[i + 1] = app;
			}
		}
	}
	ReleaseSemaphore(S->sem, 1, 0);
	return 0;
}