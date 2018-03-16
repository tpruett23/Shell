#include "history.h"

int add_Hist(char* line){
    
    /**initiliaze a static history variable to hold command lines*/
    static char* hist[HSIZE];

    /**initialize a static index to keep track of the element number*/
    static int index = 0;

    if(line == NULL){
        int i = 0;
        while(i < index){
            printf(hist[i]);
            printf("\n");
            fflush(stdout);
            i++;
        }//end while
        return EXIT_SUCCESS;
    }//end if
    
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
