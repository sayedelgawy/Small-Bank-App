#include "Admin.h"

int Admin::counter = Loading::loadLastId("adminId.txt",3001);//get the last id from Loading Class or start from this arg

//constructor methods
Admin::Admin() {
	this->idOfAdmin = " ";
	this->name = " ";
	this->password = " ";
	this->salary = 0;
}
//using it when reading from database or text file to vector admin
Admin::Admin(string idOfAdmin, string name, string password, double salary) {

	this->idOfAdmin = idOfAdmin;
	this->name = name;
	this->password = password;
	this->salary = salary;

}

//instanceAdmin Method-->the only method to instance unique Admins 
void Admin::instanceAdmin(string name, string password, double salary) {

	counter++;
	this->idOfAdmin = "admin_" + to_string(counter);
	Loading::writeNewId("adminId.txt", counter);

	Person::setName(name);
	setPassword(password);
	setSalary(salary);

}

//getters
string Admin::getId() {

	return idOfAdmin;
}

//Diplay info method
void Admin::displayInfo() {

	cout << "Your Id is: " << idOfAdmin << endl;
	Person::displayInfo();
	cout << "Your Password is: " << password << endl;
	cout << "Your Salary is: " << salary << endl;

}
