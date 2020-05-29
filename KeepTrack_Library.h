#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 20
#define MAXARRAY 10
#define FILENAME ".data.txt"
/*  KeepTrack_Library.h
*
* The following structure contains the necessary information  
* to allow the function "sum_of_string" to access its input data and 
* place its output into the structure.  This structure is 
* unchanged from the sequential version.
*/
typedef struct
 { 
   char name[MAXARRAY][MAXCHAR];     // stores the memory address of an char (ptr "points to" an int)
   int  x[MAXARRAY];        // stores the memory address of a int (cptr "points to" a char)
 } STRINGDATA;


/* DEFINE:
* globally accessible variables and a mutex 
*/
char buffer[MAXCHAR];
int total;
int entry;
int buf;
FILE *fpr, *fpw;
   STRINGDATA sumstr; 