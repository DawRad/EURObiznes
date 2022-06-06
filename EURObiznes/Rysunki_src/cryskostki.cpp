#include "Rysunki_h\cryskostki.h"





CRysKostki::CRysKostki()
{
    faza_ = 1;
    moveToken_ = false;
    primaryDice_ = false;
    oczka_ = "0";
    timer_ = NULL;
    wskWyzwalacza_ = NULL;
}





CRysKostki::CRysKostki(QPoint topLeft, QSizeF size, QTimer *timer, CNadawca *wskNadawcy, int poz, QString napis, QString imgPath, CWspSkalowaniaImg skalaImg,
                       qreal rot) : CRysPoleObraz(topLeft, size, poz, napis, imgPath, skalaImg, rot)
{
    faza_ = 1;
    moveToken_ = false;
    primaryDice_ = false;
    oczka_ = "0";
    timer_ = timer;
    wskWyzwalacza_ = wskNadawcy;
}





CRysKostki::~CRysKostki()
{

}





void CRysKostki::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image(imagePath_);
    image = image.scaled(size_.width(), size_.height());

    drawMyUpdatedImage(painter, boundingRect());
//    painter->drawImage(boundingRect(), image, QRectF(0, 0, size_.width(), size_.height()));
}





void CRysKostki::ustawOczka(QString oczka)
{
    oczka_ = oczka;
    moveToken_ = true;
}





void CRysKostki::ustawOczka(int oczka)
{
    oczka_ = QString::number(oczka);
    moveToken_ = true;
}





void CRysKostki::setPrimaryDice(bool state)
{
    primaryDice_ = state;
}





void CRysKostki::drawMyUpdatedImage(QPainter *painter, QRectF rect)
{
    delete image_;
    image_ = new QImage(imagePath_);
    *image_ = image_->scaled(skalaImg_.podajFactorW() * size_.width(), skalaImg_.podajFactorH() * size_.height());

    drawMyImage(painter, rect);
}





void CRysKostki::advance(int step)
{
    // obiekt musi mieć pozwolenie na ruch - uzyskiwane w metodzie ustawOczka(...);
    if(moveToken_)
    {
        if(!step)
            return;

        if(step)
        {
            if(faza_ == 0)
            {
                imagePath_ =  ":/Zasoby/grafika/inne_elementy/oczko_0.png";
                this->update();
                faza_ = 1;
            }
            else if (faza_ == 1)
            {
                imagePath_ =  ":/Zasoby/grafika/inne_elementy/oczko_" + oczka_ + ".png";
                this->update();
                faza_ = 2;
            }
            else
            {
                moveToken_ = false;
                faza_ = 0;

                if(primaryDice_)
                {
                    timer_->stop();
                    wskWyzwalacza_->emitRzutWykonany();
                }
            }
        }
    }
}
