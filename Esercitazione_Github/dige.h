#pragma once
#include<process.h>
#include <iostream>
#include<Windows.h>
#define MAX 5;
using namespace std;

struct dige_struct {
	HANDLE sem;
	int vett[MAX];
};

unsigned __stdcall Digenua_thread(void * data)
