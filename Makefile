all: basic ch6 person

basic: basic.cpp
	g++ -Wall -std=c++11 -g basic.cpp -o basic
ch6: ch6.cpp
	g++ -Wall -std=c++11 -g ch6.cpp -o ch6
person: person.cpp
	g++ -Wall -std=c++11 -g person.cpp -o person
