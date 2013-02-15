#include "ImageProcessor.h"

#define AREA_MINIMUM 500

ImageProcessor::ImageProcessor() : threshold(Threshold(60, 100, 90, 255, 20, 255)) {   // GREEN
    thresholdImage  = 0;
    convexHullImage = 0;
    filteredImage   = 0;

    ParticleFilterCriteria2 criteria = {IMAQ_MT_AREA, AREA_MINIMUM, 65535, false, false};
    SetParticleCriteria(criteria);
}

ImageProcessor::~ImageProcessor() {
    delete thresholdImage;
    delete convexHullImage;
    delete filteredImage;
}

const BinaryImage * ImageProcessor::Process(RGBImage * image) {
    ParticleFilterCriteria2 criteria[] = { particleCriteria };

    thresholdImage  = image->ThresholdHSV(threshold);
    convexHullImage = thresholdImage->ConvexHull(false);
    filteredImage   = convexHullImage->ParticleFilter(criteria, 1);

    return filteredImage;
}

const BinaryImage * ImageProcessor::GetThresholdImage() const {
    return thresholdImage;
}

const BinaryImage * ImageProcessor::GetConvexHullImage() const {
    return convexHullImage;
}

const BinaryImage * ImageProcessor::GetFilteredImage() const {
    return filteredImage;
}

void ImageProcessor::SetThreshold(const Threshold &threshold) {
    this->threshold = threshold;
}

void ImageProcessor::SetThreshold(simple_threshold threshold) {
    if (threshold == GREEN) {
        SetThreshold(Threshold(60, 100, 90, 255, 20, 255));
    } else if (threshold == BLUE) {
        SetThreshold(Threshold(150, 190, 90, 255, 100, 255));
    } else {
        SetThreshold(GREEN);
    }
}

void ImageProcessor::SetParticleCriteria(const ParticleFilterCriteria2 &criteria) {
    particleCriteria = criteria;
}

void ImageProcessor::WriteImages(const char * baseFilename) const {
    BinaryImage * images[] = { thresholdImage, convexHullImage, filteredImage, 0 };
    size_t length          = strlen(baseFilename);
    char * filename        = new char[length + 8];

    strcpy(filename, baseFilename);
    for (BinaryImage * image = images[0]; image != 0; image++) {
        strcpy(&filename[length], "-th.bmp");
        filename[length+7] = '\0';
        image->Write(filename);
    }

    delete[] filename;
}
