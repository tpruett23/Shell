#ifndef BUILTIN_H
    #define BUILTIN_H
    #include "shell.h"
    #include "extra.h"
    #include <errno.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <dirent.h>
    
    struct dirent *reaaddir(DIR *dir); //struct for reading directory
    void   do_pipe(char** , char** , int*);
    void   do_file_list(char**);
    void   do_file_remove(char**);
    void   do_touch(char**);
    void   do_history();
#endif
