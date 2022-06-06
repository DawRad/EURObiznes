#include "Rysunki_h/crys.h"

CRys::CRys()
{

}






CRys::CRys(QPoint topLeft, QSizeF size, qreal rot)
{
    topLeft_ = topLeft;
    size_ = size;
    rotation_ = rot;
}





CRys::~CRys()
{

}





QRectF CRys::boundingRect() const
{
    return QRectF(topLeft_, size_);
}





void CRys::setTopLeft(QPoint topLeft)
{
    topLeft_ = topLeft;
}





void CRys::setSize(QSizeF size)
{
    size_ = size;

    topLeft_.setX(-size_.width() / 2);
    topLeft_.setY(-size_.height() / 2);
}





void CRys::setSizeWithOtherDimUpdate(QSizeF size)
{
    size_ = size;

    topLeft_.setX(-size_.width() / 2);
    topLeft_.setY(-size_.height() / 2);
}





void CRys::setRotation(qreal rot)
{
    rotation_ = rot;
}





QPoint CRys::mapToRot(QPoint point, qreal rot)
{
    QPoint result;

    // distance from the point (0, 0)
    qreal r = qSqrt(point.x() * point.x() + point.y() * point.y());

    // arcsin value in radians
    qreal angle = qAsin(point.y() / r);

    // computing new position of the point
    result.setX(qCos(-angle - qDegreesToRadians(rot)) * r);
    result.setY(qSin(-angle - qDegreesToRadians(rot)) * r);

    return result;
}





QPointF CRys::mapToRot(QPointF pointF, qreal rot)
{
    QPointF result;

    // distance from the point (0, 0)
    qreal r = qSqrt(pointF.x() * pointF.x() + pointF.y() * pointF.y());

    // arcsin value in radians
    qreal angle = qAsin(pointF.y() / r);

    // computing new position of the point
    result.setX(qCos(-angle - qDegreesToRadians(rot)) * r);
    result.setY(qSin(-angle - qDegreesToRadians(rot)) * r);

    return result;
}





QRectF CRys::mapToRot(QRectF rect, qreal rot)
{
    QRectF result(mapToRot(rect.topLeft(), rot), rect.size());

    return result;
}

QColor CRys::colorIntToQCol(int color)
{
    switch (color)
    {
    case KOL_CZER:
        return QColor(245, 86, 54);

    case KOL_NIEB:
        return QColor(70, 104, 240);

    case KOL_ZIEL:
        return QColor(0, 255, 0);

    case KOL_ZOLTY:
        return QColor(252, 252, 0);

    case KOL_ROZ:
        return QColor(252, 0, 223);

    case KOL_FIOL:
        return QColor(124, 50, 240);

    case KOL_POMAR:
        return QColor(227, 131, 14);

    case KOL_CZARNY:
        return QColor(0, 0, 0);

    case KOL_AKWAMAR:
        return QColor(0, 128, 255);

    case KOL_OLIW:
        return QColor(128, 128, 0);

    case KOL_POLA_BAZA:
        return Q_KOL_POLA_BAZA;

    case KOL_ROG:
        return Q_KOL_ROG;

    case KOL_PRZYCISKI1:
        return Q_KOL_PRZYCISKI1;

    case KOL_PRZYCISKI1_DISAB:
        return Q_KOL_PRZYCISKI1_DISAB;

    case KOL_PRZYCISKI2:
        return Q_KOL_PRZYCISKI2;

    case KOL_PRZYCISKI2_DISAB:
        return Q_KOL_PRZYCISKI2_DISAB;

    case KOL_MOC_CZER:
        return QColor(161, 31, 31);

    case KOL_MOC_NIEB:
        return QColor(17, 17, 153);

    case KOL_MOC_ZOLTY:
        return QColor(153, 148, 17);

    case KOL_MOC_ZIEL:
        return QColor(37, 94, 10);

    case KOL_MOC_ROZ:
        return QColor(110, 14, 76);

    case KOL_MIETA:
        return QColor(15, 117, 93);

    case KOL_GRANAT:
        return QColor(11, 7, 237);

    default:
        return QColor(0, 0, 0);
    }
}
