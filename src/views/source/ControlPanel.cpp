#include "ControlPanel.hpp"

ControlPanel::ControlPanel(QWidget* parent) : QWidget(parent) {
  startButton = new QPushButton("Start", this);
  stopButton = new QPushButton("Stop", this);
  resetButton = new QPushButton("Reset", this);

  // Установка компоновки для размещения кнопок
  auto layout = new QHBoxLayout();
  layout->addWidget(startButton);
  layout->addWidget(stopButton);
  layout->addWidget(resetButton);
  setLayout(layout);

  // Соединение сигналов кнопок с соответствующими слотами
  connect(startButton, &QPushButton::clicked, this,
          &ControlPanel::startPressed);
  connect(stopButton, &QPushButton::clicked, this, &ControlPanel::stopPressed);
  connect(resetButton, &QPushButton::clicked, this,
          &ControlPanel::clearPressed);
}

void ControlPanel::setStartEnabled(bool enabled) {
  if (startButton) {  // Добавлено для безопасности, чтобы избежать обращения к nullptr
    startButton->setEnabled(enabled);
  }
}
