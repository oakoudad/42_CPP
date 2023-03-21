#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

void    replace(std::string &line, size_t &pos, size_t len, std::string &str);
void    transfer(std::ifstream &in, std::ofstream &out, char* argv[]);

#endif