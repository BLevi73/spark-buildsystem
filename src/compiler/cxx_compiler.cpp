#include "compiler/cxx_compiler.hpp"
#include "process/process_launcher.hpp"

cxx_compiler::cxx_compiler(std::string name) : generic_compiler(name)
{
    if (!(name == "g++" || name == "clang++"))
    {
        throw std::runtime_error{"CXX compiler is not recognized"};
    }
}

void cxx_compiler::compile_source_file(cxx_source_file source_file)
{
    std::vector<std::string> command;
    command.push_back(get_name());
    for (std::string flag : get_flags())
    {
        command.push_back(flag);
    }
    command.push_back("-c");
    command.push_back("-o");
    command.push_back(source_file.get_path().replace_extension(".o"));
    command.push_back(source_file.get_path());
    process_launcher::start_sync(command);
}