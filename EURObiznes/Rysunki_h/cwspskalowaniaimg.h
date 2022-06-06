#ifndef CWSPSKALOWANIAIMG_H
#define CWSPSKALOWANIAIMG_H






/**
 * @brief Klasa graficzna
 */
class CWspSkalowaniaImg
{
protected:
    double factorW_;
    double factorH_;

public:
    CWspSkalowaniaImg();
    CWspSkalowaniaImg(double factorW, double factorH);
    ~CWspSkalowaniaImg();

    double podajFactorW();
    double podajFactorH();

    void resetFactors(double factorW, double factorH);
};

#endif // CWSPSKALOWANIAIMG_H
