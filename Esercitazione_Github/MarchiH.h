#pragma once
#include <Windows.h>

#define MAX 5

struct Struttura
{
	HANDLE sem;
	int vett[MAX];
};

unsigned __stdcall Marchi_Ordina(void* data);
