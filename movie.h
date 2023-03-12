//movie.h
//NAME: Eshan Joshi

#include <iostream>
#include <string>

#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie {
    private:
        string name;
        double rating;
    public:
        //default constuctor
        Movie();

        Movie(string n, double r);
        
        //destructor
        ~Movie();
        string getName();
        double getRating();
};

#endif