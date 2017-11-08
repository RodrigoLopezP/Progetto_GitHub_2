#include <iostream>
#include <time.h>
#include <process.h>
#include "Biondi.h"
#include "Cecchi.h"
#include "Dangelo.h"
#include "Raddi.h"
#include "rigacci.h"
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

	strutturaBiondi* V1_Biondi = new strutturaBiondi;
	strutturaBiondi* V2_Biondi = new strutturaBiondi;
	StrutturaCecchi* V1_cecchi = new StrutturaCecchi;
	StrutturaCecchi* V2_cecchi = new StrutturaCecchi;
	Dangelo* S1_Dangelo = new Dangelo;
	Dangelo* S2_Dangelo = new Dangelo;
	Struttura_Raddi* V1_Raddi = new Struttura_Raddi;
	Struttura_Raddi* V2_Raddi = new Struttura_Raddi;
	Struttura_Rigacci* V1_rigacci = new  Struttura_Rigacci;
	Struttura_Rigacci* V2_rigacci = new  Struttura_Rigacci;
    Struttura_Tarchi* V1_tarchi = new Struttura_Tarchi;// creare delle vostre strutture
	Struttura_Tarchi* V2_tarchi = new Struttura_Tarchi;
	Struttura_Terraglia* S1_Terraglia = new Struttura_Terraglia; 
	Struttura_Terraglia* S2_Terraglia = new Struttura_Terraglia; 

	V1_Biondi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_Biondi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V1_cecchi->s = CreateSemaphore(NULL, 1, 1, NULL);
	V2_cecchi->s = CreateSemaphore(NULL, 1, 1, NULL);
	S1_Dangelo->sem = CreateSemaphore(NULL, 1, 1, NULL);
	S2_Dangelo->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V1_Raddi->semaphore = CreateSemaphore(NULL, 1, 1, NULL);
	V2_Raddi->semaphore = CreateSemaphore(NULL, 1, 1, NULL);
	V1_rigacci->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_rigacci->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V1_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_tarchi->sem = CreateSemaphore(NULL, 1, 1, NULL);
	S1_Terraglia->semaforo = CreateSemaphore(NULL, 1, 1, NULL);
	S2_Terraglia->semaforo = CreateSemaphore(NULL, 1, 1, NULL);

	Ins(V1_Biondi->vett);
	Ins(V2_Biondi->vett);
    Ins(V1_cecchi->v);
	Ins(V2_cecchi->v);
	Ins(S1_Dangelo->vett);
	Ins(S2_Dangelo->vett);
	Ins(V1_Raddi->vettore);
	Ins(V2_Raddi->vettore);
	Ins(V1_rigacci->vett);
	Ins(V2_rigacci->vett);
    Ins(V1_tarchi->vett); // potete utlizzare la funzione 'Ins' e 'stampa' gia create
	Ins(V2_tarchi->vett);
	Ins(S1_Terraglia->array);
	Ins(S2_Terraglia->array);
	

	cout << "\nInizio (Tarchi)\n";
	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);

	cout << "\nInizio (Terraglia)\n";
	stampa(V1_Terraglia->array);
	stampa(V2_Terraglia->array);

	cout << "\nInizio (Rigacci)\n";
	stampa(V1_rigacci->vett);
	stampa(V2_rigacci->vett);

	cout << "Vettori Cecchi non ordinati" << endl;
	stampa(V1_cecchi->v);
	stampa(V2_cecchi->v);

	cout << "\nInizio (D'Angelo)\n";
	stampa(S1_Dangelo->vett);
	stampa(S2_Dangelo->vett);

	cout << "\nInizio (Raddi)\n";
	stampa(V1_Raddi->vettore);
	stampa(V2_Raddi->vettore);

	cout << "\nInizio (Biondi)\n";
	stampa(V1_Biondi->vett);
	stampa(V2_Biondi->vett);
	cout << endl;

	system("pause");

	HANDLE TH1_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V1_tarchi, NULL, 0);
	HANDLE TH2_tarchi = (HANDLE)_beginthreadex(NULL, NULL, Tarchi_mythread, (void*)V2_tarchi, NULL, 0); // creare i vostri thread


	HANDLE TH1_Terraglia = (HANDLE)_beginthreadex(NULL, NULL, Terraglia_Ordina, (void*)S1_Terraglia, NULL, 0);
	HANDLE TH2_Terraglia = (HANDLE)_beginthreadex(NULL, NULL, Terraglia_Ordina, (void*)S2_Terraglia, NULL, 0);

	DWORD Await1 = WaitForSingleObject(TH1_tarchi, Time);
	DWORD Await2 = WaitForSingleObject(TH2_tarchi, Time);

	WaitForSingleObject(TH1_Terraglia, INFINITE);
	WaitForSingleObject(TH2_Terraglia, INFINITE);


	HANDLE TH1_rigacci = (HANDLE)_beginthreadex(NULL,NULL, rigacci, (void*)V1_rigacci, NULL, 0);
	HANDLE TH2_rigacci = (HANDLE)_beginthreadex(NULL,NULL, rigacci, (void*)V1_rigacci, NULL, 0);

	DWORD Await1 = WaitForSingleObject(TH1_tarchi, Time);
	DWORD Await2 = WaitForSingleObject(TH2_tarchi, Time);
	
	DWORD Await_rigacci = WaitForSingleObject(TH1_rigacci, Time);
	DWORD Await_rigacci2 = WaitForSingleObject(TH2_rigacci, Time);
	
	HANDLE threadBiondi1 = (HANDLE)_beginthreadex(NULL, NULL, Biondi_Ordina, (void*)V1_Biondi, NULL, 0);
	HANDLE threadBiondi2 = (HANDLE)_beginthreadex(NULL, NULL, Biondi_Ordina, (void*)V2_Biondi, NULL, 0);

	WaitForSingleObject(threadBiondi1, INFINITE);
	WaitForSingleObject(threadBiondi2, INFINITE);

	HANDLE ThreadCecchi1= (HANDLE)_beginthreadex(NULL, NULL, ThreadCecchi, (void*)V1_cecchi, NULL, 0);
	HANDLE ThreadCecchi2 = (HANDLE)_beginthreadex(NULL, NULL, ThreadCecchi, (void*)V2_cecchi, NULL, 0);

	HANDLE ThreadRaddi1= (HANDLE)_beginthreadex(NULL, NULL, Raddi_Ordina, (void*)V1_Raddi, NULL, 0);
	HANDLE ThreadRaddi2 = (HANDLE)_beginthreadex(NULL, NULL, Raddi_Ordina, (void*)V2_Raddi, NULL, 0);

	HANDLE TH1_Dangelo = (HANDLE)_beginthreadex(NULL, NULL, Dangelo_Ordina, (void*)S1_Dangelo, NULL, 0);
	HANDLE TH2_Dangelo = (HANDLE)_beginthreadex(NULL, NULL, Dangelo_Ordina, (void*)S2_Dangelo, NULL, 0);

	WaitForSingleObject(ThreadRaddi1, Time);
	WaitForSingleObject(ThreadRaddi2, Time);

	DWORD Await1 = WaitForSingleObject(TH1_tarchi, Time);
	DWORD Await2 = WaitForSingleObject(TH2_tarchi, Time);
	
	WaitForSingleObject(ThreadCecchi1, INFINITE);
	WaitForSingleObject(ThreadCecchi2, INFINITE);



	DWORD Wait1_Dangelo = WaitForSingleObject(TH1_Dangelo, Time);
	DWORD Wait2_Dangelo = WaitForSingleObject(TH2_Dangelo, Time);

	if (Await1 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel primo Thread\n";
	else if (Await2 == 0x00000102L) // [258]
		cout << "Tempo di attesa terminato nel secondo Thread\n";

	cout << "\nFine (Tarchi)\n";
	stampa(V1_tarchi->vett);
	stampa(V2_tarchi->vett);
	cout << endl;
	cout << "\nFine (Terraglia)\n";
	stampa(S1_Terraglia->array);
	stampa(S2_Terraglia->array);
	cout << endl;
	cout << "\nFine (Rigacci)\n";
	stampa(V1_rigacci->vett);
	stampa(V2_rigacci->vett);	
	cout << endl;
	cout << "\nFine (Biondi)\n";
	stampa(V1_Biondi->vett);
	stampa(V2_Biondi->vett);
	cout << endl;
	cout << "Vettori Cecchi ordinati" << endl;
	stampa(V1_cecchi->v);
	stampa(V2_cecchi->v);
	cout << endl;
	cout << "\nFine (Raddi)\n";
	stampa(V1_Raddi->vettore);
	stampa(V2_Raddi->vettore);
	cout << endl;
	cout << "\nFine (D'Angelo)\n";
	stampa(S1_Dangelo->vett);
	stampa(S2_Dangelo->vett);

	system("pause");

	CloseHandle(TH1_tarchi); // fate le vostre chiusure
	CloseHandle(TH2_tarchi);
	
	CloseHandle(TH1_rigacci);
    CloseHandle(TH2_rigacci);
    
	CloseHandle(V1_tarchi->sem);
	CloseHandle(V2_tarchi->sem);

	CloseHandle(threadBiondi1); 
	CloseHandle(threadBiondi2); 
	CloseHandle(V1_Biondi->sem);
	CloseHandle(V2_Biondi->sem);
	delete V1_Biondi;
	delete V2_Biondi;
	
	CloseHandle(TH1_Terraglia); 
	CloseHandle(TH2_Terraglia);
	CloseHandle(S1_Terraglia->semaforo);
	CloseHandle(S2_Terraglia->semaforo);

	delete V1_tarchi;
	delete V2_tarchi;

	CloseHandle(V1_rigacci->sem);
	CloseHandle(V2_rigacci->sem);

	delete V1_tarchi;
	delete V2_tarchi;
	
	delete V1_rigacci;
	delete V2_rigacci;
	
	CloseHandle(ThreadCecchi1);
	CloseHandle(ThreadCecchi2);
	
	CloseHandle(V1_cecchi->s);
	CloseHandle(V2_cecchi->s);
	CloseHandle(V1_Raddi->semaphore);
	CloseHandle(V2_Raddi->semaphore);

	CloseHandle(TH1_Dangelo);
	CloseHandle(TH1_Dangelo);
	
	CloseHandle(S1_Dangelo->sem);
	CloseHandle(S2_Dangelo->sem);

	delete V1_tarchi;
	delete V2_tarchi;
	
	delete V1_cecchi;
	delete V2_cecchi;
	delete V1_Raddi;
	delete V2_Raddi;
    
    //inizio Becucci
    Struttura_Becucci* V1_becucci = new Struttura_Becucci;
	Struttura_Becucci* V2_becucci = new Struttura_Becucci;

	V1_becucci->sem = CreateSemaphore(NULL, 1, 1, NULL);
	V2_becucci->sem = CreateSemaphore(NULL, 1, 1, NULL);

	delete S1_Dangelo;
	delete S2_Dangelo;

	Ins(V1_becucci->vett);
	Ins(V2_becucci->vett);

	cout << "\nInizio\n";

	stampa(V1_becucci->vett);
	stampa(V2_becucci->vett);
	cout << endl;

	system("pause");

	HANDLE TH1_becucci = (HANDLE)_beginthreadex(NULL, NULL, Becucci_mythread, (void*)V1_becucci, NULL, 0);
	HANDLE TH2_becucci = (HANDLE)_beginthreadex(NULL, NULL, Becucci_mythread, (void*)V2_becucci, NULL, 0);

	DWORD Await1 = WaitForSingleObject(TH1_becucci, Time);
	DWORD Await2 = WaitForSingleObject(TH2_becucci, Time);

	if (Await_Becucci == 0x00000102L)
		cout << "Tempo di attesa terminato nel primo Thread\n";
	else if (Await_Becucci2 == 0x00000102L)
		cout << "Tempo di attesa terminato nel secondo Thread\n";


	cout << "\nFine\n";

	stampa(V1_becucci->vett);
	stampa(V2_becucci->vett);

	system("pause");

	CloseHandle(TH1_becucci);
	CloseHandle(TH2_becucci);
	CloseHandle(V1_becucci->sem);
	CloseHandle(V2_becucci->sem);

	delete V1_becucci;
	delete V2_becucci;

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
