#MakeFile

CXXFLAGS = -std=c++11 
# --std=c++11 -g -Wall -O0

# runMovies: main.cpp 
# 	g++ $(CXXFLAGS) main.cpp -o main
runMovies: main.o movie.o
	g++ $(CXX_FLAG) main.o movie.o -o runMovies

movie.o: movie.cpp
	g++ -c $(CXX_FLAG) movie.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp
	
clean:
	rm -f main runMovies *.o
