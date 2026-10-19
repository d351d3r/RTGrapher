#include "DataController.hpp"
#include "GraphWidget.hpp"  // Include if you're using GraphWidget directly

DataController::DataController(QObject* parent)
    : QObject(parent),
      dataGenerator(new DataGenerator(this)),
      graphWidget(new GraphWidget()) {
  // Connect the controller's signals to the data generator's slots
  connect(this, &DataController::startDataGeneration, dataGenerator,
          &DataGenerator::startGenerator);
  connect(this, &DataController::stopDataGeneration, dataGenerator,
          &DataGenerator::stopGenerator);
  connect(this, &DataController::resetDataGeneration, dataGenerator,
          &DataGenerator::resetGenerator);

  // Connect the data generator's signal to the graph widget's slot
  connect(dataGenerator, &DataGenerator::newDataPoint, graphWidget,
          &GraphWidget::updateGraph);
}

// Implementation of slots that control the data generator
void DataController::startData() {
  qDebug() << "Start data generation";
  emit startDataGeneration();
}

void DataController::stopData() {
  emit stopDataGeneration();
}

void DataController::resetData() {
  emit resetDataGeneration();
}
