#pragma once
#include <cmath>
#include <string>
#include <iostream>
#include <regex>
using namespace std;


class Validation
{
	
	public:
		//custom Methods
		static bool isLetters(string input);

		static bool isSizeOk(string input, int min, int max);

		static bool isSizeOk(string input, int min);

		static bool isDigits(string input);

		static bool minValue(double value, double min);

		static void errorValidationMessage(string message);

		static bool isHaveWhiteSpace(string input);

		static bool isNegative(double input);

};

