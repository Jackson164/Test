#include "Blockbuster.h"
#include "Movie.h"
#include <cctype>





// GIVEN - mostly given to you - you will need to modify this code to add the movie
// to the Blockbuster object instead of just printing the information to the screen
void read(string filename, Blockbuster & videoStore) {
	// Attempt to open specified file
	ifstream din(filename);

	// Check if file was opened successfully
	if (din.fail()) {
		cout << "Error opening file " << filename << endl;
		exit(1);
	}

	// Declare variables to read into
	int rottenTomatoesScore;
	float imdbRating;
	string genre;
	int year;
	// profits will be a positive number, so this is an unsigned long integer now
	// this fixes the overflow issue on some computers when just long is used
	unsigned long worldwideBoxOffice;
	string title;

	// Read in header line from file, throw away
	getline(din, title);

	// Read in all movies from file
	while (!din.eof()) {
		din >> rottenTomatoesScore >> imdbRating >> genre >> year >> worldwideBoxOffice;
		getline(din, title);

		// Remove first character of title (space)
		// Can use substr or erase
		// title = title.substr(1);
		title.erase(0, 1);

		// this is provided for error checking to make sure you are reading in the file of movies - 
		// after you know you are, you will comment this line out and just add the movie to the 
		// Blockbuster object array using a method found in the Blockbuster class
		cout << year << " " << title << " " << rottenTomatoesScore << " " << imdbRating << " " << genre << " " << worldwideBoxOffice << endl;

		// Add movie to Blockbuster object array - you will be adding code here!!
		// you do NOT need to add code above this line
        videoStore.addMovie(rottenTomatoesScore, imdbRating, genre, year, worldwideBoxOffice, title);
	}

	// Close input file
	din.close();
}

// GIVEN - Function to print menu to console
void printMenu() {
	cout << "1. Filter by genre" << endl;
	cout << "2. Filter by range of IMDB rating and Rotten Tomatoes score" << endl;
	cout << "3. Get the highest grossing movie" << endl;
	cout << "4. Print all movies" << endl;
	cout << "5. Exit" << endl;
}

// GIVEN - get the user's choice from the menu
int getUserChoice() {
	// Declare variable to store user choice, prompt for input, and store input
	int choice;
	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;

	// Check if input is valid
	if (choice < 1 || choice > 5) {
		cout << "Invalid choice. Try again." << endl;
		return getUserChoice();
	}

	// Return user choice
	return choice;
}

int main() 
{
    int choice;
    string genre;
    float IMDBMAX;
    float IMDBMIN;
    int RTSCOREMAX;
    int RTSCOREMIN;
    Movie maxGrossing;
    
	// Create Blockbuster object using default constructor, call read function
    Blockbuster videoStore;
    
    read("blockbuster.txt", videoStore);
    cout << endl;
    
    
    
	// Print menu and get user choice
	while(choice != 5)
	{
    	cout << "Choose one of the following options: " << endl;
        printMenu();
        cin >> choice;
        
    	// while user's choice is not to quit	    
    	switch(choice)
        {
            case 1:
            cout << "What genre are you looking for? >> ";
            cin >> genre;
            genre[0] = toupper(genre[0]);
            //capitalizes first letter for error checking
            
            videoStore.filterByGenre(genre);
            break;
            
            case 2:
            do
            {
                cout << endl << "Enter the Min IMDB rating >>";
                cin >> IMDBMIN;
                
                cout << "Enter the Max IMDB rating >>";
                cin >> IMDBMAX;
                
                if((IMDBMIN >= IMDBMAX)||(IMDBMIN<0)||(IMDBMIN>10)||(IMDBMAX<0)||(IMDBMAX>10))
                {
                    cout << "Invalid range. Try again." << endl;
                }
            }
            while((IMDBMIN >= IMDBMAX)||(IMDBMIN<0)||(IMDBMIN>10)||(IMDBMAX<0)||(IMDBMAX>10));
            
            do
            {
                cout << endl << "Enter the Min Rotten Tomatoes score >>";
                cin >> RTSCOREMIN;
                
                cout << "Enter the Max Rotten Tomatoes score >>";
                cin >> RTSCOREMAX;
                if((RTSCOREMIN >= RTSCOREMAX)||(RTSCOREMIN<0)||(RTSCOREMIN>100)||(RTSCOREMAX<0)||(RTSCOREMAX>100))
                {
                    cout << "Invalid range. Try again." << endl;
                }
            }
            while((RTSCOREMIN >= RTSCOREMAX)||(RTSCOREMIN<0)||(RTSCOREMIN>100)||(RTSCOREMAX<0)||(RTSCOREMAX>100));
            
            videoStore.imdbTomatoRange(IMDBMIN, IMDBMAX, RTSCOREMIN, RTSCOREMAX);
            break;
            
            case 3:
            cout << "Displaying results for Highest Grossing movie:" << endl << endl;
            
            maxGrossing = videoStore.highestGrossing();
            maxGrossing.print();
            
            break;
            
            case 4:
            cout << "Displaying all movies:" << endl;
            videoStore.print();
            break;
            
            case 5:
            cout << "Exiting Blockbuster" << endl;
            break;
        }
	}
	// switch statement between the options






	
	// goodbye message
    cout << "Goodbye!" << endl;

	return 0;
}