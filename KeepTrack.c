/* ****************************************************************************
* FILE: KeepTrack.c
* DESCRIPTION:
*   An app meant to track money exchanges between two people
* SOURCE: Blaine Bettencourt, KSU
* LAST REVISED: 05/22/20 Blaine Bettencourt
******************************************************************************/
#include "KeepTrack_Library.h"

/*   VOID GET_INFO()
*
*  Gets the input from a user that is to be added to the file
*
*/
void get_info()
{
    /* Enter the name for whats being given */
    printf("\nEnter a title for the amount: ");
    scanf("%s", sumstr.name[entry]);
    /* Enter the amount */
    printf("Enter the amount amount: ");
    scanf("%d", &sumstr.x[entry]);
    /* Amount is added to total and then all data is printed on command line */
    total = sumstr.x[entry] + total;
}

/*  INT READ_INFO()
*
*  Reads the data file in and parses through the data
*  printing out the entries recorded and the total amount
*  from the data read into the file.
*
*/
int read_info()
{
    FILE *fp;
    char* filename = FILENAME; //FILENAME contains the hidden file for data (.data.txt)

    fp = fopen(filename, "r");
    //bad file read
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    
    entry = 0;
    //gets the strings one line at a time
    while (fgets(buffer, MAXCHAR, fp) != NULL)
    {
        if (r == 0)
        {
            //str = (char *) &buffer;
            sscanf(buffer, "%d", &sumstr.num); //parse through the data here
            r++;
        }
        if (r > 1)
        {
            //str = (char *) &buffer;
            sscanf(buffer, "%s %d", sumstr.name[entry], &buf);
            printf( "Entry %d) %s ", entry, sumstr.name[entry]);
            printf( "%d \n", buf);
            total += buf;
        }
        r++;
        entry++;
    }
    fclose(fp);
    r = 0;
    return 0;
}

/*  INT MAIN(INT ARGC, CHAR *ARGV[])
*
*  The main function. The main calls the functions needed
*  to first go through the data file, then take in a users
*  input, and lastly write in the new data. It also checks
*  that the data read function ran correctly.
*
*  functions used: int read_info(), void get_info(), int write_info() <-- verify successfully written and print SUCCESS
*/
int main (int argc, char *argv[])
{
    total = 0;
    r = 0;
    int success;
    //call for function to get stored data
    success = read_info();

    //check to see if data was read correctly
    if (success == 0)
    {
        //call for function to get user data
        get_info();
        //prints the data entered by the user, and the total amount owed
        printf("After adding %s for %d, the total is at %d.\n", sumstr.name[entry], sumstr.x[entry], total);
    }

    return 0;
}   
