#include "eulerproject.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EulerProject w;
	w.show();
	return a.exec();
}
