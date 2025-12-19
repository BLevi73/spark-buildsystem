#ifndef GENERIC_COMPILER_HPP
#define GENERIC_COMPILER_HPP

#include <string>
#include <vector>

class generic_compiler
{
    std::string _name;
    std::vector<std::string> _flags;
public:
    generic_compiler(std::string name);
    virtual ~generic_compiler() = 0;

    std::string get_name();
    std::vector<std::string> get_flags();
    void add_flag(std::string&& flag);
};

#endif