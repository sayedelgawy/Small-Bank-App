#include "Currency.h"

//attr
int Currency::counter = Loading::loadLastId("currencyId.txt", 8000);//get the last id from Loading Class or start from this arg


//constructor methods
Currency::Currency() {
	this->idOfCurrency = " ";
	this->name = " ";
	this->value = -1;
}
//using it when reading from database or text file to vector currency
Currency::Currency(string idOfCurrency, string name, double value) {
	this->idOfCurrency = idOfCurrency;
	this->name = name;
	this->value = value;
}


//instanceCurrency Method-->the only method to instance unique currencies 
void Currency::instanceCurrency(string name, double value) {

	counter++;
	this->idOfCurrency = "currency_" + to_string(counter);
	Loading::writeNewId("currencyId.txt", counter);

	setName(name);
	setValue(value);
}


//Setter Methods
void Currency::setName(string name) {
	this->name = name;
}
void Currency::setValue(double value) {
	if (!Validation::isNegative(value))
	{
		this->value = value;
	}
	else {

		Validation::errorValidationMessage("Please Enter Positive Value");
	}
}


//Getter Methods
string Currency::getId() {

	return this->idOfCurrency;
}
string Currency::getName() {

	return name;
}
double Currency::getValue() {

	return value;
}

//Diplay info method
void Currency::displayInfo() {
	cout << "Currency Id is: " << idOfCurrency << endl;
	cout << "Currency Name is: " << name << endl;
	cout << "Your Value is: " << value << endl;
}

//valid Currency method
bool Currency::isValid() {

	double value = this->value;

	if (!Validation::isNegative(value)) {

		return true;
	}
	else {

		return false;
	}
}