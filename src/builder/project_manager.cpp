#include "builder/project_manager.hpp"
#include <iostream>
#include <fstream>
#include "process/process_launcher.hpp"

project_manager::project_manager()
{
    std::ifstream config_file{"spark-build.config"};
    if (!config_file.is_open())
        throw std::runtime_error{"Could not open the config file"};
    std::string header;
    config_file >> header;
    if (header != "[Spark-build]")
    {
        throw std::runtime_error{"Config header is missing"};
    }
    while (!config_file.eof())
    {
        std::string token;
        config_file >> token;
        if (token == "target-name:")
        {
            config_file >> token;
            _project_name = token;
        }
        else if (token == "c-compiler:")
        {
            config_file >> token;
            _c_compiler = c_compiler{token};
        }
        else if (token == "cxx-compiler:")
        {
            config_file >> token;
            _cxx_compiler = cxx_compiler{token};
        }
        else if (token == "c-flags:")
        {
            while (config_file.peek() != '\n')
            {
                config_file >> token;
                _c_compiler.add_flag(std::move(token));
            }
        }
        else if (token == "cxx-flags:")
        {
            while (config_file.peek() != '\n')
            {
                config_file >> token;
                _cxx_compiler.add_flag(std::move(token));
            }
        }
    }
}

project_manager::~project_manager() {}

void project_manager::collect_sources()
{
    for (auto &&i : std::filesystem::recursive_directory_iterator{"src"})
    {
        if (i.exists() && i.path().extension() == ".c")
        {
            _c_sources.push_back(c_source_file{i.path()});
        }
        else if (i.exists() && i.path().extension() == ".cpp")
        {
            _cxx_sources.push_back(cxx_source_file{i.path()});
        }
        else if (!std::filesystem::is_directory(i))
        {
            std::cout << "Ignoring non-source file " << i.path() << std::endl;
        }
    }
}

void project_manager::compile_sources()
{
    for (c_source_file c_src : _c_sources)
    {
        _c_compiler.compile_source_file(c_src);
    }
    for (cxx_source_file cxx_src : _cxx_sources)
    {
        _cxx_compiler.compile_source_file(cxx_src);
    }
}

void project_manager::collect_objects()
{
    for (auto i : std::filesystem::recursive_directory_iterator{"obj"})
    {
        if (i.exists() && i.path().extension() == ".o")
        {
            _objects.push_back(object_file{i.path()});
        }
        else if (!std::filesystem::is_directory(i))
        {
            std::cout << "Ignoring non-object file " << i.path() << std::endl;
        }
    }
}

void project_manager::link_objects()
{
    std::vector<std::string> command;
    command.push_back(_cxx_compiler.get_name());
    command.push_back("-o");
    std::string binary_name{"bin/" + _project_name};
    command.push_back(binary_name);
    for (auto i : _objects)
    {
        command.push_back(i.get_path().generic_string());
    }
    process_launcher::start_sync(command);
}

void project_manager::begin_compilation()
{
    collect_sources();
    compile_sources();
    collect_objects();
    link_objects();
}