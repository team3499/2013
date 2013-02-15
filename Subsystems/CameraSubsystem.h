#ifndef CAMERA_SUBSYSTEM_H
#define CAMERA_SUBSYSTEM_H

#include "WPILib.h"

#define CAMERA_SUBSYSTEM_FILENAME_LENGTH 128

class CameraSubsystem : public Subsystem {

public:
                              CameraSubsystem(const char * filename = 0);
    virtual                   ~CameraSubsystem();

    const ColorImage *        CaptureImage();                     // captures a new image
    const ColorImage *        GetImage();                         // returns existing image
    void                      RetainImage(const char * filename); // writes captures to flash

private:
    AxisCamera *              camera;
    ColorImage *              image;

    bool                      preserveImage;
    bool                      useImageFile;

    char                      imageFilename[CAMERA_SUBSYSTEM_FILENAME_LENGTH];
};

#endif /* CAMERA_SUBSYSTEM_H */
