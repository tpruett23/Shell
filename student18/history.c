#include "history.h"

/**
 * History will initialize an array to hold command line arguments
 * if NULL is the parameter, the history of command line arguments 
 * will be printed
 * @param line - the command line to be entered into history
 *             - if NULL, print history
 * @return - 0 upon success
 */
int add_Hist(char* line){
    
    /**initiliaze a static history variable to hold command lines*/
    static char* hist[HSIZE];

    /**initialize a static index to keep track of the element number*/
    static int index = 0;

    //if NULL is entered print
    if(line == NULL){

        /** element of array to be printed*/
        int elem = 0;
        while(elem < index){
            printf(hist[elem]);
            printf("\n");
            fflush(stdout);
            elem++;
        }//end while
        return EXIT_SUCCESS;
    }//end if
    
    //add command line to history
    if(index < HSIZE){
        hist[index] = line;
        index++;
    }else{
        int elem = 1;
        while(elem < HSIZE){
            if(elem == HSIZE -1){
                hist[elem - 1] = hist[elem];
                hist[elem] = line;
            }else{
                hist[elem - 1] = hist[elem];
            }//end if-else
            elem++;
        }//end while
    }//end if-else
    return EXIT_SUCCESS;
}
