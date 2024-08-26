#include <stdio.h>
#include <stdlib.h>

//function prototypes
double* declareDoubleArray(int size);
double* readMemoryDoubleArray(int size,const char* fileName); 
int writeMemoryDoubleArray(double* array,int size, const char* fileName);
