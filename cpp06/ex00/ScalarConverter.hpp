#pragma once

# include <iostream>
# include <iomanip> // precision
# include <limits>

enum convertType
{
    type_char,
    type_int,
    type_float,
    type_double,
    error
};

struct literals {
    char    char_val;
    long    int_val;
    float   float_val;
    double  double_val;
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();
	public:
		static void convert(const std::string& literal);
};
