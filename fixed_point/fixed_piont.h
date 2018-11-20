#ifndef PRICE_PRICE_H
#define PRICE_PRICE_H
#include<stdio.h>

#include<iostream>

template <unsigned int SIZE,class T = int>
class Fixed_point
{

public:
    typedef T theType;
    explicit Fixed_point(T dollar = 0,T cent = 0);

    Fixed_point & operator=(T total);

    const Fixed_point operator+(const Fixed_point &price) const;
    const Fixed_point operator-(const Fixed_point &price) const;
    const Fixed_point operator/(const Fixed_point &price) const;
    const Fixed_point operator*(const Fixed_point &price) const;
    const Fixed_point operator%(const Fixed_point &price) const;

    Fixed_point& operator+=(const Fixed_point &price);
    Fixed_point& operator-=(const Fixed_point &price);
    Fixed_point& operator/=(const Fixed_point &price);
    Fixed_point& operator*=(const Fixed_point &price);
    Fixed_point& operator%=(const Fixed_point &price);

    Fixed_point & operator++ ();
    Fixed_point & operator--();
    const Fixed_point operator++(int);
    const Fixed_point operator--(int);
    const Fixed_point& operator-();

    bool operator==(const Fixed_point &price) const;
    bool operator!=(const Fixed_point &price) const;
    bool operator<=(const Fixed_point &price) const;
    bool operator>=(const Fixed_point &price) const;
    bool operator<(const Fixed_point &price) const;
    bool operator>(const Fixed_point &price) const;

    operator double() const {
        return double(m_cent)/TEN_POW;
        //return m_cent / TEN_POW + m_cent % TEN_POW;
    };

    friend std::ostream& operator<<(std::ostream&os, const Fixed_point<SIZE,T>&pr){
        os << pr.m_cent / pr.TEN_POW << "." << pr.m_cent % pr.TEN_POW  << "\n";
        return os;
    }

private:
    T m_cent;
    //static const int TEN_POW=100;
    const T TEN_POW;
};
int power1 (int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if ((y % 2) == 0)
        return power1 (x, y / 2) * power1 (x, y / 2);
    else
        return x * power1 (x, y / 2) * power1 (x, y / 2);

}
template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T>::Fixed_point(T dollar, T cent):TEN_POW(power1(10,SIZE)){
    m_cent=cent + dollar*TEN_POW;
}

template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T> & Fixed_point<SIZE,T>::operator=(T total) {
    m_cent=total*TEN_POW;
    return *this;
}

template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T> Fixed_point<SIZE,T>::operator+(const Fixed_point<SIZE,T> &price) const{
    return Fixed_point((m_cent + price.m_cent)/TEN_POW,(m_cent + price.m_cent)%TEN_POW);
}
template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T> Fixed_point<SIZE,T>::operator-(const Fixed_point<SIZE,T> &price) const{
    return Fixed_point((m_cent - price.m_cent)/TEN_POW,(m_cent - price.m_cent)%TEN_POW);
}
template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T> Fixed_point<SIZE,T>::operator/(const Fixed_point<SIZE,T> &price) const{
    T total= (double(m_cent) / double(price.m_cent)) * TEN_POW;
    return Fixed_point(total/TEN_POW,total%TEN_POW);
}

template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T> Fixed_point<SIZE,T>::operator*(const Fixed_point<SIZE,T> &price) const{
    T total= (m_cent * price.m_cent)/TEN_POW;
    return Fixed_point(double(total)/TEN_POW,(total)%TEN_POW);
}
template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T> Fixed_point<SIZE,T>::operator%(const Fixed_point<SIZE,T> &price) const{
    T total= m_cent % price.m_cent;
    return Fixed_point(total/TEN_POW,total%TEN_POW);
}
template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T>& Fixed_point<SIZE,T>::operator+=(const Fixed_point<SIZE,T> &price) {
    m_cent += price.m_cent;
    return *this;
}
template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T>& Fixed_point<SIZE,T>::operator-=(const Fixed_point<SIZE,T> &price) {
    m_cent -= price.m_cent;
    return *this;
}
template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T>& Fixed_point<SIZE,T>::operator*=(const Fixed_point<SIZE,T> &price) {
    m_cent *= price.m_cent;
    m_cent /= TEN_POW;
    return *this;
}
template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T>& Fixed_point<SIZE,T>::operator/=(const Fixed_point<SIZE,T> &price) {
    m_cent /= price.m_cent;
    m_cent *= TEN_POW;
    return *this;
}

template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T>& Fixed_point<SIZE,T>::operator%=(const Fixed_point<SIZE,T> &price) {
    m_cent %= price.m_cent;
    return *this;
}

template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T>& Fixed_point<SIZE,T>::operator-() {
    m_cent*=(-1);
    return  *this;
}

template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T> & Fixed_point<SIZE,T>::operator++ ()
{
    m_cent += TEN_POW;
    return *this;
}
template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T> & Fixed_point<SIZE,T>::operator-- ()
{
    m_cent -= TEN_POW;
    return *this;
}
template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T> Fixed_point<SIZE,T>::operator++(int) {
    Fixed_point tmp(*this);
    m_cent +=TEN_POW;
    return tmp;
}
template <unsigned int SIZE,class T>
inline const Fixed_point<SIZE,T> Fixed_point<SIZE,T>::operator--(int) {
    Fixed_point tmp(*this);
    m_cent -=TEN_POW;
    return tmp;
}
template <unsigned int SIZE,class T>
inline bool Fixed_point<SIZE,T>::operator==(const Fixed_point<SIZE,T> &  price) const {
    return m_cent==price.m_cent;
}
template <unsigned int SIZE,class T>
inline bool Fixed_point<SIZE,T>::operator!=(const Fixed_point<SIZE,T> &price) const {
    return !(*this==price);
}
template <unsigned int SIZE,class T>
inline bool Fixed_point<SIZE,T>::operator<=(const Fixed_point<SIZE,T> &price) const {
    return m_cent <= price.m_cent;
}
template <unsigned int SIZE,class T>
inline bool Fixed_point<SIZE,T>::operator>=(const Fixed_point<SIZE,T> &price) const {
    return m_cent >= price.m_cent;
}
template <unsigned int SIZE,class T>
inline bool Fixed_point<SIZE,T>::operator<(const Fixed_point<SIZE,T> &price) const {
    return m_cent < price.m_cent;
}
template <unsigned int SIZE,class T>
inline bool Fixed_point<SIZE,T>::operator>(const Fixed_point<SIZE,T> &price) const {
    return m_cent<price.m_cent;
}


#endif //PRICE_PRICE_H