#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int add_Hist(char *);

int main(void){
    add_Hist("line1");
    add_Hist("line2");
    add_Hist("line3");
    add_Hist(NULL);
}//end main()

int add_Hist(char* line){
    static char* hist[2];
    static int index = 0;

    if(line == NULL){
        int i = 0;
        while(i < index){
            printf(hist[i]);
            printf("\n");
            fflush(stdout);
            i++;
        }
        return 0;
    }

    if(index < 2){
        hist[index] = line;
        index++; 
    }else{

        int elem = 1;
        while(elem < 2){
            if(elem == 1){
                hist[elem - 1] = hist[elem];
                hist[elem] = line;
            }else{
                hist[elem - 1] = hist[elem];
            }
            elem++;
        }//end while
    }//end if-else

    return 0;
}//end add_Hist()
