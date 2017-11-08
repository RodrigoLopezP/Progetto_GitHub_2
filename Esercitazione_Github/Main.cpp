#include <iostream>
#include <time.h>
#include <process.h>
#include "Tarchi.h"
#include "Dangelo.h"

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

	Dangelo* S1_Dangelo = new Dangelo;
	Dangelo* S2_Dangelo = new Dangelo;

	V1_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);

	S1_Dangelo->sem = CreateSemaphore(NULL, 1, 1, NULL);
	S2_Dangelo->sem = CreateSemaphore(NULL, 1, 1, NULL);

	Ins(V1_tarchi->vett); // potete utlizzare la funzione 'Ins' e 'stampa' gia create
	Ins(V2_tarchi->vett);

	Ins(S1_Dangelo->vett);
	Ins(S2_Dangelo->vett);

	cout << "\nInizio\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);

	cout << "\nInizio (D'Angelo)\n";

	stampa(S1_Dangelo->vett);
	stampa(S2_Dangelo->vett);

	cout << endl;

	system("pause");

	HANDLE TH1_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V1_tarchi, NULL, 0);
	HANDLE TH2_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V2_tarchi, NULL, 0); // creare i vostri thread

	HANDLE TH1_Dangelo = (HANDLE)_beginthreadex(NULL, NULL, Dangelo_Ordina, (void*)S1_Dangelo, NULL, 0);
	HANDLE TH2_Dangelo = (HANDLE)_beginthreadex(NULL, NULL, Dangelo_Ordina, (void*)S2_Dangelo, NULL, 0);

	DWORD Await1 = WaitForSingleObject(TH1_tarchi, Time);
	DWORD Await2 = WaitForSingleObject(TH2_tarchi, Time);

	DWORD Wait1_Dangelo = WaitForSingleObject(TH1_Dangelo, Time);
	DWORD Wait2_Dangelo = WaitForSingleObject(TH2_Dangelo, Time);

	if (Await1 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel primo Thread\n";
	else if (Await2 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel secondo Thread\n";

	cout << "\nFine\n";

	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	
	cout << "\nFine (D'Angelo)\n";

	stampa(S1_Dangelo->vett);
	stampa(S2_Dangelo->vett);

	system("pause");

	CloseHandle(TH1_tarchi); // fate le vostre chiusure
	CloseHandle(TH2_tarchi);
	CloseHandle(V1_tarchi->sem);
	CloseHandle(V2_tarchi->sem);

	CloseHandle(TH1_Dangelo);
	CloseHandle(TH1_Dangelo);
	CloseHandle(S1_Dangelo->sem);
	CloseHandle(S2_Dangelo->sem);

	delete V1_tarchi;
	delete V2_tarchi;

	delete S1_Dangelo;
	delete S2_Dangelo;

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