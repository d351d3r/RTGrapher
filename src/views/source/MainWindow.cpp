#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  dataGenerator = new DataGenerator(this);

  // Подключаем сигналы от кнопок к слотам
  connect(ui->startButton, &QPushButton::clicked, this,
          &MainWindow::onStartButtonClicked);
  connect(ui->stopButton, &QPushButton::clicked, this,
          &MainWindow::onStopButtonClicked);
  connect(ui->resetButton, &QPushButton::clicked, this,
          &MainWindow::onResetButtonClicked);

  // Подключение генератора данных к виджету графика
  // Убедитесь, что у вас правильно настроены имена объектов в файле .ui
  connect(dataGenerator, &DataGenerator::newDataPoint, ui->graphWidget,
          &GraphWidget::addPoint);  // Исправьте GraphWidget на graphWidget
}

MainWindow::~MainWindow() {
  delete ui;  // Освобождаем ресурсы, выделенные для UI
  delete dataGenerator;  // Освобождаем ресурсы, выделенные для dataGenerator
}

void MainWindow::onStartButtonClicked() {
  qDebug() << "Start button was clicked";
  dataGenerator->startGenerator();
  ui->startButton->setEnabled(false);
  ui->stopButton->setEnabled(true);
  ui->resetButton->setEnabled(
      false);  // Деактивируем кнопку "Reset" до остановки генерации
}

void MainWindow::onStopButtonClicked() {
  qDebug() << "Stop button was clicked";
  dataGenerator->stopGenerator();
  ui->startButton->setEnabled(true);  // Активируем кнопку "Start" обратно
  ui->stopButton->setEnabled(false);
  ui->resetButton->setEnabled(
      true);  // Активируем кнопку "Reset", так как генерация остановлена
}

void MainWindow::onResetButtonClicked() {
  qDebug() << "Reset button was clicked";
  dataGenerator
      ->stopGenerator();  // Остановка генерации данных, если она активна
  ui->graphWidget->clearData();  // Очистка данных графика
  ui->resultsListWidget->clear();  // Очистка списка результатов
  ui->startButton->setEnabled(true);
  ui->stopButton->setEnabled(false);
  ui->resetButton->setEnabled(false);
}
