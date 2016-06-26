CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = main.o mushroom.o poisonshroom.o oneupshroom.o supershroom.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = plumber 

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
