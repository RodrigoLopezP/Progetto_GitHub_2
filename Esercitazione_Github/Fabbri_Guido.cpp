#include "Fabbri_Guido.h"
unsigned __stdcall mythread_Fabbri_Guido(void* data)
{
    Struttura *Vettore = (Struttura *)data;
    bool cambio;
    do
    {
        cambio = false;
        for (int i = 0; i < (MAX-1); i++)
        {
            if (Vettore -> vett[i + 1] < Vettore -> vett[i])
            {
                WaitForSingleObject(Vettore->sem, INFINITE);
                Vettore->vett[i] = Vettore->vett[i] + Vettore->vett[i + 1];
                Vettore->vett[i + 1] = Vettore->vett[i] - Vettore->vett[i + 1];
                Vettore->vett[i] = Vettore->vett[i] - Vettore->vett[i + 1];
                cambio = true;
                ReleaseSemaphore(Vettore->sem, 1, 0);
            }
        }
    } while (cambio == true);
    return 0;
}
