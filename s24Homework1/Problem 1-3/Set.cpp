//
//  Set.cpp
//  s24Homework1Problem3
//
//  Created by Cameron Maiden on 4/11/24.
//

#include "Set.h"
#include <string> // needed for the comparison operators for strings
#include <utility>
#include <algorithm>

using namespace std;

Set::Set()
 :m_size(0)
{
//    cerr << "Set constructor called!" << endl;
}

bool Set::empty() const
{
//    cerr << "Set::empty() function called!" << endl;
    if(m_size == 0)
        return true;
    else
        return false;
}

int Set::size() const
{
//    cerr << "Set::size() function called!" << endl;

    return m_size;
}

bool Set::insert(const ItemType& value)
{
//    cerr << "Set::insert() function called!" << endl;
    if (m_size == DEFAULT_MAX_ITEMS) // check if the array has reached its maximum capacity
    {
        cerr << "Array has reached full capacity!" << endl;
        return false;
    }
    
    else if (empty()) // Special case if the array is empty
    {
        m_array[m_size] = value;
        m_size++;
        return true;
    }
    
    else // Verify if there are any duplicates before inserting value into the array
    {
        if (contains(value) == true)
        {
//            cerr << "Duplicate found!" << endl;
            return false;
        }
        
        m_array[m_size] = value;
        m_size++;
        
        for (int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if (m_array[i] > m_array[j])
                    std::swap(m_array[i],m_array[j]);
            }
        }
        return true;
        
    }
    return false;
}

bool Set::erase(const ItemType& value)
{
    cerr << "Set::erase() function called!" << endl;
    
    for (int i = 0; i < m_size; i++)
    {
        if (value == m_array[i])
        {
            cerr << "Value found!" << endl;
            for (int k = i; k < m_size; k++) // Shifting the remaining elements in the set array to the left
            {
                m_array[k] = m_array[k + 1];
            }
            m_size--;
            return true;
        }
    }
    return false; // Would return false if the list is empty or value was not found
}

bool Set::contains(const ItemType& value) const
{
//    cerr << "Set::contains() function called!" << endl;
    
    for (int i = 0; i < m_size; i++)
    {
        if (value == m_array[i])
        {
//            cerr << value << " found in the Set!" << endl;
            return true;
        }
    }

    return false;
}

bool Set::get(int i, ItemType& value) const
{
//    cerr << "Set::get() function called!" << endl;
    
    if (i < 0  || i > m_size) // Checking for invalid expressions for parameter int i
        return false;
    value = m_array[i];
    return true;
}

void Set::swap(Set &other)
{
//    cerr << "Set::swap() function called!" << endl;
    std::swap(m_array, other.m_array);
    std::swap(m_size, other.m_size);
}

void Set::dump() const
{
    cerr << endl;
    // Print the array
    for (int i = 0; i < m_size; i++)
    {
        cerr << m_array[i] << endl;
    }
    
    cerr << endl;
}
