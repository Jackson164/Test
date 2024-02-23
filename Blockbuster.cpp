#include "Blockbuster.h"

using namespace std;



//default constructor
Blockbuster::Blockbuster()
{
    currentIndex = 0;
}

//copy constructor
Blockbuster::Blockbuster(const Blockbuster & blockbuster)
{
    currentIndex = blockbuster.currentIndex;
    
    for(int i = 0; i < MAX_MOVIES; i++)
    {
        movies[i] = blockbuster.movies[i];
    }
}

//destructor
Blockbuster::~Blockbuster()
{
    
}

//add movie given 6 six attributes
void Blockbuster::addMovie(const int rottenTomatoesScore, const float imdbRating, const string genre, const int year, const long worldwideBoxOffice, const string title)
{
    if(currentIndex < MAX_MOVIES)
    {
        Movie newlyAddedMovie(title, year, imdbRating, genre, worldwideBoxOffice, rottenTomatoesScore);
        movies[currentIndex++] = newlyAddedMovie;
    }
    
    else
    {
        cout << "Maximum size reached, can no longer add movies to the array." << endl;
    }
}

//add movie given movie object
void Blockbuster::addMovie(const Movie movie)
{
    if(currentIndex < MAX_MOVIES)
    {
        movies[currentIndex++] = movie;
    }
    
    else
    {
        cout << "Maximum size reached, can no longer add movies to the array." << endl;
    }
}

//filter by genre
void Blockbuster::filterByGenre(const string genre) const
{
    bool genreExists = false;
    int count = 0;
    for(int i = 0; i < MAX_MOVIES; i++)
    {
        if(movies[i].getGenre() == genre)
        {
            movies[i].print();
            genreExists = true;
            count++;
        }
    }
    
    if(genreExists == false)
    {
        cout << endl << "No movies of the Genre \"" << genre << "\" have been found" << endl << endl;
    }
    else
    {
        cout << count << " results for " << genre << endl << endl;
    }
}

void Blockbuster::imdbTomatoRange(const float imdbMin, const float imdbMax, const int tomatoMin, const int tomatoMax) const
{
    
    bool beenFound = false;
    int count = 0;
    for(int i = 0; i < MAX_MOVIES; i++)
    {
        if((movies[i].getIMDB() >= imdbMin) && (movies[i].getIMDB() <= imdbMax) && (movies[i].getRTScore() >= tomatoMin) && (movies[i].getRTScore() <= tomatoMax))
        {
            movies[i].print();
            bool beenFound = true;
            count++;
        }
    }
    
    if(beenFound = false)
    {
        cout << "No movies of the Rotten Toomatoes Score and IMDB rating criteria have been found" << endl;
    }
    
    else
    {
        cout << endl << count << " results for IMDB " << imdbMin << "-" << imdbMax << " and Rotten Tomatoes " << tomatoMin << "-" << tomatoMax << endl << endl;
    }
}

Movie Blockbuster::highestGrossing() const
{
    if(currentIndex == 0)
    {
        cout << "No movies on hand, can't find highest grossing movie." << endl;
    }
    
    Movie maxGrossing = movies[0];
    
    for(int i = 0; i < MAX_MOVIES; i++)
    {   
        if(movies[i].getWBOProfits() > maxGrossing.getWBOProfits())
        {
            maxGrossing = movies[i];
        }
        
    }
    return maxGrossing;
}

void Blockbuster::print() const
{
    int count = 0;
    if(currentIndex == 0)
    {
        cout << "No movies to display" << endl;
    }
    
    for(int i = 0; i < currentIndex; i++)
    {
        movies[i].print();
        count++;
    }
    cout << count << " results" << endl << endl;
}









