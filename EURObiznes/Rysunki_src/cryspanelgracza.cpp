#include "Rysunki_h/cryspanelgracza.h"





CRysPanelGracza::CRysPanelGracza()
{
    crtdMark_ = false;
}





CRysPanelGracza::CRysPanelGracza(QPoint topLeft, QSizeF size, SDnPionka danePionka, SDnGracza daneGr, QString imgPath, qreal rot) : CRys(topLeft, size, rot)
{
    crtdMark_ = false;

    pionek_ = new CRysPionek(danePionka);    

    // napisy    
    rodzGracza_ = "(" + odkodujRodzGracza(daneGr.rodz) + ")";
    nick_ = QString::fromStdString(daneGr.nick);
    portfel_ = QString::number(daneGr.portfel);
    lbKartWolnosc_ = QString::number(daneGr.lbKartWolnosc);

    // ścieżka do rysunku tła
    imgPath_ = imgPath;
}





CRysPanelGracza::~CRysPanelGracza()
{
    delete pionek_;
}





void CRysPanelGracza::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Rysowanie obrazu tła
    QImage image(imgPath_);
    image = image.scaled(1 * size_.width(), 1 * size_.width());
    painter->drawImage(boundingRect(), image, QRectF(0, 0, 1 * size_.width(), 1 * size_.width()));

    // rysowanie pionka
    pionek_->setPos(mapToScene(QPointF(topLeft_.x() + 0.15 * size_.width(), topLeft_.y() + 0.25 * size_.height())));
    this->scene()->addItem(pionek_);
    crtdMark_ = true;

    // pisanie tekstów
    painter->setPen(QPen(QColor(255, 255, 255)));

        // nick gracza
    QFont font("Comic Sans MS", 12);
    font.setBold(true);
    painter->setFont(font);
    QRectF tmpRect(topLeft_.x() + 0.2 * size_.width() + WYM_PIONA_PAN_GR.width(), topLeft_.y() + 0.1 * size_.height(), 0.5 * size_.width(), 0.25 * size_.height());
    painter->drawText(tmpRect, Qt::AlignLeft | Qt::TextWordWrap, "Gracz: " + nick_ + " " + rodzGracza_);

        // portfel
    QRectF tmpRect_2(tmpRect.topLeft().x(), tmpRect.topLeft().y() + 0.25 * size_.height(), 0.5 * size_.width(), 0.2 * size_.height());
    painter->drawText(tmpRect_2, Qt::AlignLeft | Qt::TextWordWrap, "Portfel: " + portfel_);

        // liczba kart wolność
    QRectF tmpRect_3(tmpRect_2.topLeft().x(), tmpRect_2.topLeft().y() + 0.2 * size_.height(), 0.5 * size_.width(), 0.2 * size_.height());
    painter->drawText(tmpRect_3, Qt::AlignLeft, "Karty \"Wyjdź z więzienia\": " + lbKartWolnosc_);
}





QPainterPath CRysPanelGracza::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}





void CRysPanelGracza::aktualizujPanel(SDnPionka danePionka, std::string rodzGracza, std::string nick, int portfel, int lbKart)
{
    this->scene()->removeItem(pionek_);
    delete pionek_;
    danePionka.topLeft = TOPLEFT_PIONA_PAN_GR;
    danePionka.size = WYM_PIONA_PAN_GR;
    pionek_ = new CRysPionek(danePionka);

    rodzGracza_ = "(" + odkodujRodzGracza(rodzGracza) + ")";
    nick_ = QString::fromStdString(nick);
    portfel_ = QString::number(portfel);
    lbKartWolnosc_ = QString::number(lbKart);
}





void CRysPanelGracza::aktualizujPanel(SDnPionka danePionka, SDnGracza daneGr)
{
    delete pionek_;
    danePionka.topLeft = TOPLEFT_PIONA_PAN_GR;
    danePionka.size = WYM_PIONA_PAN_GR;
    pionek_ = new CRysPionek(danePionka);

    rodzGracza_ = "(" + odkodujRodzGracza(daneGr.rodz) + ")";
    nick_ = QString::fromStdString(daneGr.nick);
    portfel_ = QString::number(daneGr.portfel);
    lbKartWolnosc_ = QString::number(daneGr.lbKartWolnosc);
}





void CRysPanelGracza::aktualNapisPortfel(int portfel)
{
    portfel_ = QString::number(portfel);
}





void CRysPanelGracza::aktualNapislbKartWolnosc(int lbKart)
{
    lbKartWolnosc_ = QString::number(lbKart);
}





void CRysPanelGracza::graczUzylKartyWolnosc()
{
    lbKartWolnosc_ = QString::number((lbKartWolnosc_.toInt() - 1));
    this->update();
}





QString CRysPanelGracza::odkodujRodzGracza(std::string rodzGracza)
{
    if(rodzGracza == "cz" || rodzGracza == "Cz" || rodzGracza == "CZ")
        return "człowiek";
    else if(rodzGracza == "komp"  || rodzGracza == "Komp" || rodzGracza == "KOMP")
        return "A. I.";
    else
        return "alien";
}
