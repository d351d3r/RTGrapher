#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include <QMutex>
#include <QMutexLocker>
#include <QRandomGenerator>
#include <QThread>

class DataGenerator : public QThread {
  Q_OBJECT

 public:
  explicit DataGenerator(QObject* parent = nullptr);
  ~DataGenerator();

  void startGenerator();
  void stopGenerator();
  void resetGenerator();

 signals:
  void newDataPoint(int x, int y);

 protected:
  void run() override;

 private:
  QMutex mutex;
  bool running;
  int x;
};

#endif  // DATAGENERATOR_HPP
