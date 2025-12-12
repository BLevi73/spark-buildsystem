#include "process/process_launcher.hpp"

#include <memory>
#include <exception>

#include "process/process_handle.h"

void process_launcher::start_sync(std::vector<std::string> command)
{
    std::unique_ptr<char*[]> raw_command{new char*[command.size() + 1]};
    for (size_t i = 0; i < command.size(); i++)
    {
        raw_command[i] = command[i].data();
    }
    raw_command[command.size()] = NULL;
    int exit_status = start_sync_process(raw_command.get());
    if (!exit_status == 0)
    {
        throw std::runtime_error{"Process returned non-zero exit status"};
    }
}