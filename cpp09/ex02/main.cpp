#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main(int ac, char **av) {
    if (ac < 3)
        return (std::cerr << "usage: ./PmergeMe [numbers]" << std::endl, 0);

    try {
        for (int i = 1; i < ac; i++)
            checkArg(av[i]);
        std::cout << "Before:\t";
        for (int i = 1; i < ac; i++)
            std::cout << av[i] << " ";
        std::cout << std::endl;
        PmergeMe< std::vector<int> > P_V(ac, av);
        PmergeMe< std::deque<int> > P_D(ac, av, false, "deque");
        // P.print();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}