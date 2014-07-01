#pragma once

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Step
{
public:
    enum Operation {SWAP, COMP, RIGHTINDEX, LEFTINDEX, MARK, PIVOT, CPY, R_CPY, MIN, END};
    Step(int firstValue, int secondValue, Operation operation, unsigned int number, string explanation);

	Step(int firstValue, int secondValue, Operation operation, unsigned int number);

	~Step(void);

	/**
	* Liefert explanation zur�ck
	* erstellt eine Explanation aus den vorliegenden Informationen, falls keine existiert
	*/
	string toString();

	/**
	* Getter-Funktionen
	*/
    Operation getOperation() { return op; }
    int getNumber(){ return number; }
    int getFirstValue(){ return firstValue; }
    int getSecondValue(){ return secondValue; }
protected:
	int firstValue;
	int secondValue;
	Operation op;
	int number;
	string explanation;
};

