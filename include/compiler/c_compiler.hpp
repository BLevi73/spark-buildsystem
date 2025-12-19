#ifndef C_COMPILER_HPP
#define C_COMPILER_HPP

#include "compiler/generic_compiler.hpp"
#include "file/c_source_file.hpp"

class c_compiler final : public generic_compiler
{
public:
    c_compiler() noexcept;
    c_compiler(std::string name);
    ~c_compiler();

    void compile_source_file(c_source_file source_file);
};

#endif