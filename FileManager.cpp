#include "FileManager.h"
#include "Loading.h"


//Adding methods
void FileManager::addClient(Client client) {

    if (client.isValid()) {

        ofstream file;
        file.open("Client.txt", ios::app);
        file << client.getId() << ";" << client.getName() << ";" << client.getPinCode() << ";" << client.getBalance() << "\n";
        file.close();
    }
    else {

        cout << "Invalid Inputs\n";
    }
    

};
void FileManager::addEmployee(Employee employee) {

    if (employee.isValid())
    {
        ofstream file;
        file.open("Employee.txt", ios::app);
        file << employee.getId() << ";" << employee.getName() << ";" << employee.getPassword() << ";" << employee.getSalary() << "\n";
        file.close();
    }
    else {

        cout << "Invalid Inputs\n";
    }
   
}
void FileManager::addAdmin(Admin admin) {

    if (admin.isValid()) {

        ofstream file;
        file.open("Admin.txt", ios::app);
        file << admin.getId() << ";" << admin.getName() << ";" << admin.getPassword() << ";" << admin.getSalary() << "\n";
        file.close();
    }
    else {

        cout << "Invalid Inputs\n";
    }
    
}
void FileManager::addCurrency(Currency currency) {
    if (currency.isValid())
    {
        ofstream file;
        file.open("Currency.txt", ios::app);
        file << currency.getId() << ";" << currency.getName() << ";" << currency.getValue() << "\n";
        file.close();
    }
    else {

        cout << "Invalid Inputs\n";
    }
}


//Getters Methods
vector<Client> FileManager::getAllClients() {

    vector<Client> arrayOfClients;

    ifstream file;

    file.open("Client.txt", ios::in);

    if (file.is_open())
    {

        string line;

        while (getline(file, line)) {

            vector<string> objectData;

            string currentInfo = "";
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ';') {
                    objectData.push_back(currentInfo);
                    currentInfo = "";
                }
                else {

                    currentInfo += line[i];
                }
            }
            objectData.push_back(currentInfo);

          

            Client newClient(objectData[0], objectData[1], objectData[2], stod(objectData[3]));

            arrayOfClients.push_back(newClient);
        }

        file.close();


        return arrayOfClients;

    }
   
}
vector<Employee> FileManager::getAllEmployee() {

    vector<Employee> arrayOfEmployee;

    ifstream file;

    file.open("Employee.txt", ios::in);

    if (file.is_open())
    {

        string line;

        while (getline(file, line)) {

            vector<string> objectData;

            string currentInfo = "";
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ';') {
                    objectData.push_back(currentInfo);
                    currentInfo = "";
                }
                else {

                    currentInfo += line[i];
                }
            }
            objectData.push_back(currentInfo);



            Employee newEmployee(objectData[0], objectData[1], objectData[2], stod(objectData[3]));

            arrayOfEmployee.push_back(newEmployee);
        }

        file.close();


        return arrayOfEmployee;

    }
}
vector<Employee*> FileManager::getAllAdmins() {
    
    vector<Employee*> arrayOfAdmins;

    

    ifstream file;

    file.open("Admin.txt", ios::in);

    if (file.is_open())
    {

        string line;

        while (getline(file, line)) {

            vector<string> objectData;

            string currentInfo = "";
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ';') {
                    objectData.push_back(currentInfo);
                    currentInfo = "";
                }
                else {

                    currentInfo += line[i];
                }
            }
            objectData.push_back(currentInfo);


            arrayOfAdmins.push_back(new Admin(objectData[0], objectData[1], objectData[2], stod(objectData[3])));

        }

        file.close();


        return arrayOfAdmins;

    }
}
vector<Currency> FileManager::getAllCurrency() {

    vector<Currency> arrayOfCurrencies;

    ifstream file;

    file.open("Currency.txt", ios::in);

    if (file.is_open())
    {

        string line;

        while (getline(file, line)) {

            vector<string> objectData;

            string currentInfo = "";
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ';') {
                    objectData.push_back(currentInfo);
                    currentInfo = "";
                }
                else {

                    currentInfo += line[i];
                }
            }
            objectData.push_back(currentInfo);



            Currency newCurrency(objectData[0], objectData[1],stod(objectData[2]));

            arrayOfCurrencies.push_back(newCurrency);
        }

        file.close();


        return arrayOfCurrencies;

    }

}


//Deleting Methods
void FileManager::removeAllClients() {

    ofstream file;
    file.open("Client.txt", ofstream::out | ofstream::trunc);
    file.close();

}
void FileManager::removeAllEmployee() {

    ofstream file;
    file.open("Employee.txt", ofstream::out | ofstream::trunc);
    file.close();

}
void FileManager::removeAllAdmins() {

    ofstream file;
    file.open("Admin.txt", ofstream::out | ofstream::trunc);
    file.close();

}
void FileManager::removeAllCurrencies() {

    ofstream file;
    file.open("Currency.txt", ofstream::out | ofstream::trunc);
    file.close();

 }






