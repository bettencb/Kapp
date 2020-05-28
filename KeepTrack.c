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
    scanf("%s", sumstr.name[entry-1]);
    /* Enter the amount */
    printf("Enter the amount amount: ");
    scanf("%d", &sumstr.x[entry-1]);
    /* Amount is added to total and then all data is printed on command line */
    total = sumstr.x[entry-1] + total;
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

    fp = fopen(FILENAME, "r");
    //bad file read
    if (fp == NULL){
        printf("Could not open file %s",FILENAME);
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
            sscanf(buffer, "%s %d", sumstr.name[entry-1], &sumstr.x[entry-1]);
            printf( "Entry %d) %s ", entry, sumstr.name[entry-1]);
            printf( "%d \n", sumstr.x[entry-1]);
            total += sumstr.x[entry-1];
        }
        r++;
        entry++;
    }
    fclose(fp);
    r = 0;
    return 0;
}

/*  INT WRITE_INFO()
*
*  Writes the data into .data.txt file parsing through
*  the entries recorded and the total amount from the
*  data that was read into the file and the users input.
*
*/
int write_info()
{
    FILE *fp;
    fopen(FILENAME,"w");

    //check that the file can be written.
    if (fp == NULL)
    {
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       return (1);
    }

                        //  <-- fopen(".oldprogram.bin","rb");  <-- for future enhancement

    //iterates through the data that needs to be written.
    for ( int i = 0; i < entry; i++)
    {
        fprintf(fp,"%s %d",sumstr.name[i], sumstr.x[i]);
    }
    fclose(fp);
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
    //initiate variables
    total = 0;
    r = 0;

    //check to see if data was read correctly
    if (read_info() == 0)
    {
        //call for function to get user data
        get_info();
        //prints the data entered by the user, and the total amount owed
        printf("After adding %s for %d, the total is at %d.\n", sumstr.name[entry-1], sumstr.x[entry-1], total);
    }
    //check to see if data was wrote correctly
    if (write_info() == 0) printf("File was wrote successfully");
    else printf("The information was not recorded");

    return 0;
}   
