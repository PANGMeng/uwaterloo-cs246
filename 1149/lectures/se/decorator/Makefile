CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = main.o drip.o instant.o espresso.o cream.o milk.o sugar.o coldmilk.o steamedmilk.o whisky.o beer.o water.o foam.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = coffee

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
