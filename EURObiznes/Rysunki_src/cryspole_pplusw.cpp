#include "Rysunki_h/cryspole_pplusw.h"





CRysPole_PplusW::CRysPole_PplusW()
{

}





CRysPole_PplusW::CRysPole_PplusW(QPoint topLeft, QSizeF size, int poz, QString napis[], QString path, CWspSkalowaniaImg skalaImg,
                                 qreal rot) : CRysPoleObraz(topLeft,
                                                            size,
                                                            poz,
                                                            napis[0],
                                                            path,
                                                            skalaImg,
                                                            rot)
{
    napis_1_ = napis[1];
}





CRysPole_PplusW::~CRysPole_PplusW()
{

}





void CRysPole_PplusW::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Rysowanie kwadratu zewnętrznego
    QColor brushColor(Q_KOL_POLA_BAZA);
    QBrush brush(brushColor);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    // Rysowanie obrazu
    drawMyImage(painter, QRectF(topLeft_.x() + 0.3 * size_.width(), topLeft_.y() + size_.height() * 0.3, 0.4 * size_.width(), 0.4 * size_.width()));
//    painter->drawImage(QRectF(topLeft_.x() + 0.3 * size_.width(), topLeft_.y() + size_.height() * 0.3, 0.4 * size_.width(), 0.4 * size_.width()),
//                       image, QRectF(0, 0, 0.4 * size_.width(), 0.4 * size_.width()));


    // Pisanie tekstów
        // tekst górny
    QFont font("Impact", 14);
    font.setBold(false);
    painter->setFont(font);

    QRectF tmpRect(topLeft_, QSizeF(size_.width(), 0.188 * size_.height()));
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, napis_);

        // tekst dolny
    tmpRect.setTopLeft(QPoint(topLeft_.x(), topLeft_.y() + 0.812 * size_.height()));
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, napis_1_);

//    brush.setColor(Qt::green);
//    painter->setBrush(brush);
    //    painter->drawEllipse(QRectF(-10, -10, 20, 20));
}
