CXX = g++
CXXFLAGS = -Wall
EXEC = main
OBJECTS = main.o book.o textbook.o comic.o BookVisitor.o catalogue.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

main.o: main.cc book.h textbook.h comic.h

book.o: book.h book.cc

csbook.o: textbook.h textbook.cc book.h

comic.o: comic.h comic.cc book.h

clean:
	rm ${OBJECTS} ${EXEC}
