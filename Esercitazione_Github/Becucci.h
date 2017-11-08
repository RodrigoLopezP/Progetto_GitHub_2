#pragma once
#include <Windows.h>

#define MAX 5

struct Struttura_Becucci
{
	HANDLE sem;
	int vett[MAX];
};

unsigned __stdcall Becucci_Ordina(void* data);
