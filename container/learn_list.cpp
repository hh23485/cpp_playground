//
// Created by minghu on 6/24/2019.
//

#include <iostream>
#include <list>
#include <vector>
#include "learn_container.h"

using namespace std;

list<string> lInt = {"Milton", "Shakespeare", "Austen"};
vector<int> vInt = {1,3,5,87,6,4,23,456};
vector<int> veInt;


void lListItor() {
    auto first = lInt.rbegin();
    while (first != lInt.rend()) {
        cout << *first << endl;
        first++;
    }
}

void lListReverseItor() {
    auto first = lInt.rbegin();
    while (first != lInt.rend()) {
        cout << *first << endl;
        first++;
    }
}

void lListConst() {
    // can not a[1] = "world"
    lInt = {"Hello", "world"};

    auto first = lInt.begin();
    while (first != lInt.end()) {
        cout << *first << endl;
        first++;
    }
}

void lListMaxSize() {
    cout << lInt.max_size() << endl;
}

void lVisitListItor() {
    auto val = *lInt.begin();
    cout << "first ele " << val << endl;
    auto last = lInt.end();
    last--;
    cout << "last ele " << *last << endl;
}

void lVisitListRef() {
    if (!lInt.empty()) {
        lInt.front() = "42";
        auto &v = lInt.back();
        v = "1024";
        auto v2 = lInt.back();
        v2 = "0";

        auto b = lInt.begin();
        while (b != lInt.end()) {
            cout << *b++ << endl;
        }
    }
}

void lVisitRand() {
    vector<string> v = {"hello", "world"};
    cout << v[0] << endl;
}

void lAddEle() {
    vector<int> vInt = {1, 9, 5, 6, 8, 7};
    vInt.push_back(6);
    vInt.front() = 3;
    cout << vInt[vInt.size() - 1] << endl;
    cout << "first ele " << vInt.front() << endl;
}

void lErase() {
    vInt.erase(vInt.begin());
    cout << "vInt size:" << vInt.size() << endl;
    vInt.clear();
    cout << "vInt size:" << vInt.size() << endl;
}




