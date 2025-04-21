#include "DialogPlanEdit.h"

#include <QDebug>
#include <QLayout>
#include <QPushButton>

DialogPlanEdit::DialogPlanEdit(Plan &plan, QWidget *parent) :
	QDialog(parent),
	plan{plan}
{
	QVBoxLayout *vlo_main = new QVBoxLayout(this);
	QHBoxLayout *hlo1 = new QHBoxLayout;
	QHBoxLayout *hlo2 = new QHBoxLayout;
	QHBoxLayout *hlo3 = new QHBoxLayout;
	QHBoxLayout *hlo4 = new QHBoxLayout;
	vlo_main->addLayout(hlo1);
	vlo_main->addLayout(hlo2);
	vlo_main->addLayout(hlo3);
	vlo_main->addLayout(hlo4);

	leName = new QLineEdit;
	hlo1->addWidget(leName);

	QPushButton *btn1 = new QPushButton("button1");
	hlo2->addWidget(btn1);
	connect(btn1,&QPushButton::clicked,[](){ qDebug() << "button1"; });

	QPushButton *btn2 = new QPushButton("button2");
	hlo2->addWidget(btn2);

	hlo2->addStretch();

	textEditContent = new QTextEdit;
	hlo3->addWidget(textEditContent);

	hlo4->addStretch();
	QPushButton *btnAccept = new QPushButton("Accept");
	hlo4->addWidget(btnAccept);
	connect(btnAccept,&QPushButton::clicked,[this](){ returnValue = true; SetPlanFromWidgets(); close(); });
	QPushButton *btnCansel = new QPushButton("Cansel");
	hlo4->addWidget(btnCansel);
	connect(btnCansel,&QPushButton::clicked,[this](){ close(); });

	SetWidgetsFromPlan();
}

void DialogPlanEdit::SetWidgetsFromPlan()
{
	leName->setText(plan.name);
	textEditContent->setPlainText(plan.content);
}

void DialogPlanEdit::SetPlanFromWidgets()
{
	plan.name = leName->text();
	plan.content = textEditContent->toPlainText();
}
