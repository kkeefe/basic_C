all: basic 

basic: basic.cpp
	g++ -Wall -std=c++14 -g basic.cpp -o basic
