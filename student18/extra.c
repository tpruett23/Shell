/**
 * extra.c
 *
 * @author Melchor Dominguez
 *
 * A c file to add extra methods for helping the shell
 */
#include <stdio.h>

/**
 * Allocate space on the heap and check for error
 * @param size - size of the datatype to be allocated 
 * @param num - number of items to be allocated for
 * @return - returns a valid allocated item on success
 */
char* Malloc(size_t size, int num){
    void* temp = malloc(num * size);
    if(!temp){
        printf("Error with malloc");
        _exit(EXIT_FAILURE);
    }
    return temp
}
