#if defined _WIN32 || _WIN64
#include <process.h>
#elif defined unix || __unix || __unix__
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif

#include "process/process_handle.h"

int start_synched_process(char * argv[])
{
    int exit_status;
#if defined _WIN32 || _WIN64
    exit_status = _spawnvp(_P_WAIT, argv[0], argv);
#elif defined unix || __unix || __unix__
    pid_t pid = fork();
    if (pid == -1)
    {
        exit_status = pid;
    }
    else if (pid == 0)
    {
        execvp(argv[0], argv);
    }
    else
    {
        wait(&exit_status);
    }
#endif
    return exit_status;
}