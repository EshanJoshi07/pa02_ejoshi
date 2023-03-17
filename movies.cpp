//movies.cpp
//NAME: Eshan Joshi

#include <iostream>
#include <string>
#include "movies.h"

using namespace std;

Movies::Movies() {
    name = "";
    rating = 0;
}

Movies::Movies (string n, double r) {
    name = n;
    //cout << "name set: " << name << endl;
    rating = r;
    //cout << "rating set: " << rating << endl;
}

string Movies::getName() {
    return name;
}

double Movies::getRating() {
    return rating;
}