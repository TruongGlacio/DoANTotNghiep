#ifndef TRAINOBJECTDETECTOR_H
#define TRAINOBJECTDETECTOR_H

#include <QObject>

#include <dlib/svm_threaded.h>
#include <dlib/string.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_processing.h>
#include <dlib/data_io.h>
#include <dlib/cmd_line_parser.h>
#include <iostream>
#include <fstream>



using namespace std;
using namespace dlib;
class TrainObjectDetector : public QObject
{
    Q_OBJECT
public:
    explicit TrainObjectDetector(QObject *parent = nullptr);
    bool GenerateObjectDetectorFile();
    void pick_best_window_size ( const std::vector<std::vector<rectangle> >& boxes,
                                 unsigned long& width,
                                 unsigned long& height,
                                 const unsigned long target_size);
    bool contains_any_boxes(const std::vector<std::vector<rectangle> >& boxes);
    void throw_invalid_box_error_message( const std::string& dataset_filename,
                                          const std::vector<std::vector<rectangle> >& removed,
                                          const unsigned long target_size);
signals:

};

#endif // TRAINOBJECTDETECTOR_H
