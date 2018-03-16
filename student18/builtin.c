#include "shell.h"
#include "builtin.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "extra.h"

#define num_bytes 256

/**
 * do_file_list
 *
 * Implements a built-in version of the 'ls' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        If args[1] is NULL, the current directory (./) is assumed; otherwise
 *        it specifies the directory to list.
 */
void do_file_list(char** args) {
    /*                                                                          
     * TODO: Write code here that will list the content of the specified directory (or if no
     * directory was specified, the current directory).
     */
     
    /* The current directory.*/
     DIR* curDir;
     if(args[1] == NULL){
        curDir = opendir("./");
     }else{
        curDir = opendir(args[1]);
     }
        
     if(curDir == NULL){
        printf("%s\n", strerror(errno));
        fflush(stdout);
        _exit(EXIT_FAILURE);
     }//end if
     
     /* The struct to use readdir to read the directory and access the struct.*/   
     struct dirent *entry;
     while( (entry = readdir(curDir)) != NULL)
         printf(" %s\n", entry->d_name);

     fflush(stdout);
     closedir(curDir);

}//end do_file_list()

/**
 * do_file_remove
 *
 * Implements a built-in version of the 'rm' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "rm", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_file_remove(char** args) {
    /*                                                                          
     * TODO: Write code here that will remove the specified list of files.  If no file list is
     * specified, print a usage message.
     */                                                                         

    int curElem = 1;
    while((args[curElem]) != NULL){
        /* File descriptor when opening file.*/
        int fd = open(args[curElem], O_TRUNC);
        printf(args[curElem]);
        fflush(stdout);

        /* Checking to make sure the opening the file was successful.*/
        if(fd < 0){
            printf("%s\n", strerror(errno));
            fflush(stdout);
        }//end if

        close(fd);

        /* The int unlink returns when unlinking the file from the directory.*/
        int unL = unlink(args[curElem]);
        

        /* Checking to see if unlinking was successful.*/
        if(unL < 0){
            printf("%s\n", strerror(errno));
            fflush(stdout);
        }//end if

        curElem++;
    }//end while

}//end do_file_remove()

/**
 * do_touch
 *
 * Implements a built-in version of the 'touch' command.
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "touch", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_touch(char** args) {
    /*                                                                          
     * TODO: Write code here that will modify the access time of a file(s) if it exists, or creat
     * the file(s) if it does not exist.  If no file list is specified, print a usage message.
     */   
    printf("touch\n");
    fflush(stdout);
    int curElem = 1;
    while((args[curElem]) != NULL){
        int fd = open(args[curElem], O_CREAT, 0666);
        if(fd < 0){
            printf("%s\n", strerror(errno));
        }
        close(fd);


        int uT = utime(args[curElem], NULL);
        if(uT < 0)
            printf("%s\n", strerror(errno));

        curElem++;
    }
    
        //int uT = utime(args[i], NULL);
}//end do_touch()

/**
 * do_history
 *
 * Implements a built-in version of the 'history' command. This will just list the command in the
 * form:
 *  0: command
 *  1: command
 *  2: command
 *
 * args - An array of strings corresponding to the command and its arguments.
 *        args[0] is "touch", additional arguments are in args[1] ... n.
 *        args[x] = NULL indicates the end of the argument list.
 */
void do_history(){
    /*                                                                          
     * TODO: Write code here that will print the last n command exeuted via this shell.
     */

    int curElem =0;
    while((strcmp(history[curElem], " ") != 0)){
        printf(history[curElem]);
        printf("\n");
        fflush(stdout);
        curElem++;
    }

}//end do_history()
