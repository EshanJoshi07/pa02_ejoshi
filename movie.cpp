//movie.cpp
//NAME: Eshan Joshi

#include <iostream>
#include <string>
#include "movie.h"

using namespace std;

Movie::Movie() {
    name = "";
    rating = 0;
}

Movie::Movie (string n, double r) {
    name = n;
    //cout << "name set: " << name << endl;
    rating = r;
    //cout << "rating set: " << rating << endl;
}

string Movie::getName() {
    return name;
}

double Movie::getRating() {
    return rating;
}