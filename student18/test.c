/** test.c
 * @Author Melchor Dominguez
 *
 * Class to perform tests to later be implemented to the shell program
 * 
 */
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

//Redirecting standard output (>)
int redOut(char* filename){
   int fd = dup(1); //remember the original stdout
   close(1); //close stdout
   int fd2 = open(filename, O_RDWR | O_CREAT, 0644); //make new stdout the file
   
   //check for error in open
   if(!fd2){
    printf("error in opening file for redirection");
    _exit(EXIT_FAILURE);
   }//end if

   //Write to standout(filename)
   int num2 = write(1, "You are now stdout! ", 20);

   //return stdout to normal
   close(fd2);
   dup(fd);
   close(fd);
}//end redOut

//Redirecting standard input (<)
int red
//Appending standard output to a file (>>)
