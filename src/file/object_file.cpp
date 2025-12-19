#include "file/object_file.hpp"

object_file::object_file(std::filesystem::path path) : project_file(path) {}

object_file::~object_file() {}