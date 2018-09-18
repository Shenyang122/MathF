#pragma once
#include <list>
#include <QString>
using namespace std;
// һ����¼record
class GatesType{
public:
	GatesType(): id(0){}
public:
	int id;
	char GateID[8];				//�ǻ���ID
	char TerminalHall[8];		//�ն���
	char Area[8];				//����
	char ArriveType[8];			//��������
	char DepartType[8];			//��������
	char PlaneSize[8];			//�ɻ��������
	//��������
	QString* strGateID;			//str�ǻ���ID
	QString* strTerminalHall;	//str�ն���
	QString* strArea;			//str����
	QString* strArriveType;		//str��������
	QString* strDepartType;		//str��������
	QString* strPlaneSize;		//str�ɻ��������
	int isBlocked;				//�Ƿ�����
	int UsedTimes;				//��ʹ�õĴ���
};
// ������¼���б�
typedef list<GatesType> GatesTypeList;