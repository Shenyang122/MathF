#pragma once
#include <list>
using namespace std;
// һ����¼record
class TicketsType{
public:
	TicketsType(): id(0){}
public:
	int id;
	char CustomerID[8];		//�ÿͼ�¼��
	char ArriveDate[16];		//��������
	char ArriveFlight[16];	//���ﺽ��
	char DepartDate[16];		//��������
	char DepartFlight[16];	//��������
	int CustomerNum;		//�˿�����
};
// ������¼���б�
typedef list<TicketsType> TicketsTypeList;