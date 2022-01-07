#include "Client.h"


int Client::counter = Loading::loadLastId("clientId.txt",1001);//get the last id from Loading Class or start from this arg

//constructor methods
Client::Client() {

	this->idOfClient = " ";
	this->name = " ";
	this->pinCode = " ";
	this->balance = 0;

}

//using it when reading from database or text file to vector clients
Client::Client(string idOfClient, string name , string pinCode, double balance) {

	this->idOfClient = idOfClient;
	this->name = name;
	this->pinCode = pinCode;
	this->balance = balance;
	

}

//instanceClient Method-->the only method to instance unique clients 
void Client::instanceClient(string name, string pinCode, double balance) {

	counter++;
	this->idOfClient = "client_" + to_string(counter);
	Loading::writeNewId("clientId.txt", counter);

	Person::setName(name);
	setPinCode(pinCode);
	setBalance(balance);
	

}




//Setters methods
void Client::setPinCode(string pinCode) {//pinCode must be digits chars and the size = 4

	if (Validation::isDigits(pinCode) && Validation::isSizeOk(pinCode, 4))
	{
		this->pinCode = pinCode;
		
	}else {

		if ( (!Validation::isDigits(pinCode)) && Validation::isSizeOk(pinCode, 4) ) {

			Validation::errorValidationMessage("Please Enter A Valid pinCode (pinCode must be Digits Only)");
		}
		else {

			Validation::errorValidationMessage("Please Enter A Valid pinCode Size (Name must be 4 Charcters only)");
		}
	}
	
	
}
void Client::setBalance(double balance) {//	Min balance is 1500

	if (Validation::minValue(balance, 1500)) {

		this->balance = balance;

	}else {

		Validation::errorValidationMessage("Sorry You Can't Deposit Less Than 1500");
	}
	
	

}


//Getters methods
string Client::getPinCode() {
	return pinCode;
}
double Client::getBalance() {
	return balance;
}
string Client::getId() {

	return idOfClient;
}


//Diplay info method
void Client::displayInfo() {
	cout << "Your Id is: " << idOfClient << endl;
	Person::displayInfo();
	cout << "Your Pin Code is: " << pinCode << endl;
	cout << "Your Balance is: " << balance << endl;
}


//valid client method
bool Client::isValid() {

	string name = this->name;
	string pinCode = this->pinCode;
	double balance = this->balance;

	if (Validation::isLetters(name) && Validation::isSizeOk(name, 5, 20) && Validation::isDigits(pinCode) && Validation::isSizeOk(pinCode, 4) && Validation::minValue(balance, 1500)) {
		
		return true;
	}
	else {
		return false;
	}

}