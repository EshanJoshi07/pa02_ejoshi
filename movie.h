//movie.h
//NAME: Eshan Joshi

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>


using namespace std;

class Movie {
    private:
        string name;
        double rating;
    public:
        //default constuctor
        Movie();

        Movie(string n, double r);
        
        string getName();
        double getRating();
};

#endif