#ifndef CXX_SOURCE_FILE_HPP
#define CXX_SOURCE_FILE_HPP

#include "file/project_file.hpp"

class cxx_source_file final : public project_file
{
    public:
    explicit cxx_source_file(std::filesystem::path);
    virtual ~cxx_source_file() = default;
};

#endif