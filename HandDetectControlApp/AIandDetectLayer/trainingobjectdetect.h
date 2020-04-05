#ifndef TRAININGOBJECTDETECT_H
#define TRAININGOBJECTDETECT_H

// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*

    This is an example showing how you might use dlib to create a reasonably
    functional command line tool for object detection.  This example assumes
    you are familiar with the contents of at least the following example
    programs:
        - fhog_object_detector_ex.cpp
        - compress_stream_ex.cpp




    This program is a command line tool for learning to detect objects in images.
    Therefore, to create an object detector it requires a set of annotated training
    images.  To create this annotated data you will need to use the imglab tool
    included with dlib.  It is located in the tools/imglab folder and can be compiled
    using the following commands.
        cd tools/imglab
        mkdir build
        cd build
        cmake ..
        cmake --build . --config Release
    Note that you may need to install CMake (www.cmake.org) for this to work.

    Next, let's assume you have a folder of images called /tmp/images.  These images
    should contain examples of the objects you want to learn to detect.  You will
    use the imglab tool to label these objects.  Do this by typing the following
        ./imglab -c mydataset.xml /tmp/images
    This will create a file called mydataset.xml which simply lists the images in
    /tmp/images.  To annotate them run
        ./imglab mydataset.xml
    A window will appear showing all the images.  You can use the up and down arrow
    keys to cycle though the images and the mouse to label objects.  In particular,
    holding the shift key, left clicking, and dragging the mouse will allow you to
    draw boxes around the objects you wish to detect.  So next, label all the objects
    with boxes.  Note that it is important to label all the objects since any object
    not labeled is implicitly assumed to be not an object we should detect.  If there
    are objects you are not sure about you should draw a box around them, then double
    click the box and press i.  This will cross out the box and mark it as "ignore".
    The training code in dlib will then simply ignore detections matching that box.


    Once you finish labeling objects go to the file menu, click save, and then close
    the program. This will save the object boxes back to mydataset.xml.  You can verify
    this by opening the tool again with
        ./imglab mydataset.xml
    and observing that the boxes are present.

    Returning to the present example program, we can compile it using cmake just as we
    did with the imglab tool.  Once compiled, we can issue the command
        ./train_object_detector -tv mydataset.xml
    which will train an object detection model based on our labeled data.  The model
    will be saved to the file object_detector.svm.  Once this has finished we can use
    the object detector to locate objects in new images with a command like
        ./train_object_detector some_image.png
    This command will display some_image.png in a window and any detected objects will
    be indicated by a red box.

    Finally, to make running this example easy dlib includes some training data in the
    examples/faces folder.  Therefore, you can test this program out by running the
    following sequence of commands:
      ./train_object_detector -tv examples/faces/training.xml -u1 --flip
      ./train_object_detector --test examples/faces/testing.xml -u1
      ./train_object_detector examples/faces/*.jpg -u1
    That will make a face detector that performs perfectly on the test images listed in
    testing.xml and then it will show you the detections on all the images.
*/

#define DLIB_GIF_SUPPORT 0
#include <dlib/svm_threaded.h>
#include <dlib/string.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_processing.h>
#include <dlib/data_io.h>
#include <dlib/cmd_line_parser.h>
#include <iostream>
#include <fstream>
#include <QObject>
using namespace std;
using namespace dlib;
using namespace image_dataset_metadata;
class TrainingObjectDetect : public QObject
{
    Q_OBJECT
public:
    explicit TrainingObjectDetect(QObject *parent = nullptr);
    void pick_best_window_size(const std::vector<std::vector<rectangle> >& boxes,
                               unsigned long& width,
                               unsigned long& height,
                               const unsigned long target_size);
    bool contains_any_boxes(const std::vector<std::vector<rectangle> >& boxes);
    void throw_invalid_box_error_message(const std::string& dataset_filename,
                                         const std::vector<std::vector<rectangle> >& removed,
                                         const unsigned long target_size);
    int train_object_detector(int argc, char** argv);

signals:

};

#endif // TRAININGOBJECTDETECT_H






