/**
\file mycomplex.h
\brief ������������ ���� ������ Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;


/**
\brief ����� ������������ �����
*/


class Complex

/**
\brief �������������� ����
*/

{
    double re;
/**
\brief ������� ����
*/
	double im;
public:
    Complex (double are = 0, double aim = 0);
    Complex (const Complex & );
    ~Complex();

void Set (double are, double aim = 0);

    operator double ();
    double abs ();

    friend istream & operator >> (istream &, Complex &);
    friend ostream & operator << (ostream &, Complex &);
            Complex operator + (const Complex &);
            Complex operator - (const Complex &);
            Complex operator + (const double &);

    friend
            Complex operator + (const double &, const Complex &);
            Complex operator - (const double &);

    friend
            Complex operator - (const double &, const Complex &);
            Complex operator * (const Complex &);
            Complex operator * (const double &);

    friend
            Complex operator * (const double &, const Complex &);
            Complex operator / (const double &);
            Complex & operator += (const Complex &);
            Complex & operator -= (const Complex &);
            Complex & operator *= (const Complex &);
            Complex & operator += (const double &);
            Complex & operator -= (const double &);
            Complex & operator *= (const double &);
            Complex & operator /= ( const double &);
            Complex & operator = (const Complex &);
            Complex & operator = (const double &);
};
#endif
