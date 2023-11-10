#pragma once

# include <string>
# include <iostream>
#include <stdio.h>

enum convertType
{
    type_char,
    type_int,
    type_float,
    type_double,
    error
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
