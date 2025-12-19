#include "compiler/c_compiler.hpp"
#include "process/process_launcher.hpp"

c_compiler::c_compiler(std::string name) : generic_compiler(name)
{
    if (!(name == "gcc" || name == "clang"))
    {
        throw std::runtime_error{"C compiler is not recognized"};
    }
}

void c_compiler::compile_source_file(c_source_file source_file)
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