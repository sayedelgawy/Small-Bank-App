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



	//Getters Methods
	vector<Client> getAllClients();
	vector<Employee> getAllEmployee();
	vector<Admin> getAllAdmins();


	//Deleting Methods
	void removeAllClients();
	void removeAllEmployee();
	void removeAllAdmins();
	


	//save all vectors
	void saveAllClients(vector<Client> &arrayOfClients);

	void saveAllEmployee(vector<Employee> &arrayOfEmployee);

	void saveAllAdmins(vector<Admin> &arrayOfAdmins);

	

	 

};

