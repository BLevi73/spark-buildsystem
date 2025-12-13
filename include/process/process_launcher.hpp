#ifndef PROCESS_LAUNCHER_HPP
#define PROCESS_LAUNCHER_HPP

#include <string>
#include <vector>

namespace process_launcher
{
    /**
     * @brief Starts a synchronized process
     * 
     * @param command vector containing the command and its arguments
     * 
     * Starts a synchronized process by transforming the command vector 
     * into a C-style string (char *) array, appending the terminating
     * NULL element at the end, and calling the start_sync_process()
     * function, which in turn calls the operating system's native function
     * to create a process.
     * 
     * @throws std::runtime_error if the child process returns a non-zero return value
     */
    void start_sync(std::vector<std::string> command);
}


#endif