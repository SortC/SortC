#ifndef SORTVALUE_H
#define SORTVALUE_H

#include <QWidget>
#include <math.h>
#include <QResizeEvent>

namespace Ui {
class SortValue;
}
/**
 * @brief The SortValue class
 *
 * Klasse zur Anzeige eines SortierWerts. Besitzt ein UI-Element bestehend aus einem Widget.
 * Dieses enthaelt ein QFrame zur visualisierung des Werts, und zwei Label zur Anzeige
 * des aktuellen Werts und der Arraystelle. Die Groesse des QFrame errechnet sich aus der Gesamtgroesse
 * des Widgets und dem Verhaeltnis des Wertes zum uebergeben Maximalwert.
 * Regelt intern auftretende resizeEvents.
 */
class SortValue : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief The Action enum
     *
     * Enum zur Beschreibung der aktuellen Aktion des SortValue.
     */
    enum Action {NONE, COMP, RIGHTINDEX, LEFTINDEX, SWAP, MARK, MIN, PIVOT, CPY, R_CPY};

    /**
     * @brief SortValue
     *
     * Konstruktor der SortValue Klasse
     *
     * @param parent: Pointer auf das Elternelement
     * @param value: Aktueller Wert des SortValue
     * @param maxValue: MaximalWert des Arrays
     * @param arrayIndex: arrayIndex des SortValue, wird nur im Konstruktor gesetzt
     */
    explicit SortValue(QWidget *parent = 0, int value = 0, int maxValue = 100, int arrayIndex = 0);

    /**
      * Dekonstruktor
      */
    ~SortValue();

    /**
     * @brief setValue
     *
     * Setzt den uebergebenen Wert als value des SortValue
     * Fuert zur neuberechnung der Groessenverhaeltnisse durch resizeValue()
     *
     * @param value: Neuer Wert des SortValue
     */
    void setValue(int value);
    int getValue(){return value;} /**< Getter fuer den aktuellen Wert*/

    bool getValueVisible(){return valueVisible;} /**< Gibt zurueck ob SortValue sichtbar ist oder versteckt*/

    /**
     * @brief setAction
     *
     * Setzt die uebergebene Aktion als action des SortValue. aendert dementsprechend das Styling des QFrames
     *
     * @param action: neue fuer das SortValue geltende action
     */
    void setAction(Action action);
    /**
     * @brief resizeValue
     *
     * berechnet die Groessenverhaeltnisse des QFrames neu
     */
    void resizeValue();

    /**
     * @brief showValue hidevalue
     *
     * Setzt StyleSheet des QFrames auf transtparent, bzw wieder sichtbar
     * ohne das Layout zu aendern
     */
    void showValue();
    void hideValue();

    /**
     * @brief resizeEvent
     *
     * wird aufgerufen wenn sich die groesse des gesamten SortValues aendert
     *
     * @param event
     */
    void resizeEvent ( QResizeEvent * event );

private:
    Ui::SortValue *ui;
    int arrayIndex; /**< Stelle des SortValue im Array*/
    int value; /**< Aktueller Wert des SortValue*/
    int maxValue; /**< Maximalwert im Array, wird zur Berechnung der Groessenverhaeltnisse benoetigt*/
    QString styleSheetBuffer; /**< Buffer fuer den aktuellen sichtbaren StyleSheet (relevant fuer showValue() und hideValue())*/
    bool valueVisible; /**< Aktueller Sichtbarkeitsstatus des SortValue*/
    Action currentAction; /**< Derzeitige action des SortValue*/
};

#endif // SORTVALUE_H
