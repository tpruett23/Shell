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
   int fd = dup(stdout); //remember the original stdout
   close(stdout); //close stdout
   int fd2 = open(filename, O_RDWR | O_CREAT, 0644); //make new stdout the file
   
   //check for error in open
   if(!fd2){
    printf("error in opening file for redirection");
    _exit(EXIT_FAILURE);
   }//end if

   //Write to standout(filename)
   int num2 = write(stdout, "You are now stdout! ", 20);

   //return stdout to normal
   close(fd2);
   dup(fd);
   close(fd);
}//end redOut

//Redirecting standard input (<)
int redIn(char* filename){
    int fd = dup(stdin); //remeber the original stdin
    close(stdin);
    int fd2 = open(filename, O_RDONLY);
    
    //check for error in open
    if(!fd2){
        printf("error in opening file for redirection");
        return EXIT_FAILURE;
    }//end if
    
    char buf[20] = "Nothing is in here\n";
    //Read from stdin(filename)
    int num2 = read(stdin, buf, 20);
    }

    //return stdin to normal
    close(fd2);
    dup(fd);
    close(fd); 
    return EXIT_SUCCESS;
}

//Appending standard output to a file (>>)
int appendFile(char* filename){
    int fd = open(filename, O_APPEND);
    
    //check for errors in open
    if(!fd){
        printf("error in opening file for appending\n");
        return EXIT_FAILURE;
    }//end if

    char buf[20] = "Nothing is in here\n"; //Initialize a buffer to contain a string

    printf("Enter message you would like to add(20)\n"); // 
    int num = read(stdin, buf, 20);
    write(fd, buf, 20);
    close(fd);
    return EXIT_SUCCESS;
}

//Redirecting both standard output and standard input (&>)
int red(char* filename){

}
