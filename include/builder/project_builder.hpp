#ifndef PROJECT_BUILDER_HPP
#define PROJECT_BUILDER_HPP

#include <string>
#include <filesystem>

namespace project_builder
{
    void generate_project(std::string project_name);

    void fix_folder_structure();
};

#endif