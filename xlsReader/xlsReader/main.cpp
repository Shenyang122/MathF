#include "xlsreader.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	xlsReader w;
	w.show();
	return a.exec();
}
