#pragma once

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * @brief The Step class
 *
 * Schrittklasse, speichert Informationen ueber Sortiervorgaenge
 * um diese spaeter visuell Darstellbar zu machen.
 */
class Step
{
public:
    /**
     * @brief The Operation enum
     *
     * Zum definieren der in diesem Schritt ausgefuerten Operation.
     */
    enum Operation {SWAP, COMP, RIGHTINDEX, LEFTINDEX, MARK, PIVOT, CPY, R_CPY, MIN, END};

    /**
     * @brief Step
     *
     * Konstruktor mit eigener Erklaerung
     *
     * @param firstValue : Stelle des ersten betroffenen Werts
     * @param secondValue : Stelle des zweiten betroffenen Werts
     * @param operation : Art der Operation
     * @param number : Schrittnummer
     * @param explanation : Erklaerung zum Schritt
     */
    Step(int firstValue, int secondValue, Operation operation, unsigned int number, string explanation);

    /**
     * @brief Step
     *
     * Konstruktor mit ohne eigene Erklaerung. Erklaerung wird in toString()
     * aus den uebergebenen Informationen erstellt.
     *
     * @param firstValue : Stelle des ersten betroffenen Werts
     * @param secondValue : Stelle des zweiten betroffenen Werts
     * @param operation : Art der Operation
     * @param number : Schrittnummer
     */
	Step(int firstValue, int secondValue, Operation operation, unsigned int number);

    /**
      * Dekonstruktor
      */
	~Step(void);

	/**
	* Liefert explanation zurück
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

