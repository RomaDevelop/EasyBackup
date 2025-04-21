#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>
#include <QListWidget>

#include "Plan.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	std::vector<Plan> plans;
	void SlotCreateNewPlan();
	void SlotEditCurrentPlan();
	void PlansToListWidget();
	QListWidget *listWidgPlans;

};
#endif // MAINWINDOW_H
