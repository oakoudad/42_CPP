#pragma once

#include <iostream>

bool checkArg(char *s);

template <typename T>
class PmergeMe
{
    private:
        int              last_odd;
        double           duration;
        std::string      container;
        void             insertion_sort(T &main_chain)
        {
            for (int i = 2; i < (int)main_chain.size(); i = i + 2) {
                int key_even = main_chain[i];
                int key_odd = main_chain[i + 1];
                int j = i - 2;

                while (j >= 0 && main_chain[j] > key_even)
                {
                    main_chain[j + 2] = main_chain[j];
                    main_chain[j + 3] = main_chain[j + 1];
                    j -= 2;
                }
                main_chain[j + 2] = key_even;
                main_chain[j + 3] = key_odd;
            }
        }

        void             chaines(T &main_chain, T &second_chain)
        {
            for (int i = 1; i < (int)main_chain.size(); i++)
            {
                second_chain.push_back(main_chain[i]);
                main_chain.erase(main_chain.begin() + i);
            }
            if (last_odd != -1)
                second_chain.push_back(last_odd);
            if (second_chain.size() > 0)
                main_chain.insert(main_chain.begin(), second_chain[0]);
        }

        void             push_back(T &main_chain, T &second_chain)
        {
            int a = 0, b = 1;
            int next = a * 2 + b;
            int size = second_chain.size();
            for (int i = 0; next < size; i++) {
                a = b;
                b = next;
                next = a * 2 + b;
                if(next > size)
                    next = size;
                for (int j = next; j > b; j--) {

                    typename T::const_iterator low = lower_bound(main_chain.begin(), main_chain.end(), second_chain[j - 1]);
                    main_chain.insert(low, second_chain[j - 1]);
                }
            }
        }

        void print(T &main_chain, bool after) const
        {
            if (after)
            {
                std::cout << "After:\t";
                for (typename T::const_iterator it = main_chain.begin(); it != main_chain.end(); it++)
                    std::cout << *it << " ";
                std::cout << std::endl;
            }
            std::cout << "Time to process a range of\t" << main_chain.size() << " elements with std::" << container << "\t: "  << std::fixed <<  duration <<" us" << std::endl;
        }
    public:
        PmergeMe(int ac, char **av, bool after = true, std::string container = "vector") : container(container)
        {
            clock_t start = clock();
            T main_chain;
            T second_chain;

            last_odd = -1;
            if (ac % 2 == 0)
                last_odd = atoi(av[ac - 1]);
            if (ac % 2 == 0 && !checkArg(av[ac - 1]))
                throw std::logic_error("Error: not a positive number.");
            for (int i = 1; i < ((last_odd == -1) ? ac : (ac - 1)); i++)
            {
                checkArg(av[i]);
                main_chain.push_back(atoi(av[i]));
                typename T::iterator end = main_chain.end();
                if (main_chain.size() % 2 == 0 && *(end - 2) < *(end - 1))
                    std::iter_swap(main_chain.end() - 1, main_chain.end() - 2);
            }
            insertion_sort(main_chain);
            chaines(main_chain, second_chain);
            push_back(main_chain, second_chain);
            second_chain.clear();
            clock_t end = clock();
            duration = ((double)end - start) / ((double)(CLOCKS_PER_SEC) / 1000000);
            print(main_chain, after);
        }
        ~PmergeMe(){}
        
};

bool checkArg(char *s);