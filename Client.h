#pragma once
#include "Person.h"
#include "Loading.h"



class Client:public Person
{
private:
	//counter
	static int counter;

	//attr
	string idOfClient;
	string pinCode;
	double balance;
	
	
	

public:
	
	//constructor methods
	Client();
	//using it when reading from database or text file to vector clients
	Client(string idOfClient, string name, string pinCode, double balance);
	

	//instanceClient Method-->the only method to instance unique clients 
	void instanceClient(string name, string pinCode, double balance);

	//Setters methods
	void setPinCode(string pinCode);
	void setBalance(double balance);
	

	//Getters methods
	string getPinCode();
	double getBalance();
	string getId();

	//Diplay info method
	void displayInfo();
	void displayInfoForQuery();

	//valid client method
	bool isValid();

	//banking methods
	void withdraw(double amount);

	void deposit(double amount);

	void transferTo(double amount,Client &client);


};

