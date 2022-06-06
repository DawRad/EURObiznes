#include "Rysunki_h/cryspolestnd.h"

CRysPoleStnd::CRysPoleStnd()
{

}





CRysPoleStnd::CRysPoleStnd(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, QString cena, int kolor,
                           CWspSkalowaniaImg skalaImg, qreal rot) : CRysPoleObraz(topLeft,
                                                                 size,
                                                                 poz,
                                                                 napis,
                                                                 path,
                                                                 skalaImg,
                                                                 rot)
{
    cena_ = cena;
    kolor_ = kolor;
}





CRysPoleStnd::~CRysPoleStnd()
{

}





void CRysPoleStnd::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->rotate(rotation_);
    // Rysowanie kwadratu zewnętrznego
    QColor brushColor(Q_KOL_POLA_BAZA);
    QBrush brush(brushColor);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    // Rysowanie paska koloru
    QSizeF tmpSize;
    tmpSize.setHeight(0.2 * size_.height());
    tmpSize.setWidth(size_.width());
    brush.setColor(CRys::colorIntToQCol(kolor_));
    painter->setBrush(brush);
    painter->drawRect(QRectF(topLeft_, tmpSize));

    // Wypisywanie tekstu
    QFont font("Impact", 8);
    font.setBold(false);
    painter->setFont(font);
    QRectF tmpRect(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.2 * size_.height(), 0.9 * size_.width(), 0.25 * size_.height());
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, napis_);

    // Rysowanie obrazu
    drawMyImage(painter, QRectF(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.45 * size_.height(), 0.9 * size_.width(), 0.35 * size_.height()));
//    painter->drawImage(QRectF(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() + 0.45 * size_.height(), 0.9 * size_.width(), 0.35 * size_.height()),
//                       image, QRectF(0, 0, 0.9 * size_.width(), 0.35 * size_.height()));

    // Wypisywanie ceny
    tmpRect.setTopLeft(QPoint(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y()+ 0.8 * size_.height()));
    tmpRect.setSize(QSizeF(0.9 * size_.width(), 0.2 * size_.height()));
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, cena_);

//    brush.setColor(Qt::green);
//    painter->setBrush(brush);
//    painter->drawEllipse(QRectF(-10, -10, 20, 20));

}
