#include "LoadData.h"

void LoadData::Load(std::string id) {
    std::ifstream FileStream("Storage.txt");
    while (!FileStream.eof()) {
        std::string input;
        FileStream >> input;
        if (input == "$" + id) {
            int cntOfTowns;
            FileStream >> cntOfTowns;
            while (cntOfTowns--) {
                std::string townName;
                FileStream >> townName;
                Graph::Instance()->AddTown(townName);
            }
            while (!FileStream.eof()) {
                std::string townName;
                FileStream >> townName;
                if (townName.empty() || townName[0] == '$') {
                    FileStream.close();
                    return;
                }
                int numOfEdges;
                FileStream >> numOfEdges;
                while (numOfEdges--) {
                    std::string secTownName;
                    int cost;
                    FileStream >> secTownName;
                    FileStream >> cost;
                    Graph::Instance()->AddEdge(townName, secTownName, cost);
                }
            }
        }
    }
    FileStream.close();
    throw std::exception();
}