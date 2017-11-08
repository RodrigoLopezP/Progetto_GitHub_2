#pragma  once
#include <Windows.h>

#define MAX 5

struct Dangelo
{
	HANDLE sem;
	int vett[MAX];
};

unsigned __stdcall Dangelo_Ordina(void* data);
