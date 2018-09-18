#include "DataManager.h"
DataManager::DataManager(void){
//	loadPucks();
//	loadTickets();
//	loadGates();
}
DataManager::~DataManager(void){}
int DataManager::loadPucks(){
	FILE* fp = fopen("Pucks.data", "rb");
	if(!fp) return 0;
	m_Pucks.clear(); // 清空
	// 加载数据	
	while( !feof(fp)){
		PucksType record;
		int n = fread(&record, 1, sizeof(PucksType), fp);
		if( n < 0 ) break;
		if( n == 0) continue;
		m_Pucks.push_back(record);
	}
	fclose(fp);
	return 0;
}
int DataManager::loadTickets(){
	FILE* fp = fopen("Tickets.data", "rb");
	if(!fp) return 0;
	m_Tickets.clear(); // 清空
	// 加载数据	
	while( !feof(fp)){
		TicketsType record;
		int n = fread(&record, 1, sizeof(TicketsType), fp);
		if( n < 0 ) break;
		if( n == 0) continue;
		m_Tickets.push_back(record);
	}
	fclose(fp);
	return 0;
}
int DataManager::loadGates(){
	FILE* fp = fopen("Gates.data", "rb");
	if(!fp) return 0;
	m_Gates.clear(); // 清空
	// 加载数据	
	while( !feof(fp)){
		GatesType record;
		int n = fread(&record, 1, sizeof(GatesType), fp);
		if( n < 0 ) break;
		if( n == 0) continue;
		m_Gates.push_back(record);
	}
	fclose(fp);
	return 0;
}
int DataManager::saveGates(){
	FILE* fp = fopen("Gates.data", "wb");
	if(!fp) return -1;
	// 保存每条记录
	for(GatesTypeList::iterator iter = m_Gates.begin();	iter != m_Gates.end(); iter ++){
		GatesType& record = *iter;
		fwrite(&record, 1, sizeof(GatesType), fp);
	}
	fclose(fp);
	return 0;
}
int DataManager::addGates(GatesType& record){
	m_Gates.push_back(record);
	return 0;
}
int DataManager::savePucks(){
	FILE* fp = fopen("Pucks.data", "wb");
	if(!fp) return -1;
	// 保存每条记录
	for(PucksTypeList::iterator iter = m_Pucks.begin();	iter != m_Pucks.end(); iter ++){
		PucksType& record = *iter;
		fwrite(&record, 1, sizeof(PucksType), fp);
	}
	fclose(fp);
	return 0;
}
int DataManager::addPucks(PucksType& record){
	m_Pucks.push_back(record);
	return 0;
}
int DataManager::saveTickets(){
	FILE* fp = fopen("Tickets.data", "wb");
	if(!fp) return -1;
	// 保存每条记录
	for(TicketsTypeList::iterator iter = m_Tickets.begin();	iter != m_Tickets.end(); iter ++){
		TicketsType& record = *iter;
		fwrite(&record, 1, sizeof(TicketsType), fp);
	}
	fclose(fp);
	return 0;
}
int DataManager::addTickets(TicketsType& record){
	m_Tickets.push_back(record);
	return 0;
}