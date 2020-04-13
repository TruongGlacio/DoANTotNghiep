// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*

    This example shows how to use the correlation_tracker from the dlib C++ library.  This
    object lets you track the position of an object as it moves from frame to frame in a
    video sequence.  To use it, you give the correlation_tracker the bounding box of the
    object you want to track in the current video frame.  Then it will identify the
    location of the object in subsequent frames.

    In this particular example, we are going to run on the video sequence that comes with
    dlib, which can be found in the examples/video_frames folder.  This video shows a juice
    box sitting on a table and someone is waving the camera around.  The task is to track the
    position of the juice box as the camera moves around.
*/
#ifndef VIDEO_TRACKING_H
#define VIDEO_TRACKING_H

#include <QObject>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <dlib/dir_nav.h>
#include "CameraManager/cameramanager.h"

using namespace dlib;
using namespace std;

class video_tracking : public QObject
{
    Q_OBJECT
public:
    explicit video_tracking(QObject *parent = nullptr);
    int video_tracking_hand(int argc, char** argv);
    void CaptureImage();

//signals:
CameraManager mCamera;
public slots:
    void getImagePath(QString imagePath);

};

#endif // VIDEO_TRACKING_H
