#pragma once
#include <QtGui/QMainWindow>
#include "ui_gateplaner.h"
#include "DataManager.h"
#include "readexcel.h"
using namespace std;
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
	list<QString> Gateslist;	//备选登机口队列
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
	void distributeGatesByQuestion1();		//根据问题一分配登机口
	int explainTimeString(char* str);
	int explainDataString(char* str);
	int getUsedTimes(QString GateID);
	void BlockGate(QString GateID,int DeblockTime);
	void DeblockGate(QString GateID);
};
