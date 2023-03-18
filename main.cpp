// Winter '23
// Instructor: Diba Mirza
// Student name: Eshan Joshi 

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>

#include "movies.h"

using namespace std;


bool parseLine(string &line, string &movieName, double &movieRating);
void alphabetizeML(vector <Movies> ml);
void printML(vector <Movies> ml);
bool compareRating(Movies a, Movies b);
void moviesByPreAndRating (vector <Movies> ml, int argc, char** argv);

int main(int argc, char** argv) {
	if (argc < 2){
		cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
		cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
		exit(1);
	}

	ifstream movieFile (argv[1]);
	//cout << "moviefile is created" << endl;
 
	if (movieFile.fail()){
		cerr << "Could not open file " << argv[1];
		exit(1);
	}
  
	// Create an object of a STL data-structure to store all the movies
	vector <Movies> movielist;
	//cout << "movieList is created" << endl;
  
	string line, movieName;
	double movieRating;
	// Read each file and store the name and rating

	Movies temp;
	while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){

			//cout << "Movie name: " << movieName << ", " << "Movie Rating: " << movieRating << endl;
			temp.setName(movieName);
			temp.setRating(movieRating);
			movielist.push_back(temp);

			//cout << "data added " << endl;

			// Use std::string movieName and double movieRating
			// to construct your Movie objects
			// cout << movieName << " has rating " << movieRating << endl;
			// insert elements into your data structure
	}
	//cout << "movieList is filled in random order" << endl;

	movieFile.close();

	if (argc == 2){
			alphabetizeML(movielist);
			//print all the movies in ascending alphabetical order of movie names
			return 0;
			//cout << "movieList is alphabetized and printed" << endl;
	}

	if (argc > 2) {
		moviesByPreAndRating (movielist, argc, argv);
	}
	return 0;
}


/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
	if (line.length() <= 0) return false;
	string tempRating = "";

	bool flag = false;
	movieName = tempRating = "", movieRating = 0.0, flag = false;

	for (int i = 0; i < line.length(); i++){
		if(flag) tempRating += line[i];
		else if(line[i]==','&& line[0]!='"') flag = true;
		else {
			if(i==0 && line[0]=='"') continue;
			if(line[i]=='"'){ i++; flag=true; continue;}
			movieName += line[i];
		}
	}
	
	movieRating = stod(tempRating);
	return true;
}

void alphabetizeML(vector <Movies> ml) {
	//alphabetizes movielist
	Movies temp;
	for (int i = 0; i < ml.size(); i++) {
		for (int j = i + 1; j < ml.size(); j++) {
			if (ml.at(i).getName() > ml.at(j).getName()) {
				temp = ml.at(i);
				ml.at(i) = ml.at(j);
				//cout << ml.at(i).getName() << endl;
				ml.at(j) = temp;
				//cout << ml.at(j).getName() << endl;
			}
		} 
	}
	//cout << "movielist list is alphabetized" << endl;
	printML(ml);
	return;
}

void printML(vector <Movies> ml) {
	for (int i = 0; i < ml.size(); i++) {
		cout << ml.at(i).getName() << ", " << ml.at(i).getRating() << endl;
	}
	//cout << "movielist list is printed" << endl;
	return;
}

bool compareRating(Movies a, Movies b) {
	return (a.getRating() < b.getRating());
}

void moviesByPreAndRating (vector <Movies> ml, int argc, char** argv) {
	string pre;
	vector<Movies> bestMovies;
	vector<string> foundPre;
	vector <Movies> samePrefixMovie;

	// Run for each prefix argument given
	for(int i = 2; i < argc; i++) {
		int left = 0;
		int right = ml.size()-1;
		int middle = 0;
		bool areSame = true;
		pre = argv[i];

		// For each prefix, find all movies that have that prefix and store them in an appropriate data structure
		// Binary search for middle
		while(left <= right) { 
			middle = (left + (right))/2;
			for (int k = 0; k < pre.size(); k++) {
				if(ml.at(middle).getName().at(k) != pre.at(k)) {
					areSame = false;
					break;
				}
			}        
			if (areSame) {
				samePrefixMovie.push_back(ml.at(middle));
				break;
			}
			if (ml.at(middle).getName() < argv[i]) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
			areSame = true;
		}
		
		// If no movie with that prefix exists print the following message
		if (samePrefixMovie.size() == 0) {
			cout << "No movies found with prefix " << pre << endl;
			break;
		}

		// Add prefixes that have matches into a list
		foundPre.push_back(pre);

		// Linear search up from middle
		for (int k = middle - 1; k > 0; k--){
			for(int j = 0; j < pre.size(); j++) {
				if (ml.at(k).getName().at(j) != pre.at(j)) {
					areSame = false;
					break;
				}
			}
			if (areSame) {
				samePrefixMovie.push_back(ml.at(k));
			}
			areSame = true;
		}

		// Linear search down from middle
		for(int k = middle + 1; k < ml.size(); k++) {
			for(int j = 0; j < pre.size(); j++) {
				if(ml.at(k).getName().at(j) != pre.at(j)) {
					areSame = false;
					break;
				}
			}
			if (areSame) {
				samePrefixMovie.push_back(ml.at(k));
			}
			areSame = true;
		}
	
		
		// Sort based on rating after compiling all matching prefixes into a list
		sort(samePrefixMovie.begin(),samePrefixMovie.end(),compareRating);
			
		// Print movies that match with prefix
		for (int k=0;k<samePrefixMovie.size();k++){
			cout << samePrefixMovie.at(k).getName() << ", " <<  std::fixed << std::setprecision(1) << samePrefixMovie.at(k).getRating() << endl;
		}

		// Add highest rating movies into a list
		if(!samePrefixMovie.empty()){
			bestMovies.push_back(samePrefixMovie.at(0));
		}
		cout << endl;
	}
    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
    for(int i = 0; i < foundPre.size(); i++) {
      cout << "Best movie with prefix " << foundPre.at(i) << " is: " << bestMovies.at(i).getName() << " with rating " << std::fixed << std::setprecision(1) << bestMovies.at(i).getRating() << endl;
	}
}
