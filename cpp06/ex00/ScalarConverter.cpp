#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

enum convertType
{
    type_char,
    type_int,
    type_float,
    type_double,
    error
};

bool isChar(const std::string& literal)
{
    if (literal.length() == 1 && !isdigit(literal.at(0)))
        return true;
    return false;
}

bool isInt(const std::string& literal)
{
    size_t from;
    double n = strtod(literal.c_str(), NULL);

    if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
        return false;
    (literal.at(0) == '-') ? from = 1 : from = 0;
    for (size_t i = from; i < literal.length(); i++) {
        if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}

bool isFloating(const std::string& literal, bool is_double = false)
{
    int from;

    if (is_double == false && (literal == "+inff" || literal == "-inff" || literal == "nanf"))
        return true;
    if ((is_double == false && literal.at(literal.length() - 1) != 'f') || literal.find(".") != literal.rfind("."))
        return false;
    (literal.at(0) == '-') ? from = 1 : from = 0;
    for (size_t i = from; i < literal.length() - 1; i++)
        if (!isdigit(literal.at(i)) && literal.at(i) != '.')
            return false;
    if (is_double == false && literal.at(from) == '.' && literal.at(from + 1) == 'f')
        return false;
    return true;
}

convertType detectType(const std::string& literal)
{
    if (isChar(literal))
        return type_char;
    else if(isInt(literal))
        return type_int;
    else if(isFloating(literal))
        return type_float;
    else if(isFloating(literal, true))
        return type_double;
    return error;
}

void representation(double n)
{
    // CHAR
    (std::isprint(n))
        ? std::cout << "Char: '" << (char)n << "'" << std::endl
        : std::cout << "char: Non displayable" << std::endl;
    // INT
    (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
        ? std::cout << "Int: impossible" << std::endl
        : std::cout << "Int: " << (int)n << std::endl;
    // FLOAT
    (n > std::numeric_limits<float>::max() || n < std::numeric_limits<float>::min())
        ? std::cout << "Float: impossible" << std::endl
        : std::cout << "Float: " << std::fixed << std::setprecision(1) << n << std::endl;
    

}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << ">" << detectType(literal) << std::endl;
    switch (detectType(literal))
    {
        case type_char:
            representation(literal.at(0));
            break;
        case type_int:
            representation(strtod(literal.c_str(), NULL));
            break;
        case type_float:
            representation(strtod(literal.c_str(), NULL));
            break;
        case type_double:
            representation(strtod(literal.c_str(), NULL));
            break;
        default:
            throw std::logic_error("Error: literal is not a char, int, float or double");
    }
}