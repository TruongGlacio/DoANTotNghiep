#ifndef TRAINOBJECTDETECTOR_H
#define TRAINOBJECTDETECTOR_H

#include <QObject>

class TrainObjectDetector : public QObject
{
    Q_OBJECT
public:
    explicit TrainObjectDetector(QObject *parent = nullptr);

signals:

};

#endif // TRAINOBJECTDETECTOR_H
