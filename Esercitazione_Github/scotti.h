#include<windows.h>
 
struct pStr
{
       HANDLE sem;
       int ptr[max];
}       
unsigned _stdcall SCotti_OrdinaVet(void *data)
