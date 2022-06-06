#include "Rysunki_h\crysinfo.h"





CRysInfo::CRysInfo(QPoint topLeft, QSizeF size, QString imgPath, qreal rot) : CRys(topLeft, size, rot)
{
    imgPath_ = imgPath;
}





CRysInfo::~CRysInfo()
{

}





void CRysInfo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Rysowanie obrazu tła
    QImage image(imgPath_);
    image = image.scaled(1 * size_.width(), 1 * size_.width());
    painter->drawImage(boundingRect(), image, QRectF(0, 0, 1 * size_.width(), 1 * size_.width()));

        // nick gracza
    QFont font("Comic Sans MS", 12);
    font.setBold(true);
    painter->setFont(font);
    QRectF tmpRect(topLeft_.x() + 0.1 * size_.width(), topLeft_.y() + 0.1 * size_.height(), 0.8 * size_.width(), 0.8 * size_.height());
    painter->drawText(tmpRect, Qt::AlignCenter | Qt::TextWordWrap, text_);
}





QPainterPath CRysInfo::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}





void CRysInfo::ustawText(std::string tresc)
{
    text_ = QString::fromStdString(tresc);
}
