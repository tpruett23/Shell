#include "shell.h"
#include "builtin.h"
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

    
    if(sizeof(args)== 1){
        fprintf(stdout, "Usage: rm, filename1,filename2...");
    }else{
        size_t i = 1;
        size_t numElem = sizeof(args)/sizeof(args[0]);
        for(;i < numElem ; i++){
            int fd =  open(args[i],O_TRUNC);
            
            if(fd < 0){
                printf("%s\n", strerror(errno));
                _exit(EXIT_FAILURE);
            }//end if
            char* path = "./";
            int s = unlink(strcat(path, args[i]));
        
            if(s < 0){
                printf("%s\n", strerror(errno));
                _exit(EXIT_FAILURE);
            }//end if
        }//end for
    }//end if-else

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
    size_t numElem = sizeof(args)/ sizeof(args[0]);
    for(;i < numElem; i++){
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
