#MakeFile

CXXFLAGS = -std=c++11 
# --std=c++11 -g -Wall -O0

# runMovies: main.cpp 
# 	g++ $(CXXFLAGS) main.cpp -o main
runMovies: main.o movies.o
	g++ $(CXX_FLAG) main.o movies.o -o runMovies

movies.o: movies.cpp
	g++ -c $(CXX_FLAG) movies.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp
	
clean:
	rm -f main runMovies *.o
