#pragma once
#include <Windows.h>
#define MAX 5
struct Struttura_Fabbri
{
	HANDLE sem;
	int vett[MAX];
};
unsigned __stdcall mythread_Fabbri_Guido(void* data);

