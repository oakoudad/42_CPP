#include "MutantStack.hpp"

int main()
{
    std::cout << "// BASICS:" << std::endl;
    const MutantStack<int> mstack;
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << "TOP:\t" << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << "SIZE:\t" << mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // mstack.push(0);

    // USING ITERATOR
    MutantStack<int>::const_iterator it = mstack.cbegin();
    // MutantStack<int>::iterator ite = mstack.cend();
    // ++it;
    // --it;
    // std::cout << std::endl << "// USING ITERATOR:" << std::endl;
    // while (it != ite)
    // {
    //     std::cout << "\t" << *it << std::endl;
    //     ++it;
    // }
    // std::cout << "SIZE:\t" << mstack.size() << std::endl;

    // // STACK STYLE
    // std::stack<int> s(mstack);
    // std::cout << std::endl << "// STACK STYLE:" << std::endl;
    // while (!s.empty())
    // {
    //     std::cout << "\t" << s.top() << std::endl;
    //     s.pop();
    // }
    // std::cout << "SIZE:\t" << s.size() << std::endl;


    return 0;
}