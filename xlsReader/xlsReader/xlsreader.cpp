#include "xlsreader.h"

xlsReader::xlsReader(QWidget *parent, Qt::WFlags flags)	: QMainWindow(parent, flags){
	ui.setupUi(this);
	ReadExcel excel;
	excel.openExcel("C:/Users/Administrator/Downloads/MathF/xlsReader/xlsReader/test.xls");
	std::string str = excel.getCellData(1,1);
}

xlsReader::~xlsReader(){

}
