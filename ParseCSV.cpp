#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <string>
#include <libpq-fe.h>
#include <FileWatcher.h>
#include <ParseCSV.h>
#include <Positions.h>
#include <Events.h>
#include <Connections.h>
#include <Monitoring.h>
#include <Database.h>
using namespace std;

Positions p1;
Events e1;
Connections c1;
Monitoring m1;

int goodFile;
void getDataCSV(std::string file)
{
    try {
        // std::cout << goodFile << std::endl;
        checkNameCSV(file);
        std::ifstream csv(file.c_str());
	csv.ignore(10000, '\n');
        std::string line;
        CreateConnection();
        // removeAll();

        while (std::getline(csv, line))
        {
	    std::cout << line;
            setDataCSV(line);
        }
        CloseConnection();
        std::cout << "Program is done" << std::endl;
    }
    catch( std::exception& e ) 
    {
        fprintf(stderr, "An exception has occurred: %s\n", e.what());
    }
}

void checkNameCSV(std::string file) {
    if (file == "uploads/Positions.csv") {
        goodFile = 1;
    }
    else {
        if (file == "uploads/Events.csv") {
            goodFile = 2;
        }
        else {
            if (file == "uploads/Connections.csv") {
                goodFile = 3;
            }
            else {
                if(file == "uploads/Monitoring.csv")
                    goodFile = 4;
            }
        }
    }
}

void setDataCSV(std::string line)
{
    int follow = 1;
    for (int i = 0; i < 9; i++)
    {
        std::string splitter = ";";
        std::string substring = line.substr(0, line.find(splitter));
        if (goodFile == 1) {
            setPositions(substring, follow);
        }else {
            if (goodFile == 2) {
                setEvents(substring, follow);
            }
            else {
                if (goodFile == 3) {
                    setConnections(substring, follow);
                }
                else {
                    if (goodFile == 4) {
                        setMonitoring(substring, follow);
                    }
                }
            } 
        }
        line.erase(0, substring.length() + 1);
        follow++;
    }
    if (goodFile == 1) {
        savePositions(p1);
    }
    else {
        if (goodFile == 2) {
            saveEvents(e1);
        }
        else {
            if (goodFile == 3) {
                saveConnections(c1);
            }
            else {
                if (goodFile == 4) {
                    saveMonitoring(m1);
                }
            }
        }
    }
}

int setPositions(std::string line, int follow) {
    if (follow == 1) {
        p1.DateTime = line;
    }
    if (follow == 2) {
        p1.UnitId = line;
    }
    if (follow == 3) {
        p1.Rdx = line;
		return 1;
    }
    if (follow == 4) {
        p1.Rdy = line;
		return 2;
    }
    if (follow == 5) {
        p1.Speed = line;
    }
    if (follow == 6) {
        p1.Course = line;
    }
    if (follow == 7) {
        p1.NumSatellites = line;
    }
    if (follow == 8) {
        p1.HDOP = line;
    }
    if (follow == 9) {
        p1.Quality = line;
    }
	return 0;
}

void setEvents(std::string line, int follow) {
    if (follow == 1) {
        e1.DateTime = line;
    }
    if (follow == 2) {
        e1.UnitId = line;
    }
    if (follow == 3) {
        e1.Port = line;
    }
    if (follow == 4) {
        e1.Value = line;
    }
}

void setConnections(std::string line, int follow) {
    if (follow == 1) {
        c1.DateTime = line;
    }
    if (follow == 2) {
        c1.UnitId = line;
    }
    if (follow == 3) {
        c1.Port = line;
    }
    if (follow == 4) {
        c1.Value = line;
    }
}

void setMonitoring(std::string line, int follow) {
    if (follow == 1) {
        m1.UnitId = line;
    }
    if (follow == 2) {
        m1.BeginTime = line;
    }
    if (follow == 3) {
        m1.EndTime = line;
    }
    if (follow == 4) {
        m1.Type = line;
    }
    if (follow == 5) {
        m1.Type = line;
    }
    if (follow == 6) {
        m1.Type = line;
    }
    if (follow == 7) {
        m1.Type = line;
    }
}

// vim:set et sw=4 ts=4: ft=cpp
