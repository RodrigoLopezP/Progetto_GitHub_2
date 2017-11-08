#include <Windows.h>
#include "Cecchi.h"

/*
@fn unsigned __stdcall ThreadCecchi(void *data)
@brief Thread che ordina gli elementi di un vettore di interi passato come stuttura
@param void* data: puntatore void
@return 0
@date 08/11/2017
@author Andrea D. Cecchi 5BIA
@file Source.cpp
*/
unsigned __stdcall ThreadCecchi(void *data)
{
	StrutturaCecchi* sPtr = (StrutturaCecchi*)data;//dereferenziazione struttura
	int* v = sPtr->v;//dereferenziazione vettore
	int temp;//variabile temporanea di appoggio

	//bubble sort
	for (int i = 0;i<(MAX-1);i++)
	{
			WaitForSingleObject(sPtr->s, INFINITE);//blocco regolato da semaforo
			if (v[i]>v[i + 1])
			{
				temp = v[i+1];
				v[i + 1] = v[i];
				v[i + 1] = v[i];
				v[i] = temp;
				i = -1;
			}
			ReleaseSemaphore(sPtr->s, 1, NULL);//cambio stato del semaforo
	}
	return 0;
}