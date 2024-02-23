#ifndef BLOCKBUSTER_H
#define BLOCKBUSTER_H

#include "Movie.h"

// Declare constant for size of array - based off of blockbuster.txt file
const int MAX_MOVIES = 398;

class Blockbuster {
	public:
		// Default/no argument constructor, copy constructor, destructor
		Blockbuster();
		Blockbuster(const Blockbuster & blockbuster);
		~Blockbuster();
		
		// Adding data to array methods
		void addMovie(const int rottenTomatoesScore, const float imdbRating, const string genre, const int year, const long worldwideBoxOffice, const string title);
		void addMovie(const Movie movie);

		// User filter methods
		void filterByGenre(const string genre) const;
		void imdbTomatoRange(const float imdbMin, const float imdbMax, const int tomatoMin, const int tomatoMax) const;
		Movie highestGrossing() const;

		// Print method
		void print() const;

	private:
		Movie movies[MAX_MOVIES];
		int currentIndex;
};

#endif