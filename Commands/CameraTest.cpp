#include "CameraTest.h"
#include "../ImageProcessor.h"
#include "../TargetReport.h"

CameraTest::CameraTest() {
    Requires(cameraSubsystem);
    Requires(cameraLEDsSubsystem);

    timer     = new Timer;
    finished  = false;
}

void CameraTest::Initialize() {
    finished = false;
    timer->Reset();
    timer->Start();

    greenOn = cameraLEDsSubsystem->IsGreenOn();
    blueOn  = cameraLEDsSubsystem->IsBlueOn();
}

void CameraTest::Execute() {
    cameraLEDsSubsystem->GreenOn();
    cameraLEDsSubsystem->BlueOff();

    // Allow time for the LEDs to light up
    if(!timer->HasPeriodPassed(0.1)) { return; }   // min tested was 80ms

    Preferences * prefs = Preferences::GetInstance();

    // Capture an image from the camera and save it to flash
    timer->Reset();
    ColorImage * image;
    if (prefs->GetInt("image_retain", 1) == 1) {
        cameraSubsystem->RetainImage("/cameratest.jpg");
        image = cameraSubsystem->CaptureImage();
        cameraSubsystem->RetainImage(NULL);  // stop retaining
        printf("[CAMERA] Captured image and wrote to /cameratest.jpg in %.1f ms\n", timer->Get() * 1000);
    } else {
        image = cameraSubsystem->CaptureImage();
        printf("[CAMERA] Captured image in %.1f ms\n", timer->Get() * 1000);
    }

    // Load preferences for filtering threshold image
    Threshold threshold = Threshold(prefs->GetInt("hue_low", 100), prefs->GetInt("hue_high", 140),
                                    prefs->GetInt("sat_low", 90), prefs->GetInt("sat_high", 255),
                                    prefs->GetInt("lum_low", 20), prefs->GetInt("lum_high", 255));

    // Process the captured image
    timer->Reset();
    ImageProcessor * ip = new ImageProcessor();
    ip->SetThreshold(threshold);
    ip->Process(image);
    printf("[CAMERA] Image processed in %.1f ms\n", timer->Get() * 1000);

    // Write the processed images to flash
    if (prefs->GetInt("image_retain", 1) == 1) {
        timer->Reset();
        ip->WriteImages("/cameratest");
        printf("[CAMERA] Processed images written to /cameratest.*.bmp in %.1f ms\n", timer->Get() * 1000);
    }

    // Generate a target report
    timer->Reset();
    TargetReport * tr = new TargetReport(ip->GetThresholdImage(), ip->GetFilteredImage());
    tr->Generate();
    printf("[CAMERA] Target report generated in %.1f ms\n", timer->Get() * 1000);

    tr->OutputScores();

    finished = true;

    delete tr;
    delete ip;
}

bool CameraTest::IsFinished() {
    return finished;
}

void CameraTest::End() {
    if (blueOn) { cameraLEDsSubsystem->BlueOn(); }
    if (!greenOn) { cameraLEDsSubsystem->GreenOff(); }
    finished = true;
    timer->Stop();
    timer->Reset();
}

void CameraTest::Interrupted() {
    End();
}
