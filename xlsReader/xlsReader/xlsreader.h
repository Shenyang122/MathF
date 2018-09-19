#ifndef XLSREADER_H
#define XLSREADER_H

#include <QtGui/QMainWindow>
#include "ui_xlsreader.h"
#include "readexcel.h"

class xlsReader : public QMainWindow{
	Q_OBJECT

public:
	xlsReader(QWidget *parent = 0, Qt::WFlags flags = 0);
	~xlsReader();

private:
	Ui::xlsReaderClass ui;
};

#endif // XLSREADER_H
