#include "RPN.hpp"

void removeSpaces(std::string &str)
{
    while (str.find("  ") != std::string::npos)
        str.erase(str.find("  "), 1);
    if (str.at(0) == ' ')
        str.erase(0, 1);
    if (str.at(str.size() - 1) == ' ')
        str.erase(str.size() - 1, 1);
}

bool isValid(char c)
{
    if (isdigit(c) || c == '+' || c == '-' || c == '/' || c == '*')
        return true;
    return false;
}

void RPN::handler(char exp)
{
    if (exp >= '0' && exp <= '9')
        return (main_chain.push(exp - '0'), void());
    if (main_chain.size() < 2)
        throw std::logic_error("Error");
    int second = main_chain.top();
    main_chain.pop();
    int first = main_chain.top();
    main_chain.pop();
    switch (exp)
    {
        case '+':
            main_chain.push(first + second);
            break;
        case '-':
            main_chain.push(first - second);
            break;
        case '*':
            main_chain.push(first * second);
            break;
        case '/':
            main_chain.push(first / second);
            break;
    }
}

RPN::RPN(std::string parm){
    removeSpaces(parm);

    char *str = (char *)parm.c_str();
    char *pch = strtok(str, " ");
    while (pch != NULL)
    {
        if (std::string(pch).size() > 1 || !isValid(pch[0]))
            throw std::logic_error("Error");
        handler(pch[0]);
        pch = strtok(NULL, " ");
    }
    if (main_chain.size() != 1)
        throw std::logic_error("Error");
    std::cout << main_chain.top() << std::endl;
}

RPN::~RPN(){}