#ifndef TARGET_REPORT_H
#define TARGET_REPORT_H

#include "Vision/BinaryImage.h"

class TargetReport {

public:
    struct Scores {
        double rectangularity;
        double aspectRatioInner;
        double aspectRatioOuter;
        double xEdge;
        double yEdge;
    };

                                     TargetReport(BinaryImage * thresholdImage, BinaryImage * filteredImage);
    virtual                          ~TargetReport();

    void                             Generate();
    vector<ParticleAnalysisReport> * GenerateParticleReport();
    Scores *                         GenerateScores();
    void                             OutputScores();

private:
                                     TargetReport() {};

    BinaryImage *                    thresholdImage;
    BinaryImage *                    filteredImage;
    vector<ParticleAnalysisReport> * reports;
    Scores *                         scores;

    double computeDistance(BinaryImage * image, ParticleAnalysisReport * report, bool outer);
    double scoreAspectRatio(BinaryImage * image, ParticleAnalysisReport * report, bool outer);
    bool   scoreCompare(TargetReport::Scores scores, bool outer);
    double scoreRectangularity(ParticleAnalysisReport * report);
    double scoreXEdge(BinaryImage * image, ParticleAnalysisReport * report);
    double scoreYEdge(BinaryImage * image, ParticleAnalysisReport * report);

};

#endif /* TARGET_REPORT_H */
