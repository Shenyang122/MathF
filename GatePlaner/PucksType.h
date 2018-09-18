#pragma once
#include <list>
#include <QTime>
using namespace std;
// һ����¼record
class PucksType{

public:
	PucksType(): id(0){}

public:
	int id;
	char PlaneID[8];			//�ɻ�ת����¼��
	char ArriveDate[16];		//��������
	char ArriveTime[16];		//����ʱ��
	char ArriveFlight[16];		//���ﺽ��
	char DepartDate[16];		//��������
	char DepartTime[16];		//����ʱ��
	char DepartFlight[16];		//��������
	char PlaneType[8];			//�ɻ��ͺ�
	char ArriveType[8];			//��������
	char DepartType[8];			//��������
	//��������
	int BlockTime;				//���εǻ���ʱ��
	int DeblockTime;			//������εǻ���ʱ��
	QString* strPlaneID;		//str�ɻ�ת����¼��
	QString* strArriveDate;		//str��������
	QString* strArriveTive;		//str����ʱ��
	QString* strArriveFlight;	//str���ﺽ��
	QString* strDepartDate;		//str��������
	QString* strDepartTime;		//str����ʱ��
	QString* strDepartFlight;	//str��������
	QString* strArriveType;		//str��������
	QString* strDepartType;		//str��������
	QString* strPlaneType;		//str�ɻ��ͺ�
	QString* strPlaneSize;		//str�ɻ���խ
};
// ������¼���б�
typedef list<PucksType> PucksTypeList;
