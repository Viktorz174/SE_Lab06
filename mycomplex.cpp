#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

Complex :: Complex (double are, double aim)
    {
    re = are;
    im = aim;
    }
    Complex :: Complex (const Complex & arval)
    {
    re = arval.re;
    im = arval.im;
    }
    Complex :: ~Complex()
    {
    re = 0.0;
    im = 0.0;
    }
    void Complex :: Set (double are, double aim)
    {
    re = are;
    im = aim;
    }
    Complex :: operator double()
    {
    return abs();
    }
    double Complex :: abs()
    {
    return sqrt(re * re + im * im);
    }
    Complex Complex :: operator + (const Complex & arval )
    {
    Complex Result;
    Result.re = re + arval.re;
    Result.im = im + arval.im ;
    return Result;
    }
    Complex Complex :: operator - (const Complex & arval)
    {
    Complex Result;
    Result.re = re - arval.re;
    Result.im = im - arval.im;
    return Result;
    }
    Complex Complex :: operator + (const double & arval)
    {
    Complex result;
    result.re = re + arval;
    result.im = im;
    return result;
    }
    Complex Complex :: operator - (const double & arval)
    {
    Complex Result (*this);
    Result.re = re - arval;
    return Result;
    }
    Complex Complex  :: operator * (const Complex & arval)
    {
    Complex Result;
    Result.re = re * arval.re - im * arval.im;
    Result.im = re * arval.im + im * arval.re;
    return Result;
    }
    Complex Complex :: operator * (const double & arval)
    {
    Complex Result;
    Result.re =re * arval;
    Result.im =im * arval;
    return Result;
    }
    Complex Complex :: operator / (const double & arval)
    {   Complex Result;
    Result.re = re / arval;
    Result.im = im / arval;
    return Result;
    }
    Complex & Complex :: operator += (const Complex & arval)
    {
    re += arval.re;
    im += arval.im;
    return * this;
    }
    Complex & Complex :: operator -= (const Complex & arval)
    {
    re -= arval.re;
    im -= arval.im;
    return * this;
    }
    Complex & Complex :: operator *= (const Complex & arval)
    {
    double tmpre = re;
    re = re * arval.re - im * arval.im;
    im = im * arval.re + tmpre * arval.im;
    return * this;
    }
    Complex & Complex :: operator += (const double & arval)
    {
    re += arval;
    return * this;
    }
    Complex & Complex :: operator -= (const double & arval)
    {
    re -= arval;
    return * this;
    }
    Complex & Complex :: operator *= (const double & arval)
    {
    re *= arval;
    im *= arval;
    return * this;
    }
    Complex & Complex :: operator /= (const double & arval)
    {
    re /= arval;
    im /= arval;
    return * this;
    }
    Complex & Complex :: operator = (const Complex & arval)
    {
    re = arval.re;
    im = arval.im;
    return * this;
    }
    Complex & Complex :: operator = (const double & arval)
    {
    re = arval;
    im = 0.0;
    return * this;
    }
    istream & operator >> (istream & stream, Complex & arval)
    {
    char tmp [256];
    stream >> arval.re >> arval.im >> tmp;
    return stream;
    }
    ostream & operator << (ostream & stream, Complex & arval)
    {
    stream << arval.re;
    if ( ! (arval.im < 0) ) stream << '+';
    stream << arval.im << 'i';
    return stream;
    }
    Complex operator + (const double & alval, const Complex & arval)
    {
    Complex Result;
    Result.re = alval + arval.re;
    Result.im = arval.im;
    return Result;
    }
    Complex operator - (const double & alval, const Complex & arval)
    {
    Complex Result;
    Result.re = alval - arval.re;
    Result.im = -arval.im;
    return Result;
    }
    Complex operator * (const double & alval, const Complex & arval)
    {
    Complex r;
    r.re = alval * arval.re;
    r.im = alval * arval.im;
    return r;
    }
