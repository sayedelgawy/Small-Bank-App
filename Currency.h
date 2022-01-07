#pragma once
#include "Validation.h"
#include "Loading.h"


class Currency
{
private:
	//counter
	static int counter;

	//attr
	string name;
	string idOfCurrency;
	double value;

public:
	//constructor methods
	Currency();
	//using it when reading from database or text file to vector currency
	Currency(string idOfCurrency, string name, double value);


	//instanceCurrency Method-->the only method to instance unique currencies 
	void instanceCurrency(string name, double value);


	//Setter Methods
	void setName(string name);
	void setValue(double value);

	//Getter Methods
	string getId();
	string getName();
	double getValue();


	//Diplay info method
	void displayInfo();


	//valid Currency method
	bool isValid();
};


