#include "replace_in_file.hpp"

bool replace_in_file(const std::string &filename,
                     const std::string &s1,
                     const std::string &s2)
{
    if (s1.empty())
    {
        std::cerr << "First string shouln't be empty!\n";
        return false;
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Failed to open file for reading.\n";
        return false;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Failed to open file for writing.\n";
        return false;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::string newLine;
        size_t pos = 0, found;

        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            newLine += line.substr(pos, found - pos);
            newLine += s2;
            pos = found + s1.size();
        }
        newLine += line.substr(pos);
        outfile << newLine << "\n";
    }

    return true;
}