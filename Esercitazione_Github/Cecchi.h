#pragma once
#include <Windows.h>
#define MAX 5

struct StrutturaCecchi
{
	HANDLE s;
	int v[MAX];
};

unsigned __stdcall ThreadCecchi(void *data);