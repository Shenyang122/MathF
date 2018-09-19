#pragma once
#include "PucksType.h"
#include "TicketsType.h"
#include "GatesType.h"
class DataManager{
public:
	DataManager(void);
	~DataManager(void);
	int loadPucks();
	int savePucks();
	int addPucks(PucksType& record);
	int loadTickets();
	int saveTickets();
	int addTickets(TicketsType& record);
	int loadGates();
	int saveGates();
	int addGates(GatesType& record);
	PucksTypeList& listPucks() { return m_Pucks; }
	TicketsTypeList& listTickets() { return m_Tickets; }
	GatesTypeList& listGates() { return m_Gates; }
public:
	char m_filename[256];
	PucksTypeList m_Pucks;	//ËùÓÐpucks¼ÇÂ¼
	TicketsTypeList m_Tickets;
	GatesTypeList m_Gates;
};

