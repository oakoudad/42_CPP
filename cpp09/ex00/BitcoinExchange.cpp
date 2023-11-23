#include "BitcoinExchange.hpp"

bool isFloat(std::string literal)
{
    if (literal.find(".") != std::string::npos && literal.find(".") != literal.rfind("."))
        return false;
    size_t n = 0;
    for (size_t i = (literal.at(0) == '-' || literal.at(0) == '+') ? 1 : 0; i < literal.length(); i++)
    {
        if (!isdigit(literal.at(i)) && literal.at(i) != '.')
            return false;
        if (isdigit(literal.at(i)))
            n++;
    }
    if (literal.find(".") != std::string::npos && n == 0)
        return false;
    return true;
}

bool isNumber(const char *str)
{
    while(*str != '\0')
        if (!std::isdigit(*(str++)))
            return (false);
    return (true);
}

bool inValidInCalandar(int Y, int M, int D)
{
    if (M > 12 || D > 31)
        return (false);
    if ((M == 4 || M == 6 || M == 9 || M == 11) && D > 30)
        return (false);
    if (M == 2 && D > 29)
        return (false);
    if (M == 2 && D == 29 && ((Y % 4 != 0) || (Y % 100 == 0 && Y % 400 != 0)))
        return (false);
    return (true);
}

bool validate_date(std::string date)
{
    if (date.size() != 10)
        return (false);
    char *year = std::strtok((char *)date.c_str(), "-");
    if (!(std::string(year).size() == 4 && isNumber(year)))
        return false;
    char *month = std::strtok((char *)date.c_str() + 5, "-");
    if (!(std::string(month).size() == 2 && isNumber(month)))
        return false;
    char *day = std::strtok((char *)date.c_str() + 8, "\0");
    if (!(std::string(day).size() == 2 && isNumber(day)))
        return false;
    return (inValidInCalandar(atoi(year), atoi(month), atoi(day)));
}

float BitcoinExchange::getPrice(std::string &date) const
{
    if (_data.find(date) != _data.end())
        return _data.at(date);
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    return (--it)->second; 
    
}

bool putError(std::string err)
{
    return (std::cerr << err << std::endl, true);
}

void BitcoinExchange::print(const std::string &f) const
{
    std::ifstream file(f);
    if (!file)
        throw std::logic_error("Could not open file");
    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
            continue ;
        if (line.find(" | ") == std::string::npos && putError("Error: bad input => " + line))
            continue ;
        size_t delim = line.find_first_of(" | ");
        std::string date = line.substr(0, delim);

        if (date == "date")
        {
            if (line != "date | value") putError("Error: bad input => " + line);
            continue;
        }
        if (date < _data.begin()->first && putError("Error: date start from " + _data.begin()->first))
            continue ;
        std::string price = line.substr(delim + 3, line.size() - 1);
        if ((!validate_date(date) || price.size() == 0 || !isFloat(price)) && putError("Error: bad input => " + line))
            continue ;
        float f_price = std::stof(price);
        (void)  f_price;
        if (f_price > 1000)
            std::cerr << "Error: too large a number." << std::endl;
        else if (f_price < 0)
            std::cerr << "Error: not a positive number." << std::endl;
        else
            f_price * getPrice(date) > 100
                ? std::cout << date << " => " << price << " = " << std::fixed << std::setprecision(2) << f_price * getPrice(date) << std::endl
                : std::cout << date << " => " << price << " = " << std::setprecision(2) << f_price * getPrice(date) << std::endl;
    }
    file.close();
}

void BitcoinExchange::insert(const std::string &line)
{
    size_t delim = line.find_first_of(",");
    if (line.substr(0, delim) == "date")
        return ;
    _data.insert(std::make_pair(
        line.substr(0, delim),
        std::stof(line.substr(delim + 1, line.size() - 1)))
    );
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream csv("./data.csv");
    if (!csv)
        throw std::logic_error("Could not open file");

    std::string line;
    while (std::getline(csv, line))
        insert(line);
    csv.close();
    if (_data.size() == 0)
        throw std::logic_error("Empty database");
}

BitcoinExchange::~BitcoinExchange(){}