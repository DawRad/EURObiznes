#include "Rysunki_h\cwspskalowaniaimg.h"





CWspSkalowaniaImg::CWspSkalowaniaImg()
{

}





CWspSkalowaniaImg::CWspSkalowaniaImg(double factorW, double factorH)
{
    factorW_ = factorW;
    factorH_ = factorH;
}





CWspSkalowaniaImg::~CWspSkalowaniaImg()
{

}





double CWspSkalowaniaImg::podajFactorW()
{
    return factorW_;
}





double CWspSkalowaniaImg::podajFactorH()
{
    return factorH_;
}





void CWspSkalowaniaImg::resetFactors(double factorW, double factorH)
{
    factorW_ = factorW;
    factorH_ = factorH;
}
