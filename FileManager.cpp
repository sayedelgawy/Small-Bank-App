#include "FileManager.h"



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

       
 
    }

    file.close();
    return arrayOfClients;
   
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

    }

    return arrayOfEmployee;
}
vector<Admin> FileManager::getAllAdmins() {
    
    vector<Admin> arrayOfAdmins;

    

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

            Admin newAdmin(objectData[0], objectData[1], objectData[2], stod(objectData[3]));
            
            arrayOfAdmins.push_back(newAdmin);

        }

        file.close();


    }
    return arrayOfAdmins;
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


//save all vectors
void FileManager::saveAllClients(vector<Client> &arrayOfClients) {

   
    

    

    ofstream fileTxt;

    fileTxt.open("Client.txt", ios::out);

    if (fileTxt.is_open())
    {
        for (int i = 0; i < arrayOfClients.size(); i++)
        {


            fileTxt << arrayOfClients[i].getId() << ";" << arrayOfClients[i].getName() << ";" << arrayOfClients[i].getPinCode() << ";" << arrayOfClients[i].getBalance() << "\n";

          

        }
    }
    else {

        cout << "Internal Error File Coudn't Open\n";
    }
   

    fileTxt.close();

    
}

void FileManager::saveAllEmployee(vector<Employee>& arrayOfEmployee) {

    ofstream fileTxt;

    fileTxt.open("Employee.txt", ios::out);

    if (fileTxt.is_open())
    {
        for (int i = 0; i < arrayOfEmployee.size(); i++)
        {


            fileTxt << arrayOfEmployee[i].getId() << ";" << arrayOfEmployee[i].getName() << ";" << arrayOfEmployee[i].getPassword() << ";" << arrayOfEmployee[i].getSalary() << "\n";



        }
    }
    else {

        cout << "Internal Error File Coudn't Open\n";
    }


    fileTxt.close();
}


void FileManager::saveAllAdmins(vector<Admin>& arrayOfAdmins) {

    ofstream fileTxt;

    fileTxt.open("Admin.txt", ios::out);

    if (fileTxt.is_open())
    {
        for (int i = 0; i < arrayOfAdmins.size(); i++)
        {


            fileTxt << arrayOfAdmins[i].getId() << ";" << arrayOfAdmins[i].getName() << ";" << arrayOfAdmins[i].getPassword() << ";" << arrayOfAdmins[i].getSalary() << "\n";



        }
    }
    else {

        cout << "Internal Error File Coudn't Open\n";
    }


    fileTxt.close();
}


