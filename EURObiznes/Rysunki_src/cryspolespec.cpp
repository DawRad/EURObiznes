#include "Rysunki_h/cryspolespec.h"

CRysPoleSpec::CRysPoleSpec()
{

}





CRysPoleSpec::CRysPoleSpec(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, QString cena, int kolor, CWspSkalowaniaImg skalaImg, qreal rot) : CRysPoleStnd(topLeft,
                                                                                                                                                                size,
                                                                                                                                                                poz,
                                                                                                                                                                napis,                                                                                                                                                                
                                                                                                                                                                path,                                                                                                                                                                
                                                                                                                                                                cena,
                                                                                                                                                                kolor,
                                                                                                                                                                skalaImg,
                                                                                                                                                                rot)
{

}





CRysPoleSpec::~CRysPoleSpec()
{

}





void CRysPoleSpec::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->rotate(rotation_);    

    // Rysowanie kwadratu zewnętrznego
    QColor brushColor(Q_KOL_POLA_BAZA);
    QBrush brush(brushColor);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    // Wypisywanie tekstu
    QFont font("Impact", 8);
    font.setBold(false);
    painter->setFont(font);
    QRect textRect(topLeft_.x(), topLeft_.y(), size_.width(), 0.25 * size_.height());
    painter->drawText(textRect, Qt::AlignCenter | Qt::TextWordWrap, napis_);

    // Rysowanie obrazu
    drawMyImage(painter, QRectF(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.3125 * size_.height(), 0.9 * size_.width(), 0.35 * size_.height()));
//    painter->drawImage(QRectF(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.3125 * size_.height(), 0.9 * size_.width(), 0.35 * size_.height()),
//                       image, QRectF(0, 0, 0.9 * size_.width(), 0.35 * size_.height()));

    // Wypisanie ceny
    QRectF tmpRect;
    tmpRect.setTopLeft(QPoint(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.75 * size_.height()));
    tmpRect.setSize(QSizeF(0.9 * size_.width(), 0.25 * size_.height()));

    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, cena_);

//    brush.setColor(Qt::green);
//    painter->setBrush(brush);
//    painter->drawEllipse(QRectF(-10, -10, 20, 20));
}
