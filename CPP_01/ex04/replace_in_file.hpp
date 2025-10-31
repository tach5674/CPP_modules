#ifndef REPLACE_IN_FILE_HPP
#define REPLACE_IN_FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

bool replace_in_file(const std::string &filename,
                     const std::string &s1,
                     const std::string &s2);
#endif