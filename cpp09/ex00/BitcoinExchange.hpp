#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float>  _data;
        void insert(const std::string &line);
        float getPrice(std::string &date) const;
    public:
        BitcoinExchange();
        void print(const std::string &f) const;
        ~BitcoinExchange();
};