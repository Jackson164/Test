#include "Movie.h"


using namespace std;



//default constructor
Movie::Movie()
{
    Title = "";
    Year = 0;
    IMDB = 0.0;
    Genre = "";
    WBOProfits = 0;
    RTScore = 0;
}

//parameterized constructor
Movie::Movie(const string title, const int year, const float imdb, const string genre, const unsigned long wboprofits, const int rtscore)
{
    Title = title;
    Year = year;
    IMDB = imdb;
    Genre = genre;
    WBOProfits = wboprofits;
    RTScore = rtscore;
}

//copy constructor
Movie::Movie(const Movie &movie)
{
    Title = movie.Title;
    Year = movie.Year;
    IMDB = movie.IMDB;
    Genre = movie.Genre;
    WBOProfits = movie.WBOProfits;
    RTScore = movie.RTScore;
}

//destructor
Movie::~Movie()
{
    
}




//getters

string Movie::getTitle() const
{
    return Title;
}


int Movie::getYear() const
{
    return Year;
}

float Movie::getIMDB() const
{
    return IMDB;
}

string Movie::getGenre() const
{
    return Genre;
}

unsigned long Movie::getWBOProfits() const
{
    return WBOProfits;
}

int Movie::getRTScore() const
{
    return RTScore;
}





//setters

void Movie::setTitle(const string title)
{
    Title = title;
}



void Movie::setYear(const int year)
{
    Year = year;
}



void Movie::setIMDB(const float imdb)
{
    IMDB = imdb;
}



void Movie::setGenre(const string genre)
{
    Genre = genre;
}



void Movie::setWBOProfits(const unsigned long wboprofits)
{
    WBOProfits = wboprofits;
}



void Movie::setRTScore(const int rtscore)
{
    RTScore = rtscore;
}



void Movie::print() const
{
    cout << "Rotten Tomatoes Score: " << RTScore << endl;
    cout << "IMDB Rating: " << IMDB << endl;
    cout << "Genre: " << Genre << endl;
    cout << "Year: " << Year << endl;
    cout << "Worldwide Box Office: " << WBOProfits << endl;
    cout << "Title: " << Title << endl << endl;
}








