#include "shell.h"

/*
 * append_redirection
 *
 * Redirects the standard output of this process to append to the file with the specified name.
 *
 * filename - the name of the file to which to append our output
 */
void append_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output of this process to be sent to a file with
     * the specified name.  The output should be appended to the file if the file already exists.
     */

    int fd = dup(1);
    close(1);
    int fd2 = open(filename,O_APPEND | O_CREAT);
    if(fd2 < 0){
        perror(fd2);
        _exit(EXIT_FAILURE);
    }
    



}

/*
 * stdout_redirection
 *
 * Redirects the standard output of this process to overwrite the file with the specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stdout_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output of this process to be sent to a file with
     * the specified name.  If the file already exists, its contents should be truncated before
     * this process writes to the file.
     */
        
     int fd = dup(1);
    close(1);
    int fd2 = open(filename,O_TRUNC | O_CREAT);
     if(fd2 < 0){
        perror(fd2);
        _exit(EXIT_FAILURE);
    }
    

}
/*
 * stderr_redirection
 *
 * Redirects the standard error of this process to overwrite the file with the specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stderr_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard error of this process to be sent to a file with the
     * specified name.  If the file already exists, its contents should be truncated before this
     * process writes to the file.
     */

  int fd = dup(2);
    close(2);
    int fd2 = open(filename,O_TRUNC | O_CREAT);
     if(fd2 < 0){
        perror(fd2);
        _exit(EXIT_FAILURE);
    }
    
}

/*
 * stdout_stderr_redirection
 *
 * Redirects the standard output AND standard error of this process to overwrite the file with the
 * specified name.
 *
 * filename - the name of the file which to overwrite
 */
void stdout_stderr_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard output and standard error of this process to be
     * sent to a file with the specified name.  If the file already exists, its contents should be
     * truncated before this process writes to the file.
     */
        int fd = dup(1);
        int fd2 = dup(2);
        close(2)
        close(1);
        int fd3 = open(filename,O_TRUNC | O_CREAT);
        int dupp = dup2(2,fd3);


}
/*
 * stdin_redirection
 *
 * Redirects the standard input to this process from the file with the specified name.
 *
 * filename - the name of the file from which to read as standard input.
 */
void stdin_redirection(char* filename) {
    /*
     * TODO:  Write code to cause the standard input of this process to be read from a file with
     * the specified name.
     */

     int fd = dup(0);
          close(0);
        int fd2 = open(filename,O_TRUNC);
        int 
            if(fd2 < 0){
                perror(fd2);
               _exit(EXIT_FAILURE);
    }
    

}





}

