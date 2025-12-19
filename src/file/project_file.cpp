#include "file/project_file.hpp"

project_file::project_file(std::filesystem::path path)
{
    _path = path;
    if(!std::filesystem::exists(path))
    {
        throw std::runtime_error{"The path doesn't exist"};
    }
    _last_write = std::filesystem::last_write_time(path);
}

project_file::~project_file() {}

std::filesystem::path project_file::get_path()
{
    return _path;
}

std::filesystem::file_time_type project_file::get_last_write()
{
    return _last_write;
}