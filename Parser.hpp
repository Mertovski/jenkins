#ifndef PARSER_HPP__
#define PARSER_HPP__

class Parser
{
public:
	int setPositions(std::string line, int follow);
	int setEvents(std::string line, int follow);
};

#endif