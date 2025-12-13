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

    config_file << "[Spark-build Configuration]" << std::endl;
    config_file << "target-name = " << name << std::endl;
    config_file << "target-type = executable" << std::endl;
    config_file << "version = 0.1.0" << std::endl;

    config_file << "c-compiler = auto" << std::endl;
    config_file << "cxx-compiler = auto" << std::endl;
    config_file << "c-standard = latest" << std::endl;
    config_file << "cxx-standard = latest" << std::endl;
    config_file << "c-flags = " << std::endl;
    config_file << "cxx-flags = " << std::endl;
    
    config_file.close();
}