#include "AdminManager.h"


//Constructor
AdminManager::AdminManager() {
   
    this->indexOfClient = -1;
    this->indexOfEmployee = -1;
    this->arrayOfAdmins = this->file.getAllAdmins();
}


//custom Admin methods
Admin* AdminManager::login(string id, string pass){

    Admin* admin;

    for (int i = 0; i < arrayOfAdmins.size(); i++)
    {
        if (arrayOfAdmins[i].getId() == id)
        {
            if (arrayOfAdmins[i].getPassword() != pass)
            {
                cout << "Password Is Wrong\n";

                return nullptr;
            }
            else {

                admin = new Admin(arrayOfAdmins[i].getId(), arrayOfAdmins[i].getName(), arrayOfAdmins[i].getPassword(), arrayOfAdmins[i].getSalary());

                this->indexOfAdmin = i;

                return admin;

            }


        }

    }
    cout << "No Match\n";
    return nullptr;
}

void AdminManager::printAdminMenu(){
    system("CLS");
    cout << "\nPlaese Choose From The Following\n\n1 - display my Info\n2 - update my Password\n\n";
    cout << "3 - add new Employee\n4 - search for Employee\n5 - list all Employee\n6 - edit or Delete info of Employee\n\n";
    cout << "7 - add new Client\n8 - search for client\n9 - list all clients\n10 - edit or Delete info of client\n\n0 - logout\n";
}

void AdminManager::displayAdminInfo(){
    system("CLS");
    string choice;
    int counter{ 0 };


    cin.ignore();

    this->arrayOfAdmins[indexOfAdmin].displayInfo();

    do
    {


        cout << "\nEnter 0 to go back\n";
        cout << "Your input: ";

        getline(cin, choice);

        if (choice == "0")
        {

            counter = 4;

        }
        else {

            system("CLS");

            this->arrayOfAdmins[indexOfAdmin].displayInfo();

            counter++;
            cout << "\nPlease Enter 0 To Go back or you will be directed after";
            cout << " (" << 3 - counter << ") invalid inputs\n";

        }


    } while (counter < 3);
}

void AdminManager::updatePassword(){

    system("CLS");
    string password;
    int counter{ 0 };


    cin.ignore();

    do
    {
        system("CLS");
        cout << "\nPlease Enter a New Password (8~20 char and no whiteSpace)\n\nor Enter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, password);

        if (Validation::isSizeOk(password, 8, 20) && Validation::isHaveWhiteSpace(password))
        {

            arrayOfAdmins[indexOfAdmin].setPassword(password);

            this->file.saveAllAdmins(arrayOfAdmins);

            system("CLS");
            cout << "\nPassword Updated Successfully\n";
            Sleep(2000);
            counter = 4;
        }
        else if (password == "0") {

            counter = 4;
        }
        else {

            system("CLS");
            counter++;
            cout << "\nPassword Must be between 4 to 8 charcters and have no whiteSpace\n";
            cout << "You Have (" << 3 - counter << ") remaining try\n";
            Sleep(2000);



        }

    } while (counter < 3);

}


//custom methods of employee
void AdminManager::addNewEmployee() {
    system("CLS");

    string name, password, salary;


    int counter{ 0 };

    cin.ignore();

    do
    {
        system("CLS");
        cout << "\nPlease Enter the name (Letters Only & 5~20 char) of the Employee\n\nor Enter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, name);


        if (Validation::isLetters(name) && Validation::isSizeOk(name, 5, 20))
        {
            system("CLS");
            cout << "\nName Accepted\n";
            Sleep(1000);
            int pinCounter = 0;

            do
            {

                system("CLS");
                cout << "\nPlease Enter a password (must be 8 ~ 20 charcters Long and no whitespace)\n\nor Enter 0 to go back\n\n";
                cout << "Your input: ";

                getline(cin, password);

                if (Validation::isHaveWhiteSpace(password) && Validation::isSizeOk(password, 8, 20)) {

                    system("CLS");
                    cout << "\nPassword Accepted\n";
                    Sleep(1000);

                    int balanceCounter = 0;


                    do
                    {
                        system("CLS");
                        cout << "\nPlease put A salary (salary >= 5000) To The Employee\n\nor Enter 0 to go back\n\n";
                        cout << "Your input: ";

                        getline(cin, salary);

                        if (Validation::isDigits(salary))
                        {
                            double amount = stod(salary);

                            if (Validation::minValue(amount, 5000))
                            {
                                Employee newEmployee;

                                newEmployee.instanceEmployee(name, password, amount);

                                this->file.addEmployee(newEmployee);

                                system("CLS");
                                cout << "\nEmployee Added Succefully\n";
                                Sleep(2000);
                                break;
                            }
                            else {
                                system("CLS");
                                cout << "\nSorry You Can't put salary Less Than 5000\n";
                                balanceCounter++;
                                cout << "You Have (" << 3 - balanceCounter << ") remaining try\n";
                                Sleep(2000);
                            }

                        }
                        else {

                            system("CLS");
                            cout << "\nPlease enter A Valid Value\n";
                            balanceCounter++;
                            cout << "You Have (" << 3 - balanceCounter << ") remaining try\n";
                            Sleep(2000);

                        }


                    } while (balanceCounter < 3);
                    break;
                }
                else if (password == "0") {

                    break;

                }
                else {

                    system("CLS");
                    pinCounter++;
                    cout << "\nPlease Enter A password (It must be 8 ~ 20 charcters Long and no whitespace)\n";
                    cout << "You Have (" << 3 - pinCounter << ") remaining try\n";
                    Sleep(2000);
                }

            } while (pinCounter < 3);

            break;

        }
        else if (name == "0") {

            break;

        }
        else {

            if ((!Validation::isLetters(name)) && Validation::isSizeOk(name, 5, 20)) {

                system("CLS");
                counter++;
                cout << "\nPlease Enter A Valid Name (Name must be Letters Only)\n";
                cout << "You Have (" << 3 - counter << ") remaining try\n";
                Sleep(2000);
            }
            else {

                system("CLS");
                counter++;
                cout << "\nPlease Enter A Valid Name Size (Name must be Between 5 and 20 Charcters)\n";
                cout << "You Have (" << 3 - counter << ") remaining try\n";
                Sleep(2000);

            }
        }



    } while (counter < 3);
}

void AdminManager::searchForEmployee() {

    this->arrayOfEmployee = this->file.getAllEmployee();
    system("CLS");
    string employeeId;
    int counter{ 0 };

    cin.ignore();
    do
    {

        system("CLS");
        cout << "\nPlease Enter The Id of The Employee\n\nor Enter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, employeeId);

        if (employeeId == "0")
        {
            counter = 4;
        }
        else {

            for (int i = 0; i < arrayOfEmployee.size(); i++)
            {
                if (arrayOfEmployee[i].getId() == employeeId)
                {

                    this->indexOfEmployee = i;
                    break;
                }

            }

            if (indexOfEmployee != -1)
            {

                string freezeScreenChoice;
                int freezeScreenChoiceCount{ 0 };
                do
                {
                    system("CLS");
                    cout << "================= Account Info ================\n\n";
                    arrayOfEmployee[indexOfEmployee].displayInfoForQuery();
                    cout << "\n================================================\n";

                    cout << "\n\nEnter 0 to go back\n\n";
                    cout << "Your input: ";

                    getline(cin, freezeScreenChoice);

                    if (freezeScreenChoice == "0")
                    {
                        break;
                    }
                    else {

                        system("CLS");
                        cout << "================= Account Info ================\n\n";
                        arrayOfEmployee[indexOfEmployee].displayInfoForQuery();
                        cout << "\n================================================\n";

                        freezeScreenChoiceCount++;
                        cout << "You Will be back after(" << 3 - freezeScreenChoiceCount << ") remaining invalid inputs \n";
                        Sleep(1000);
                    }

                } while (freezeScreenChoiceCount < 3);


                indexOfEmployee = -1;

            }
            else {

                system("CLS");
                cout << "No Employee Match in Our Database\n";
                Sleep(2000);
                break;
            }



        }


    } while (counter < 3);
}

void  AdminManager::listAllEmployee(){

    this->arrayOfEmployee = this->file.getAllEmployee();
    cin.ignore();
    system("CLS");
    cout << "\n================ Employees List  ==============\n\n";
    for (int i = 0; i < arrayOfEmployee.size(); i++)
    {
        arrayOfEmployee[i].displayInfoForQuery();
        cout << "\n==========================================\n";
    }

    string freezeScreenChoice;
    int freezeScreenChoiceCount{ 0 };
    do
    {
        system("CLS");
        cout << "\n================ Accounts List  ==============\n\n";
        for (int i = 0; i < arrayOfEmployee.size(); i++)
        {
            arrayOfEmployee[i].displayInfoForQuery();
            cout << "\n==========================================\n";
        }
        cout << "\n\nEnter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, freezeScreenChoice);

        if (freezeScreenChoice == "0")
        {
            break;
        }
        else {

            system("CLS");
            cout << "\n================ Accounts List  ==============\n\n";
            for (int i = 0; i < arrayOfEmployee.size(); i++)
            {
                arrayOfEmployee[i].displayInfoForQuery();
                cout << "\n==========================================\n";
            }
            freezeScreenChoiceCount++;
            cout << "You Will be back after(" << 3 - freezeScreenChoiceCount << ") remaining invalid inputs \n";
            Sleep(2000);
        }

    } while (freezeScreenChoiceCount < 3);
}

void  AdminManager::editInfoOfEmployee(){

    this->arrayOfEmployee = this->file.getAllEmployee();
    system("CLS");
    string employeeId;
    int counter{ 0 };

    cin.ignore();
    do
    {

        system("CLS");
        cout << "\nPlease Enter The Id of The Employee\n\nor Enter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, employeeId);

        if (employeeId == "0")
        {
            counter = 4;
        }
        else {

            for (int i = 0; i < arrayOfEmployee.size(); i++)
            {
                if (arrayOfEmployee[i].getId() == employeeId)
                {

                    this->indexOfEmployee = i;
                    break;
                }

            }

            if (indexOfEmployee != -1)
            {


                string freezeScreenChoice;
                int freezeScreenChoiceCount{ 0 };
                do
                {
                    system("CLS");
                    cout << "================= Account Info ================\n\n";
                    arrayOfEmployee[indexOfEmployee].displayInfoForQuery();
                    cout << "\n================================================\n";


                    cout << "\n\nEnter 1 to edit name\n";
                    cout << "\nEnter 2 to edit his Salary\n";
                    cout << "\nEnter 3 to Delete the Employee\n";
                    cout << "\nEnter 0 to go back\n";
                    cout << "\nYour input: ";

                    getline(cin, freezeScreenChoice);

                    if (freezeScreenChoice == "0")
                    {
                        break;
                    }
                    else if (freezeScreenChoice == "1") {

                        string name;
                        int counter{ 0 };



                        do
                        {
                            system("CLS");
                            cout << "\nPlease Enter a new name or Enter 0 to go back\n";
                            cout << "Your input: ";

                            getline(cin, name);


                            if (name == "0") {

                                counter = 4;
                            }
                            else if (Validation::isLetters(name) && Validation::isSizeOk(name, 5, 20))
                            {

                                this->arrayOfEmployee[indexOfEmployee].setName(name);

                                this->file.saveAllEmployee(arrayOfEmployee);

                                system("CLS");
                                cout << "\nName Succefully Edited\n";
                                Sleep(2000);
                                counter = 4;

                            }
                            else {

                                system("CLS");
                                cout << "\nPlease enter A Valid credentials name must be letters and (5~20) charcters\n";
                                counter++;
                                cout << "You Have (" << 3 - counter << ") remaining try\n";
                                Sleep(2000);

                            }




                        } while (counter < 3);

                    }

                    else if (freezeScreenChoice == "2") {

                        string userAmount;
                        int counter{ 0 };



                        do
                        {
                            system("CLS");
                            cout << "\nPlease Enter a new Amount to Salary or Enter 0 to go back\n";
                            cout << "Your input: ";

                            getline(cin, userAmount);



                            if (Validation::isDigits(userAmount))
                            {
                                double amount = stod(userAmount);

                                if (amount == 0)
                                {

                                    counter = 4;

                                }
                                else if (amount < 0) {

                                    system("CLS");
                                    cout << "\nPlease enter Positive Value\n";
                                    counter++;
                                    cout << "You Have (" << 3 - counter << ") remaining try\n";
                                    Sleep(2000);

                                }
                                else if (amount < 5000) {
                                    system("CLS");
                                    cout << "\nMinmun Salary is 5000 be fair boss\n";
                                    counter++;
                                    cout << "You Have (" << 3 - counter << ") remaining try\n";
                                    Sleep(2000);
                                }
                                else {

                                    this->arrayOfEmployee[indexOfEmployee].setSalary(amount);

                                    this->file.saveAllEmployee(arrayOfEmployee);

                                    system("CLS");
                                    cout << "\nSalary Successfully Edited\n";
                                    Sleep(2000);
                                    counter = 4;

                                }
                            }
                            else {

                                system("CLS");
                                cout << "\nPlease enter A Valid Value\n";
                                counter++;
                                cout << "You Have (" << 3 - counter << ") remaining try\n";
                                Sleep(2000);

                            }




                        } while (counter < 3);

                    }

                    else if (freezeScreenChoice == "3") {
                        
                        string choice;
                        int counter{ 0 };



                        do
                            {
                                system("CLS");
                                cout << "\nAre You Sure To Delete This Employee Enter 1 to confirm or Enter 0 to go back\n";
                                cout << "\nYour input: ";

                                getline(cin, choice);



                                if (choice == "1")
                                {

                                    this->arrayOfEmployee.erase(arrayOfEmployee.begin() + indexOfEmployee);

                                    this->file.saveAllEmployee(arrayOfEmployee);

                                    system("CLS");
                                    cout << "\nEmployee Successfully Deleted\n";
                                    Sleep(2000);
                                    counter = 4;
                                }
                                else if (choice == "0") {
                                    break;
                                }
                                else {

                                    system("CLS");
                                    cout << "\nPlease enter A Valid Value\n";
                                    counter++;
                                    cout << "You Have (" << 3 - counter << ") remaining try\n";
                                    Sleep(2000);
                                   

                                }




                            } while (counter < 3);

                        break;
                    }
                    else {

                        system("CLS");
                        cout << "================= Account Info ================\n\n";
                        arrayOfEmployee[indexOfEmployee].displayInfoForQuery();
                        cout << "\n================================================\n";

                        freezeScreenChoiceCount++;
                        cout << "\nInvalid Input\n";
                        cout << "\nYou Will be dircted back after(" << 3 - freezeScreenChoiceCount << ") remaining invalid inputs \n";
                        Sleep(1000);
                    }

                } while (freezeScreenChoiceCount < 3);


                indexOfEmployee = -1;

            }
            else {

                system("CLS");
                cout << "No Employee Match in Our Database\n";
                Sleep(2000);
                break;
            }



        }


    } while (counter < 3);
}//



//custom methods of client
void AdminManager::addNewClient() {

    system("CLS");

    string name, pinCode, balance;


    int counter{ 0 };

    cin.ignore();

    do
    {
        system("CLS");
        cout << "\nPlease Enter the name(Letters Only & 5~20 char) of the Client\n\nor Enter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, name);


        if (Validation::isLetters(name) && Validation::isSizeOk(name, 5, 20))
        {
            system("CLS");
            cout << "\nName Accepted\n";
            Sleep(1000);
            int pinCounter = 0;

            do
            {

                system("CLS");
                cout << "\nPlease Enter a Pin Code (It must be Digits Only & 4 Char)\n\nor Enter 0 to go back\n\n";
                cout << "Your input: ";

                getline(cin, pinCode);

                if (Validation::isDigits(pinCode) && Validation::isSizeOk(pinCode, 4)) {

                    system("CLS");
                    cout << "\nPin Code Accepted\n";
                    Sleep(1000);

                    int balanceCounter = 0;


                    do
                    {
                        system("CLS");
                        cout << "\nPlease Make A Deposit (Deposit >= 1500) To Open The Account\n\nor Enter 0 to go back\n\n";
                        cout << "Your input: ";

                        getline(cin, balance);

                        if (Validation::isDigits(balance))
                        {
                            double amount = stod(balance);

                            if (Validation::minValue(amount, 1500))
                            {
                                Client newClient;
                                newClient.instanceClient(name, pinCode, amount);
                                this->file.addClient(newClient);
                                system("CLS");
                                cout << "\nClient Added Succefully\n";
                                Sleep(2000);
                                break;
                            }
                            else {
                                system("CLS");
                                cout << "\nSorry You Can't Deposit Less Than 1500\n";
                                balanceCounter++;
                                cout << "You Have (" << 3 - balanceCounter << ") remaining try\n";
                                Sleep(2000);
                            }

                        }
                        else {

                            system("CLS");
                            cout << "\nPlease enter A Valid Value\n";
                            balanceCounter++;
                            cout << "You Have (" << 3 - balanceCounter << ") remaining try\n";
                            Sleep(2000);

                        }


                    } while (balanceCounter < 3);
                    break;
                }
                else if (pinCode == "0") {

                    break;

                }
                else {

                    system("CLS");
                    pinCounter++;
                    cout << "\nPlease Enter A Valid Pin Code (It must be Digits Only & 4 Char)\n";
                    cout << "You Have (" << 3 - pinCounter << ") remaining try\n";
                    Sleep(2000);
                }

            } while (pinCounter < 3);

            break;

        }
        else if (name == "0") {

            break;

        }
        else {

            if ((!Validation::isLetters(name)) && Validation::isSizeOk(name, 5, 20)) {

                system("CLS");
                counter++;
                cout << "\nPlease Enter A Valid Name (Name must be Letters Only)\n";
                cout << "You Have (" << 3 - counter << ") remaining try\n";
                Sleep(2000);
            }
            else {

                system("CLS");
                counter++;
                cout << "\nPlease Enter A Valid Name Size (Name must be Between 5 and 20 Charcters)\n";
                cout << "You Have (" << 3 - counter << ") remaining try\n";
                Sleep(2000);

            }
        }



    } while (counter < 3);


}

void AdminManager::searchForClient() {

    this->arrayOfClients = this->file.getAllClients();
    system("CLS");
    string clientId;
    int counter{ 0 };

    cin.ignore();
    do
    {

        system("CLS");
        cout << "\nPlease Enter The Id of The Client\n\nor Enter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, clientId);

        if (clientId == "0")
        {
            counter = 4;
        }
        else {

            for (int i = 0; i < arrayOfClients.size(); i++)
            {
                if (arrayOfClients[i].getId() == clientId)
                {

                    this->indexOfClient = i;
                    break;
                }

            }

            if (indexOfClient != -1)
            {

                string freezeScreenChoice;
                int freezeScreenChoiceCount{ 0 };
                do
                {
                    system("CLS");
                    cout << "================= Account Info ================\n\n";
                    arrayOfClients[indexOfClient].displayInfoForQuery();
                    cout << "\n================================================\n";

                    cout << "\n\nEnter 0 to go back\n\n";
                    cout << "Your input: ";

                    getline(cin, freezeScreenChoice);

                    if (freezeScreenChoice == "0")
                    {
                        break;
                    }
                    else {

                        system("CLS");
                        cout << "================= Account Info ================\n\n";
                        arrayOfClients[indexOfClient].displayInfoForQuery();
                        cout << "\n================================================\n";

                        freezeScreenChoiceCount++;
                        cout << "You Will be back after(" << 3 - freezeScreenChoiceCount << ") remaining invalid inputs \n";
                        Sleep(1000);
                    }

                } while (freezeScreenChoiceCount < 3);


                indexOfClient = -1;

            }
            else {

                system("CLS");
                cout << "No Client Match in Our Database\n";
                Sleep(2000);
                break;
            }



        }


    } while (counter < 3);

}

void AdminManager::listAllClients() {

    this->arrayOfClients = this->file.getAllClients();
    cin.ignore();
    system("CLS");
    cout << "\n================ Accounts List  ==============\n\n";
    for (int i = 0; i < arrayOfClients.size(); i++)
    {
        arrayOfClients[i].displayInfoForQuery();
        cout << "\n==========================================\n";
    }

    string freezeScreenChoice;
    int freezeScreenChoiceCount{ 0 };
    do
    {
        system("CLS");
        cout << "\n================ Accounts List  ==============\n\n";
        for (int i = 0; i < arrayOfClients.size(); i++)
        {
            arrayOfClients[i].displayInfoForQuery();
            cout << "\n==========================================\n";
        }
        cout << "\n\nEnter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, freezeScreenChoice);

        if (freezeScreenChoice == "0")
        {
            break;
        }
        else {

            system("CLS");
            cout << "\n================ Accounts List  ==============\n\n";
            for (int i = 0; i < arrayOfClients.size(); i++)
            {
                arrayOfClients[i].displayInfoForQuery();
                cout << "\n==========================================\n";
            }
            freezeScreenChoiceCount++;
            cout << "You Will be back after(" << 3 - freezeScreenChoiceCount << ") remaining invalid inputs \n";
            Sleep(2000);
        }

    } while (freezeScreenChoiceCount < 3);



}

void AdminManager::editInfoOfClient() {

    this->arrayOfClients = this->file.getAllClients();
    system("CLS");
    string clientId;
    int counter{ 0 };

    cin.ignore();
    do
    {

        system("CLS");
        cout << "\nPlease Enter The Id of The Client\n\nor Enter 0 to go back\n\n";
        cout << "Your input: ";

        getline(cin, clientId);

        if (clientId == "0")
        {
            counter = 4;
        }
        else {

            for (int i = 0; i < arrayOfClients.size(); i++)
            {
                if (arrayOfClients[i].getId() == clientId)
                {

                    this->indexOfClient = i;
                    break;
                }

            }

            if (indexOfClient != -1)
            {


                string freezeScreenChoice;
                int freezeScreenChoiceCount{ 0 };
                do
                {
                    system("CLS");
                    cout << "================= Account Info ================\n\n";
                    arrayOfClients[indexOfClient].displayInfoForQuery();
                    cout << "\n================================================\n";


                    cout << "\n\nEnter 1 to edit name\n";
                    cout << "\nEnter 2 to cash out\n";
                    cout << "\nEnter 3 to cash in\n";
                    cout << "\nEnter 4 to transfere money to another account\n";
                    cout << "\nEnter 5 to Delete or close the Account\n";
                    cout << "\nEnter 0 to go back\n";
                    cout << "Your input: ";

                    getline(cin, freezeScreenChoice);

                    if (freezeScreenChoice == "0")
                    {
                        break;
                    }
                    else if (freezeScreenChoice == "1") {

                        string name;
                        int counter{ 0 };



                        do
                        {
                            system("CLS");
                            cout << "\nPlease Enter a new name or Enter 0 to go back\n";
                            cout << "Your input: ";

                            getline(cin, name);


                            if (name == "0") {

                                counter = 4;
                            }
                            else if (Validation::isLetters(name) && Validation::isSizeOk(name, 5, 20))
                            {

                                this->arrayOfClients[indexOfClient].setName(name);

                                this->file.saveAllClients(arrayOfClients);

                                system("CLS");
                                cout << "\nName Succefully Edited\n";
                                Sleep(2000);
                                counter = 4;

                            }
                            else {

                                system("CLS");
                                cout << "\nPlease enter A Valid credentials name must be letters and (5~20) charcters\n";
                                counter++;
                                cout << "You Have (" << 3 - counter << ") remaining try\n";
                                Sleep(2000);

                            }




                        } while (counter < 3);

                    }
                    else if (freezeScreenChoice == "2") {

                        string userAmount;
                        int counter{ 0 };



                        do
                        {
                            system("CLS");
                            cout << "\nPlease Enter an Amount to Withdraw or Enter 0 to go back\n";
                            cout << "Your input: ";

                            getline(cin, userAmount);



                            if (Validation::isDigits(userAmount))
                            {
                                double amount = stod(userAmount);

                                if (amount == 0)
                                {

                                    counter = 4;

                                }
                                else if (amount < 0) {

                                    system("CLS");
                                    cout << "\nPlease enter Positive Value\n";
                                    counter++;
                                    cout << "You Have (" << 3 - counter << ") remaining try\n";
                                    Sleep(2000);

                                }
                                else {

                                    this->arrayOfClients[indexOfClient].withdraw(amount);

                                    this->file.saveAllClients(arrayOfClients);

                                    system("CLS");
                                    cout << "\nSuccessful Transaction\n";
                                    Sleep(2000);
                                    counter = 4;

                                }
                            }
                            else {

                                system("CLS");
                                cout << "\nPlease enter A Valid Value\n";
                                counter++;
                                cout << "You Have (" << 3 - counter << ") remaining try\n";
                                Sleep(2000);

                            }




                        } while (counter < 3);

                    }
                    else if (freezeScreenChoice == "3") {
                        string userAmount;
                        int counter{ 0 };



                        do
                        {
                            system("CLS");
                            cout << "\nPlease Enter an Amount to Deposit or Enter 0 to go back\n";
                            cout << "Your input: ";

                            getline(cin, userAmount);



                            if (Validation::isDigits(userAmount))
                            {
                                double amount = stod(userAmount);

                                if (amount == 0)
                                {

                                    counter = 4;

                                }
                                else if (amount < 0) {

                                    system("CLS");
                                    cout << "\nPlease enter Positive Value\n";
                                    counter++;
                                    cout << "You Have (" << 3 - counter << ") remaining try\n";
                                    Sleep(2000);

                                }
                                else {

                                    this->arrayOfClients[indexOfClient].deposit(amount);

                                    this->file.saveAllClients(arrayOfClients);

                                    system("CLS");
                                    cout << "\nSuccessful Transaction\n";
                                    Sleep(2000);
                                    counter = 4;

                                }
                            }
                            else {

                                system("CLS");
                                cout << "\nPlease enter A Valid Value\n";
                                counter++;
                                cout << "You Have (" << 3 - counter << ") remaining try\n";
                                Sleep(2000);

                            }




                        } while (counter < 3);

                    }
                    else if (freezeScreenChoice == "4") {
                        string userAmount, receiptId;

                        int indexOfReceiptClient = -1;

                        int counter{ 0 };



                        do {
                            system("CLS");
                            cout << "\nPlease Enter The Id Account You Want To Send The Money To or Enter 0 to go back\n";
                            cout << "Your input: ";

                            getline(cin, receiptId);

                            if (receiptId == "0")
                            {
                                counter = 4;
                            }
                            else {

                                for (int i = 0; i < arrayOfClients.size(); i++)
                                {
                                    if (arrayOfClients[i].getId() == receiptId) {

                                        indexOfReceiptClient = i;

                                        break;



                                    }
                                }

                                if (indexOfReceiptClient != -1 && indexOfReceiptClient != indexOfClient)
                                {
                                    system("CLS");
                                    cout << "\nPlease Enter An amount to transfere Or Enter 0 to go back\n";
                                    cout << "Your input: ";

                                    getline(cin, userAmount);

                                    if (Validation::isDigits(userAmount))
                                    {
                                        double amount = stod(userAmount);

                                        if (amount == 0)
                                        {

                                            counter = 4;

                                        }
                                        else if (amount < 0) {

                                            system("CLS");
                                            cout << "\nPlease enter Positive Value\n";
                                            counter++;
                                            cout << "You Have (" << 3 - counter << ") remaining try\n";
                                            Sleep(2000);

                                        }
                                        else {

                                            this->arrayOfClients[indexOfClient].transferTo(amount, arrayOfClients[indexOfReceiptClient]);

                                            this->file.saveAllClients(arrayOfClients);

                                            system("CLS");
                                            cout << "\nSuccessful Transaction\n";
                                            Sleep(2000);
                                            counter = 4;

                                        }
                                    }
                                    else {

                                        system("CLS");
                                        cout << "\nPlease enter A Valid Value\n";
                                        counter++;
                                        cout << "You Have (" << 3 - counter << ") remaining try\n";
                                        Sleep(2000);

                                    }

                                }
                                else if (indexOfReceiptClient != -1 && indexOfReceiptClient == indexOfClient) {

                                    system("CLS");
                                    cout << "\nYou Can't Send Money To Yourself You Can Make Deposit instead\n";
                                    counter++;
                                    cout << "You Have (" << 3 - counter << ") remaining try\n";
                                    Sleep(2000);
                                }
                                else {

                                    system("CLS");
                                    cout << "\nNo Client Matched With This Id\n";
                                    counter++;
                                    cout << "You Have (" << 3 - counter << ") remaining try\n";
                                    Sleep(2000);

                                }

                            }




                        } while (counter < 3);
                    }
                    else if (freezeScreenChoice == "5") {
                        string choice;
                        int counter{ 0 };



                        do
                        {
                            system("CLS");
                            cout << "\nAre You Sure To Delete This Client Account Enter 1 to confirm or Enter 0 to go back\n";
                            cout << "\nYour input: ";

                            getline(cin, choice);



                            if (choice == "1")
                            {

                                this->arrayOfClients.erase(arrayOfClients.begin() + indexOfClient);

                                this->file.saveAllClients(arrayOfClients);

                                system("CLS");
                                cout << "\nClient Successfully Deleted\n";
                                Sleep(2000);
                                counter = 4;
                            }
                            else if (choice == "0") {
                                break;
                            }
                            else {

                                system("CLS");
                                cout << "\nPlease enter A Valid Value\n";
                                counter++;
                                cout << "You Have (" << 3 - counter << ") remaining try\n";
                                Sleep(2000);


                            }




                        } while (counter < 3);

                        break;
                    }
                    else {

                        system("CLS");
                        cout << "================= Account Info ================\n\n";
                        arrayOfClients[indexOfClient].displayInfoForQuery();
                        cout << "\n================================================\n";

                        freezeScreenChoiceCount++;
                        cout << "\nInvalid Input\n";
                        cout << "\nYou Will be back after(" << 3 - freezeScreenChoiceCount << ") remaining invalid inputs \n";
                        Sleep(1000);
                    }

                } while (freezeScreenChoiceCount < 3);


                indexOfClient = -1;

            }
            else {

                system("CLS");
                cout << "No Client Match in Our Database\n";
                Sleep(2000);
                break;
            }



        }


    } while (counter < 3);
}



void AdminManager::logout() {
    system("CLS");
    cout << "\nBye Bye Keep an eye on your staff boss :)\n";
}