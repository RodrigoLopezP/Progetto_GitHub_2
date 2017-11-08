#include <iostream>
#include <time.h>
#include <process.h>
#include "Tarchi.h"
#include "Terraglia.h"
#include <SCOTTOX.h>
#include <Raddi.h>
using namespace std;

/** Definisce il massimo di tempo del Thread*/
#define Time 3000

void stampa(int V[MAX]);

void Ins(int V[MAX]);

int main()
{
	srand(unsigned(time(NULL)));

	Struttura_Tarchi* V1_tarchi = new Struttura_Tarchi; // creare delle vostre strutture
	Struttura_Tarchi* V2_tarchi = new Struttura_Tarchi;
	Struttura_Terraglia* S1_Terraglia = New Struttura_Terraglia; 
	Struttura_Terraglia* S2_Terraglia = New Struttura_Terraglia; 

	V1_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	S1_Terraglia->semaforo = CreateSemaphore(NULL, 1, 1, NULL);
	S2_Terraglia->semaforo = CreateSemaphore(NULL, 1, 1, NULL);
	Ins(V1_tarchi->vett); // potete utlizzare la funzione 'Ins' e 'stampa' gia create
	Ins(V2_tarchi->vett);
	Ins(S1_Terraglia->array);
	Ins(S2_Terraglia->array);

	cout << "\nInizio\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	stampa(V1_Terraglia->array);
	stampa(V2_Terraglia->array);
	cout << endl;

	system("pause");

	HANDLE TH1_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V1_tarchi, NULL, 0);
	HANDLE TH2_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V2_tarchi, NULL, 0); // creare i vostri thread
	HANDLE TH1_Terraglia = (HANDLE)_beginthreadex(NULL, NULL, Terraglia_Ordina, (void*)S1_Terraglia, NULL, 0);
	HANDLE TH2_Terraglia = (HANDLE)_beginthreadex(NULL, NULL, Terraglia_Ordina, (void*)S2_Terraglia, NULL, 0);
	DWORD Await1 = WaitForSingleObject(TH1_tarchi, Time);
	DWORD Await2 = WaitForSingleObject(TH2_tarchi, Time);
	WaitForSingleObject(TH1_Terraglia, 
	WaitForSingleObject(TH2_Terraglia, INFINITE);

	if (Await1 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel primo Thread\n";
	else if (Await2 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel secondo Thread\n";

	cout << "\nFine\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	stampa(S1_Terraglia->array);
	stampa(S2_Terraglia->array);

	system("pause");

	CloseHandle(TH1_tarchi); // fate le vostre chiusure
	CloseHandle(TH2_tarchi);
	CloseHandle(V1_tarchi->sem);
	CloseHandle(V2_tarchi->sem);
	CloseHandle(TH1_Terraglia); 
	CloseHandle(TH2_Terraglia);
	CloseHandle(S1_Terraglia->semaforo);
	CloseHandle(S2_Terraglia->semaforo);

	delete V1_tarchi;
	delete V2_tarchi;
	delete S1_tarchi;
	delete S2_tarchi;

	return 0;
}



void stampa(int V[MAX])
{
	for (int i = 0; i < MAX; i++)
		cout << V[i] << "\t";
	cout << endl;
}


void Ins(int V[MAX])
{
		for (int i = 0; i < MAX; i++)
		{
			V[i] = rand() % 1000 + 1;
		}
}