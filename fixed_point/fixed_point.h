#ifndef PRICE_PRICE_H
#define PRICE_PRICE_H
#include<stdio.h>

#include<iostream>


template<unsigned int power>
struct compilation_pow
{
    static const size_t value = compilation_pow<power - 1>::value * 10 ;
};

template <>
struct compilation_pow<0>
{
    static const size_t value = 1 ;
};


template <unsigned int SIZE,class T = int>
class Fixed_point
{

public:

    explicit Fixed_point(T dollar = 0,T cent = 0);

    Fixed_point & operator=(T total);
    Fixed_point & operator=(Fixed_point price);

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
    typedef T theType;
    enum {PRECISION = SIZE};

private:
    T m_cent;
    static const T TEN_POW=compilation_pow<SIZE>::value;

};

template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T>::Fixed_point(T dollar, T cent){
    m_cent=cent + dollar*TEN_POW;
}

template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T> & Fixed_point<SIZE,T>::operator=(T total) {
    m_cent=total*TEN_POW;
    return *this;
}

template <unsigned int SIZE,class T>
inline Fixed_point<SIZE,T> & Fixed_point<SIZE,T>::operator=(Fixed_point<SIZE,T> price) {
    m_cent=price.m_cent;
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
    return m_cent>price.m_cent;
}


template <typename T>
class numeric_limits
{
public:
    static const bool is_specialized = false;
};


template<>
template<unsigned int SIZE, typename T>
class numeric_limits<Fixed_point<SIZE,T> >
{
public:
    static const bool is_specialized = true;
    static Fixed_point<SIZE,T> min()
    {
        T new_min = numeric_limits<T>::min();
        return Fixed_point<SIZE,T>(0,new_min);
    }

    static Fixed_point<SIZE,T> max() {
        T new_max = numeric_limits<T>::max();
        return Fixed_point<SIZE,T>(0,new_max);
    }
};
#endif //PRICE_PRICE_H