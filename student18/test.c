/** test.c
 * @Author Melchor Dominguez
 *
 * Class to perform tests to later be implemented to the shell program
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <stdlib.h>

//Redirecting standard output (>)
int redOut(char* filename){
   int fd = dup(1); //remember the original stdout
   close(1);//close stdout
   int fd2 = open(filename, O_WRONLY | O_CREAT, 0644); //make new stdout the file
   
   //check for error in open
   if(!fd2){
        printf("error in opening file for redirection\n");
        return EXIT_FAILURE;
   }//end if

   //Write to standout(filename)
   fprintf(stdout, "Hello there screen nice to see you\n");

   //return stdout to normal
   close(fd2);
   dup(fd);
   fprintf(stdout, "back to normal\n");
   return EXIT_SUCCESS;
}//end redOut

//Redirecting standard input (<)
int redIn(char* filename){
    int fd = dup(0); //remeber the original stdin
    close(0);
    int fd2 = open(filename, O_RDONLY);
    
    //check for error in open
    if(!fd2){
        printf("error in opening file for redirection");
        return EXIT_FAILURE;
    }//end if
    
    char buf[20] = "Nothing is in here\n";
    //Read from stdin(filename)
    int num2 = read(0, buf, 20);

    //return stdin to normal
    close(fd2);
    dup(fd);
    close(fd); 
    return EXIT_SUCCESS;
}

//Appending standard output to a file (>>)
int appendFile(char* filename){
    int fd = dup(1);
    close(1);
    int fd2 = open(filename, O_APPEND);
    
    //check for errors in open
    if(!fd2){
        printf("error in opening file for appending\n");
        return EXIT_FAILURE;
    }//end if

    char buf[20] = "Nothing is in here\n"; //Initialize a buffer to contain a string

    printf("Enter message you would like to add(20)\n"); // 
    int num = read(0, buf, 20);
    write(fd, buf, 20);
    close(fd);
    return EXIT_SUCCESS;
}

//Redirecting both standard output and standard input (&>)
int red(char* filename){
    int fdo = dup(0);
    int fdi = dup(1);
    close(0);
    close(1);
    int fd = open(filename, O_APPEND);

    //check for errors in open
    if(!fd){
        printf("error in opening file for appending\n");
        return EXIT_FAILURE;
    }//end if

    char buf[20] = "Nothing is in here\n"; //Initialize a buffer to contain a string

    int num = read(0, buf, 20);
    write(1, buf, 20);
    close(fd);
    return EXIT_SUCCESS;
}//end red

int main(void){
    fprintf(stdout, "hello\n");
    fflush(stdout);
    //Redirecting standard output
    int exNum = redOut("newFile.txt");
    fprintf(stdout, "hello?\n");
    _exit(exNum);
}
