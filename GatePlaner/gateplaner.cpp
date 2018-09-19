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
	distributeGatesByQuestion1();
	displayPucks(m_DataSource.listPucks());
	displayTickets(m_DataSource.listTickets());
	displayGates(m_DataSource.listGates());


}
GatePlaner::~GatePlaner(){}

void GatePlaner::MakePucksData(){ 
	Pucks = new ReadExcel;
	Pucks->openExcel("C:/Users/Administrator/Downloads/MathF/GatePlaner/Resources/Pucks.xls");
	//Pucks->openExcel("C:/Users/Administrator/Downloads/MathF/GatePlaner/Resources/PucksConcise.xls");
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
	//����excel�ļ��������Ƹ�ʽ
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
	// ��������
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
	item->setText(10,QString("%1").arg((*(record.strArriveGate)).toStdString().c_str()));
	// �����к�
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
	// �����к�
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
	item->setText(0, QString("%1").arg(*(record.strGateID)));		//QString*��Ȼ��ʹ
	item->setText(1, QString("%1").arg(record.TerminalHall));
	item->setText(2, QString("%1").arg(record.Area));
	item->setText(3, QString("%1").arg(record.ArriveType));
	item->setText(4, QString("%1").arg(record.DepartType));
	item->setText(5, QString("%1").arg(record.PlaneSize));
	// �����к�
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
		record.strArriveGate = new QString;
		QString sPT = *(record.strPlaneType);
		if(sPT == QString("332") || sPT == QString("333") || sPT == QString("33E") || sPT == QString("33H") || sPT == QString("33L") || sPT == QString("773")){
			record.strPlaneSize = new QString("W");
		}else{
			record.strPlaneSize = new QString("N");
		}
		record.DigitalArriveTime = explainTimeString(record.ArriveTime)+explainDataString(record.ArriveDate);
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
		record.UsedTimes = 0;		//��ʼ��ʹ�ô���Ϊ0
		record.isBlocked = 0;		//��ʼ��δ����
		record.DeblockTime = 0;		//���ʱ��Ĭ��0(Ĭ�Ͻ��)
	}
}
int GatePlaner::explainTimeString(char* str){
	//���ַ�����ʽ��ʱ��ת��Ϊ��ɢʱ����Ҫ����ʵ�ʳ��ֵ������ַ�����ʽ
	int DigitalTime,h,m;
	int isAM = 1;	//Ĭ��������
	int i = 0;
	int maohaocount = 0;
	while(str[i++]!='\0'){
		if(str[i]=='P'){
			isAM = 0;
			break;
		}
	}
	i = 0;
	int j = 0;
	char timestr[8];
	while(str[i]!='\0'){
		if(str[i]==':'){
			maohaocount++;
		}
		if(maohaocount<2){
			timestr[j++]=str[i];
		}else{
			break;
		}
		i++;
	}
	timestr[j] = '\0';
	char hstr[4],mstr[4];
	i = 0, j = 0, maohaocount = 0;
	int k = 0;
	while(timestr[i]!='\0'){
		if(str[i]==':'){
			maohaocount++;
		}else{
			if(maohaocount == 0){
				hstr[j++] = str[i];
			}else{
				mstr[k++] = str[i];
			}
		}
		i++;
	}
	hstr[j] = '\0';
	mstr[k] = '\0';
	if(strlen(hstr)==1){
		h = hstr[0] - '0';
	}else{
		h = (hstr[0]-'0')*10+hstr[1]-'0';
	}
	m = (mstr[0]-'0')*10+mstr[1]-'0';
	DigitalTime = (h*60+m)/5;
	if(isAM == 0){
		DigitalTime += 144;
	}
	return DigitalTime;
}
int GatePlaner::explainDataString(char* str){
	int DigitalTime;
	int i=0;
	while(str[i]!='\0'){
		if(str[i]=='1'&&str[i+1]=='9'){
			DigitalTime = 0;
			break;
		}else if(str[i-1]=='/'&&str[i]=='2'&&str[i+1]=='0'){
			DigitalTime = 288;
			break;
		}else if(str[i]=='2'&&str[i+1]=='1'){
			DigitalTime = 576;
			break;
		}
		i++;
	}
	return DigitalTime;
}
void GatePlaner::distributeGatesByQuestion1(){
	PucksTypeList records = m_DataSource.m_Pucks;
	Gateslist.clear();
	for(PucksTypeList::iterator iter = records.begin();	iter != records.end(); iter++){
		PucksType& record = *iter;
		//��ÿһ���ɻ����з�������Ҫ�����б�ѡ�ǻ�����ɵĶ��У����ڶ��������Ծ�����ͣ��
		for(GatesTypeList::iterator iter1 = m_DataSource.m_Gates.begin();iter1!=m_DataSource.m_Gates.end();iter1++){
			GatesType& recordGate = *iter1;
			//ÿ�ܷɻ�ѡ��ͣ����֮ǰ�����ý��ĵǻ��ڽ��
			if(recordGate.DeblockTime<explainTimeString(record.ArriveTime)+explainDataString(record.ArriveDate)){	//������ʱ���ڷɻ�����֮ǰ��Ӧ�����
				DeblockGate(*(recordGate.strGateID));
			}
			if((recordGate.strArriveType->compare(QString(record.ArriveType))==0||recordGate.strArriveType->length()>1)&&(recordGate.strDepartType->compare(QString(record.DepartType))==0||recordGate.strArriveType->length()>1)&&recordGate.strPlaneSize->compare(*(record.strPlaneSize))==0&&recordGate.isBlocked==0){
				Gateslist.push_back(*(recordGate.strGateID));
			}
		}
		//�Ѿ�ѡ���˱�ѡ�ǻ��ڶ��У������ڱ�ѡ�ǻ��ڶ�����ѡȡ��Ծ�����
		int maxusedtimes = -1;
		QString MostActiveGate;
		for(list<QString>::iterator iter2 = Gateslist.begin();iter2!=Gateslist.end();iter2++){
			QString GateID = *iter2;
			if(getUsedTimes(GateID)>maxusedtimes){
				maxusedtimes = getUsedTimes(GateID);
				MostActiveGate = GateID;
			}
		}
		//�Ѿ�ѡ�������Ծ��
		*(record.strArriveGate) = MostActiveGate;
		int DeblockTime = explainTimeString(record.DepartTime)+ explainDataString(record.DepartDate) + 9;	//+9��45���ӵ���˼
		BlockGate(MostActiveGate,DeblockTime);	//��ѡ�еĵǻ�������
		Gateslist.clear();
	}
}
int GatePlaner::getUsedTimes(QString GateID){	//���ݵǻ��ںŵ�ȡ�䱻ʹ�ô���
	int usedtimes;
	for(GatesTypeList::iterator iter = m_DataSource.m_Gates.begin();iter!=m_DataSource.m_Gates.end();iter++){
		if(GateID.compare(*(iter->strGateID))==0){
			usedtimes = iter->UsedTimes;
		}
	}
	return usedtimes;
}
void GatePlaner::BlockGate(QString GateID,int DeblockTime){
	//�����ƶ��ǻ���
	for(GatesTypeList::iterator iter = m_DataSource.m_Gates.begin();iter!=m_DataSource.m_Gates.end();iter++){
		GatesType& recordGate = *iter;
		if(recordGate.strGateID->compare(GateID)==0){
			recordGate.isBlocked = 1;
			iter->isBlocked = 1;
			recordGate.DeblockTime = DeblockTime;
		}
	}
}
void GatePlaner::DeblockGate(QString GateID){
	for(GatesTypeList::iterator iter1 = m_DataSource.m_Gates.begin();iter1!=m_DataSource.m_Gates.end();iter1++){
		GatesType& recordGate = *iter1;
		if(recordGate.strGateID->compare(GateID)==0){
			recordGate.isBlocked = 0;
		}
	}
}