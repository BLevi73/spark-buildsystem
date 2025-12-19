#ifndef CXX_COMPILER_HPP
#define CXX_COMPILER_HPP

#include "compiler/generic_compiler.hpp"
#include "file/cxx_source_file.hpp"

class cxx_compiler final : public generic_compiler
{
public:
    cxx_compiler(std::string name);
    virtual ~cxx_compiler() = default;

    void compile_source_file(cxx_source_file source_file);
};

#endif