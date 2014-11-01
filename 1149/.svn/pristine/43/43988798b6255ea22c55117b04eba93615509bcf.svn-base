main: main.o book.o textbook.o comic.o
	g++ main.o book.o textbook.o comic.o -o main

main.o: main.cc book.h textbook.h comic.h
	g++ -c main.cc

book.o: book.h book.cc
	g++ -c book.cc

textbook.o: textbook.h textbook.cc book.h
	g++ -c textbook.cc

comic.o: comic.h comic.cc book.h
	g++ -c comic.cc

