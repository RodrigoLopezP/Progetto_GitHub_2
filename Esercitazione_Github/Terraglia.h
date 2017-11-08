#include <Windows.h>
#define MAX 5

struct Struttura_Terraglia
{
	HANDLE semaforo;
	int array[MAX];
};

unsigned __stdcall Terraglia_Ordina(void* data);