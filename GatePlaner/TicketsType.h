#pragma once
#include <list>
using namespace std;
// 一条记录record
class TicketsType{
public:
	TicketsType(): id(0){}
public:
	int id;
	char CustomerID[8];		//旅客记录号
	char ArriveDate[16];		//到达日期
	char ArriveFlight[16];	//到达航班
	char DepartDate[16];		//出发日期
	char DepartFlight[16];	//出发航班
	int CustomerNum;		//乘客数量
};
// 多条记录（列表）
typedef list<TicketsType> TicketsTypeList;