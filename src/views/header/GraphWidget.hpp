#ifndef GRAPHWIDGET_HPP
#define GRAPHWIDGET_HPP

#include <QPainter>
#include <QPointF>
#include <QVector>
#include <QWidget>

class GraphWidget : public QWidget {
  Q_OBJECT

 public:
  explicit GraphWidget(QWidget* parent = nullptr);
  void addPoint(double x, double y);
  void clearData();
  void updateGraph(int x, int y);

 protected:
  void paintEvent(QPaintEvent* event) override;

 private:
  QVector<QPointF> dataPoints;  // Контейнер для хранения точек данных

  QPointF mapToWidget(
      const QPointF&
          point);  // Преобразование точек данных в координаты виджета
};

#endif  // GRAPHWIDGET_HPP
