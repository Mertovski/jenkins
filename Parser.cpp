#include "Parser.hpp"

int Parser::setPositions(std::string line, int follow) {
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

int Parser::setEvents(std::string line, int follow) {
	if (follow == 1) {
		e1.DateTime = line;
		return 0;
	}
	if (follow == 2) {
		e1.UnitId = line;
		return 0;
	}
	if (follow == 3) {
		e1.Port = line;
	}
	if (follow == 4) {
		e1.Value = line;
	}
}