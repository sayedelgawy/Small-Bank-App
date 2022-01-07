#include "Employee.h"
int Employee::counter = Loading::loadLastId("employeeId.txt",2001);//get the last id from Loading Class or start from this arg

//constructor methods
Employee::Employee() {
	this->idOfEmployee = " ";
	this->name = " ";
	this->password = " ";
	this->salary = 0;
	
}
//using it when reading from database or text file to vector employees
Employee::Employee(string idOfEmployee, string name, string password, double salary){

	this->idOfEmployee = idOfEmployee;
	this->name = name;
	this->password = password;
	this->salary = salary;
}

//instanceEmployee Method-->the only method to instance unique employees 
void Employee::instanceEmployee(string name, string password, double salary) {

	counter++;
	this->idOfEmployee = "employee_" + to_string(counter);
	Loading::writeNewId("employeeId.txt", counter);

	Person::setName(name);
	setPassword(password);
	setSalary(salary);


}

//Setters methods
void Employee::setPassword(string password) {

	if (Validation::isSizeOk(password, 8 ,20) && Validation::isHaveWhiteSpace(password))
	{
		this->password = password;
	}
	else {
		if ((!Validation::isSizeOk(password, 8, 20)) && Validation::isHaveWhiteSpace(password)) {

			Validation::errorValidationMessage("Please Enter A Valid Password (Password must be 8 ~ 20 charcters Long)");
		}
		else {

			Validation::errorValidationMessage("Please Enter A Valid Password (Password Must has No White Space)");
		}
	}
}
void Employee::setSalary(double salary) {

	if (Validation::minValue(salary, 5000)) {

		this->salary = salary;

	}
	else {

		Validation::errorValidationMessage("Sorry The Minmum Salary is 5000");
	}
}

//Getters methods
string Employee::getPassword() {

	return password;
}
double Employee::getSalary() {

	return salary;
}
string Employee::getId() {

	return idOfEmployee;
}

//Diplay info method
void Employee::displayInfo() {

	cout << "Your Id is: " << idOfEmployee << endl;
	Person::displayInfo();
	cout << "Your Password is: " << password << endl;
	cout << "Your Salary is: " << salary << endl;

}


//valid employee method
bool Employee::isValid() {
	string name = this->name;
	string password = this->password;
	double salary = this->salary;

	if (Validation::isLetters(name) && Validation::isSizeOk(name, 5, 20) && Validation::isSizeOk(password, 8, 20) && Validation::isHaveWhiteSpace(password) && Validation::minValue(salary, 5000)) {
		return true;
	}
	else {
		return false;
	}
}