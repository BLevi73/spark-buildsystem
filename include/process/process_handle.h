#ifndef PROCESS_HANDLE_H
#define PROCESS_HANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Starts a synchronized process
 * 
 * @param argv The command and its arguments
 * 
 * @return the exit status of the child process
 * 
 * Starts a synchronized process using the operating system's
 * native method. argv[0] contains the program to launch,
 * and is followed by the arguments passed to the program, terminated
 * by a NULL element at the end of the array.
 * 
 */
int start_synched_process(char * argv[]);

#ifdef __cplusplus
}
#endif

#endif