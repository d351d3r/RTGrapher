#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "DataGenerator.hpp"
#include "ui_MainWindow.h"  // Добавляем сгенерированный заголовочный файл

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);

 private slots:
  void onStartButtonClicked();
  void onStopButtonClicked();
  void onResetButtonClicked();

 private:
  Ui::MainWindow* ui;  // Указатель на сгенерированный класс UI
  DataGenerator* dataGenerator;  // Указатель на класс генератора данных
};

#endif  // MAINWINDOW_HPP
