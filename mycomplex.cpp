/**
\file mycomplex.cpp
\brief Заголовочный файл класса Copmlex
*/
#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
\brief Конструктор класса
\param are Действительная составляющая
\param aim Мнимая составляющая
*/

    Complex :: Complex (double are, double aim)
    {
    re = are;
    im = aim;
    }

/**
\brief Конструктор класса через указатель
\param arval.re Действительная составляющая
\param arval.im Мнимая составляющая
*/

    Complex :: Complex (const Complex & arval)
    {
    re = arval.re;
    im = arval.im;
    }

/**
\brief Деструктор
*/

    Complex :: ~Complex()
    {
    re = 0.0;
    im = 0.0;
    }

/**
\brief Метод присваивания значения
\param are Действительная составляющая
\param aim Мнимая составляющая
*/

    void Complex :: Set (double are, double aim)
    {
    re = are;
    im = aim;
    }

/**
\brief Метод присваивания значения
\param are Действительная составляющая
\param aim Мнимая составляющая
\return Модуль
*/

    Complex :: operator double()
    {
    return abs();
    }

/**
\brief Метод абсолютное значение
\return Модуль
*/

    double Complex :: abs()
    {
    return sqrt(re * re + im * im);
    }

/**
\brief Оператор +
\param &arval Комплексное число
\return Сумма
*/

    Complex Complex :: operator + (const Complex & arval )
    {
    Complex Result;
    Result.re = re + arval.re;
    Result.im = im + arval.im ;
    return Result;
    }

/**
\brief Оператор -
\param &arval Комплексное число
\return Разность
*/

    Complex Complex :: operator - (const Complex & arval)
    {
    Complex Result;
    Result.re = re - arval.re;
    Result.im = im - arval.im;
    return Result;
    }

/**
\brief Оператор +
\param &arval Комплексное число
\return Сумма
*/

    Complex Complex :: operator + (const double & arval)
    {
    Complex result;
    result.re = re + arval;
    result.im = im;
    return result;
    }

/**
\brief Оператор -
\param &arval Комплексное число
\return Разность
*/

    Complex Complex :: operator - (const double & arval)
    {
    Complex Result (*this);
    Result.re = re - arval;
    return Result;
    }

/**
\brief Оператор *
\param &arval Комплексное число
\return Произведение
*/

    Complex Complex  :: operator * (const Complex & arval)
    {
    Complex Result;
    Result.re = re * arval.re - im * arval.im;
    Result.im = re * arval.im + im * arval.re;
    return Result;
    }

/**
\brief Оператор *
\param &arval Комплексное число константа
\return Произведение
*/

    Complex Complex :: operator * (const double & arval)
    {
    Complex Result;
    Result.re =re * arval;
    Result.im =im * arval;
    return Result;
    }

/**
\brief Оператор /
\param &arval Комплексное число
\return Частное
*/

    Complex Complex :: operator / (const double & arval)
    {   Complex Result;
    Result.re = re / arval;
    Result.im = im / arval;
    return Result;
    }

/**
\brief Оператор +=
\param &arval Комплексное число
\return Сумма
*/

    Complex & Complex :: operator += (const Complex & arval)
    {
    re += arval.re;
    im += arval.im;
    return * this;
    }

/**
\brief Оператор -=
\param &arval Комплексное число
\return Разность
*/

    Complex & Complex :: operator -= (const Complex & arval)
    {
    re -= arval.re;
    im -= arval.im;
    return * this;
    }

/**
\brief Оператор *=
\param &aкval Комплексное число
\return Разность
*/

    Complex & Complex :: operator *= (const Complex & arval)
    {
    double tmpre = re;
    re = re * arval.re - im * arval.im;
    im = im * arval.re + tmpre * arval.im;
    return * this;
    }

/**
\brief Оператор +=
\param &arval Комплексное число
\return Сумма
*/

    Complex & Complex :: operator += (const double & arval)
    {
    re += arval;
    return * this;
    }

/**
\brief Оператор -=
\param &arval Комплексное число
\return Разность
*/

    Complex & Complex :: operator -= (const double & arval)
    {
    re -= arval;
    return * this;
    }

/**
\brief Оператор *=
\param &arval Комплексное число
\return Произведение
*/

    Complex & Complex :: operator *= (const double & arval)
    {
    re *= arval;
    im *= arval;
    return * this;
    }

/**
\brief Оператор *=
\param &arval Комплексное число
\return Частное
*/

    Complex & Complex :: operator /= (const double & arval)
    {
    re /= arval;
    im /= arval;
    return * this;
    }

/**
\brief Оператор =
\param &arval Комплексное число
\return Присваивание
*/

    Complex & Complex :: operator = (const Complex & arval)
    {
    re = arval.re;
    im = arval.im;
    return * this;
    }

/**
\brief Оператор =
\param &arval Комплексное число
\return Присваивание
*/

    Complex & Complex :: operator = (const double & arval)
    {
    re = arval;
    im = 0.0;
    return * this;
    }

/**
\brief Оператор >>
\param &arval Комплексное число
\return сдвиг право
*/

    istream & operator >> (istream & stream, Complex & arval)
    {
    char tmp [256];
    stream >> arval.re >> arval.im >> tmp;
    return stream;
    }

/**
\brief Оператор >>
\param &arval Комплексное число
\return сдвиг лево
*/

    ostream & operator << (ostream & stream, Complex & arval)
    {
    stream << arval.re;
    if ( ! (arval.im < 0) ) stream << '+';
    stream << arval.im << 'i';
    return stream;
    }
/**
\brief Оператор +
\param &arval Комплексное число
\return Сумма
*/

    Complex operator + (const double & alval, const Complex & arval)
    {
    Complex Result;
    Result.re = alval + arval.re;
    Result.im = arval.im;
    return Result;
    }

/**
\brief Оператор -
\param &arval Комплексное число
\return Разность
*/

    Complex operator - (const double & alval, const Complex & arval)
    {
    Complex Result;
    Result.re = alval - arval.re;
    Result.im = -arval.im;
    return Result;
    }

/**
\brief Оператор *
\param &arval Комплексное число
\return Произведение
*/

    Complex operator * (const double & alval, const Complex & arval)
    {
    Complex r;
    r.re = alval * arval.re;
    r.im = alval * arval.im;
    return r;
    }
