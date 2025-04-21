#include "MainWindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QLayout>
#include <QPushButton>
#include <QTextBrowser>
#include <QSplitter>

#include "MyQShortings.h"

#include "DialogPlanEdit.h"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout *vlo_main = new QVBoxLayout(this);
	QHBoxLayout *hlo1 = new QHBoxLayout;
	QHBoxLayout *hlo2 = new QHBoxLayout;
	vlo_main->addLayout(hlo1);
	vlo_main->addLayout(hlo2);

	QPushButton *btn1 = new QPushButton("+");
	hlo1->addWidget(btn1);
	connect(btn1,&QPushButton::clicked, this, &MainWindow::SlotCreateNewPlan);

	hlo1->addStretch();

	auto splitter = new QSplitter;
	hlo2->addWidget(splitter);

	listWidgPlans = new QListWidget;
	splitter->addWidget(listWidgPlans);
	PlansToListWidget();
	connect(listWidgPlans, &QListWidget::itemDoubleClicked, this, &MainWindow::SlotEditCurrentPlan);
	splitter->addWidget(new QTextBrowser);
}

MainWindow::~MainWindow()
{
}

void MainWindow::SlotCreateNewPlan()
{
	Plan newPlan;
	if(DialogPlanEdit::Execute(newPlan))
	{
		plans.emplace_back(std::move(newPlan));
		PlansToListWidget();
	}
}

void MainWindow::SlotEditCurrentPlan()
{
	QString planName = listWidgPlans->currentItem()->text();
	Plan *planToEdit = nullptr;
	for(auto &plan:plans)
		if(plan.name == planName) planToEdit = &plan;

	if(!planToEdit) { QMbError("plan " + planName + " not found"); return; }

	if(DialogPlanEdit::Execute(*planToEdit))
		PlansToListWidget();
}

void MainWindow::PlansToListWidget()
{
	listWidgPlans->clear();
	for(auto &plan:plans)
		listWidgPlans->addItem(plan.name);
}

