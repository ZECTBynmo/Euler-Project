#ifndef EULERPROJECT_H
#define EULERPROJECT_H

#include <QtGui/QMainWindow>
#include "ui_eulerproject.h"
#include "C:\Users\ZECTBynmo\Documents\Visual Studio 2008\Projects\EulerProject\EulerProject\ProblemSolver.h"

class EulerProject : public QMainWindow
{
	Q_OBJECT

public:
	EulerProject(QWidget *parent = 0, Qt::WFlags flags = 0);
	~EulerProject();

private:
	Ui::EulerProjectClass ui;

	Solvers::ProblemSolver* m_pProblemSolver;
};

#endif // EULERPROJECT_H
