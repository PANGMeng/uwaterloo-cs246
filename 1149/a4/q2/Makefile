CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = a4q2
OBJECTS = main.o expression.o intexpression.o oneoperator.o twooperator.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
	rm *.o
	rm *.d
