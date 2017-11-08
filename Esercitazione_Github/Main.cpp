#include <iostream>
#include <time.h>
#include <process.h>
#include "Cecchi.h"
#include "Raddi.h"
#include "Tarchi.h"

using namespace std;

/** Definisce il massimo di tempo del Thread*/
#define Time 3000

void stampa(int V[MAX]);

void Ins(int V[MAX]);

int main()
{
	srand(unsigned(time(NULL)));

	StrutturaCecchi* V1_cecchi = new StrutturaCecchi;
	StrutturaCecchi* V2_cecchi = new StrutturaCecchi;
	Struttura_Raddi* V1_Raddi = new Struttura_Raddi;
	Struttura_Raddi* V2_Raddi = new Struttura_Raddi;
    	Struttura_Tarchi* V1_tarchi = new Struttura_Tarchi;// creare delle vostre strutture
	Struttura_Tarchi* V2_tarchi = new Struttura_Tarchi;
	
	V1_Raddi->semaphore = CreateSemaphore(NULL, 1, 1, NULL);
	V2_Raddi->semaphore = CreateSemaphore(NULL, 1, 1, NULL);
	V1_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V1_cecchi->s = CreateSemaphore(NULL, 1, 1, NULL);
	V2_cecchi->s = CreateSemaphore(NULL, 1, 1, NULL);

	Ins(V1_tarchi->vett); // potete utlizzare la funzione 'Ins' e 'stampa' gia create
	Ins(V2_tarchi->vett);
	Ins(V1_cecchi->v);
	Ins(V2_cecchi->v);
	Ins(V1_Raddi->vettore);
	Ins(V2_Raddi->vettore);

	cout << "\nInizio\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	cout << "Vettori Cecchi non ordinati" << endl;
	stampa(V1_cecchi->v);
	stampa(V2_cecchi->v);
	stampa(V1_Raddi->vettore);
	stampa(V2_Raddi->vettore);
	cout << endl;

	system("pause");

	HANDLE TH1_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V1_tarchi, NULL, 0);
	HANDLE TH2_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V2_tarchi, NULL, 0); // creare i vostri thread
	HANDLE ThreadCecchi1= (HANDLE)_beginthreadex(NULL, NULL, ThreadCecchi, (void*)V1_cecchi, NULL, 0);
	HANDLE ThreadCecchi2 = (HANDLE)_beginthreadex(NULL, NULL, ThreadCecchi, (void*)V2_cecchi, NULL, 0);
	HANDLE ThreadRaddi1= (HANDLE)_beginthreadex(NULL, NULL, Raddi_Ordina, (void*)V1_Raddi, NULL, 0);
	HANDLE ThreadRaddi2 = (HANDLE)_beginthreadex(NULL, NULL, Raddi_Ordina, (void*)V2_Raddi, NULL, 0);

	WaitForSingleObject(ThreadRaddi1, Time);
	WaitForSingleObject(ThreadRaddi2, Time);
	DWORD Await1 = WaitForSingleObject(TH1_tarchi, Time);
	DWORD Await2 = WaitForSingleObject(TH2_tarchi, Time);
	WaitForSingleObject(ThreadCecchi1, INFINITE);
	WaitForSingleObject(ThreadCecchi2, INFINITE);

	if (Await1 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel primo Thread\n";
	else if (Await2 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel secondo Thread\n";

	cout << "\nFine\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	cout << "Vettori Cecchi ordinati" << endl;
	stampa(V1_cecchi->v);
	stampa(V2_cecchi->v);
	stampa(V1_Raddi->vettore);
	stampa(V2_Raddi->vettore);

	system("pause");

	CloseHandle(TH1_tarchi); // fate le vostre chiusure
	CloseHandle(TH2_tarchi);
	CloseHandle(V1_tarchi->sem);
	CloseHandle(V2_tarchi->sem);
	CloseHandle(ThreadCecchi1);
	CloseHandle(ThreadCecchi2);
	CloseHandle(V1_cecchi->s);
	CloseHandle(V2_cecchi->s);
	CloseHandle(V1_Raddi->semaphore);
	CloseHandle(V2_Raddi->semaphore);

	delete V1_tarchi;
	delete V2_tarchi;
	delete V1_cecchi;
	delete V2_cecchi;
	delete V1_Raddi;
	delete V2_Raddi;

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