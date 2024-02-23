#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;


class Movie
{
    public:
        //constructors
        Movie();
        Movie(const string title, const int year, const float imdb, const string genre, const unsigned long wboprofits, const int rtscore);
        Movie(const Movie &movie);
        
        //destructor
        ~Movie();
        
        //getters
        string getTitle() const;
        int getYear() const;
        float getIMDB() const;
        string getGenre() const;
        unsigned long getWBOProfits() const;
        int getRTScore() const;
        
        //setters
        void setTitle(const string title);
        void setYear(const int year);
        void setIMDB(const float IMDB);
        void setGenre(const string genre);
        void setWBOProfits(const unsigned long wboprofits);
        void setRTScore(const int rtscore);
        
        //print method
        void print() const;
    
    private:
        string Title;
        int Year;
        float IMDB;
        string Genre;
        unsigned long WBOProfits;
        int RTScore;
};

#endif