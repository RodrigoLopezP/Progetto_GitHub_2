unsigned _stdcall SCotti_OrdinaVet(void *data) 
	{
		Struttura*pStr = (Struttura*)data;
		int t = 0;
		WaitForSingleObject(pStr->sem, INFINITE);
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (pStr->ptr[i] < pStr->ptr[j])
				{
					t = pStr->ptr[i];
					pStr->ptr[i] = pStr->ptr[j];
					pStr->ptr[j] = t;

				}
			}
			ReleaseSemaphore(pStr->sem, 1, NULL);
		}
		return 0;
	}
