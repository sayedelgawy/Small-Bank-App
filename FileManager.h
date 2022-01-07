#pragma once
#include "DataSource.h"
#include "Loading.h"
#include <fstream>
#include <iostream>

class FileManager : public DataSource
{

public:
	//Adding methods
	void addClient(Client client);
	void addEmployee(Employee employee);
	void addAdmin(Admin admin);
	void addCurrency(Currency currency);


	//Getters Methods
	vector<Client> getAllClients();
	vector<Employee> getAllEmployee();
	vector<Employee*> getAllAdmins();
	vector<Currency> getAllCurrency();


	////Deleting Methods
	void removeAllClients();
	void removeAllEmployee();
	void removeAllAdmins();
	void removeAllCurrencies();


	

	 

};

