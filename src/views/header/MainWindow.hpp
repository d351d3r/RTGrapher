#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "DataGenerator.hpp"
#include "ui_MainWindow.h"  // Убедитесь, что название совпадает с сгенерированным файлом

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();  // Добавляем деструктор

 private slots:
  void onStartButtonClicked();
  void onStopButtonClicked();
  void onResetButtonClicked();

 private:
  Ui::MainWindow* ui;
  DataGenerator* dataGenerator;
};

#endif  // MAINWINDOW_HPP
