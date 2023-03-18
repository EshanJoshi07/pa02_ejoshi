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
vector <Movies> alphabetizeML(vector <Movies> ml);
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
			movielist = alphabetizeML(movielist);
			printML(movielist);
			//print all the movies in ascending alphabetical order of movie names
			return 0;
			//cout << "movieList is alphabetized and printed" << endl;
	}

	if(argc > 2){
		movielist = alphabetizeML(movielist);
		string prefix;
		vector<Movies> bestMovies;
		vector<string> foundPrefixes;

		for(int i = 2; i < argc; i++) {
			vector<Movies> samePrefixMovie;
			int left = 0;
			int right = movielist.size()-1;
			int middle = 0;
			bool areSame = true;
			prefix=argv[i];

			while (left <= right) { 
				middle = (left + (right))/2;
				for (int k = 0; k < prefix.size(); k++) {
					if (movielist.at(middle).getName().at(k) != prefix.at(k)) {
						areSame = false;
						break;
					}
				}        
				if (areSame) {
					samePrefixMovie.push_back(movielist.at(middle));
					break;
				}
				if (movielist.at(middle).getName() < argv[i]) {
					left = middle+1;
				}
				else {
					right = middle - 1;
				}
				areSame = true;
			}

			if (samePrefixMovie.size() == 0) {
				cout << "No movies found with prefix " << prefix << endl;
				i++;
			}

			foundPrefixes.push_back(prefix);

			for (int k = middle - 1; k > 0; k--) {
				for (int j = 0; j < prefix.size(); j++) {
					if (movielist.at(k).getName().at(j) != prefix.at(j)) {
						areSame = false;
						break;
					}
				}
				if (areSame) {
					samePrefixMovie.push_back(movielist.at(k));
				}
				areSame = true;
			}

			for (int k = middle + 1; k < movielist.size(); k++) {
				for (int j = 0; j < prefix.size(); j++) {
					if (movielist.at(k).getName().at(j) != prefix.at(j)) {
						areSame = false;
						break;
					}
				}
				if (areSame) {
					samePrefixMovie.push_back(movielist.at(k));
				}
				areSame = true;
			}
			
			// Sort based on rating after compiling all matching prefixes into a list
			sort(samePrefixMovie.begin(), samePrefixMovie.end(), compareRating);
			
			// Print movies that match with prefix
			for (int k = 0; k < samePrefixMovie.size(); k++) {
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
		//if (foundPrefixes.size() > 0) {
			for (int i = 0; i < foundPrefixes.size(); i++) {
				if (bestMovies.at(i).getName().capacity() != 0) {
				// 	break;
				// }
				// else {
					cout << "Best movie with prefix "<<foundPrefixes.at(i)<<" is: " << bestMovies.at(i).getName() <<" with rating " << std::fixed << std::setprecision(1) <<bestMovies.at(i).getRating()<< endl;
				}
				// cout << "augh " << foundPrefixes.at(i) << endl;
				// cout << "augh " << bestMovies.at(i).getName() << endl;
				// cout << "Best movie with prefix "<<foundPrefixes.at(i)<<" is: " << bestMovies.at(i).getName() <<" with rating " << std::fixed << std::setprecision(1) <<bestMovies.at(i).getRating()<< endl;

			}
		//}

		return 0;
  	}
}


/* Add your run time analysis for part 3 of the assignment here as commented block*/
//didn't get time to finish runtime analysis :(

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

vector <Movies> alphabetizeML(vector <Movies> ml) {
	//alphabetizes movielist
	vector <Movies> alpha = ml;

	Movies temp;
	for (int i = 0; i < alpha.size(); i++) {
		for (int j = i + 1; j < alpha.size(); j++) {
			if (alpha.at(i).getName() > alpha.at(j).getName()) {
				temp = alpha.at(i);
				alpha.at(i) = alpha.at(j);
				//cout << ml.at(i).getName() << endl;
				alpha.at(j) = temp;
				//cout << ml.at(j).getName() << endl;
			}
		} 
	}
	//cout << "movielist list is alphabetized" << endl;
	//printML(ml);
	return alpha;
}

void printML(vector <Movies> ml) {
	for (int i = 0; i < ml.size(); i++) {
		cout << ml.at(i).getName() << ", " << ml.at(i).getRating() << endl;
	}
	//cout << "movielist list is printed" << endl;
	return;
}

bool compareRating(Movies a, Movies b) {
	return (a.getRating() > b.getRating());
}
