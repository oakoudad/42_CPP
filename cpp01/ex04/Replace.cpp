#include "Replace.hpp"

void    replace(std::string &line, size_t &pos, size_t len, std::string &str)
{
    line.erase(pos, len);
    line.insert(pos, str);
    pos += str.length();
}

void    transfer(std::ifstream &in, std::ofstream &out, char* argv[])
{
    std::string line;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    size_t pos;

    size_t i = 1;
    while (std::getline(in, line)) {
        pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
            replace(line, pos, s1.length(), s2);
        out << line << std::endl;
        i++;
    }
}
