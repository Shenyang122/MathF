#pragma once
#include <list>
#include <QTime>
using namespace std;
// 一条记录record
class PucksType{

public:
	PucksType(): id(0){}

public:
	int id;
	char PlaneID[8];			//飞机转场记录号
	char ArriveDate[16];		//到达日期
	char ArriveTime[16];		//到达时间
	char ArriveFlight[16];		//到达航班
	char DepartDate[16];		//出发日期
	char DepartTime[16];		//出发时间
	char DepartFlight[16];		//出发航班
	char PlaneType[8];			//飞机型号
	char ArriveType[8];			//到达类型
	char DepartType[8];			//出发类型
	//额外属性
	int BlockTime;				//屏蔽登机口时间(约定每5分钟为1个离散值，从19日凌晨0点起计时，则24*12=288是20日0时，576是21日零时)
	int DeblockTime;			//解除屏蔽登机口时间
	int DigitalArriveTime;		//数字化到达时间
	int DigitalDepartTime;		//数字化起飞时间
	QString* strArriveGate;		//停靠的登机口的位置
	QString* strPlaneID;		//str飞机转场记录号
	QString* strArriveFlight;	//str到达航班
	QString* strDepartFlight;	//str出发航班
	QString* strArriveType;		//str到达类型
	QString* strDepartType;		//str出发类型
	QString* strPlaneType;		//str飞机型号
	QString* strPlaneSize;		//str飞机宽窄
};
// 多条记录（列表）
typedef list<PucksType> PucksTypeList;
