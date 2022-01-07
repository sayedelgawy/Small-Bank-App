#pragma once
#include "Employee.h"
class Admin : public Employee
{
private:
	//counter
	static int counter;

	//attr
	string idOfAdmin;
public:
	//constructor methods
	Admin();
	//using it when reading from database or text file to vector admin
	Admin(string idOfAdmin ,string name, string password, double salary);
	

	//instanceAdmin Method-->the only method to instance unique Admins 
	void instanceAdmin(string name, string password, double salary);



	//Getters methods
	string getId();

	//Diplay info method
	void displayInfo();

};

