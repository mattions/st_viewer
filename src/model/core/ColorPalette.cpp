/*
    Copyright (C) 2012  Spatial Transcriptomics AB,
    read LICENSE for licensing terms.
    Contact : Jose Fernandez Navarro <jose.fernandez.navarro@scilifelab.se>

*/

#include "ColorPalette.h"

ColorPalette::ColorPalette(QObject* parent)
    : QObject(parent)
{

}
ColorPalette::~ColorPalette()
{

}

StandardPalette::StandardPalette(QObject* parent)
    : ColorPalette(parent)
{
    const QStringList colorNameList = QColor::colorNames();
    foreach(const QString colorName, colorNameList)
    {
        m_colorList << ColorPair(QColor(colorName), colorName);
    }
}
StandardPalette::~StandardPalette()
{

}
const ColorPalette::ColorList StandardPalette::colorList() const
{
    return m_colorList;
}
const ColorPalette::ColorList StandardPalette::colorList(const int count) const
{
    const int limit = qMin(m_colorList.size(), count);
    return m_colorList.mid(0, limit);
}

const int HSVPalette::DEFAULT_SATURATION = 255;
const int HSVPalette::DEFAULT_VALUE = 255;
const int HSVPalette::DEFAULT_COUNT = 12;

HSVPalette::HSVPalette(QObject* parent)
    : ColorPalette(parent), m_saturation(DEFAULT_SATURATION), m_value(DEFAULT_VALUE)
{

}
HSVPalette::~HSVPalette()
{

}

void HSVPalette::setSaturation(const int saturation)
{
    m_saturation = saturation;
}
void HSVPalette::setValue(const int value)
{
    m_value = value;
}

const ColorPalette::ColorList HSVPalette::colorList() const
{
    return colorList(DEFAULT_COUNT);
}
const ColorPalette::ColorList HSVPalette::colorList(const int count) const
{
    ColorList colorList;

    const qreal step = qreal(360) / qreal(count);
    for(int i=0; i<count; ++i)
    {
        const int hue = int(i * step);
        const QColor color = QColor::fromHsv(hue, m_saturation, m_value);
        //colorList << ColorPair(color, QString("HSV[%1,%2,%3]").arg(color.hue()).arg(color.saturation()).arg(color.value()));
        colorList << ColorPair(color, QString());
    }
    return colorList;
}
