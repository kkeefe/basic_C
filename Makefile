all: basic person test

basic: basic.cpp 
	g++ -Wall -std=c++11 -g basic.cpp -o basic
# test: test.cpp
# 	g++ -Wall -std=c++11 -g test.cpp -o test
