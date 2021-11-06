#pragma once
#include <iostream>
#include <string>
using namespace std;

class Plate
{
private:
	string color_plate;
	Plate* prev;

public:

	void setColorPlate(string _color_plate) { color_plate = _color_plate; }
	string getColorPlate() { return color_plate; }
	void setPrevPtr(Plate* _prev) { prev = _prev; }
	Plate* getPrevPtr() { return prev; }

};

