//
// Created by minghu on 6/24/2019.
//

#include <iostream>
#include <list>
#include "learn_container.h"

using namespace std;

list<string> a = {"Milton", "Shakespeare", "Austen"};

void lListItor() {
    auto first = a.rbegin();
    while (first != a.rend()) {
        cout << *first << endl;
        first++;
    }
}

void lListReverseItor() {
    auto first = a.rbegin();
    while (first != a.rend()) {
        cout << *first << endl;
        first++;
    }
}

void lListConst() {
    // can not a[1] = "world"
    a = {"Hello", "world"};

    auto first = a.begin();
    while (first != a.end()) {
        cout << *first << endl;
        first++;
    }
}

void lListMaxSize() {
    cout << a.max_size() << endl;
}

void lVisitList() {
    auto val = *a.begin();
    cout << "first ele " << val << endl;
    auto last = a.end();
    last--;
    cout << "last ele " << *last << endl;
}



