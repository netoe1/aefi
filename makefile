#	defining variables

PROGRAM = main.cpp
COMPILER = g++

#	libraries defining
#	utils
UTILS_HPP = ./include/utils.hpp
UTILS_CPP = ./src/utils.cpp
UTILS_O = ./obj/utils.o

#	main
MAIN_CPP = ./src/main.cpp
MAIN_O = ./obj/main.o

utils.o: ${UTILS_CPP} ${UTILS_HPP}
	${COMPILER} -c ${UTILS_CPP} -o ${UTILS_O}

main.o: ${MAIN_CPP} ${UTILS_O}
	${COMPILER} -o ${MAIN_O} ${MAIN_CPP} ${UTILS_O}
	 
clean:
	rm -rf ./obj/*.o