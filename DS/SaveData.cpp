#include "SaveData.h"
#include<iosream>
using namespace std;
void SaveData::Save(string id,list<Town*>* Towns) {
    if (!Towns)
        return;
    ifstream IFileStream("Storage.txt");
    list<string> ls;
    bool found = false;
    while (!IFileStream.eof()) {
       string input;
        IFileStream >> input;
        if (input.empty())
            break;
        if (input == "$" + id) {
            found = true;
        }
        else if (input[0] == '$' && found) {
            found = false;
        }
        if (!found) {
            ls.push_back(input);
        }
    }
    IFileStream.close();

  ofstream OFileStream("Storage.txt");

    for (auto &Item : ls) {
        OFileStream << Item << '\n';
    }

    OFileStream << "$" + id << '\n';
    OFileStream << Towns->size() << '\n';
    for (auto &Town : *Towns) {
        OFileStream << Town->getName() << '\n';
    }
    for (auto& Town : *Towns) {
        OFileStream << Town->getName() << '\n';
        if (!Town->getDestinations()) {
            OFileStream << 0 << '\n';
            continue;
        }
        OFileStream << Town->getDestinations()->size() << '\n';
        for (auto &Destination : *Town->getDestinations()) {
            OFileStream << Destination.first->getName() << '\n';
            OFileStream << Destination.second << '\n';
        }
    }
    OFileStream.close();
}