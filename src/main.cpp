#include <iostream>
#include "builder/project_builder.hpp"
#include "builder/project_manager.hpp"

void help_message()
{
    std::cout << "Usage: spark-build <mode>" << std::endl;
    std::cout << "The following modes are available:" << std::endl;
    std::cout << "generate <project-name>" << std::endl;
    std::cout << "compile" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        help_message();
        return EXIT_FAILURE;
    }
    if (argc == 3 && std::string{argv[1]} == "generate")
    {
        project_builder::generate_project(argv[2]);
        return EXIT_SUCCESS;
    }
    if (argc == 2 && std::string{argv[1]} == "compile")
    {
        project_manager manager;
        manager.begin_compilation();
    }
}
