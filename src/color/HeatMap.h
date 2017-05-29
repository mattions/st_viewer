#ifndef HEATMAP_H
#define HEATMAP_H

#include "math/Common.h"
#include "qcustomplot.h"

class QImage;

// Heatmap is a convenience namespace containing functions to generate
// heatmap related images and data.
namespace Color
{

typedef QCPColorGradient::GradientPreset ColorGradients;

// Convenience function to generate a heatmap spectrum image given specific
// mapping function
// using the wave lenght spectra or a linear interpolation spectra between two
// colors
// the input image will be transformed with the new colors
void createLegend(QImage &image, const float lowerbound,
                  const float upperbound, const ColorGradients cmap);

// Convenience function to generate a QColor color from a real value
QColor createHeatMapWaveLenghtColor(const float value);

// Convenience function to generate a QColor color from a real value given a
// range
QColor createHeatMapLinearColor(const float value, const float min, const float max);

// Function that creates a dynamic color (alpha adjusted to the value given and min-max)
QColor createDynamicRangeColor(const float value, const float min, const float max, const QColor color);

// Functions to create a color mapped in the color range given
QColor createRangeColor(const float value, const float min, const float max,
                        const QColor init, const QColor end);

// Functions to create a color from a pre-set color map
QColor createCMapColor(const float value, const float min, const float max,
                       const ColorGradients cmap);

}

#endif // HEATMAP_H //
