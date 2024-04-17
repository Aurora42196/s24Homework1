//
//  testSet.cpp
//  s24Homework1Problem3
//
//  Created by Cameron Maiden on 4/11/24.
//

//#include "Set.h"
//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;
//
//int main()
//{
//
///////////////////////////////////////////////////////////
/// Test cases for a Set of strings
/// /////////////////////////////////////////////////////

//    Set ss;
//    ss.insert("lavash");
//    ss.insert("roti");
//    ss.insert("chapati");
//    ss.insert("injera");
//    ss.insert("roti");
//    ss.insert("matzo");
//    ss.insert("injera");
//    ss.insert("RoTi");
////    assert(ss.size() == 6);  // duplicate "roti" and "injera" were not addedlicate "roti" and "injera" were not added
//    ss.dump();
//    ss.erase("roti");
//    ss.dump();

//    Set s2;
//    s2.insert("hello");
//    s2.insert("goodbye");
//    assert(s2.size() == 2);
//    s2.dump();
//    s2.erase("goodbye");
//    assert(!s2.contains("goodbye"));
//    s2.dump();
//
//    Set ss1;
//    ss1.insert("tortilla");
//    Set ss2;
//    ss2.insert("matzo");
//    ss2.insert("pita");
//    ss1.swap(ss2);
//    assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
//           ss2.size() == 1  &&  ss2.contains("tortilla"));
//
//    Set s;
//    assert(s.empty());
//    ItemType x = "arepa";
//    assert( !s.get(42, x)  &&  x == "arepa"); // x unchanged by get failure
//    s.insert("chapati");
//    assert(s.size() == 1);
//    assert(s.get(0, x)  &&  x == "chapati");
//    cout << "Passed all tests" << endl;

//    Set ss;
//    ss.insert("lavash");
//    ss.insert("roti");
//    ss.insert("chapati");
//    ss.insert("injera");
//    ss.insert("roti");
//    ss.insert("matzo");
//    ss.insert("injera");
//    ss.dump();
//    assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
//    string x;
//    ss.get(0, x);
//    assert(x == "roti");  // "roti" is less than exactly 0 items in ss
//    ss.get(4, x);
//    assert(x == "chapati");  // "chapati" is less than exactly 4 items in ss
//    ss.get(2, x);
//    assert(x == "lavash");  // "lavash" is less than exactly 2 items in ss
//
//    Set ss3;
//    ss3.insert("dosa");
//    assert(!ss.contains(""));
//    ss3.insert("laobing");
//    ss3.insert("");
//    ss3.insert("focaccia");
//    ss3.dump();
//    assert(ss3.contains(""));
//    ss3.erase("dosa");
//    assert(ss3.size() == 3  &&  ss3.contains("focaccia")  &&  ss3.contains("laobing")  &&
//           ss3.contains(""));
//    string v;
//    assert(ss3.get(0, v)  &&  v == "laobing");
//    assert(ss3.get(1, v)  &&  v == "focaccia");
//    assert(ss3.get(2, v)  &&  v == "");
//    ss3.dump();
//    cout << "Passed all tests" << endl;



//    Set s;
//    assert(s.empty());
//    ItemType x = 9876543;
//    assert( !s.get(42, x)  &&  x == 9876543); // x unchanged by get failure
//    s.insert(123456789);
//    assert(s.size() == 1);
//    assert(s.get(0, x)  &&  x == 123456789);
//    cout << "Passed all tests" << endl;
//}

#include "newSet.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

#define TEST_WITH_STRING

#ifdef TEST_WITH_STRING

    const ItemType DUMMY_VALUE = "hello";
    const ItemType V1 = "abc";

    #else // assume unsigned long

    const ItemType DUMMY_VALUE = 9876543;
    const ItemType V1 = 123456789;

    #endif

    void test()
    {
        Set s;
        assert(s.empty());
        ItemType v = DUMMY_VALUE;
        assert( !s.get(0, v)  &&  v == DUMMY_VALUE); // v unchanged by get failure
        s.insert(V1);
        assert(s.size() == 1);
        assert(s.get(0, v)  &&  v == V1);
        
        /////////////////////////////////////////////////////////
        // Test cases for a Set of strings
        /////////////////////////////////////////////////////
            
//        Set ss;
//        ss.insert("lavash");
//        ss.insert("roti");
//        ss.insert("chapati");
//        ss.insert("injera");
//        ss.insert("roti");
//        ss.insert("matzo");
//        ss.insert("injera");
//        ss.insert("RoTi");
//        // assert(ss.size() == 6);  // duplicate "roti" and "injera" were not added
//        ss.dump();
//        ss.erase("roti");
//        ss.dump();
        
        Set s2;
        s2.insert("hello");
        s2.insert("goodbye");
        assert(s2.size() == 2);
        s2.dump();
        s2.erase("goodbye");
        assert(!s2.contains("goodbye"));
        s2.dump();
        
        Set ss1;
        ss1.insert("tortilla");
        Set ss2;
        ss2.insert("matzo");
        ss2.insert("pita");
        ss1.swap(ss2);
        assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
               ss2.size() == 1  &&  ss2.contains("tortilla"));
        
//        Set s;
//        assert(s.empty());
//        ItemType x = "arepa";
//        assert( !s.get(42, x)  &&  x == "arepa"); // x unchanged by get failure
//        s.insert("chapati");
//        assert(s.size() == 1);
//        assert(s.get(0, x)  &&  x == "chapati");
//        cout << "Passed all tests" << endl;
        
        Set ss;
        ss.insert("lavash");
        ss.insert("roti");
        ss.insert("chapati");
        ss.insert("injera");
        ss.insert("roti");
        ss.insert("matzo");
        ss.insert("injera");
        ss.dump();
        assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
        string x;
        ss.get(0, x);
        assert(x == "roti");  // "roti" is less than exactly 0 items in ss
        ss.get(4, x);
        assert(x == "chapati");  // "chapati" is less than exactly 4 items in ss
        ss.get(2, x);
        assert(x == "lavash");  // "lavash" is less than exactly 2 items in ss
        
//        Set ss3;
//        ss3.insert("dosa");
//        assert(!ss.contains(""));
//        ss3.insert("laobing");
//        ss3.insert("");
//        ss3.insert("focaccia");
//        ss3.dump();
//        assert(ss3.contains(""));
//        ss3.erase("dosa");
//        assert(ss3.size() == 3  &&  ss3.contains("focaccia")  && ss3.contains("laobing")  && ss3.contains(""));
//        string v;
//        assert(ss3.get(0, v)  &&  v == "laobing");
//        assert(ss3.get(1, v)  &&  v == "focaccia");
//        assert(ss3.get(2, v)  &&  v == "");
//        ss3.dump();
//        cout << "Passed all tests" << endl;
        
        
        
//        Set s;
//        assert(s.empty());
//        ItemType x = 9876543;
//        assert( !s.get(42, x)  &&  x == 9876543); // x unchanged by get failure
//        s.insert(123456789);
//        assert(s.size() == 1);
//        assert(s.get(0, x)  &&  x == 123456789);
//        cout << "Passed all tests" << endl;
//    }

    }

    int main()
    {
        test();
        cout << "Passed all tests" << endl;
    }

//void test()
//{
//    Set a(1000);   // a can hold at most 1000 distinct items
//    Set b(5);      // b can hold at most 5 distinct items
//    Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
//    ItemType v[6] = {"roti","lavash","injera","tortilla","engineer","student"};
//    
////    b.dump();
//    // No failures inserting 5 distinct items into b
//    for (int k = 0; k < 5; k++)
//        assert(b.insert(v[k]));
//    
////    b.dump();
//    // Failure if we try to insert a sixth distinct item into b
//    assert(!b.insert(v[5]));
//    
//    // When two Sets' contents are swapped, their capacities are swapped
//    // as well:
//    a.swap(b);
//    
//    assert(!a.insert(v[5])  &&  b.insert(v[5]));
//    cerr << "a: " << endl;
//    a.dump();
//    
//    cerr << endl << "b: " << endl;
//    b.dump();
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}



////////////////////////////////////////////////////////////////////////////////
/////  Test cases for a Set of unsigned longs
////////////////////////////////////////////////////////////////////////////////

//#include "Set.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test(const Set& uls)
//{
//    assert(uls.size() == 2);
//    assert(uls.contains(20));
//    ItemType x = 30;
//    assert(uls.get(0, x)  &&  x == 20);
//    assert(uls.get(1, x)  &&  x == 10);
//}
//
//int main()
//{
//    Set s;
//    assert(s.insert(10));
//    assert(s.insert(20));
//    test(s);
//    cout << "Passed all tests" << endl;
//}


