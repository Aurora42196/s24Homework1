//
//  Set.h
//  s24Homework1Problem3
//
//  Created by Cameron Maiden on 4/11/24.
//

#ifndef Set_h
#define Set_h

#include <iostream>

using ItemType = std::string;

const int  DEFAULT_MAX_ITEMS = 180;

class Set
{
    public:
    
        Set(); // Default Constructor: Create an empty set (i.e., one whose size() is 0).
        Set(const int); // Constructor with parameter
        Set(const Set& other); // Copy Constructor
        Set& operator=(const Set& rhs); // assignment operator
        ~Set(); // Destructor
        
        bool empty() const;  // Return true if the set is empty, otherwise false.
        
        int size() const;    // Return the number of items in the set.
        
        bool insert(const ItemType& value);
        // Insert value into the set if it is not already present.  Return
        // true if the value is actually inserted.  Leave the set unchanged
        // and return false if value was not inserted (perhaps because it
        // was already in the set or because the set has a fixed capacity and
        // is full).
        
        bool erase(const ItemType& value);
        // Remove the value from the set if present.  Return true if the
        // value was removed; otherwise, leave the set unchanged and
        // return false.
        
        bool contains(const ItemType& value) const;
        // Return true if the value is in the set, otherwise false.
        
        bool get(int i, ItemType& value) const;
        // If 0 <= i < size(), copy into value the item in the set that is
        // strictly less than exactly i items in the set and return true.
        // Otherwise, leave value unchanged and return false.
        
        void swap(Set& other);
        // Exchange the contents of this set with the other one.
    
        void dump() const; // Used to print information about the Set
    private:
        /// Class Invariants:
        ///     m_size cannot be greater than DEFAULT_MAX_ITEMS and cannot be less than 0;
        ///     DEFAULT_MAX_ITEMS > 0
        
        int m_size; // holds the number of how many items are in the array
        int m_capacity;
        ItemType* m_array; // a pointer to a dynamically allocated array that can hold any type the based on the alias ItemType
};
#endif /* Set_h */
