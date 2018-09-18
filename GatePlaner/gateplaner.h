#pragma once
#include <QtGui/QMainWindow>
#include "ui_gateplaner.h"
#include "DataManager.h"
#include "readexcel.h"

class GatePlaner : public QMainWindow{
	Q_OBJECT

public:
	GatePlaner(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GatePlaner();
	
	ReadExcel* Pucks;
	ReadExcel* Tickets;
	ReadExcel* Gates;

private:
	Ui::GatePlanerClass ui;
	DataManager m_DataSource;
	void MakePucksData();
	void MakeTicketsData();
	void MakeGatesData();
	void InitPucksData();
	void InitTicketsData();
	void InitGatesData();
	void displayPucks(PucksType& record);
	void displayPucks(PucksTypeList& records);
	void displayTickets(TicketsType& record);
	void displayTickets(TicketsTypeList& records);
	void displayGates(GatesType& record);
	void displayGates(GatesTypeList& records);
};
