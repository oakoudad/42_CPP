#include "ScalarConverter.hpp"

bool isChar(const std::string& literal, literals &literals)
{
    if (!(literal.length() == 1 && !isdigit(literal.at(0))))
        return false;
    literals.char_val = literal.at(0);
    return true;
}

bool isInt(const std::string& literal, literals &literals)
{
    for (size_t i = (literal.at(0) == '-' || literal.at(0) == '+') ? 1 : 0; i < literal.length(); i++) {
        if (!isdigit(literal.at(i)))
            return false;
    }
    literals.int_val = atoi(literal.c_str());
    double n = strtod(literal.c_str(), NULL);
    if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
        throw std::logic_error("Error: literal is not a char, int, float or double"); 
    return true;
}

bool isFloating(std::string literal, literals& literals, bool isdouble = false)
{
    if (!(literal == "+inf" || literal == "-inf" || literal == "nan"))
    {
        if (literal.find(".") != literal.rfind("."))
            return false;
        for (size_t i = (literal.at(0) == '-' || literal.at(0) == '+') ? 1 : 0; i < literal.length(); i++)
            if (!isdigit(literal.at(i)) && literal.at(i) != '.')
                return false;
    }
    if (isdouble)
        literals.double_val = strtod(literal.c_str(), NULL);
    else
        literals.float_val = atof(literal.c_str());
    return true;
}

static convertType detectType(const std::string& literal, literals& literals)
{
    if (isChar(literal, literals))
        return type_char;
    else if (isInt(literal, literals))
        return type_int;
    else if (literal.find_last_of('f') ==literal.size() - 1 && isFloating(literal.substr(0, literal.size() - 1), literals))
        return type_float;
    else if(isFloating(literal, literals, true))
        return type_double;
    return error;
}

void caster(literals &literals, convertType &type)
{
    if (type == type_char)
    {
        literals.int_val = literals.char_val;
        literals.float_val = literals.char_val;
        literals.double_val = literals.char_val;
    }
    else if (type == type_int)
    {
        literals.char_val = static_cast<char>(literals.int_val);
        literals.float_val = literals.int_val;
        literals.double_val = literals.int_val;
    }
    else if (type == type_float)
    {
        literals.char_val = static_cast<char>(literals.float_val);
        literals.int_val = static_cast<long>(literals.float_val);
        literals.double_val = literals.float_val;
    }
    else
    {
        literals.char_val = static_cast<char>(literals.double_val);
        literals.int_val = static_cast<long>(literals.double_val);
        literals.float_val = static_cast<float>(literals.double_val);
    }
}

void representation(literals &literals)
{
    if (std::isprint(literals.char_val))
        std::cout << "char: '" << literals.char_val << "'" << std::endl;
    else if(literals.int_val <= std::numeric_limits<char>::max() && literals.int_val >= std::numeric_limits<char>::min())
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;
    
    if(literals.int_val <= std::numeric_limits<int>::max() && literals.int_val >= std::numeric_limits<int>::min())
        std::cout << "int: " << literals.int_val << std::endl;
    else
        std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << literals.float_val << 'f' << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << literals.double_val << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    literals literals;

    convertType type = detectType(literal, literals);
    if (type == error)
        throw std::logic_error("Error: literal is not a char, int, float or double");
    caster(literals, type);
    representation(literals);
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    if (this != &obj)
        *this = obj;
    return *this;
}

ScalarConverter::~ScalarConverter(){}
