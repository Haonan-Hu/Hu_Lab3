Hashing: main.o Executive.o HashTable.o User.o
	g++ -std=c++11 -g -Wall main.o Executive.o HashTable.o User.o -o Hashing

main.o: main.cpp Executive.h Executive.cpp HashTable.h HashTable.cpp User.h User.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp HashTable.h HashTable.cpp User.h User.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

HashTable.o: HashTable.h HashTable.cpp User.h User.cpp
	g++ -std=c++11 -g -Wall -c HashTable.cpp

User.o: User.h
	g++ -std=c++11 -g -Wall -c User.cpp

clean:
	rm *.o Hashing
