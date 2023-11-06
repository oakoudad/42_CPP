#pragma once

# include <string>
# include <iostream>

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
		static char char_value;
		static int int_value;
		static float float_value;
		static double double_value;
	public:
		static void convert(const std::string& literal);
};
