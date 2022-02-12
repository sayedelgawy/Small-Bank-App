#pragma once
#include "FileManager.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<windows.h>

class AdminManager
{
protected:
	int indexOfAdmin;
	int indexOfEmployee;
	int indexOfClient;
	FileManager file;
	vector<Employee> arrayOfEmployee;
	vector<Client> arrayOfClients;
	vector<Admin> arrayOfAdmins;

public:


	//Constructor
	AdminManager();


	//custom methods of admin
	Admin* login(string id, string pass);

	void printAdminMenu();

	void displayAdminInfo();

	void updatePassword();


	//custom methods of employee
	void addNewEmployee();

	void searchForEmployee();

	void listAllEmployee();

	void editInfoOfEmployee();




	//custom methods of client
	void addNewClient();

	void searchForClient();

	void listAllClients();

	void editInfoOfClient();




	void logout();



};

