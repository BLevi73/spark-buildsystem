#include "compiler/generic_compiler.hpp"

#include <exception>

generic_compiler::generic_compiler() noexcept {}

generic_compiler::generic_compiler(std::string name) : _name(name) {}

generic_compiler::~generic_compiler() {}

std::string generic_compiler::get_name()
{
    return _name;
}

std::vector<std::string> generic_compiler::get_flags()
{
    return _flags;
}
void generic_compiler::add_flag(std::string&& flag)
{
    _flags.push_back(flag);
}