#ifndef getCsv_H
#define getCsv_H
#include <string>
#include <libpq-fe.h>
#include <Positions.h>
#include <Events.h>
#include <Connections.h>
#include <Monitoring.h>

void getDataCSV(std::string file);
void checkNameCSV(std::string file);
void setDataCSV(std::string line);
void setPositions(std::string line, int follow);
void setEvents(std::string line, int follow);
void setConnections(std::string line, int follow);
void setMonitoring(std::string line, int follow);
#endif

// vim:set et sw=4 ts=4: ft=cpp
