//movies.h
//NAME: Eshan Joshi

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <string>


using namespace std;

class Movies {
    private:
        string name;
        double rating;
    public:
        //default constuctor
        Movies();

        Movies(string n, double r);
        
        string getName();
        double getRating();
};

#endif