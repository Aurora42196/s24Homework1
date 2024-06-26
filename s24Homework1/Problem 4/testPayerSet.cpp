//
//  testPayerSet.cpp
//  s24Homework1
//
//  Created by Cameron Maiden on 4/15/24.
//

#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Set s;
    assert(s.empty());
    ItemType x = 9876543;
    assert( !s.get(42, x)  &&  x == 9876543); // x unchanged by get failure
    s.insert(123456789);
    assert(s.size() == 1);
    assert(s.get(0, x)  &&  x == 123456789);
    cout << "Passed all tests" << endl;
}
