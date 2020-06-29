//
// Created by logra on 6/27/2020.
// const variable cannot be modified. It applies to const reference variable too.
//
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main(void)
{
    int a =10;
    double val=3.14;
    const int ci = a; //ci cannot be modified. ci++ is error.
    const int &rci = a; //rci cannot be modified. rci++ is error.
    int k = ci; //const ci CAN be assigned to a non-const k
    //int &rk = ci; //const ci CANNOT be assigned to a non-const reference k. Compilation error.
    const int &rck = ci; // OK. const ref is assigned to a const int.
    //rck++; ci++;rci++; //ERROR. Cannot modify const variables.
    a++;
    const int dc = val; //OK. 3.14 will be rounded to an int. i.e 3 and assigned to dc.
    int dd=val; //OK. 3.14 will be rounded to an int. i.e 3 and assigned to dd.
    const int &rdc = val; /*OK. compiler generates a temp variable and assigns to rdc. compiler does as
    1. const int temp = val; 2. const int &rdc = temp; So here rdc gets 3 as value(similar to declaration
    const int &rdc = 3). Because it is const reference it cannot change the value in `val` variable.*/

    //int &rdd = val;
    /*ERROR. Similar to above, compiler assigns the rdd to temp variable. So the changes done
    to the rdd will be reflected in temp but not `val` variable(similar to declaration int &rdd=3).
    So it does not make sense to have a reference variable pointing to unrelated data type(i.e int
    reference assigned to double). So compiler gives error.
    But because rdc was const reference above and it would anyway be not allowed to change the value, compiler
    does not throw error. */

    //int &rff= a*100; //ERROR: Here too expression is evaluated to a constant and copied into a temp
    // variable. The reference variable cannot be assigned to a const. So compiler error.

    typedef char *ptr;
    const ptr str = "hello";
    //str++;
    const char *p = "hello";
    p++;
    //int *p = &null;
    cout<<a<<","<<str<<","<<p<<endl;
    return 0;
}
