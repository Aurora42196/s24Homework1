//
//  Set.cpp
//  s24Homework1Problem3
//
//  Created by Cameron Maiden on 4/11/24.
//

#include "newSet.h"
#include <string> // needed for the comparison operators for strings
#include <utility>
#include <algorithm>

using namespace std;

Set::Set()
 :m_size(0),m_capacity(DEFAULT_MAX_ITEMS)
{
//    cerr << "Set constructor called!" << endl;
    m_array = new ItemType[m_capacity];
}

Set::Set(const int arrSize) // Constructor for dynamic memory allocation
 :m_size(0)
{
    if(arrSize < 0)
    {
        cout << "invalid parameter for size" << endl;
        exit(1);
    }
    m_capacity = arrSize;
    m_array = new ItemType[m_capacity];
}

Set::Set(const Set& other) // Copy constructor
{
    m_size = other.m_size;
    m_array = new ItemType[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = other.m_array[i];
    }
}

Set& Set::operator=(const Set &rhs) // assignment operator
{
    if(this != &rhs)
    {
        Set temp(rhs);
        swap(temp);
    }
    return *this;
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
    if (m_size == DEFAULT_MAX_ITEMS || m_size == m_capacity) // check if the array has reached its maximum capacity (for both the default constructor or an array of a passed in fixed size)
    {
//        cerr << "Array has reached full capacity!" << endl;
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
//    cerr << "Set::erase() function called!" << endl;
    
    for (int i = 0; i < m_size; i++)
    {
        if (value == m_array[i])
        {
//            cerr << "Value found!" << endl;
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
    
    if (i < 0  || i >= m_size) // Checking for invalid expressions for parameter int i
        return false;
    value = m_array[i];
    return true;
}

void Set::swap(Set &other)
{
//    cerr << "Set::swap() function called!" << endl;
//    std::swap(m_array, other.m_array);
//    std::swap(m_size, other.m_size);
    
    if (m_size == other.m_size) // The dynamically allocated arrays are the same size
    {
        for (int i = 0; i < m_size; i++)
        {
            ItemType temp = m_array[i];
            m_array[i] = other.m_array[i];
            other.m_array[i] = temp;
        }
    }
    else if (m_size < other.m_size) // We want to copy the smaller array of the two into the temp variable
    {
        for (int i = 0; i < m_size; i++)
        {
            ItemType temp = m_array[i];
            m_array[i] = other.m_array[i];
            other.m_array[i] = temp;
        }
        
        for (int i = m_size; i < other.m_size; i++)
        {
            m_array[i] = other.m_array[i];
        }
    }
    else if(m_size > other.m_size) // If the other array is smaller, we want to store that one into temp
    {
        for (int i = 0; i < other.m_size; i++)
        {
            ItemType temp = other.m_array[i];
            other.m_array[i] = m_array[i];
            m_array[i] = temp;
        }
        
        for(int i = other.m_size; i < m_size; i++)
        {
            other.m_array[i] = m_array[i];
        }
    }
    
    //Swap the capacities of the arrays
    int tempC = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = tempC;
    
    //Swap the sizes of the arrays
    int tempS = m_size;
    m_size = other.m_size;
    other.m_size = tempS;
}

void Set::dump() const
{
//    cerr << endl;
    // Print the array
    for (int i = 0; i < m_size; i++)
    {
        cerr << m_array[i] << endl;
    }
    
    cerr << endl;
}

Set::~Set()
{
    delete [] m_array;
}
