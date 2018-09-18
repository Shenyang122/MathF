#include "gateplaner.h"

GatePlaner::GatePlaner(QWidget *parent, Qt::WFlags flags):QMainWindow(parent, flags){
	ui.setupUi(this);
	//MakePucksData();
	//MakeTicketsData();
	//MakeGatesData();
	m_DataSource.loadPucks();
	m_DataSource.loadTickets();
	m_DataSource.loadGates();
	InitPucksData();
	InitTicketsData();
	InitGatesData();
	displayPucks(m_DataSource.listPucks());
	displayTickets(m_DataSource.listTickets());
	displayGates(m_DataSource.listGates());

}
GatePlaner::~GatePlaner(){}

void GatePlaner::MakePucksData(){ 
	Pucks = new ReadExcel;
	//Pucks->openExcel("C:/Users/Administrator/Downloads/MathF/GatePlaner/Resources/Pucks.xls");
	Pucks->openExcel("C:/Users/Administrator/Downloads/MathF/GatePlaner/Resources/PucksConcise.xls");
	PucksType PuckRecord;
	for(int i=2;i<Pucks->m_row+1;i++){
		PuckRecord.id = stoi(Pucks->getCellData(i,1));
		strcpy(PuckRecord.PlaneID,Pucks->getCellData(i,2).c_str());
		strcpy(PuckRecord.ArriveDate,Pucks->getCellData(i,3).c_str());
		strcpy(PuckRecord.ArriveTime,Pucks->getCellData(i,4).c_str());
		strcpy(PuckRecord.ArriveFlight,Pucks->getCellData(i,5).c_str());
		strcpy(PuckRecord.ArriveType,Pucks->getCellData(i,6).c_str());
		strcpy(PuckRecord.PlaneType,Pucks->getCellData(i,7).c_str());
		strcpy(PuckRecord.DepartDate,Pucks->getCellData(i,8).c_str());
		strcpy(PuckRecord.DepartTime,Pucks->getCellData(i,9).c_str());
		strcpy(PuckRecord.DepartFlight,Pucks->getCellData(i,10).c_str());
		strcpy(PuckRecord.DepartType,Pucks->getCellData(i,11).c_str());
		m_DataSource.addPucks(PuckRecord);
	}
	m_DataSource.savePucks();
}
void GatePlaner::MakeTicketsData(){
	Tickets = new ReadExcel;
	//Tickets->openExcel("C:/Users/Administrator/Downloads/MathF/GatePlaner/Resources/Tickets.xls");
	Tickets->openExcel("C:/Users/Administrator/Downloads/MathF/GatePlaner/Resources/TicketsConcise.xls");
	TicketsType TicketRecord;
	for(int i=2;i<Tickets->m_row+1;i++){
		TicketRecord.id = stoi(Tickets->getCellData(i,1));
		strcpy(TicketRecord.CustomerID,Tickets->getCellData(i,2).c_str());
		TicketRecord.CustomerNum = stoi(Tickets->getCellData(i,3));
		strcpy(TicketRecord.ArriveFlight,Tickets->getCellData(i,4).c_str());
		strcpy(TicketRecord.ArriveDate,Tickets->getCellData(i,5).c_str());
		strcpy(TicketRecord.DepartFlight,Tickets->getCellData(i,6).c_str());
		strcpy(TicketRecord.DepartDate,Tickets->getCellData(i,7).c_str());
		m_DataSource.addTickets(TicketRecord);
	}
	m_DataSource.saveTickets();
}
void GatePlaner::MakeGatesData(){
	Gates = new ReadExcel;
	Gates->openExcel("C:/Users/Administrator/Downloads/MathF/GatePlaner/Resources/Gates.xls");
	//保存excel文件到二进制格式
	GatesType GateRecord;
	for(int i=2;i<Gates->m_row+1;i++){
		GateRecord.id = stoi(Gates->getCellData(i,1));
		strcpy(GateRecord.GateID,Gates->getCellData(i,2).c_str());
		strcpy(GateRecord.TerminalHall,Gates->getCellData(i,3).c_str());
		strcpy(GateRecord.Area,Gates->getCellData(i,4).c_str());
		strcpy(GateRecord.ArriveType,Gates->getCellData(i,5).c_str());
		strcpy(GateRecord.DepartType,Gates->getCellData(i,6).c_str());
		strcpy(GateRecord.PlaneSize,Gates->getCellData(i,7).c_str());
		m_DataSource.addGates(GateRecord);
	}
	m_DataSource.saveGates();
}
void GatePlaner::displayPucks(PucksType& record){
	// 设置数据
	QTreeWidgetItem* item = new QTreeWidgetItem(ui.tablePucks);
	item->setText(0, QString("%1").arg(record.PlaneID) );
	item->setText(1, QString("%1").arg(record.ArriveDate));
	item->setText(2, QString("%1").arg(record.ArriveTime));
	item->setText(3, QString("%1").arg(record.ArriveFlight));
	item->setText(4, QString("%1").arg(record.ArriveType));
	item->setText(5, QString("%1").arg(record.PlaneType));
	item->setText(6, QString("%1").arg(record.DepartDate));
	item->setText(7, QString("%1").arg(record.DepartTime));
	item->setText(8, QString("%1").arg(record.DepartFlight));
	item->setText(9, QString("%1").arg(record.DepartType));
	// 设置行号
	item->setData(0, Qt::UserRole, record.id);
}
void GatePlaner::displayPucks(PucksTypeList& records){
	for(PucksTypeList::iterator iter = records.begin();	iter != records.end(); iter++){
		PucksType& record = *iter;
		displayPucks(record);
	}
}
void GatePlaner::displayTickets(TicketsType& record){
	QTreeWidgetItem* item = new QTreeWidgetItem(ui.tableTickets);
	item->setText(0, QString("%1").arg(record.CustomerID) );
	item->setText(2, QString("%1").arg(record.ArriveDate));
	item->setText(3, QString("%1").arg(record.ArriveFlight));
	item->setText(4, QString("%1").arg(record.DepartDate));
	item->setText(5, QString("%1").arg(record.DepartFlight));
	item->setText(1, QString("%1").arg(record.CustomerNum));
	// 设置行号
	item->setData(0, Qt::UserRole, record.id);
}
void GatePlaner::displayTickets(TicketsTypeList& records){
	for(TicketsTypeList::iterator iter = records.begin();	iter != records.end(); iter++){
		TicketsType& record = *iter;
		displayTickets(record);
	}
}
void GatePlaner::displayGates(GatesType& record){
	QTreeWidgetItem* item = new QTreeWidgetItem(ui.tableGates);
	item->setText(0, QString("%1").arg(*(record.strGateID)));		//QString*依然好使
	item->setText(1, QString("%1").arg(record.TerminalHall));
	item->setText(2, QString("%1").arg(record.Area));
	item->setText(3, QString("%1").arg(record.ArriveType));
	item->setText(4, QString("%1").arg(record.DepartType));
	item->setText(5, QString("%1").arg(record.PlaneSize));
	// 设置行号
	item->setData(0, Qt::UserRole, record.id);
}
void GatePlaner::displayGates(GatesTypeList& records){
	for(GatesTypeList::iterator iter = records.begin();	iter != records.end(); iter++){
		GatesType& record = *iter;
		displayGates(record);
	}
}
void GatePlaner::InitPucksData(){
	for(PucksTypeList::iterator iter = m_DataSource.m_Pucks.begin();iter!=m_DataSource.m_Pucks.end();iter++){
		PucksType& record = *iter;
		record.strPlaneType = new QString(record.PlaneType);
		QString sPT = *(record.strPlaneType);
		if(sPT == QString("332") || sPT == QString("333") || sPT == QString("33E") || sPT == QString("33H") || sPT == QString("33L") || sPT == QString("773")){
			record.strPlaneSize = new QString("W");
		}else{
			record.strPlaneSize = new QString("N");
		}
	}
}
void GatePlaner::InitTicketsData(){

}
void GatePlaner::InitGatesData(){
	for(GatesTypeList::iterator iter = m_DataSource.m_Gates.begin();iter != m_DataSource.m_Gates.end(); iter++){
		GatesType& record = *iter;
		record.strGateID = new QString(record.GateID);
		record.strArea = new QString(record.Area);
		record.strArriveType = new QString(record.ArriveType);
		record.strTerminalHall = new QString(record.TerminalHall);
		record.strDepartType = new QString(record.DepartType);
		record.strPlaneSize = new QString(record.PlaneSize);
		record.UsedTimes = 0;		//初始化使用次数为0
		record.isBlocked = 0;		//初始化未屏蔽
	}
}