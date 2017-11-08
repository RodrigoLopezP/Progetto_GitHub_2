#pragma once
#include <Windows.h>
#include <process.h>
#define MAX 5

/*
struttura con semaforo e vettore
*/
struct strutturaBiondi
{
	HANDLE sem;
	int vett[MAX];
};

unsigned __stdcall Biondi_Ordina(void * data)