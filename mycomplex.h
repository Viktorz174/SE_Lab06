/**
\file mycomplex.h
\brief Çàãîëîâî÷íûé ôàéë êëàññà Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_

#include <iostream>

using namespace std;

/**
\brief Êëàññ êîìïëåêñíîãî ÷èñëà
*/

class Complex
{
/**
\brief Äåéñòâèòåëüíàÿ ÷àòü
*/
    double Re;
/**
\brief Ìèíèìàÿ ÷àòü
*/
    double Im;

    public:
    Complex(double aRe = 0, double aIm = 0);
    Complex(const Complex &);
    Complex &operator = (const Complex&);
    Complex &operator = (const double&);
    Complex &operator += (const Complex&);
    Complex &operator += (const double&);
    Complex &operator -= (const Complex&);
    Complex &operator -= (const double&);
    Complex &operator *= (const Complex&);
    Complex &operator *= (const double&);
    Complex &operator /= (const Complex&);
    Complex &operator /= (const double&);

    void Set(double aRe, double aIm);
    operator double();
    double abs();
}
#endif
