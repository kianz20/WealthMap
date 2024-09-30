#pragma once

#include <QDialog>
#include "ui_adddialog.h"

class AddDialog : public QDialog, public Ui::AddDialogClass
{
	Q_OBJECT

public:
	AddDialog(QWidget *parent = nullptr);
	~AddDialog();

private:
	 
};
