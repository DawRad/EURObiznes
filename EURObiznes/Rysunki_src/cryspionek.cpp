#include "Rysunki_h/cryspionek.h"





CRysPionek::CRysPionek()
{
    krok_ = 0;
    moveToken_ = false;
    aktPozPola_ = 0;
}





CRysPionek::CRysPionek(QPoint topLeft, QSizeF size, int shape, int innerShape, int kolor, qreal rot) : CRys(topLeft, size, rot)
{
    shape_ = shape;
    innerShape_ = innerShape;
    kolor_ = CRys::colorIntToQCol(kolor);
    innerKolor_ = CRys::colorIntToQCol(innKolFromKol(kolor));
    krok_ = 0;
    moveToken_ = false;
    aktPozPola_ = 0;
}





CRysPionek::CRysPionek(SDnPionka dane) : CRys(dane.topLeft, dane.size, dane.rot)
{
    aktPozPola_ = 0;
    shape_ = dane.shape;
    innerShape_ = dane.innerShape;
    kolor_ = dane.kolor;
    innerKolor_ = dane.innerKolor;
}





CRysPionek::~CRysPionek()
{

}





void CRysPionek::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->rotate(rotation_);

    painter->setBrush(QBrush(kolor_));
    drawShape(painter);

    painter->setBrush(innerKolor_);
    drawInnerShape(painter);
}





QPainterPath CRysPionek::shape() const
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





SDnPionka CRysPionek::podajSwojeSkladniki()
{
    SDnPionka wynik;

    wynik.topLeft = topLeft_;
    wynik.size = size_;
    wynik.shape = shape_;
    wynik.innerShape = innerShape_;
    wynik.kolor = kolor_;
    wynik.innerKolor = innerKolor_;
    wynik.rot = rotation_;

    return wynik;
}





void CRysPionek::setShape(int shape)
{
    shape_ = shape;
}





void CRysPionek::setInnerShape(int innerShape)
{
    innerShape_ = innerShape;
}





void CRysPionek::setKolor(int kolor)
{
    kolor_ = CRys::colorIntToQCol(kolor);
    innerKolor_ = CRys::colorIntToQCol(innKolFromKol(kolor));
}





void CRysPionek::setTimer(QTimer *timer)
{
    sceneTimer_ = timer;
}





void CRysPionek::setWskWyzw(CNadawca *wskWyzw)
{
    wskWyzwalacza_ = wskWyzw;
}





void CRysPionek::ustawParamRuchu(QPointF start, QPointF pCelu)
{
    nastPoz_ = pCelu;
    startPoz_ = start;

    dx_ = QLineF(startPoz_, nastPoz_).length() / krokiDoZrob_;
    moveToken_ = true;
}





void CRysPionek::ustawParamRuchu(int kroki, QPointF start, QPointF pCelu)
{
    krokiDoZrob_ = kroki;

    nastPoz_ = pCelu;
    startPoz_ = start;

    dx_ = QLineF(startPoz_, nastPoz_).length() / krokiDoZrob_;
    moveToken_ = true;
}





void CRysPionek::ustawParamRuchu(int kroki, QPointF start, QPointF pCelu, int finPozPola)
{
    krokiDoZrob_ = kroki;

    nastPoz_ = pCelu;
    startPoz_ = start;
    finPozPola_ = finPozPola;

    dx_ = QLineF(startPoz_, nastPoz_).length() / krokiDoZrob_;
    moveToken_ = true;
    //dx_ = abs(0 - nastPoz_.x()) / krokiDoZrob_;
}





void CRysPionek::zmienAktPoz(int aktPoz)
{
    aktPozPola_ = aktPoz;
}





int CRysPionek::innKolFromKol(int kolor)
{
    switch (kolor)
    {
    case KOL_CZER:
        return KOL_MOC_CZER;

    case KOL_NIEB:
        return KOL_MOC_NIEB;

    case KOL_ZIEL:
        return KOL_MOC_ZIEL;

    case KOL_ROZ:
        return KOL_MOC_ROZ;

    case KOL_ZOLTY:
        return KOL_MOC_ZOLTY;

    default:
        return KOL_MOC_CZER;
    }
}





void CRysPionek::advance(int step)
{
    // ruch konkretnego pionka ma odbyć się tylko wtedy, gdy ma on pozwolenie na ruch
    // jest ono udzielane (moveToken = true) przy użyciu metody ustawParamRuchu(...)
   if(moveToken_)
   {
       if(!step)
           return;

       if(nastPoz_.x() - startPoz_.x() != 0)
       {
           if(nastPoz_.x() - startPoz_.x() > 0)
           {
               poziomoWPrawo();
               krok_++;
           }

           else
           {
               poziomoWLewo();
               krok_++;
           }
       }
       else if(nastPoz_.y() - startPoz_.y() != 0)
       {
           if(nastPoz_.y() - startPoz_.y() > 0)
           {
               pionowoWDol();
               krok_++;
           }
           else
           {
               pionowoWGore();
               krok_++;
           }
       }

       if(krok_ == krokiDoZrob_)
       {
           krok_ = 0;

           if(aktPozPola_ == 23)
               aktPozPola_ = 0;
           else
               aktPozPola_ += 1;

           this->setPos(nastPoz_);
           this->update();           
           this->scene()->update();
           moveToken_ = false;

           sceneTimer_->stop();
           if(aktPozPola_ != finPozPola_)
           {
               if(aktPozPola_ == 23)
                   wskWyzwalacza_->emitPionSiePoruszyl(23, 0);
               else
                   wskWyzwalacza_->emitPionSiePoruszyl(aktPozPola_, aktPozPola_ + 1);
           }
           else
               wskWyzwalacza_->emitPionDotarl();
           // (...) -----> trzeba dodać sprawdzenie, czy na polu nie stoją inne pionki
       }
   }
}





void CRysPionek::drawShape(QPainter *painter)
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





void CRysPionek::drawInnerShape(QPainter *painter)
{
    switch (innerShape_)
    {
    case 0:
        drawInnerShapeBow(painter);
        break;

    case 1:
        drawInnerShapeThreeSquares(painter);
        break;

    case 2:
        drawInnerShapeFourCircles(painter);
        break;

    case 3:
        drawInnerShapeSquare8(painter);
        break;

    default:
        drawInnerShapeBow(painter);
        break;
    }
}





void CRysPionek::drawInnerShapeBow(QPainter *painter)
{
    QPolygon polyg;
    QPoint point(0, 0);

    polyg<<point;

    point.setX(-size_.width() * 0.5 * 0.6);
    point.setY(size_.width() * 0.5 * 0.3);
    polyg<<point;

    point.setY(-point.y());
    polyg<<point;

    painter->drawPolygon(polyg);

    painter->rotate(180);
    painter->drawPolygon(polyg);

    painter->rotate(180);
}





void CRysPionek::drawInnerShapeThreeSquares(QPainter *painter)
{
    QPolygon polyg;
    QPoint point(-size_.width() * 0.5 * 0.8, 0);

    polyg << point;

    point.setX(point.x() + size_.width() * 0.33 * 0.5);
    point.setY(point.y() - size_.width() * 0.33 * 0.5);
    polyg << point;

    point.setX(point.x() + size_.width() * 0.33 * 0.5);
    point.setY(point.y() + size_.width() * 0.33 * 0.5);
    polyg << point;

    point.setX(point.x() - size_.width() * 0.33 * 0.5);
    point.setY(point.y() + size_.width() * 0.33 * 0.5);
    polyg << point;

    painter->drawPolygon(polyg);

    QTransform transform = painter->transform();
    painter->translate(QPoint(size_.width() * 0.33 * 0.7, 0));
    painter->drawPolygon(polyg);

    painter->translate(QPoint(size_.width() * 0.33 * 0.7, 0));
    painter->drawPolygon(polyg);

    painter->setTransform(transform);
}





void CRysPionek::drawInnerShapeFourCircles(QPainter *painter)
{
    //QTransform transform = painter->transform();

    painter->rotate(-45);

    QSizeF tmpSize(size_.height() * 8 / 31, size_.height() * 8 / 31);
    QPoint point(-tmpSize.width() / 2, -size_.height() * 0.5 * 0.8);

    painter->drawEllipse(QRectF(point, tmpSize));

    point.setY(point.y() + 0.7 * tmpSize.height());
    painter->drawEllipse(QRectF(point, tmpSize));

    point.setY(point.y() + 0.7 * tmpSize.height());
    painter->drawEllipse(QRectF(point, tmpSize));

    point.setY(point.y() + 0.7 * tmpSize.height());
    painter->drawEllipse(QRectF(point, tmpSize));

    painter->rotate(45);
    //painter->setTransform(transform);
}





void CRysPionek::drawInnerShapeSquare8(QPainter *painter)
{
    QPolygon polyg;
    QPoint point(0, 0);

    polyg << point;

    point.setX(-size_.width() * 0.5 * 0.3);
    point.setY(-size_.height() * 0.5 * 0.7 * 0.5);
    polyg << point;

    point.setX(0);
    point.setY(-size_.height() * 0.5 * 0.7);
    polyg << point;

    point.setX(size_.width() * 0.5 * 0.3);
    point.setY(-size_.height() * 0.5 * 0.7 * 0.5);
    polyg << point;

    painter->drawPolygon(polyg);


    painter->rotate(180);
    painter->drawPolygon(polyg);

    painter->rotate(180);

}





void CRysPionek::poziomoWLewo()
{
    QPointF nextPos = this->pos();

    nextPos.setX(nextPos.x() - dx_);
    nextPos.setY(nastPoz_.y() + parA_ * (nextPos.x() - startPoz_.x()) * (nextPos.x() - nastPoz_.x()));

    this->setPos(nextPos);
}





void CRysPionek::poziomoWPrawo()
{
    QPointF nextPos = this->pos();

    nextPos.setX(nextPos.x() + dx_);
    nextPos.setY(nastPoz_.y() - parA_ * (nextPos.x() - startPoz_.x()) * (nextPos.x() - nastPoz_.x()));

    this->setPos(nextPos);
}





void CRysPionek::pionowoWGore()
{
    QPointF nextPos = this->pos();

    //
    nextPos.setY(nextPos.y() - dx_);
    nextPos.setX(nastPoz_.x() - parA_ * (nextPos.y() - startPoz_.y()) * (nextPos.y() - nastPoz_.y()));

    this->setPos(nextPos);
}





void CRysPionek::pionowoWDol()
{
    QPointF nextPos = this->pos();

    //
    nextPos.setY(nextPos.y() + dx_);
    nextPos.setX(nastPoz_.x() + parA_ * (nextPos.y() - startPoz_.y()) * (nextPos.y() - nastPoz_.y()));

    this->setPos(nextPos);
}
