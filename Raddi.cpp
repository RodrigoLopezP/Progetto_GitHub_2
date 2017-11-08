void Ordina(void* str)
{
	int app = 0;
	Struct *a = (Struct *)str;
	WaitForSingleObject(a->smp, 2000);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			if (a->Array[j] > a->Array[j + 1])
			{
				app = v->Array[j];
				a->Array[j] = a->Array[j + 1];
				a->Array[j + 1] = app;
			}
		}
	}
	ReleaseSemaphore(a->smp, 1, 0);
}