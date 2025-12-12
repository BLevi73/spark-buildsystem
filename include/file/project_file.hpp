#ifndef PROJECT_FILE_HPP
#define PROJECT_FILE_HPP

#include <filesystem>

/**
 * @brief Represents a project file
 * 
 * Represents a project file for the buildsystem.
 */
class project_file
{
private:
    std::filesystem::path _path;
    std::filesystem::file_time_type _last_write; 
public:
    explicit project_file(std::filesystem::path);
    ~project_file();
};
#endif