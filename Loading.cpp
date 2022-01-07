#include "Loading.h"


////This class is For Loading old written ids in text id's files to keep id's unique////

vector<int> Loading::loadTheIdsOfAllpersons(string fileName) {//read Id.txt file and return vector arrayOfIds

    vector<int> arrayOfIds;

    ifstream id_file;

    id_file.open(fileName, ios::in);

    if (id_file.is_open())
    {

        string line;

        while (getline(id_file, line)) {


                string currentID = "";

                for (int i = 0; i < line.size(); i++) {


                    currentID += line[i];

                }

                arrayOfIds.push_back(stoi(currentID));

                currentID = "";   
            

        }


        id_file.close();

    }

    return arrayOfIds;
}

int Loading::loadLastId(string fileName,int startIds) {

    if (loadTheIdsOfAllpersons(fileName).empty()) {

        return startIds;//starting id if no id's yet
    }
    else {

        return loadTheIdsOfAllpersons(fileName).back();//return the last id from the vector
    }

    

}

void Loading::writeNewId(string filename, int newId) {//writing id's in the Ids.txt file to each person

    ofstream id_file;

    id_file.open(filename, ios::app);

    if (id_file.is_open()) {

        id_file << newId << "\n";

        id_file.close();
    }
   
    
}


