#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddTask);
    connect(ui->markButton, &QPushButton::clicked, this, &MainWindow::onMarkAsCompleted);

    ui->taskTable->setColumnCount(3);
    ui->taskTable->setHorizontalHeaderLabels({"Дата", "Задача", "Статус"});

    ui->taskTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Дата
    ui->taskTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);          // Задача
    ui->taskTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Статус
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onAddTask()
{
    bool ok;
    QString task = QInputDialog::getText(this, "Добавить задачу", "Введите задачу:", QLineEdit::Normal, "", &ok);

    if (!ok || task.isEmpty()) {
        return;
    }

    int row = ui->taskTable->rowCount();
    ui->taskTable->insertRow(row);

    QTableWidgetItem *dateItem = new QTableWidgetItem(ui->dateEdit->date().toString("dd.MM.yyyy"));
    QTableWidgetItem *taskItem = new QTableWidgetItem(task);
    QTableWidgetItem *statusItem = new QTableWidgetItem("Не выполнено");

    ui->taskTable->setItem(row, 0, dateItem);
    ui->taskTable->setItem(row, 1, taskItem);
    ui->taskTable->setItem(row, 2, statusItem);
}

void MainWindow::onMarkAsCompleted()
{
    int currentRow = ui->taskTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::information(this, "Ошибка", "Ты ничё не выбрал.");
        return;
    }

    QTableWidgetItem *statusItem = ui->taskTable->item(currentRow, 2);
    if (statusItem->text() == "Выполнено") {
        QMessageBox::information(this, "Информация", "Задача уже выполнена.");
        return;
    }

    statusItem->setText("Выполнено");
}

