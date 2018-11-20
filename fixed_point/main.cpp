#include <iostream>
#include "fixed_piont.h"

void test_price_ctor_1(){
    Fixed_point<2,int> p(8);
    std::cout<<"test constructor 1 ok"<<std::endl;
}

//void test_price_ctor_2(){
//    Price p(8,68);
//    std::cout<<"test constructor 2 ok"<<std::endl;
//}
//
//void test_assignment_int_operator(){
//    Price p;
//    p = 9;
//    if(p == Price(9))
//        std::cout<<"test assignment int ok"<<std::endl;
//}
//
void test_add_operator(){
    Fixed_point<4,long> p(8,68);
    Fixed_point<4,long> p2(2,11);
    if(p+p2 == Fixed_point<4,long>(10,79))
        std::cout<<"test operator + ok "<<std::endl;

}
//void test_sub_operator(){
//    Price p(8,68);
//    Price p2(2,11);
//    if(p-p2 == Price(6,57))
//        std::cout<<"test operator - ok "<<std::endl;
//
//}
//void test_div_operator(){
//
//    Price p(8,0);
//    Price p2(2);
//    if(p/p2 == Price(4))
//        std::cout<<"test operator / ok "<<std::endl;
//}
//
void test_mul_operator(){

    Fixed_point<4,long> p(1,5555);
    Fixed_point<4,long> p2(3,0);
    std::cout<<"test "<<p*p2<<std::endl;
    if(p*p2 == Fixed_point<4,long>(4,6665))
        std::cout<<"test operator * ok "<<p*p2<<std::endl;

}
//
//void test_modulo_operator(){
//
//    Price p(8,0);
//    Price p2(2);
//    if(p%p2 == Price(0))
//        std::cout<<"test operator % ok "<<std::endl;
//
//}
//void test_add_equals_operator(){
//
//    Price p(8,0);
//    p+=Price(2);
//    if(p == Price(10))
//        std::cout<<"test operator += ok "<<std::endl;
//
//}
//void test_sub_equals_operator(){
//
//    Price p(8,0);
//    p-=Price(2);
//    if(p == Price(6))
//        std::cout<<"test operator -= ok "<<std::endl;
//
//
//}
//void test_less_operator(){
//
//    Price p(8,0);
//    Price p2(2);
//    if(p2 < p)
//        std::cout<<"test operator < ok "<<std::endl;
//
//
//}
//void test_less_equals_operator(){
//
//    Price p(8,0);
//    Price p2(8);
//    if(p2 <= p)
//        std::cout<<"test operator <= ok "<<std::endl;
//
//
//}
//void test_greater_equals_operator(){
//
//    Price p(20,0);
//    Price p2(20);
//    if(p2>=p)
//        std::cout<<"test operator >= ok "<<std::endl;
//
//}
//void test_greater_operator(){
//
//    Price p(8,0);
//    Price p2(20);
//    if(p2>p)
//        std::cout<<"test operator > ok "<<std::endl;
//
//}
//void test_plus_plus_operator(){
//
//    Price p(8,0);
//    if(p++ == Price(8))
//        std::cout<<"test operator ++ ok "<<p<<std::endl;
//
//}
//void test_minus_minus_operator(){
//
//    Price p(8,0);
//    if(p-- == Price(8))
//        std::cout<<"test operator -- ok "<<std::endl;
//
//}
//void test_plus_plus_int_operator(){
//
//    Price p(8,0);
//    Price p2;
//    p2=p++;
//    if((p == Price(9)) && (p2==Price(8)))
//        std::cout<<"test operator ++(int) ok "<<std::endl;
//
//}
//
//void test_minus_minus_int_operator(){
//
//    Price p(8,0);
//    Price p2;
//    p2=p--;
//    if((p == Price(7)) && (p2==Price(8)))
//        std::cout<<"test operator --(int) ok "<<std::endl;
//
//}

void test_minus_operator(){

    Fixed_point<2,int> p2(8,0);
    if(-p2 ==  Fixed_point<2,int>(-8))
        std::cout<<"test operator -- ok "<<std::endl;

}
int main() {
    Fixed_point<4>::theType x;
//test_price_ctor_1();
//    test_price_ctor_2();
//test_assignment_int_operator();
//test_add_operator();
//    test_sub_operator();
//    test_div_operator();
//test_mul_operator();
//test_modulo_operator();
//    test_less_operator();
//    test_less_equals_operator();
//test_add_equals_operator();
//
//test_greater_equals_operator();
//test_greater_operator();
//test_plus_plus_operator();
//test_minus_minus_operator();
//test_plus_plus_int_operator();
//test_minus_minus_int_operator();
    test_minus_operator();
    return 0;
}