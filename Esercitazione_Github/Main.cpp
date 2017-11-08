#include <iostream>
#include <time.h>
#include <process.h>
#include "Tarchi.h"
#include "rigacci.h"

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
	Struttura_Rigacci* V1_rigacci = new  Struttura_Rigacci;
	Struttura_Rigacci* V2_rigacci = new  Struttura_Rigacci;

	V1_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V1_rigacci->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_rigacci->sem = CreateSemaphore(NULL, 1, 1, NULL);


	Ins(V1_tarchi->vett); // potete utlizzare la funzione 'Ins' e 'stampa' gia create
	Ins(V2_tarchi->vett);
	Ins(V1_rigacci->vett);
	Ins(V2_rigacci->vett);

	cout << "\nInizio\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	stampa(V1_rigacci->vett);
	stampa(V2_rigacci->vett);
	cout << endl;

	system("pause");

	HANDLE TH1_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V1_tarchi, NULL, 0);
	HANDLE TH2_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V2_tarchi, NULL, 0); // creare i vostri thread
	HANDLE TH1_rigacci = (HANDLE)_beginthreadex(NULL,NULL, rigacci, (void*)V1_rigacci, NULL, 0);
	HANDLE TH2_rigacci = (HANDLE)_beginthreadex(NULL,NULL, rigacci, (void*)V1_rigacci, NULL, 0);

	DWORD Await1 = WaitForSingleObject(TH1_tarchi, Time);
	DWORD Await2 = WaitForSingleObject(TH2_tarchi, Time);
	DWORD Await_rigacci = WaitForSingleObject(TH1_rigacci, Time);
	DWORD Await_rigacci2 = WaitForSingleObject(TH2_rigacci, Time);

	if (Await1 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel primo Thread\n";
	else if (Await2 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel secondo Thread\n";

	cout << "\nFine\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	stampa(V1_rigacci->vett);
	stampa(V2_rigacci->vett);	

	system("pause");

	CloseHandle(TH1_tarchi); // fate le vostre chiusure
	CloseHandle(TH2_tarchi);
	CloseHandle(TH1_rigacci);
    CloseHandle(TH2_rigacci);
	CloseHandle(V1_tarchi->sem);
	CloseHandle(V2_tarchi->sem);
	CloseHandle(V1_rigacci->sem);
	CloseHandle(V2_rigacci->sem);

	delete V1_tarchi;
	delete V2_tarchi;
	delete V1_rigacci;
	delete V2_rigacci

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
