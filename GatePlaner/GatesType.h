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
	char ArriveType[16];			//��������
	char DepartType[16];			//��������
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
	int DeblockTime;			//���ʱ��
};
// ������¼���б�
typedef list<GatesType> GatesTypeList;