#include <iostream>
#pragma once

#include <string>
#include <vector>
#include <fstream>


class FileManagment
{
public:
    void clear_file(std::string file_name);
    void put_to_file(std::string file_name, std::vector<std::string> );
    std::vector<std::string> get_from_file(std::string file_name);
};