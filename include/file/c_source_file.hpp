#ifndef C_SOURCE_FILE_HPP
#define C_SOURCE_FILE_HPP

#include "file/project_file.hpp"

class c_source_file final : public project_file
{
public:
    explicit c_source_file(std::filesystem::path);
    ~c_source_file();
};

#endif