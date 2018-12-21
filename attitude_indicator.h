/**
 * @file
 *   @brief Class Attitude_indicator. The widget to display attitude of UAV in real time.
 *
 */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QTimer>

class Attitude_Indicator : public QWidget
{
    Q_OBJECT

public:
    Attitude_Indicator(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void paint();
    void paintPitchLines(float pitch, QPainter* painter);
    void paintPitchLinePos(const float widget, QString text, float refPosX, float refPosY, QPainter* painter);
    void rotatePolygonClockWiseRad(QPolygonF& p, float angle, QPointF origin);

    void paintText(QString text, QColor color, float fontSize, float refX, float refY, QPainter* painter);
    void drawLine(float refX1, float refY1, float refX2, float refY2, float width, const QColor& color, QPainter* painter);

    ~Attitude_Indicator();

    //degree
    float rollLP;
    float pitchLP;
    float yaw;
    float scalingFactor;
    float pitchScaleFactor;

 private:
    static const int updateInterval = 100;
    float vwidth; ///640
    float vheight; ///480
    float vPitchPerDeg; ///< Virtual pitch to mm conversion. Currently one degree is 3 mm up/down in the pitch markings

    // HUD colors
    QColor defaultColor;       ///< Color for most HUD elements, e.g. pitch lines, center cross, change rate gauges
    QColor skyColor;
    QColor earthColor;

    QTimer* refreshTimer;      ///< The main timer, controls the update rate
  }

#endif // WIDGET_H
