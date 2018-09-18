#pragma once
#include <list>
#include <QString>
using namespace std;
// 一条记录record
class GatesType{
public:
	GatesType(): id(0){}
public:
	int id;
	char GateID[8];				//登机口ID
	char TerminalHall[8];		//终端厅
	char Area[8];				//区域
	char ArriveType[8];			//到达类型
	char DepartType[8];			//出发类型
	char PlaneSize[8];			//飞机体型类别
	//额外属性
	QString* strGateID;			//str登机口ID
	QString* strTerminalHall;	//str终端厅
	QString* strArea;			//str区域
	QString* strArriveType;		//str到达类型
	QString* strDepartType;		//str出发类型
	QString* strPlaneSize;		//str飞机体型类别
	int isBlocked;				//是否被屏蔽
	int UsedTimes;				//被使用的次数
};
// 多条记录（列表）
typedef list<GatesType> GatesTypeList;