#include "builder/project_builder.hpp"

#include <fstream>

void project_builder::generate_project(std::string name)
{
    std::filesystem::create_directory(name);
    std::filesystem::create_directory(name + "/src");
    std::filesystem::create_directory(name + "/include");
    std::filesystem::create_directory(name + "/lib");
    std::filesystem::create_directory(name + "/obj");
    std::filesystem::create_directory(name + "/bin");

    std::ofstream config_file{name + "/spark-build.config"};

    config_file << "[Spark-build]" << std::endl;
    config_file << "target-name: " << name << std::endl;
    config_file << "c-compiler: gcc" << std::endl;
    config_file << "cxx-compiler: g++" << std::endl;
    config_file << "c-flags: --std=c23" << std::endl;
    config_file << "cxx-flags: --std=c++23" << std::endl;
    
    config_file.close();
}