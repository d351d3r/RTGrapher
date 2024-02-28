#include "DataGenerator.hpp"

DataGenerator::DataGenerator(QObject* parent)
    : QThread(parent), running(false), x(0) {}

DataGenerator::~DataGenerator() {
  stopGenerator();
  wait();
}

void DataGenerator::startGenerator() {
  QMutexLocker locker(&mutex);
  if (!running) {
    running = true;
    if (!isRunning()) {
      start();
    }
  }
}

void DataGenerator::stopGenerator() {
  QMutexLocker locker(&mutex);
  running = false;
}

void DataGenerator::resetGenerator() {
  QMutexLocker locker(&mutex);
  running = false;
  x = 0;
}

void DataGenerator::run() {
  while (running) {
    {
      QMutexLocker locker(&mutex);
      int y = QRandomGenerator::global()->bounded(100);
      emit newDataPoint(x++, y);
    }  // MutexLocker выходит из области видимости и разблокирует mutex здесь
    QThread::msleep(100);  // Adjust the sleep time as needed
  }
}
