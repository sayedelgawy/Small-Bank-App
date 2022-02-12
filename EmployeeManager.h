#pragma once
#include "FileManager.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<windows.h>


class EmployeeManager
{
protected:
	int indexOfEmployee;
	int indexOfClient;
	FileManager file;
	vector<Employee> arrayOfEmployee;
	vector<Client> arrayOfClients;

public:


	//Constructor
	EmployeeManager();


	//custom employee methods
	Employee* login(string id, string pass);

	void printEmployeeMenu();

	void displayEmployeeInfo();

	void updatePassword();


	//custom client methods
	void addNewClient();

	void searchForClient();

	void listAllClients();

	void editInfoOfClient();






	void logout();



};

