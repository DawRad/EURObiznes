#include "Rysunki_h/cryspolestart.h"

CRysPoleStart::CRysPoleStart()
{

}





CRysPoleStart::CRysPoleStart(QPoint topLeft, QSizeF size, int poz, QString napis[], QString path, CWspSkalowaniaImg skalaImg, qreal rot) : CRysPoleObraz(topLeft,
                                                                                                                                                         size,
                                                                                                                                                         poz,
                                                                                                                                                         napis[0],
                                                                                                                                                         path,
                                                                                                                                                         skalaImg,
                                                                                                                                                         rot)
{
    napis_1_ = napis[1];
    napis_2_ = napis[2];
}





CRysPoleStart::~CRysPoleStart()
{

}





void CRysPoleStart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->rotate(rotation_);    

    // Rysowanie kwadratu zewnętrznego
    QColor brushColor(Q_KOL_POLA_BAZA);
    QBrush brush(brushColor);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    // Rysowanie obrazu    
    drawMyImage(painter, QRectF(topLeft_.x() - 0.0625 * topLeft_.x(), topLeft_.y() + 0.65 * size_.height() , 0.9375 * size_.width(), 0.3 * size_.height()));
//    painter->drawImage(QRectF(topLeft_.x() - 0.0625 * topLeft_.x(), topLeft_.y() + 0.7 * size_.height() , 0.9375 * size_.width(), 0.3 * size_.height()),
//                       image, QRectF(0, 0, 0.9375 * size_.width(), 0.3 * size_.height()));

    /*
    QPen basePen = painter->pen();
    QPen modPen = painter->pen();
    modPen.setColor(QColor(0, 255, 0));
    painter->setPen(modPen);
    painter->drawLine(0, size_.height() / 2, 0, -size_.height() / 2);
    painter->drawLine(-size_.width() / 2, 0, size_.width() / 2, 0);
    painter->setPen(basePen);
    */


    // Pisanie tekstów
        // tekst górny
    QFont font("Impact", 10);
    font.setBold(false);
    painter->setFont(font);    

    QPointF tmpP(topLeft_.x(), topLeft_.y());
    QRectF tmpRect(tmpP.x(), tmpP.y(), size_.height(), 0.25 * size_.height());
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, napis_);

    font.setBold(false);
    font.setPointSize(14);
    painter->setFont(font);

        // tekst "START"
    tmpP.setX(tmpP.x());
    tmpP.setY(tmpP.y() + 0.25 * size_.height());
    tmpRect.setTopLeft(tmpP);
    tmpRect.setSize(QSizeF(size_.height(), 0.2 * size_.height()));
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, napis_1_);

        // tekst z pensją
    tmpP.setX(tmpP.x());
    tmpP.setY(tmpP.y() + 0.2 * size_.height());
    tmpRect.setTopLeft(tmpP);
    tmpRect.setSize(QSize(size_.height(), 0.2 * size_.height()));

    font.setBold(false);
    font.setPointSize(10);
    painter->setFont(font);
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, napis_2_);

    /*
    modPen.setColor(QColor(0, 0, 255));
    painter->setPen(modPen);
    painter->drawLine(0, size_.height() / 2, 0, -size_.height() / 2);
    painter->drawLine(-size_.width() / 2, 0, size_.width() / 2, 0);
    */

//    brush.setColor(Qt::green);
//    painter->setBrush(brush);
//    painter->drawEllipse(QRectF(-10, -10, 20, 20));

}





void CRysPoleStart::aktualKwote(int kwota, QString waluta)
{
    napis_2_ = "pobierz " + QString::number(kwota) + " " + waluta;
}
