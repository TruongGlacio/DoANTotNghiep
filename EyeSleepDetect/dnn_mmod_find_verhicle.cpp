#include "dnn_mmod_find_verhicle.h"

dnn_mmod_find_verhicle::dnn_mmod_find_verhicle(QObject *parent) : QObject(parent)
{
    FUNCTION_LOG();
    InitialVerhicleDetector(SHAPE_PREDIRTOR_MMOD_VERHICLE);
}

void dnn_mmod_find_verhicle::DetectVerhicle(Mat frame)
{
    FUNCTION_LOG();

    try{
        cv::Mat im_small, im_display;
        cv::Mat frame1, frame2,frame3,frame4,frame5;
        full_object_detection shape;

        //resize frame to increase performance
        dlib::cv_image<bgr_pixel> cimg(frame);

        dlib::matrix<dlib::rgb_pixel> matrix;
        assign_image(matrix, cimg);
        //while(matrix.size() < 500*500)
        //pyramid_up(matrix);

        // Note that you can process a bunch of images in a std::vector at once and it runs
        // much faster, since this will form mini-batches of images and therefore get
        // better parallelism out of your GPU hardware.  However, all the images must be
        // the same size.  To avoid this requirement on images being the same size we
        // process them individually in this example.
        auto dets = mNet(matrix);
        cv::Rect cv_rect;
        int i=0 ;
        for (auto&& dlib_rect : dets){
            i++;
            cv::Rect cv_rect= cv::Rect(cv::Point2i(dlib_rect.rect.left(), dlib_rect.rect.top()), cv::Point2i(dlib_rect.rect.right(), dlib_rect.rect.bottom()));
            qDebug()<<"left="<<dlib_rect.rect.left()<<"TOP="<<dlib_rect.rect.top()<<"right =" <<dlib_rect.rect.right()<<"bottom= "<<dlib_rect.rect.bottom();
            cv::rectangle(frame, cv_rect, cv::Scalar(255, 0, 0),2,8,0);

            //win.add_overlay(d);
        }
        qDebug()<<"number of detect"<<i;
        emit SendVerhicleFrameDrawed(frame);

        // Detect verhicle
//        std::vector<dlib::rectangle> verhicle;
//        cv::Rect cv_rect;
//        // Run the detector on the image and show us the output.
//        for (auto&& d : mNet(matrix))
//        {
//            // We use a shape_predictor to refine the exact shape and location of the detection
//            // box.  This shape_predictor is trained to simply output the 4 corner points of
//            // the box.  So all we do is make a rectangle that tightly contains those 4 points
//            // and that rectangle is our refined detection position.
//            auto fd = mSp(matrix,d);
//            dlib::rectangle dlib_rect;
//            for (unsigned long j = 0; j < fd.num_parts(); ++j)
//                dlib_rect += fd.part(j);

//            cv_rect= cv::Rect(cv::Point2i(dlib_rect.left(), dlib_rect.top()), cv::Point2i(dlib_rect.right() + 1, dlib_rect.bottom() + 1));

//            cv::rectangle(frame, cv_rect, cv::Scalar(0, 255, 0),2,8,0);
//        }

//        const float lower = -2.5;
//        const float upper = 0.0;
//        cout << "jet color mapping range:  lower="<< lower << "  upper="<< upper << endl;



//        // Create a tiled pyramid image and display it on the screen.
//        std::vector<dlib::rectangle> rects;
//        dlib::matrix<rgb_pixel> tiled_img;

//        // Get the type of pyramid the CNN used
//        using pyramid_type = std::remove_reference<decltype(input_layer(mNet))>::type::pyramid_type;
//        // And tell create_tiled_pyramid to create the pyramid using that pyramid type.
//        create_tiled_pyramid<pyramid_type>(matrix, tiled_img, rects,
//                                           input_layer(mNet).get_pyramid_padding(),
//                                           input_layer(mNet).get_pyramid_outer_padding());

//        //image_window winpyr(tiled_img, "Tiled pyramid");

//        // This CNN detector represents a sliding window detector with 3 sliding windows.  Each
//        // of the 3 windows has a different aspect ratio, allowing it to find vehicles which
//        // are either tall and skinny, squarish, or short and wide.  The aspect ratio of a
//        // detection is determined by which channel in the output image triggers the detection.
//        // Here we are just going to max pool the channels together to get one final image for
//        // our display.  In this image, a pixel will be bright if any of the sliding window
//        // detectors thinks there is a car at that location.
//        qDebug() << "Number of channels in final tensor image: " << mNet.subnet().get_output().k() << endl;
//        dlib::matrix<float> network_output = image_plane(mNet.subnet().get_output(),0,0);
//        for (long k = 1; k < mNet.subnet().get_output().k(); ++k)
//            network_output = max_pointwise(network_output, image_plane(mNet.subnet().get_output(),0,k));
//        // We will also upsample the CNN's output image.  The CNN we defined has an 8x
//        // downsampling layer at the beginning. In the code below we are going to overlay this
//        // CNN output image on top of the raw input image.  To make that look nice it helps to
//        // upsample the CNN output image back to the same resolution as the input image, which
//        // we do here.
//        const double network_output_scale = matrix.nc()/(double)network_output.nc();
//        resize_image(network_output_scale, network_output);
//        // Display the network's output as a color image.
//        image_window win_output(jet(network_output, upper, lower), "Output tensor from the network");
//        // Also, overlay network_output on top of the tiled image pyramid and display it.
//        for (long r = 0; r < tiled_img.nr(); ++r)
//        {
//            for (long c = 0; c < tiled_img.nc(); ++c)
//            {
//                dpoint tmp(c,r);
//                tmp = input_tensor_to_output_tensor(mNet, tmp);
//                tmp = point(network_output_scale*tmp);
//                if (get_rect(network_output).contains(tmp))
//                {
//                    float val = network_output(tmp.y(),tmp.x());
//                    // alpha blend the network output pixel with the RGB image to make our
//                    // overlay.
//                    rgb_alpha_pixel p;
//                    assign_pixel(p , colormap_jet(val,lower,upper));
//                    p.alpha = 120;
//                    assign_pixel(tiled_img(r,c), p);
//                }
//            }
//        }
//        // them.  That's the CNN saying "there is a car here!".  You will also notice there is
//        // a certain scale at which it finds cars.  They have to be not too big or too small,
//        // which is why we have an image pyramid.  The pyramid allows us to find cars of all
//        // scales.
//        image_window win_pyr_overlay(tiled_img, "Detection scores on image pyramid");




//        // Finally, we can collapse the pyramid back into the original image.  The CNN doesn't
//        // actually do this step, since it's enough to threshold the tiled pyramid image to get
//        // the detections.  However, it makes a nice visualization and clearly indicates that
//        // the detector is firing for all the cars.
//        dlib::matrix<float> collapsed(matrix.nr(), matrix.nc());
//        resizable_tensor input_tensor;
//        input_layer(mNet).to_tensor(&matrix, &matrix+1, input_tensor);
//        for (long r = 0; r < collapsed.nr(); ++r)
//        {
//            for (long c = 0; c < collapsed.nc(); ++c)
//            {
//                // Loop over a bunch of scale values and look up what part of network_output
//                // corresponds to the point(c,r) in the original image, then take the max
//                // detection score over all the scales and save it at pixel point(c,r).
//                float max_score = -1e30;
//                for (double scale = 1; scale > 0.2; scale *= 5.0/6.0)
//                {
//                    // Map from input image coordinates to tiled pyramid coordinates.
//                    dpoint tmp = center(input_layer(mNet).image_space_to_tensor_space(input_tensor,scale, drectangle(dpoint(c,r))));
//                    // Now map from pyramid coordinates to network_output coordinates.
//                    tmp = point(network_output_scale*input_tensor_to_output_tensor(mNet, tmp));

//                    if (get_rect(network_output).contains(tmp))
//                    {
//                        float val = network_output(tmp.y(),tmp.x());
//                        if (val > max_score)
//                            max_score = val;
//                    }
//                }

//                collapsed(r,c) = max_score;

//                // Also blend the scores into the original input image so we can view it as
//                // an overlay on the cars.
//                rgb_alpha_pixel p;
//                assign_pixel(p , colormap_jet(max_score,lower,upper));
//                p.alpha = 120;
//                assign_pixel(matrix(r,c), p);
//            }
//        }
        //cv::Mat frame_Output = dlib::toMat(matrix);
        //cv::rectangle(frame_Output, cv_rect, cv::Scalar(0, 255, 0),1,8,0);
        //emit SendVerhicleFrameDrawed(frame_Output);

    }

    catch(image_load_error& e)
    {
        cout << e.what() << endl;
        cout << "The test image is located in the examples folder.  So you should run this program from a sub folder so that the relative path is correct." << endl;
    }
    catch(serialization_error& e)
    {
        cout << e.what() << endl;
        cout << "The correct model file can be obtained from: http://dlib.net/files/mmod_rear_end_vehicle_detector.dat.bz2" << endl;
    }
    catch(std::exception& e)
    {
        cout << e.what() << endl;
    }
}

void dnn_mmod_find_verhicle::InitialVerhicleDetector(string shapeDetectorPath)
{

    // You can get this file from http://dlib.net/files/mmod_rear_end_vehicle_detector.dat.bz2
    // This network was produced by the dnn_mmod_train_find_cars_ex.cpp example program.
    // As you can see, the file also includes a separately trained shape_predictor.  To see
    // a generic example of how to train those refer to train_shape_predictor_ex.cpp.
    deserialize(shapeDetectorPath) >> mNet;// >> mSp;

}

Mat dnn_mmod_find_verhicle::DrawandVerhicleLineOnFrame(full_object_detection shape, Mat frame)
{

}

Mat dnn_mmod_find_verhicle::DrawRVerhicleDetectStatus(Mat frame, string verhicledetectStatus)
{

}

std::vector<dlib::rectangle> dnn_mmod_find_verhicle::ResizeBoxes(std::vector<dlib::rectangle> rects, int scaleFactor)
{

}
