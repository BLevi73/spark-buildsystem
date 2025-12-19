#ifndef PROJECT_MANAGER_HPP
#define PROJECT_MANAGER_HPP

#include <vector>
#include <map>
#include <filesystem>

#include "compiler/c_compiler.hpp"
#include "compiler/cxx_compiler.hpp"

#include "file/c_source_file.hpp"
#include "file/cxx_source_file.hpp"
#include "file/object_file.hpp"

class project_manager
{
    std::string _project_name;

    c_compiler _c_compiler;
    cxx_compiler _cxx_compiler;

    std::vector<c_source_file> _c_sources;
    std::vector<cxx_source_file> _cxx_sources;
    std::vector<object_file> _objects;

    void collect_sources();
    void compile_sources();

    void collect_objects();
    void link_objects();
public:
    project_manager();
    ~project_manager();

    void begin_compilation();
};

#endif