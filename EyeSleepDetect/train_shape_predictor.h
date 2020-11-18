#ifndef TRAIN_SHAPE_PREDICTOR_H
#define TRAIN_SHAPE_PREDICTOR_H

#include <QObject>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "dlib/data_io.h"
#include "dlib/external/libjpeg/jpeglib.h"
#include "GlobalFile.h"
#include <QDebug>
using namespace dlib;
using namespace std;

class Train_Shape_Predictor : public QObject
{
    Q_OBJECT
public:
    explicit Train_Shape_Predictor(QObject *parent = nullptr);
    // ----------------------------------------------------------------------------------------

    double interocular_distance (const full_object_detection& det );
    /*!
        ensures
            - returns an object D such that:
                - D[i][j] == the distance, in pixels, between the eyes for the face represented
                  by objects[i][j].
    !*/

    // ----------------------------------------------------------------------------------------
    std::vector<std::vector<double> > get_interocular_distances (const std::vector<std::vector<full_object_detection> > &objects );
    void GeneratedtrainerFile();
signals:


};

#endif // TRAIN_SHAPE_PREDICTOR_H
