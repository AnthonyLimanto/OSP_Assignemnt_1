# USAGE
# compiles all task then makes an executable for each one
all: Task1 Task2

Task1: Task1.cpp
	g++ -Wall -g -o Task1 Task1.cpp

Task2: Task2.cpp
	g++ -Wall -g -o Task2 Task2.cpp