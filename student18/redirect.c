#include "shell.h"
#include "redirect.h"
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

    int fd = dup(1); //remember original stdout
    close(1); //close stdout
    int fd2 = open(filename, O_APPEND | O_CREAT, 0644); //new stdout

    if(!fd2){
        printf("%s\n", strerror(errno)); //print error message
        dup(fd); //return stdout to normal
        _exit(EXIT_FAILURE);
    }//end if
    
}//end append redirection

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
            
    int fd = dup(1); //remember original stdout
    close(1); //close stdout
    int fd2 = open(filename,O_TRUNC | O_CREAT, 0644); //new stdout
    
    if(!fd2){
        printf("%s\n", strerror(errno)); //print error message
        dup(fd); //return stdout to normal
        _exit(EXIT_FAILURE);
    }//end if
    

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

    int fd = dup(2); //remember stderror
    close(2); //close stderr
    int fd2 = open(filename,O_TRUNC | O_CREAT); //new stderr
    
    if(fd2 < 0){
        dup(fd); //return stderr to normal
        printf("%s\n", strerror(errno)); //print error message
        dup(fd);
        _exit(EXIT_FAILURE);
    }//end if
    
}//end stderr_redirection

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
        int fd = dup(1); //remember stdout
        int fd2 = dup(2); //remember stderr
        close(2); //close stderr
        close(1); //close stdout
        int fd3 = open(filename,O_TRUNC | O_CREAT); //new stdout

        if(!fd3){
            dup(fd);
            dup(fd2);
            printf("%s\n", strerror(errno)); //print error messae
            _exit(EXIT_FAILURE);
        }
        dup(fd);
        dup(fd2);


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

    int fd = dup(0);//remember stdin
    close(0); //close stdin
    int fd2 = open(filename,O_TRUNC); //new stdin

    if(!fd2){
        printf("%s\n", strerror(errno));
        dup(fd);
        _exit(EXIT_FAILURE);
    }//end if
}//end stdin_redirection

