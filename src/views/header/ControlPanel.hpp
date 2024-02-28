#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP

#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

class ControlPanel : public QWidget {
  Q_OBJECT

 public:
  explicit ControlPanel(QWidget* parent = nullptr);
  void setStartEnabled(bool enabled);

 signals:
  void startPressed();
  void stopPressed();
  void clearPressed();

 private:
  QPushButton* startButton;
  QPushButton* stopButton;
  QPushButton* resetButton;
};

#endif  // CONTROLPANEL_HPP
