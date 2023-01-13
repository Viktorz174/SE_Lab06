/**
\file mycomplex.cpp
\brief Çàãîëîâî÷íûé ôàéë êëàññà Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
\brief Êîíñòðóêòîð êëàññà
\param aRe Äåéñòâèòåëüíàÿ ñîñòàâëÿþùàÿ
\param aIm Ìíèìàÿ ñîñòàâëÿþùàÿ
*/
Complex::Complex (double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
\brief Êîíñòðóêòîð êëàññà ÷åðåç óêàçàòåëü
\param aRval.Re Äåéñòâèòåëüíàÿ ñîñòàâëÿþùàÿ
\param aRval.Im Ìíèìàÿ ñîñòàâëÿþùàÿ
*/
Complex::Complex (const Complex &aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
\brief Äåñòðóêòîð
*/
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

/**
\brief Ìåòîä ïðèñâàèâàíèÿ çíà÷åíèÿ
\param aRe Äåéñòâèòåëüíàÿ ñîñòàâëÿþùàÿ
\param aIm Ìíèìàÿ ñîñòàâëÿþùàÿ
*/
void Complex::Set (double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
\brief Ìåòîä ïðèñâàèâàíèÿ çíà÷åíèÿ
\param aRe Äåéñòâèòåëüíàÿ ñîñòàâëÿþùàÿ
\param aIm Ìíèìàÿ ñîñòàâëÿþùàÿ
\return Ìîäóëü
*/
Complex::operator double()
{
    return abs();
}

/**
\brief Ìåòîä àáñîëþòíîå çíà÷åíèå
\return Ìîäóëü
*/
double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}

/**
\brief Îïåðàòîð +
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ñóììà
*/
Complex Complex::operator + (const Complex &aRval)
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im ;
    return Result;
}

/**
\brief Îïåðàòîð -
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ðàçíîñòü
*/
Complex Complex::operator - (const Complex &aRval)
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
\brief Îïåðàòîð +
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ñóììà
*/
Complex Complex::operator + (const double &aRval)
{
    Complex Result;
    Result.Re = Re + aRval;
    Result.Im = Im;
    return Result;
}

/**
\brief Îïåðàòîð -
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ðàçíîñòü
*/
Complex Complex:: operator - (const  double &aRval)
{
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

/**
\brief Îïåðàòîð *
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ïðîèçâåäåíèå
*/
Complex Complex::operator * (const Complex &aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
\brief Îïåðàòîð *
\param &aRval Êîìïëåêñíîå ÷èñëî êîíñòàíòà
\return Ïðîèçâåäåíèå
*/
Complex Complex::operator * (const double &aRval)
{
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/**
\brief Îïåðàòîð /
\param &aRval Êîìïëåêñíîå ÷èñëî
\return ×àñòíîå
*/
Complex Complex::operator / (const double &aRval)
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/**
\brief Îïåðàòîð +=
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ñóììà
*/
Complex &Complex::operator += (const Complex &aRval)
{
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
\brief Îïåðàòîð -=
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ðàçíîñòü
*/
Complex &Complex::operator -= (const Complex &aRval)
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
\brief Îïåðàòîð *=
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ïðîèçâåäåíèå
*/
Complex &Complex::operator *= (const Complex &aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
\brief Îïåðàòîð +=
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ñóììà
*/
Complex &Complex::operator += (const double &aRval)
{
    Re += aRval;
    return *this;
}

/**
\brief Îïåðàòîð -=
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ðàçíîñòü
*/
Complex &Complex::operator -= (const double &aRval)
{
    Re -= aRval;
    return *this;
}

/**
\brief Îïåðàòîð *=
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ïðîèçâåäåíèå
*/
Complex &Complex::operator *= (const double &aRval)
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/**
\brief Îïåðàòîð /=
\param &aRval Êîìïëåêñíîå ÷èñëî
\return ×àñòíîå
*/
Complex &Complex::operator /= (const double &aRval)
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/**
\brief Îïåðàòîð =
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ïðèñâàèâàíèå
*/
Complex &Complex::operator = (const Complex &aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
\brief Îïåðàòîð =
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ïðèñâàèâàíèå
*/
Complex &Complex::operator = (const double &aRval)
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

/**
\brief Îïåðàòîð >>
\param &aRval Êîìïëåêñíîå ÷èñëî
\return ñäâèã âïðàâî
*/
istream &operator >> (istream& stream, Complex &aRval)
{
    char tmp[256];
    stream >> aRval.Re >> aRval.Im >> tmp;
    return stream;
}

/**
\brief Îïåðàòîð <<
\param &aRval Êîìïëåêñíîå ÷èñëî
\return ñäâèã âëåâî
*/
ostream &operator << (ostream& stream, Complex &aRval)
{
    stream << aRval.Re;
    if(!(aRval.Im < 0))
    {
        stream << '+';
        stream << aRval.Im << 'i';
    }
    return stream;
}

/**
\brief Îïåðàòîð +
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ñóììà
*/
Complex operator + (const double& aLval, const Complex &aRval)
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im =  aRval.Im;
    return Result;
}

/**
\brief Îïåðàòîð -
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ðàçíîñòü
*/
Complex operator - (const double &aLval, const Complex &aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im =- aRval.Im;
    return Result;
}

/**
\brief Îïåðàòîð *
\param &aRval Êîìïëåêñíîå ÷èñëî
\return Ïðîèçâåäåíèå
*/
Complex operator * (const double &aLval, const Complex &aRval)
{
    Complex Result;
    Result.Re = aLval * aRval.Re;
    Result.Im = aLval * aRval.Im;
    return Result;
}
