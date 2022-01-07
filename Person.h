#pragma once
#include "Validation.h"





class Person
{

protected:
	string name;
	

public:
	//constructor methods
	Person();
	Person(string name);
	

	//Setters methods
	void setName(string name);

	//Getters methods
	string getName();

	//Diplay info method
	virtual void displayInfo();


};

