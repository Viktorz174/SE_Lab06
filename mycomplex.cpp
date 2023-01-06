/**
\file mycomplex.cpp
\brief ������������ ���� ������ Copmlex
*/
#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
\brief ����������� ������
\param are �������������� ������������
\param aim ������ ������������
*/

    Complex :: Complex (double are, double aim)
    {
    re = are;
    im = aim;
    }

/**
\brief ����������� ������ ����� ���������
\param arval.re �������������� ������������
\param arval.im ������ ������������
*/

    Complex :: Complex (const Complex & arval)
    {
    re = arval.re;
    im = arval.im;
    }

/**
\brief ����������
*/

    Complex :: ~Complex()
    {
    re = 0.0;
    im = 0.0;
    }

/**
\brief ����� ������������ ��������
\param are �������������� ������������
\param aim ������ ������������
*/

    void Complex :: Set (double are, double aim)
    {
    re = are;
    im = aim;
    }

/**
\brief ����� ������������ ��������
\param are �������������� ������������
\param aim ������ ������������
\return ������
*/

    Complex :: operator double()
    {
    return abs();
    }

/**
\brief ����� ���������� ��������
\return ������
*/

    double Complex :: abs()
    {
    return sqrt(re * re + im * im);
    }

/**
\brief �������� +
\param &arval ����������� �����
\return �����
*/

    Complex Complex :: operator + (const Complex & arval )
    {
    Complex Result;
    Result.re = re + arval.re;
    Result.im = im + arval.im ;
    return Result;
    }

/**
\brief �������� -
\param &arval ����������� �����
\return ��������
*/

    Complex Complex :: operator - (const Complex & arval)
    {
    Complex Result;
    Result.re = re - arval.re;
    Result.im = im - arval.im;
    return Result;
    }

/**
\brief �������� +
\param &arval ����������� �����
\return �����
*/

    Complex Complex :: operator + (const double & arval)
    {
    Complex result;
    result.re = re + arval;
    result.im = im;
    return result;
    }

/**
\brief �������� -
\param &arval ����������� �����
\return ��������
*/

    Complex Complex :: operator - (const double & arval)
    {
    Complex Result (*this);
    Result.re = re - arval;
    return Result;
    }

/**
\brief �������� *
\param &arval ����������� �����
\return ������������
*/

    Complex Complex  :: operator * (const Complex & arval)
    {
    Complex Result;
    Result.re = re * arval.re - im * arval.im;
    Result.im = re * arval.im + im * arval.re;
    return Result;
    }

/**
\brief �������� *
\param &arval ����������� ����� ���������
\return ������������
*/

    Complex Complex :: operator * (const double & arval)
    {
    Complex Result;
    Result.re =re * arval;
    Result.im =im * arval;
    return Result;
    }

/**
\brief �������� /
\param &arval ����������� �����
\return �������
*/

    Complex Complex :: operator / (const double & arval)
    {   Complex Result;
    Result.re = re / arval;
    Result.im = im / arval;
    return Result;
    }

/**
\brief �������� +=
\param &arval ����������� �����
\return �����
*/

    Complex & Complex :: operator += (const Complex & arval)
    {
    re += arval.re;
    im += arval.im;
    return * this;
    }

/**
\brief �������� -=
\param &arval ����������� �����
\return ��������
*/

    Complex & Complex :: operator -= (const Complex & arval)
    {
    re -= arval.re;
    im -= arval.im;
    return * this;
    }

/**
\brief �������� *=
\param &a�val ����������� �����
\return ��������
*/

    Complex & Complex :: operator *= (const Complex & arval)
    {
    double tmpre = re;
    re = re * arval.re - im * arval.im;
    im = im * arval.re + tmpre * arval.im;
    return * this;
    }

/**
\brief �������� +=
\param &arval ����������� �����
\return �����
*/

    Complex & Complex :: operator += (const double & arval)
    {
    re += arval;
    return * this;
    }

/**
\brief �������� -=
\param &arval ����������� �����
\return ��������
*/

    Complex & Complex :: operator -= (const double & arval)
    {
    re -= arval;
    return * this;
    }

/**
\brief �������� *=
\param &arval ����������� �����
\return ������������
*/

    Complex & Complex :: operator *= (const double & arval)
    {
    re *= arval;
    im *= arval;
    return * this;
    }

/**
\brief �������� *=
\param &arval ����������� �����
\return �������
*/

    Complex & Complex :: operator /= (const double & arval)
    {
    re /= arval;
    im /= arval;
    return * this;
    }

/**
\brief �������� =
\param &arval ����������� �����
\return ������������
*/

    Complex & Complex :: operator = (const Complex & arval)
    {
    re = arval.re;
    im = arval.im;
    return * this;
    }

/**
\brief �������� =
\param &arval ����������� �����
\return ������������
*/

    Complex & Complex :: operator = (const double & arval)
    {
    re = arval;
    im = 0.0;
    return * this;
    }

/**
\brief �������� >>
\param &arval ����������� �����
\return ����� �����
*/

    istream & operator >> (istream & stream, Complex & arval)
    {
    char tmp [256];
    stream >> arval.re >> arval.im >> tmp;
    return stream;
    }

/**
\brief �������� >>
\param &arval ����������� �����
\return ����� ����
*/

    ostream & operator << (ostream & stream, Complex & arval)
    {
    stream << arval.re;
    if ( ! (arval.im < 0) ) stream << '+';
    stream << arval.im << 'i';
    return stream;
    }
/**
\brief �������� +
\param &arval ����������� �����
\return �����
*/

    Complex operator + (const double & alval, const Complex & arval)
    {
    Complex Result;
    Result.re = alval + arval.re;
    Result.im = arval.im;
    return Result;
    }

/**
\brief �������� -
\param &arval ����������� �����
\return ��������
*/

    Complex operator - (const double & alval, const Complex & arval)
    {
    Complex Result;
    Result.re = alval - arval.re;
    Result.im = -arval.im;
    return Result;
    }

/**
\brief �������� *
\param &arval ����������� �����
\return ������������
*/

    Complex operator * (const double & alval, const Complex & arval)
    {
    Complex r;
    r.re = alval * arval.re;
    r.im = alval * arval.im;
    return r;
    }
