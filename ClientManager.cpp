#include "ClientManager.h"

//Constructor
ClientManager::ClientManager() {

   this->arrayOfClients = this->file.getAllClients();
  
}


//custom methods
Client* ClientManager::login(string id,string pass) {

    Client* client;

    for (int i = 0; i < arrayOfClients.size(); i++)
    {
        if (arrayOfClients[i].getId() == id)
        {
            if (arrayOfClients[i].getPinCode() != pass)
            {
                cout << "Password Is Wrong\n";

                return nullptr;
            }
            else {



                client = new Client(arrayOfClients[i].getId(), arrayOfClients[i].getName(), arrayOfClients[i].getPinCode(), arrayOfClients[i].getBalance());

                this->indexOfClient = i;

                return client;

            }
  

        }
        
    }
    cout << "No Match\n";
    return nullptr;
   
}

void ClientManager::printClientMenu() {
    system("CLS");
    cout << "\nPlaese Choose From The Following\n\n1 - display myInfo\n2 - update pin code\n3 - withdraw\n4 - deposit\n5 - transfer amount\n0 - logout\n";
    
}

void ClientManager::displayClientInfo() {

   
    system("CLS");
    string choice;
    int counter{ 0 };


    cin.ignore();

    this->arrayOfClients[indexOfClient].displayInfo();

    do
    {
        
       
        cout << "\nEnter 0 to go back\n";
        cout << "Your input: ";

        getline(cin, choice);

        if (choice == "0")
        {

            counter = 4;

        }else {

            system("CLS");

            this->arrayOfClients[indexOfClient].displayInfo();

            counter++;
            cout << "\nPlease Enter 0 To Go back or you will be directed after";
            cout << " (" << 3 - counter << ") invalid inputs\n";

        }


    } while (counter < 3);
}

void ClientManager::updatePinCode() {

    system("CLS");
    string pinCode;
    int counter{ 0 };


    cin.ignore();
    
    do
    {
        system("CLS");
        cout << "\nPlease Enter a New Password (Digits only and must be 4 char)\nor Enter 0 to go back\n";
        cout << "Your input: ";

        getline(cin, pinCode);

        if (Validation::isDigits(pinCode) && Validation::isSizeOk(pinCode, 4))
        {
            
            arrayOfClients[indexOfClient].setPinCode(pinCode);

            this->file.saveAllClients(arrayOfClients);

            system("CLS");
            cout << "\nPassword Updated Successfully\n";
            Sleep(2000);
            counter = 4;
        }
        else if (pinCode == "0") {

            counter = 4;
        }
        else{

            system("CLS");
            counter++;
            cout << "\nPassword Must be Digits only and must be 4\n";
            cout << "You Have (" << 3 - counter << ") remaining try\n";
            Sleep(2000);
            
           
           
        }

    } while (counter < 3);

    

}

void ClientManager::withdraw() {

    string userAmount;
    int counter{ 0 };

    cin.ignore();

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

void ClientManager::deposit() {

    string userAmount;
    int counter{ 0 };

    cin.ignore();

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

void ClientManager::transfer() {

    string userAmount, receiptId;

    int indexOfReceiptClient = -1;

    int counter{ 0 };

    cin.ignore();

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
    
void ClientManager::logout() {
    system("CLS");
    cout << "\nBye Bye we are glade to deal with You\n";

}


