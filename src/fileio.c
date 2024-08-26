#include "fileio.h"

/******************************************************************************
 Purpose: Declares a pointer to a double array in memory.  

 Where: int size    - the desired size of the array.
        
 Returns: double*   -a double array to the desired size or NULL
 Errors:  prints a message and returns with NULL                    
******************************************************************************/ 
double* declareDoubleArray(int size){ 
    if(size <= 0){
        fprintf(stderr, "ERROR: size is not positive, size:%d",size);
        return NULL;
    }
    double* array = malloc(sizeof(double) * size);
    if (array == NULL){
        fprintf(stderr, "MALLOC error at line %d\n", __LINE__); 
        return NULL;
    } 
    return array;
}

/******************************************************************************
 Purpose: reads a text file and places them into a double array. 

 Where: int size        - size of the array
        char* fileName  - the string name of the file trying to be read.
            
 Returns: double*   -a double array filled with data or NULL
 Errors:  prints a message and returns with NULL                    
******************************************************************************/ 
double* readMemoryDoubleArray(int size, const char* fileName){  	 
    //input checks:
    if(size <= 0){
        fprintf(stderr, "ERROR: size is not positive, size:%d",size);
        return NULL;
    }
    double* array = declareDoubleArray(size);
    FILE *openedFile = fopen(fileName, "r");
	if(openedFile == NULL){
        fprintf(stderr, "Error opening file\n");
        return NULL;
    } 
	double numberRetrieved;
	for(int i = 0; i < size; i++){ 
        if(fscanf(openedFile,"%lf", &numberRetrieved) != EOF){
            array[i]  = numberRetrieved;
        }  
	}
    fclose(openedFile);
    return array;
}

/******************************************************************************
 Purpose: Writes a double array into memory. 

 Where: double* array   - a pointer to a double array.
        int size        - size of the array
        char* fileName  - the string name of the file trying to be read.
            
 Returns: int   - 0 indicates Success while -1 indicates an error
 Errors:  prints a message and returns -1             
******************************************************************************/ 
int writeMemoryDoubleArray(double* array, int size, const char* fileName){  	 
    //input checks:
    if (array == NULL){  
        fprintf(stderr, "Array is NULL \n"); 
        return -1;
    } 
    if(size <= 0){
        fprintf(stderr, "ERROR: size is not positive, size:%d",size);
        return -1;
    }
    FILE *openedFile = fopen(fileName, "w");
	if(openedFile == NULL){
        fprintf(stderr, "Error opening file");
        return -1;
    } 
	for(int i = 0; i < size; i++){ 
        if(fprintf(openedFile,"%lf", array[i]) == -1){
            fprintf(stderr, "ERROR: writing failed");
            fclose(openedFile);
            return -1;
        }  
	}
    fclose(openedFile);
    return 0;
}
