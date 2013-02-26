#include "CameraSubsystem.h"
#include "../RobotMap.h"

#include "Vision/RGBImage.h"

// If a filename is passed in with the constructor, the camera will
// use a saved file intead of capturing an image.  To save the camera
// capture, use the default constructor and then call RetainImage().
CameraSubsystem::CameraSubsystem(const char * filename) : Subsystem("CameraSubsystem") {
    camera           = &AxisCamera::GetInstance(CAMERA_IP_ADDR);
    image            = 0;
    preserveImage    = false;
    useImageFile     = false;
    imageFilename[0] = '\0';

    if (filename != 0) {
        strncpy(imageFilename, filename, CAMERA_SUBSYSTEM_FILENAME_LENGTH - 1);
        imageFilename[CAMERA_SUBSYSTEM_FILENAME_LENGTH - 1] = '\0';
        useImageFile = true;
    }
}

CameraSubsystem::~CameraSubsystem() {
    delete image;
}

// Captures the image or uses an existing captured image from
// a file depending on how the object was constructed.  If
// the default constructor was used and RetainImage called,
// the capture is saved to a file.
//
// The returned pointer is owned by CameraSubsystem and should
// not be deleted.
ColorImage * CameraSubsystem::CaptureImage() {
    delete image;
    image = 0;

    if (useImageFile) {
        image = new HSLImage(imageFilename);
    } else {
        image = camera->GetImage();
        if (preserveImage && image != 0) { image->Write(imageFilename); }
    }

    return image;
}

// Gets the last captured image.  If no image has yet been
// captured, does the capture first.
//
// The returned pointer is owned by CameraSubsystem and should
// not be deleted.
ColorImage * CameraSubsystem::GetImage() {
    if (image == 0) { CaptureImage(); }

    return image;
}

// Configures the Camera subsystem to retain the captured images in
// a file.  Will activate camera captures if they were previously
// disabled by reading a file on capture.
void CameraSubsystem::RetainImage(const char * filename) {
    if (useImageFile) { return; }   // not compatible - just bail out

    if (filename == 0 || strlen(filename) == 0) {
        imageFilename[0] = '\0';
        preserveImage = false;
    } else {
        strncpy(imageFilename, filename, CAMERA_SUBSYSTEM_FILENAME_LENGTH - 1);
        imageFilename[CAMERA_SUBSYSTEM_FILENAME_LENGTH - 1] = '\0';
        preserveImage       = true;
    }
}
