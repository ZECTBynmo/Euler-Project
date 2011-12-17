#include "eulerproject.h"
#include "ProblemSolver.h"

EulerProject::EulerProject(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	
	m_pProblemSolver= new Solvers::ProblemSolver( uint(0) );
}

EulerProject::~EulerProject()
{

}
