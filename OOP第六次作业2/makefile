main: main.cpp Calculator.o LevelStrategy.o PerformStrategy.o
	g++ main.cpp Calculator.o LevelStrategy.o PerformStrategy.o -o main
Calculator.o: Calculator.cpp Calculator.h
	g++ -c Calculator.cpp -o Calculator.o
LevelStrategy.o: LevelStrategy.cpp LevelStrategy.h
	g++ -c LevelStrategy.cpp -o LevelStrategy.o
PerformStrategy.o: PerformStrategy.cpp PerformStrategy.h
	g++ -c PerformStrategy.cpp -o PerformStrategy.o