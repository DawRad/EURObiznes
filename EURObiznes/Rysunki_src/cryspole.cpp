#include "Rysunki_h/cryspole.h"

CRysPole::CRysPole()
{

}






CRysPole::CRysPole(QPoint topLeft, QSizeF size, int poz, QString napis, qreal rot) : CRys(topLeft, size, rot)
{
    poz_ = poz;
    napis_ = napis;
}





CRysPole::~CRysPole()
{

}





void CRysPole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    QRect textRect(topLeft_.x() - 0.1 * topLeft_.x(), topLeft_.y() - 0.1 * topLeft_.y(), 0.9 * size_.width(), 0.3 * size_.height());
    painter->drawText(textRect, Qt::AlignCenter | Qt::TextWordWrap, napis_);
}






QPainterPath CRysPole::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}





QString CRysPole::podajPozQStr()
{
    return QString::fromStdString(std::to_string(poz_));
}





int CRysPole::podajPozInt()
{
    return poz_;
}
