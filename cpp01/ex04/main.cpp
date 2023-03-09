#include <iostream>
#include <fstream>

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

    int i = 1;
    while (std::getline(in, line)) {
        pos = 0;
        while ((pos = line.find(s1, pos)) != -1)
            replace(line, pos, s1.length(), s2);
        out << line << std::endl;
        i++;
    }
}


int     main(int argc, char* argv[])
{
    if (argc != 4) return (std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl, 0);
    std::string filename = argv[1];

    std::ifstream infile(filename);
    if (!infile) return (std::cerr << "Error: " << filename << " not found" << std::endl ,0);

    std::ofstream outfile(filename + ".replace");
    if (!outfile) return ( std::cerr << "Error: could not create output file " << filename << ".replace" << std::endl,0);
    
    transfer(infile, outfile, argv);
    infile.close();
    outfile.close();
    std::cout << "File Created: " << filename + ".replace" << std::endl;
    return 0;
}
