#include <iostream>
#include "Client.h"
#include"Person.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"

using namespace std;



int main()
{
	

	Client c;
	c.instanceClient("sayed","1234",2000);//instance client with unique Id
	

	FileManager f;
	f.addClient(c);//add that client to database (Client.txt)
	

	if (f.getAllClients().size() > 0)
	{
		f.getAllClients().back().displayInfo();//Display the last client info after loading data from database(Client.txt)
	}
	else {

		cout << "no Data yet";
	}
	

	
	


	

	
	



	////Client c1("syaed", "1234", 5000);
	////Client c2("ahmed", "1234", 5000);

	//FileManager f1;
	////f1.addClient(c1);
	////f1.addClient(c2);

	//

	//cout << f1.test();



	

	

	

	

	
}


