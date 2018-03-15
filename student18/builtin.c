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
        int fd = open(args[curElem], O_TRUNC);
        printf(args[curElem]);
        fflush(stdout);
        if(fd < 0){
            printf("%s\n", strerror(errno));
            fflush(stdout);
        }//end if

        close(fd);
        int unL = unlink(args[curElem]);
        
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
    size_t i = 1;
    printf("touch");
    size_t numElem = sizeof(args)/ sizeof(args[0]);
    for(;i < numElem; i++){
        printf("for");
        int fd = open(args[i], O_CREAT, 0644);
        if(fd < 0){
            printf("%s\n", strerror(errno));
            _exit(EXIT_FAILURE);
        }//end if
        char* path = "./";
        int uT = utime(strcat(path, args[i]), NULL);
        if(uT < 0){
            printf("%s\n", strerror(errno));
            _exit(EXIT_FAILURE);
        }
    }//end for
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
  size_t list = 0;
  size_t numElem = sizeof(history)/sizeof(history[0]);

   for(; list < numElem; list++){
        fprintf(stdout, strcat(history[list], "\n"));
   }//end for
}//end do_history()
