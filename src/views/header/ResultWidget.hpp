#ifndef RESULTWIDGET_HPP
#define RESULTWIDGET_HPP

#include <QListWidget>

class ResultWidget : public QListWidget {
  Q_OBJECT

 public:
  explicit ResultWidget(QWidget* parent = nullptr);

 public slots:
  void addResult(const QString& result);
  void clearResults();
};

#endif  // RESULTWIDGET_HPP
