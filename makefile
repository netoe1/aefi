#	defining variables

PROGRAM = main.cpp
COMPILER = g++

#	libraries defining

#	scripts.hpp
SCRIPTS.HPP = ./include/scripts.hpp
SCRIPTS.CPP = ./include/scripts.cpp
SCRIPTS.O = ./obj/scripts.o

#	utils.hpp
UTILS_HPP = ./include/utils.hpp
UTILS_CPP = ./src/utils.cpp
UTILS_O = ./obj/utils.o

#	main.cpp
MAIN_CPP = ./src/main.cpp
MAIN_O = ./obj/main.o

utils.o: ${UTILS_CPP} ${UTILS_HPP}
	${COMPILER} -c ${UTILS_CPP} -o ${UTILS_O}

main.o: ${MAIN_CPP} ${UTILS_O}
	${COMPILER} -o ${MAIN_O} ${MAIN_CPP} ${UTILS_O} ${SCRIPTS_O}

scripts.o: ${SCRIPTS_HPP} ${SCRIPTS_CPP}
	${COMPILER} -c ${SCRIPTS_CPP} -o ${SCRIPTS_O}
all:
	make utils.o scripts.o main.o
clean:
	rm -rf ./obj/*.o