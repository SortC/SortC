#include <QApplication>
#include <view/ConfiguratorView.h>
/**
 * @brief main
 * Das Programm visualisiert verschiedene Sortieralgorithmen und dient so der Wissensvermittlung
 * logischer Sortierverfahren in Theorie und Praxis. Der Benutzer hat durch eine funktionsreiche
 * Benutzeroberfläche vielseitige Möglichkeiten um den Algorithmus optimal verstehen zu können.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConfiguratorView* configuratorView = new ConfiguratorView(0);
    configuratorView->show();
    int retval = a.exec();
    delete configuratorView;

    return retval;
}
