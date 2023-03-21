#include "Replace.hpp"

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
