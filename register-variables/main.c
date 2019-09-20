typedef unsigned int U32;
typedef unsigned char U08;

#define ARRAY_SIZE  (U32)(10)

int main()
{
  /*    REGISTER VALUES for increasing perfomance
        register Keyword in this case does not change the resulting assembly,
        the optimization is not to access arrays re-calculating indexes evrytime,
        increase a pointer which points to that array saves the index calculation.
  */
  U32 a[ARRAY_SIZE], b[ARRAY_SIZE];
  U08 i;
  register U32 *p = a, *q = b;

  /* Inefficient */
  for (i = 0; i < ARRAY_SIZE; i++)
  {
    a[i] = (a[i] * 20) + b[i];
  }

  /* Efficient */
  for (i = 0; i < ARRAY_SIZE; i++)
  {
    *p++ = (*p * 20) + *q++;
  }

  return 0;
}
