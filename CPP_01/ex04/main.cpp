#include "replace_in_file.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments!\n";
        return 1;
    }
    if (!replace_in_file(argv[1], argv[2], argv[3]))
        return 1;
    return 0;
}
