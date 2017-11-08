#include <Windows.h>

#define LF 5

struct Struttura_Raddi
{
	HANDLE semaphore;
	int vettore[LF];
};

unsigned __stdcall Raddi_Ordina(void* data);