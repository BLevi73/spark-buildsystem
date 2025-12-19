#include "compiler/cxx_compiler.hpp"
#include "process/process_launcher.hpp"

#include <iostream>

cxx_compiler::cxx_compiler() noexcept {}

cxx_compiler::cxx_compiler(std::string name) : generic_compiler(name)
{
    if (!(name == "g++" || name == "clang++"))
    {
        throw std::runtime_error{"CXX compiler is not recognized"};
    }
}

cxx_compiler::~cxx_compiler() {}

void cxx_compiler::compile_source_file(cxx_source_file source_file)
{
    std::vector<std::string> command;
    command.push_back(get_name());
    for (std::string flag : get_flags())
    {
        command.push_back(flag);
    }
    command.push_back("-Iinclude");
    command.push_back("-c");
    command.push_back("-o");
    std::filesystem::path output{"obj"};
    output.append(source_file.get_path().filename().generic_string());
    command.push_back(output.replace_extension(".o"));
    command.push_back(source_file.get_path());
    process_launcher::start_sync(command);
}