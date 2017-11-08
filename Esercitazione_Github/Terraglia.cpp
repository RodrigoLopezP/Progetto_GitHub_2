unsigned __stdcall Terraglia_Ordina(void* data)
	{
		Struttura* S = (Struttura*)data;
		int *P = S->array;
		WaitForSingleObject(S->semaforo, INFINITE);
		for (int j = 0; j < MAX; j++)
		{
			for (int i = 0; i < MAX - 1; i++)
			{
				if (P[i] > P[i + 1])
				{
					int s = P[i];
					P[i] = P[i + 1];
					P[i + 1] = s;
				}
			}
		}
		ReleaseSemaphore(S->array, 1, NULL);
		return 0;
	}