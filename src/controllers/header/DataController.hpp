#ifndef DATACONTROLLER_HPP  // Ensure this matches the file name and convention
#define DATACONTROLLER_HPP

#include <QObject>
#include "DataGenerator.hpp"  // Include if you're using DataGenerator in the header

class GraphWidget;  // Forward declaration if GraphWidget is used

class DataController : public QObject {
  Q_OBJECT

 public:
  explicit DataController(QObject* parent = nullptr);

 signals:
  void startDataGeneration();
  void stopDataGeneration();
  void resetDataGeneration();

 public slots:
  void startData();
  void stopData();
  void resetData();

 private:
  DataGenerator* dataGenerator;
  GraphWidget*
      graphWidget;  // Ensure you have a pointer to the GraphWidget if you're using it
};

#endif  // DATACONTROLLER_HPP
