#pragma once

#include <QtWidgets/QWidget>
#include "ui_code.h"

class code : public QWidget
{
    Q_OBJECT

private slots:
    void on_addButton_clicked();
    void on_weeklyExpenses_currentItemChanged();
    void on_deleteButton_clicked();

public:
    code(QWidget *parent = nullptr);
    ~code();

private:
    Ui::codeClass ui;
};
