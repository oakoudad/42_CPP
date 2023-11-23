#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int>  main_chain;
        RPN();
        void handler(char exp);
    public:
        RPN(std::string parm);
        ~RPN();
};