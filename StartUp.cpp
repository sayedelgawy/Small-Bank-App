#include "StartUp.h"

void StartUp::startProgram() {

	int counter{ 0 };
	
	do
	{
		system("CLS");
		string id, pass;

		
		cout << "\n----------------------------------------------------------------------------\n";
		cout << "\n--------------------------Welcome To World Wide Bank------------------------\n";
		cout << "\n----------------------------------------------------------------------------\n";
		cout << "\n--------------------------Your Gate To the new World------------------------\n";
		cout << "\n----------------------------------------------------------------------------\n";
		cout << "\n----------------------------------------------------------------------------\n";
		
		

		cout << "Please, enter your Id: ";
		getline(cin, id);
		cout << "Please, enter your Password: ";
		getline(cin, pass);
		

		if (id[0] == 'c')
		{
			ClientManager c;

			Client* client = c.login(id, pass);


			if (client != nullptr)
			{
				system("CLS");

				cout << "\nLogin successful\n";

				cout << "\nHi " << client->getName() << " ! We Are Glade To See You !" << endl;

				Sleep(2000);

				int number;

				do
				{
					
					c.printClientMenu();

					cout << "\nYour Choice: ";

					cin >> number;

					cout << "\n";
					switch (number)
					{
					case 1:						
						c.displayClientInfo();
						break;
					case 2:						
						c.updatePinCode();						
						break;
					case 3:					
						c.withdraw();
						break;
					case 4:
						c.deposit();
						break;
					case 5:
						c.transfer();
						break;
					case 0:
						c.logout();
						break;
					default:
						system("CLS");
						cout << "\nPlease Enter A valid Choice\n";
						Sleep(2000);
					}

				} while (number != 0);
				
				
				counter = 4;
				
			}
			else {

				system("CLS");
				counter++;

				
				cout << "No Match Please, enter a valid credentials \n";
				cout << "You Have (" << 3 - counter << ") remaining try\n";
				Sleep(2000);
			}


		}
		else if (id[0] == 'e') {

			EmployeeManager e;

			Employee* employee = e.login(id, pass);


			if (employee != nullptr)
			{
				system("CLS");

				cout << "\nLogin successful\n";

				cout << "\nHi " << employee->getName() << " ! We Are Glade To See You !" << endl;

				Sleep(2000);

				int number;

				do
				{

					e.printEmployeeMenu();

					cout << "\nYour Choice: ";

					cin >> number;

					cout << "\n";
					switch (number)
					{
					case 1:
						e.displayEmployeeInfo();
						break;
					case 2:
						e.updatePassword();
						break;
					case 3:
						e.addNewClient();
						break;
					case 4:
						e.searchForClient();
						break;
					case 5:
						e.listAllClients();
						break;
					case 6:
						e.editInfoOfClient();
						break;
					case 0:
						e.logout();
						break;
					default:
						system("CLS");
						cout << "\nPlease Enter A valid Choice\n";
						Sleep(2000);
					}

				} while (number != 0);


				counter = 4;

			}
			else {

				system("CLS");
				counter++;

				
				cout << "No Match Please, enter a valid credentials \n";
				cout << "You Have (" << 3 - counter << ") remaining try\n";
				Sleep(2000);
			}
		}
		else if (id[0] == 'a') {


		AdminManager a;

		Admin* admin = a.login(id, pass);


		if (admin != nullptr)
		{
			system("CLS");

			cout << "\nLogin successful\n";

			cout << "\nHi " << admin->getName() << " ! We Are Glade To See You !" << endl;

			Sleep(2000);

			int number;

			do
			{

				a.printAdminMenu();

				cout << "\nYour Choice: ";

				cin >> number;

				cout << "\n";
				switch (number)
				{
				case 1:
					a.displayAdminInfo();
					break;
				case 2:
					a.updatePassword();
					break;
				case 3:
					a.addNewEmployee();
					break;
				case 4:
					a.searchForEmployee();
					break;
				case 5:
					a.listAllEmployee();
					break;
				case 6:
					a.editInfoOfEmployee();
					break;
				case 7:
					a.addNewClient();
					break;
				case 8:
					a.searchForClient();
					break;
				case 9:
					a.listAllClients();
					break;
				case 10:
					a.editInfoOfClient();
					break;
				case 0:
					a.logout();
					break;
				default:
					system("CLS");
					cout << "\nPlease Enter A valid Choice\n";
					Sleep(2000);
				}

			} while (number != 0);


			counter = 4;

		}
		else {

			system("CLS");
			counter++;


			cout << "No Match Please, enter a valid credentials \n";
			cout << "You Have (" << 3 - counter << ") remaining try\n";
			Sleep(2000);
		}
		}
		else {

			system("CLS");
			counter++;
			cout << "You Have (" << 3 - counter << ") remaining try\n";
			cout << "Please, enter a valid credentials\n";
			Sleep(2000);

		}



	} while (counter < 3);
	
	
	
	
}
