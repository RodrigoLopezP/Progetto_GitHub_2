#pragma once
#include<iostream>
#include<process.h>
#include<Windows.h>

#define MAX 5

struct Struttura_Kumar {
	HANDLE sem;
	int vett[MAX];
};
unsigned __stdcall Kumar_Funzione_Ordinamento(void * data);