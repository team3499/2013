#include "Commands/CameraTest.h"
#include "ImageProcessor.h"
#include "TargetReport.h"

CameraTest::CameraTest() {
    Requires(cameraSubsystem);
    Requires(cameraLEDsSubsystem);

    timer = new Timer;
}

void CameraTest::Initialize() {
    timer->Reset();
    timer->Start();
    printf("CameraTest::Initialize()\n");
}

void CameraTest::Execute() {
    cameraLEDsSubsystem->GreenOn();

    // Allow time for the LEDs to light up
    if (!timer->HasPeriodPassed(0.1)) { return; }

    // Capture an image from the camera and save it to flash
    timer->Reset();
    cameraSubsystem->RetainImage("/cameratest.jpg");
    ColorImage * image = cameraSubsystem->CaptureImage();
    cameraSubsystem->RetainImage(NULL);  // stop retaining
    printf("[CAMERA] Image captured to /cameratest.jpg in %01f ms\n", timer->Get() * 1000);

    // Process the captured image
    timer->Reset();
    ImageProcessor * ip = new ImageProcessor();
    ip->Process(image);
    printf("[CAMERA] Image processed in %01f ms\n", timer->Get() * 1000);

    // Write the processed images to flash
    timer->Reset();
    ip->WriteImages("/cameratest");
    printf("[CAMERA] Processed images written to /cameratest.*.bmp in %01f ms\n", timer->Get() * 1000);

    // Generate a target report
    timer->Reset();
    TargetReport * tr = new TargetReport(ip->GetThresholdImage(), ip->GetFilteredImage());
    tr->Generate();
    printf("[CAMERA] Target report generated in %01f ms\n", timer->Get() * 1000);

    tr->OutputScores();

    delete tr;
    delete ip;

    cameraLEDsSubsystem->GreenOff();
}

bool CameraTest::IsFinished() {
    return true;
}

void CameraTest::End() {
    timer->Stop();
    timer->Reset();
}

void CameraTest::Interrupted() {
    End();
}
