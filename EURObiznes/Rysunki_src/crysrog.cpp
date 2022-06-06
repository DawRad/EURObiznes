#include "Rysunki_h/crysrog.h"

CRysRog::CRysRog(QPoint topLeft, QSizeF size, int poz, QString napis, QPolygon polygon, QString napis_1, qreal rot) : CRysPole(topLeft, size, poz, napis, rot)
{    
    polygon_ = polygon;
    napis_1_ = napis_1;
}





CRysRog::CRysRog(QPoint topLeft, QSizeF size, int poz, QString napis, QString napis_1, qreal rot) : CRysPole(topLeft, size, poz, napis, rot)
{
    // automatyczne tworzenie pola polygon_
    polygon_ << QPoint(topLeft);

    QPoint tmpPoint(topLeft.x(), topLeft.y() + size.height());
    polygon_ << tmpPoint;

    tmpPoint.setX(topLeft.x() + size.width());
    polygon_ << tmpPoint;

    tmpPoint.setY(tmpPoint.y() - 0.25 * size.height());
    polygon_ << tmpPoint;

    tmpPoint.setX(topLeft.x() + 0.25 * size.width());
    polygon_ << tmpPoint;

    tmpPoint.setY(topLeft.y());
    polygon_ << tmpPoint;


    // - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - -
    napis_1_ = napis_1;
}





CRysRog::~CRysRog()
{

}





void CRysRog::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{    
    painter->rotate(rotation_);
    painter->drawRect(boundingRect());

    QColor brushColor(Q_KOL_ROG);
    QBrush brush(brushColor);
    painter->setBrush(brush);

    painter->drawPolygon(polygon_);    

    // wypisanie napisu pierwszego
    painter->rotate(90);
    QTransform actTransf = painter->transform();
    //actTransf.rotate(90);
    painter->setWorldTransform(actTransf);


    QSizeF textRectSize(abs(polygon_.at(0).y() - polygon_.at(4).y()), abs(polygon_.at(0).x() - polygon_.at(5).x()));
    QPointF txtRectTopLeft(polygon_.at(5).x(), polygon_.at(5).y());
    QRectF *textRect = new QRectF(mapToRot(txtRectTopLeft, -90), textRectSize);
    //QRectF *textRect = new QRectF(txtRectTopLeft, textRectSize);
    painter->drawText(*textRect, Qt::AlignCenter | Qt::TextWordWrap, napis_);

    /*
    brushColor.setRed(255);
    brushColor.setGreen(0);
    brushColor.setBlue(0);
    painter->setPen(brushColor);
    painter->drawRect(*textRect);    

    brushColor.setRgb(122, 246, 255);
    painter->setPen(brushColor);

    txtRectTopLeft.setX(0);
    txtRectTopLeft.setY(0);
    painter->drawEllipse(polygon_.at(5), 15, 5);

    delete textRect;
    */

    // wypisanie napisu drugiego
    painter->setPen(Qt::black);
        //painter->rotate(-90);
    actTransf.rotate(-90);
    painter->setWorldTransform(actTransf);
    textRect = new QRectF(polygon_.at(4).x(), polygon_.at(4).y(), abs(polygon_.at(4).x() - polygon_.at(3).x()), abs(polygon_.at(4).y() - polygon_.at(2).y()));
    painter->drawText(*textRect, Qt::AlignCenter | Qt::TextWordWrap, napis_1_);
    delete textRect;

//    brush.setColor(Qt::green);
//    painter->setBrush(brush);
//    painter->drawEllipse(QRectF(-10, -10, 20, 20));
}





QPainterPath CRysRog::shape() const
{
    QPainterPath path;
    path.addPolygon(polygon_);
    return path;
}





void CRysRog::setSizeWithOtherDimUpdate(QSizeF size)
{
    size_ = size;

    topLeft_.setX(-size_.width() / 2);
    topLeft_.setY(-size_.height() / 2);

    polygon_.clear();

    // automatyczne tworzenie pola polygon_
    polygon_ << QPoint(topLeft_);

    QPoint tmpPoint(topLeft_.x(), topLeft_.y() + size.height());
    polygon_ << tmpPoint;

    tmpPoint.setX(topLeft_.x() + size.width());
    polygon_ << tmpPoint;

    tmpPoint.setY(tmpPoint.y() - 0.25 * size.height());
    polygon_ << tmpPoint;

    tmpPoint.setX(topLeft_.x() + 0.25 * size.width());
    polygon_ << tmpPoint;

    tmpPoint.setY(topLeft_.y());
    polygon_ << tmpPoint;
}
