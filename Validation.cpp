#include "Validation.h"


 //custom Methods
 bool Validation::isLetters(string input)//letters validation in string
{
	for (int i = 0; i < input.size(); i++)
	{

		if (!isalpha(input[i]))
		{

			return false;

		}
	}
	//At this point, we have gone through every character and checked it.
	return true; //Return true since every character had to be a-zA-Z
}

 bool Validation::isSizeOk(string input, int min, int max) //size validation of string min - max
 {
	 if (input.size() <= max && input.size() >= min) {

		 return true;
	 }
	 else {
		 return false;
	 }
 }

 bool Validation::isSizeOk(string input, int equal) //size validation of string equal only
 {
	 if (input.size() == equal) {

		 return true;
	 }
	 else {
		 return false;
	 }
 }

 bool Validation::isDigits(string input)//digits validation in string
 {

	 for (int i = 0; i < input.size(); i++)
	 {

		 if (!isdigit(input[i]))
		 {

			 return false;

		 }
	 }

	 return true;
 }

 bool Validation::minValue(double value, double min) {
	 if (value < min) {
		 return false;
	 }
	 else {
		 return true;
	 }
 }

 void Validation::errorValidationMessage(string message) {
	 cout << message << endl;
}

 bool Validation::isHaveWhiteSpace(string input) {

	 for (int i = 0; i < input.size(); i++)
	 {

		 if (input[i] == ' ')
		 {

			 return false;

		 }
	 }

	 return true;
 }

 bool Validation::isNegative(double input) {
	 if (input < 0) {

		 return true;
	 }
	 else {
		 return false;
	 }
  }



