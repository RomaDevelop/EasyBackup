#ifndef DIALOGPLANEDIT_H
#define DIALOGPLANEDIT_H

#include <memory>
#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>

#include "Plan.h"

class DialogPlanEdit : public QDialog
{
	Q_OBJECT

	explicit DialogPlanEdit(Plan &plan, QWidget *parent = nullptr);

public:
	static bool Execute(Plan &plan)
	{
		std::unique_ptr<DialogPlanEdit> dialog(new DialogPlanEdit(plan));
		dialog->exec();
		return dialog->returnValue;
	}

private:
	Plan &plan;
	QLineEdit *leName;
	QTextEdit *textEditContent;
	bool returnValue = false;

	void SetWidgetsFromPlan();
	void SetPlanFromWidgets();
};

#endif // DIALOGPLANEDIT_H
