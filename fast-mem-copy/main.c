#include <string.h>

typedef unsigned int U32;

#define ARRAY_SIZE  (U32)(1000)

U32 a[ARRAY_SIZE];
U32 ac[ARRAY_SIZE];

struct sMemBlock
{
      U32 b[ARRAY_SIZE];  
} memblock1, memblock2;

void funcion(void);
void funcion2(void);
void funcion3(void);

int main(void)
{
  funcion();
  
  funcion2();
  
  funcion3();
  
  return 0;
}

void funcion(void)
{
    U32 i;

    /* inefficient */
    for(i = (U32)0; i < ARRAY_SIZE; i++)
    {
        ac[i] = a[i];
    }
}

void funcion2(void)
{
    /* optimal copying */
    memblock2 = memblock1;
}

void funcion3(void)
{
    /* inefficient */
    memcpy(ac, a, sizeof(a));
}