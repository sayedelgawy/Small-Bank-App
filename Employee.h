#pragma once
#include "Person.h"
#include "Loading.h"


class Employee : public Person
{
private:
	//counter
	static int counter;

	//attr
	string idOfEmployee;

protected:
	//attr
	string password;
	double salary;


public:
	//constructor methods
	Employee();
	//using it when reading from database or text file to vector employees
	Employee(string idOfEmployee,string name, string password, double salary);


	//instanceEmployee Method-->the only method to instance unique employees 
	void instanceEmployee(string name, string password, double salary);

	//Setters methods
	void setPassword(string password);
	void setSalary(double salary);

	//Getters methods
	string getPassword();
	double getSalary();
	virtual string getId();

	//Diplay info method
	virtual void displayInfo();

	void displayInfoForQuery();


	//valid employee method
	virtual bool isValid();
};

