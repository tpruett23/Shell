#ifndef REDIRECT_H
   #define REDIRECT_H
    #include <errno.h>

    void   append_redirection(char*);
    void   stdout_redirection(char*);
    void   stderr_redirection(char*);
    void   stdout_stderr_redirection(char*);
    void   stdin_redirection(char*);
#endif
