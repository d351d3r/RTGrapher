#include "ResultWidget.hpp"

ResultWidget::ResultWidget(QWidget* parent) : QListWidget(parent) {}

void ResultWidget::addResult(const QString& result) {
  addItem(result);
}

void ResultWidget::clearResults() {
  clear();
}
