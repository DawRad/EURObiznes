#include "Rysunki_h/cryspoleobraz.h"





CRysPoleObraz::CRysPoleObraz()
{

}





CRysPoleObraz::CRysPoleObraz(QPoint topLeft, QSizeF size, int poz, QString napis, QString path, CWspSkalowaniaImg skalaImg, qreal rot) : CRysPole(topLeft, size, poz, napis, rot)
{
    imagePath_ = path;

    skalaImg_ = skalaImg;

    image_ = new QImage(imagePath_);
    *image_ = image_->scaled(skalaImg_.podajFactorW() * size_.width(), skalaImg_.podajFactorH() * size_.height());
}





CRysPoleObraz::~CRysPoleObraz()
{
    delete image_;
}





void CRysPoleObraz::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Rysowanie kwadratu zewnętrznego
    QColor brushColor(Q_KOL_POLA_BAZA);
    QBrush brush(brushColor);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    // Rysowanie obrazu
    QImage image(imagePath_);
    image = image.scaled(1 * size_.width(), 1 * size_.width());
    painter->drawImage(QRectF(topLeft_.x() + 0 * size_.width(), topLeft_.y() + 0 * size_.height(), 1 * size_.width(), 1 * size_.width()),
                       image, QRectF(0, 0, 1 * size_.width(), 1 * size_.width()));
}





void CRysPoleObraz::setSize(QSizeF size)
{
    size_ = size;

    topLeft_.setX(-size_.width() / 2);
    topLeft_.setY(-size_.height() / 2);

    *image_ = image_->scaled(skalaImg_.podajFactorW() * size_.width(), skalaImg_.podajFactorH() * size_.height());
}





void CRysPoleObraz::drawMyImage(QPainter *painter,QRectF rect)
{
    painter->drawImage(rect, *image_, QRectF(QPointF(0, 0), image_->size()));
}
