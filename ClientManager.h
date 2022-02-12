#pragma once
#include "FileManager.h"
#include <iostream>
#include <string>
#include <algorithm>
#include<windows.h>



class ClientManager
{
private:
	int indexOfClient;
	FileManager file;
	vector<Client> arrayOfClients;

public:
	

	//Constructor
	ClientManager();

	
	//custom methods
	Client* login(string id, string pass);

	void printClientMenu();

	void displayClientInfo();

	void updatePinCode();

	void withdraw();

	void deposit();

	void transfer();

	void logout();



};

