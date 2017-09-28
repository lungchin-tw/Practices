/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/


#include <iostream>


class A
{
protected:
    friend class B;
    void B_CanDo() { std::cout << __FUNCTION__ << std::endl; }

private:
    friend class C;
    void C_CanDo() { std::cout << __FUNCTION__ << std::endl; }
};

class B
{
public:
    B( A& a ) { a.C_CanDo(); }
};

int main()
{
    std::cout << __FUNCTION__ << std::endl;

    A a;
    B b(a);
    return 0;
}