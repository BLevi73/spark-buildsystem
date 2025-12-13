#ifndef GENERIC_COMPILER_HPP
#define GENERIC_COMPILER_HPP

#include <string>
#include <vector>
#include <filesystem>

class generic_compiler
{
    std::filesystem::path _name;
    std::vector<std::string> _flags;
public:
    generic_compiler(std::string name);
    virtual ~generic_compiler() = 0;

    void add_flag(std::string flag);
};

#endif