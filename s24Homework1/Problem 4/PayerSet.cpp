//
//  PayerSet.cpp
//  s24Homework1Problem4
//
//  Created by Cameron Maiden on 4/16/24.
//

#include <iostream>
#include "PayerSet.h"

using namespace std;

PayerSet::PayerSet()
{
    
}

bool PayerSet::add(unsigned long accountNum)
{
    if (m_set.contains(accountNum))
        return false;
    else if(m_set.insert(accountNum))
    {
        cerr << "Account number add to set" << endl;
        return true;
    }
    return false; // default return value
}

int PayerSet::size() const
{
    return m_set.size();
}

void PayerSet::print() const
{
    unsigned long u;
    for (int i = 0; i < m_set.size(); i++)
    {
        cout << m_set.get(i, u) << endl;
    }
}


