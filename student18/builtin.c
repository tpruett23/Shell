#include "shell.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

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
    
    int fdR;
    if(args[1] == NULL){
        fdR = open("./", O_DIRECTORY); //Open the current directory for read only    
    }else{
        fdR = open(args[1], O_DIRECTORY); //Open specified directory for read only
    }//end if


    char* temp = Malloc(sizeof(char), num_bytes);

    int num = read(fdR, temp, num_bytes);
    
    while(num > 0){
        int num2 = write(1, temp, sizeof(temp));
        if(num2 < 0){
            printf("error in writing to destination\n");
            _exit(EXIT_FAILURE);
        }//end if 
        num = read(fdR, temp, num_bytes); //attempt to read another num of bytes
    }//end while

    free(temp);
    temp = NULL;

    if(num < 0){
        printf("Failure in reading file\n");
        _exit(EXIT_FAILURE);
    }//end if

    close(fdR); //close reading file
    fflush(stdout);
}
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

    int i = 1;
    int s;
    if(sizeof(args)== 1){
        fprintf(stdout, "Usage: rm, filename1,filename2...");
    }else{

        for(i; i < sizeof(args);i++){
            int fd =  open(args[i],O_TRUNC);
            int s = unlink("./"+args[i]);
        }
        if(s == -1){
            printf("%s\n", strerror(errno));
        }
    }

}

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

    for(int i = 1; i < sizeof(args); i++){
        // create specified file, if file already exists time stampt is updated
        int fd = open(args[i], O_CREAT, 0644);
        close(fd);
    }//end for 
}

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
void do_history(char** args) {
    /*                                                                          
     * TODO: Write code here that will print the last n command exeuted via this shell.
     */                                                                         
   
   for(int list = 0; list < sizeof(history); list++){
        fprintf(stdout, history[list] + "\n");
   }
}
