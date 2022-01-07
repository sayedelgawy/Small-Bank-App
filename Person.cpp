#include "Person.h"

//constructor methods
Person::Person() {
	this->name = "Person";
	
}
Person::Person(string name) {
	this->name = name;
}


//Setters methods
void Person::setName(string name) {//name must be alphabetic chars and min size 5 and max size 20

	if (Validation::isLetters(name) && Validation::isSizeOk(name, 5, 20))
	{
		this->name = name;
	}
	else {
		if ((!Validation::isLetters(name)) && Validation::isSizeOk(name, 5, 20)) {

			Validation::errorValidationMessage("Please Enter A Valid Name (Name must be Letters Only)");
		}
		else {

			Validation::errorValidationMessage("Please Enter A Valid Name Size (Name must be Between 5 and 20 Charcters)");
		}
	}



}

//Getters methods
string Person::getName() {
	return name;
}

//Diplay info method
void Person::displayInfo() {
	cout <<"Your Name is: " << name << endl;
}




