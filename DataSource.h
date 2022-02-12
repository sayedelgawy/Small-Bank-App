#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"


class DataSource
{
public:
	//Adding methods
	virtual void addClient(Client client) = 0;
	virtual void addEmployee(Employee employee) = 0;
	virtual void addAdmin(Admin admin) = 0;
	

	//Getters Methods
	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee> getAllEmployee() = 0;
	virtual vector<Admin> getAllAdmins() = 0;


	//Deleting Methods
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployee() = 0;
	virtual void removeAllAdmins() = 0;
	

	

};

