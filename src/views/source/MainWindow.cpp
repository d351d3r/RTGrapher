#include "MainWindow.hpp"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), dataGenerator(new DataGenerator(this)) {
  auto centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  auto layout = new QVBoxLayout(centralWidget);

  graphWidget = new GraphWidget();
  graphWidget->setMinimumSize(640, 480);
  controlPanel = new ControlPanel();
  resultWidget = new ResultWidget();

  layout->addWidget(graphWidget);
  layout->addWidget(controlPanel);
  layout->addWidget(resultWidget);

  connect(controlPanel, &ControlPanel::startPressed, this,
          &MainWindow::onStartButtonClicked);
  connect(controlPanel, &ControlPanel::stopPressed, this,
          &MainWindow::onStopButtonClicked);
  connect(controlPanel, &ControlPanel::clearPressed, this,
          &MainWindow::onResetButtonClicked);
  connect(dataGenerator, &DataGenerator::newDataPoint, graphWidget,
          &GraphWidget::addPoint);
}

void MainWindow::onStartButtonClicked() {
  qDebug() << "Start button was clicked";
  dataGenerator->startGenerator();
  ui->startButton->setEnabled(false);  // Деактивируем кнопку "Start"
  ui->stopButton->setEnabled(true);  // Активируем кнопку "Stop"
  ui->resetButton->setEnabled(
      false);  // Деактивируем кнопку "Reset" до остановки генерации
}

void MainWindow::onStopButtonClicked() {
  qDebug() << "Stop button was clicked";
  dataGenerator->stopGenerator();
  ui->startButton->setEnabled(
      true);  // Возвращаем кнопку "Start" в активное состояние
  ui->stopButton->setEnabled(false);  // Деактивируем кнопку "Stop"
  ui->resetButton->setEnabled(
      true);  // Активируем кнопку "Reset", так как генерация остановлена
}

void MainWindow::onResetButtonClicked() {
  qDebug() << "Reset button was clicked";
  // Остановка генератора, если это еще не было сделано
  if (dataGenerator->isRunning()) {
    dataGenerator->stopGenerator();
  }
  ui->graphWidget->clearData();  // Очищаем данные графика
  ui->resultWidget->clear();  // Очищаем список результатов
  // Состояние кнопок после сброса данных
  ui->startButton->setEnabled(true);
  ui->stopButton->setEnabled(
      false);  // Убедимся, что кнопка "Stop" деактивирована
  ui->resetButton->setEnabled(
      false);  // Деактивируем кнопку "Reset", так как уже нет данных для сброса
}
