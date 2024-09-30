#include "code.h"
#include <adddialog.h>

code::code(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

code::~code()
{}

void code::on_addButton_clicked() {

    AddDialog dialog(this);

    if (dialog.exec()) {
        QString name = dialog.nameEdit->text();
        QString email = dialog.emailEdit->text();


        if (!name.isEmpty() && !email.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem(name, ui.weeklyExpenses);
            item->setData(Qt::UserRole, email);
            ui.weeklyExpenses->setCurrentItem(item);
        }
    }  
}

void code::on_weeklyExpenses_currentItemChanged() {
    QListWidgetItem* curItem = ui.weeklyExpenses->currentItem();

    if (curItem) {
        ui.nameLabel->setText("Name: " + curItem->text());
        ui.emailLabel->setText("Email: " + curItem->data(Qt::UserRole).toString());
    }
    else {
        ui.nameLabel->setText("<No item selected>");
        ui.emailLabel->clear();
    }
}

void code::on_deleteButton_clicked() {
    QListWidgetItem* curItem = ui.weeklyExpenses->currentItem();
    if (curItem) {
        int row = ui.weeklyExpenses->row(curItem);
        ui.weeklyExpenses->takeItem(row);
        delete curItem;

        if (ui.weeklyExpenses->count() > 0) {
            ui.weeklyExpenses->setCurrentRow(0);
        }
        else {
            on_weeklyExpenses_currentItemChanged();
        }
    }
}