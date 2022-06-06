#include "Rysunki_h/crysprzycisk.h"





CRysPrzycisk::CRysPrzycisk()
{

}





CRysPrzycisk::CRysPrzycisk(QPoint topLeft, QSizeF size, QString nazwa, int shape, string imieNad, qreal rot) : CRysEmiter(topLeft, size, imieNad, rot)
{
    shape_ = shape;
    nazwa_ = nazwa;
}





CRysPrzycisk::~CRysPrzycisk()
{

}





void CRysPrzycisk::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(this->isEnabled())
    {
        QBrush brush(Q_KOL_PRZYCISKI1);
        painter->setBrush(brush);
        painter->rotate(rotation_);
        drawShape(painter);

        // Wypisywanie tekstu
        QFont font("Impact", 8);
            //font.setBold(false);
        painter->setFont(font);
        QRectF tmpRect(topLeft_, size_);
        painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, nazwa_);
    }

    else
    {
        QBrush brush(Q_KOL_PRZYCISKI1_DISAB);
        painter->setBrush(brush);
        painter->rotate(rotation_);
        drawShape(painter);

        // Wypisywanie tekstu
        QFont font("Impact", 8);
            //font.setBold(false);
        painter->setFont(font);
        QRectF tmpRect(topLeft_, size_);
        painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, nazwa_);
    }
}





QPainterPath CRysPrzycisk::shape() const
{
    QPainterPath path;

    switch (shape_)
    {
    case 0:
        path.addRect(QRectF(topLeft_, size_));
        break;

    case 1:
        path.addEllipse(QRectF(topLeft_, size_));
        break;

    default:
        path.addRect(QRectF(topLeft_, size_));
        break;
    }

    return path;
}





void CRysPrzycisk::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    nadawca_->emitPressedSig();
}





void CRysPrzycisk::drawShape(QPainter *painter)
{
    switch (shape_)
    {
    case 0:
        painter->drawRect(QRectF(topLeft_, size_));
        break;

    case 1:
        painter->drawEllipse(QRectF(topLeft_, size_));
        break;

    default:
        painter->drawRect(QRectF(topLeft_, size_));
        break;
    }
}
