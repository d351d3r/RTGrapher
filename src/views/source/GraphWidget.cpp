#include "GraphWidget.hpp"

GraphWidget::GraphWidget(QWidget* parent) : QWidget(parent) {}

void GraphWidget::addPoint(double x, double y) {
  qDebug() << "Adding point:" << x << y;
  dataPoints.append(QPointF(x, y));
  update();
}
void GraphWidget::updateGraph(int x, int y) {
  addPoint(x,
           y);  // Добавление точки и обновление графика могут быть объединены
  // Дополнительная логика обновления, если требуется
}

void GraphWidget::clearData() {
  dataPoints.clear();  // Очистка всех точек данных
  update();  // Запрос на перерисовку виджета
}

void GraphWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // Отрисовка осей координат
  painter.drawLine(10, height() - 10, 10, 10);  // Вертикальная ось
  painter.drawLine(10, height() - 10, width() - 10,
                   height() - 10);  // Горизонтальная ось
  qDebug() << "Drawing graph with" << dataPoints.size() << "points";

  if (!dataPoints.isEmpty()) {
    painter.setPen(QPen(Qt::blue, 2));  // Настройка стиля линии
    QPointF previousPoint = mapToWidget(dataPoints.first());
    for (int i = 1; i < dataPoints.size(); ++i) {
      QPointF currentPoint = mapToWidget(dataPoints[i]);
      painter.drawLine(previousPoint, currentPoint);
      previousPoint = currentPoint;
    }
  }
}

QPointF GraphWidget::mapToWidget(const QPointF& point) {
  // Простейшее масштабирование для примера
  // Предполагаем, что данные находятся в диапазоне [0, 100] для обеих осей
  qreal xScale =
      (width() - 20) / 100.0;  // Оставляем поля по 10 пикселей с каждой стороны
  qreal yScale = (height() - 20) / 100.0;
  return QPointF(10 + point.x() * xScale, height() - 10 - point.y() * yScale);
}
