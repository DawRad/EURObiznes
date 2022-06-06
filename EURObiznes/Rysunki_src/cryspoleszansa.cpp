#include "Rysunki_h/cryspoleszansa.h"

CRysPoleSzansa::CRysPoleSzansa()
{

}





CRysPoleSzansa::CRysPoleSzansa(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, CWspSkalowaniaImg skalaImg, qreal rot) : CRysPoleObraz(topLeft,
                                                                                                                                            size,
                                                                                                                                            poz,
                                                                                                                                            napis,
                                                                                                                                            path,
                                                                                                                                            skalaImg,
                                                                                                                                            rot)
{

}





CRysPoleSzansa::~CRysPoleSzansa()
{

}





void CRysPoleSzansa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    drawMyImage(painter, QRectF(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.3 * size_.height(), 0.9 * size_.width(), 0.9 * size_.width()));
//    painter->drawImage(QRectF(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.3 * size_.height(), 0.9 * size_.width(), 0.9 * size_.width()),
//                       image, QRectF(0, 0, 0.9 * size_.width(), 0.9 * size_.width()));

//    brush.setColor(Qt::green);
//    painter->setBrush(brush);
//    painter->drawEllipse(QRectF(-10, -10, 20, 20));
}
