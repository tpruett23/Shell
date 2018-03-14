#include <stdio.h>
#define HIST_SIZE 40
// TODO: Stuff in here to save and list history

/**
 * Will add a command line to the history
 * @param args - arguments from the command line
 * @param hist - array which holds history 
 */
void add_history(char* args, char hist[]){
    int length = hist.size();
    hist[length - 1] = args;
}

/**
 * Will execute the history command 
 *
void do_history(char* args, char hist[]){
    add_history(args,hist);
    int i;
    for(i = 0; i < HIST_SIZE; i++){
        printf(stdout,hist[i] + "\n");

    }
} */ 
