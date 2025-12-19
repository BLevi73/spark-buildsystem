#ifndef OBJECT_FILE_HPP
#define OBJECT_FILE_HPP

#include "file/project_file.hpp"

class object_file : public project_file
{
public:
    explicit object_file(std::filesystem::path);
    ~object_file();
};

#endif