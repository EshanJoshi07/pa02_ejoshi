//movie.cpp
//NAME: Eshan Joshi

#include <iostream>
#include <string>
#include <movie.h>

using namespace std;

Movie::Movie (string n, double r) {
    name = n;
    rating = r;
}

Movie::~Movie() {
    delete this;
}

string Movie::getName() {
    return name;
}

double Movie::getRating() {
    return rating;
}