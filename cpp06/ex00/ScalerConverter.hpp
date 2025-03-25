#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>

#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6

class ScalerConverter
{
    private:
		const std::string _input;
		int _type;
		char _char;
		int _int;
		float _float;
		double _double;

        ScalerConverter();

        void    convert(void);
        void    printout(void);
        int     check_input(void);

        void fromChar(void);
		void fromInt(void);
		void fromFloat(void);
		void fromDouble(void);

        std::string getInput(void)const;
		int getType(void)const;
		char getChar(void)const;
		int getInt(void)const;
		float getFloat(void)const;
		double getDouble(void)const;

    public:
        ScalerConverter(const std::string input);
        ScalerConverter(const ScalerConverter &copy);

        ~ScalerConverter();

        ScalerConverter &operator=(const ScalerConverter &copy);

        class Exception: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};