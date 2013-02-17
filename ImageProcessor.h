#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include "WPILib.h"
#include "Vision/RGBImage.h"
#include "Vision/BinaryImage.h"


class ImageProcessor {

public:
    typedef enum {
        GREEN,
        BLUE
    } simple_threshold;

                             ImageProcessor();
    virtual                  ~ImageProcessor();

    BinaryImage *            Process(ColorImage * image);

    BinaryImage *            GetThresholdImage() const;
    BinaryImage *            GetConvexHullImage() const;
    BinaryImage *            GetFilteredImage() const;

    void                     SetThreshold(const Threshold &threshold);
    void                     SetThreshold(simple_threshold threshold);
    void                     SetParticleCriteria(const ParticleFilterCriteria2 &particleCriteria);

    void                     WriteImages(const char * baseFilename) const;

private:
    BinaryImage *            thresholdImage;
    BinaryImage *            convexHullImage;
    BinaryImage *            filteredImage;

    Threshold                threshold;
    ParticleFilterCriteria2  particleCriteria;
};

#endif /* IMAGE_PROCESSOR_H */
