path = ..
standard = c++17

flags = -std=$(standard)  # compile with standard
flags += -Wall  # compile with all warnings
flags += -pedantic  # even more warnings
flags += -I $(path)  # add parent to preprocessor include path
flags += -g  # include gdb instrumentation

num1: num1_main.o topology.o
	g++ $(flags) bin/num1_main.o bin/topology.o -o num1

num1_main.o: src/main1.cpp
	g++ $(flags) -c src/main1.cpp -o bin/num1_main.o

topology.o: src/findTop.cpp inc/findTop.h
	g++ $(flags) -c src/findTop.cpp -o bin/topology.o


num2: num2_main.o quickSort.o
	g++ $(flags) bin/num2_main.o bin/quickSort.o -o num2

num2_main.o: src/main2.cpp
	g++ $(flags) -c src/main2.cpp -o bin/num2_main.o

bonus: bonus_main.o quickSort.o
	g++ $(flags) bin/bonus_main.o bin/quickSort.o -o bonus

bonus_main.o: src/mainB.cpp
	g++ $(flags) -c src/mainB.cpp -o bin/bonus_main.o

quickSort.o: src/quickSort.cpp inc/quickSort.h
	g++ $(flags) -c src/quickSort.cpp -o bin/quickSort.o


clean:
	rm bin/*
	rm num2
	rm bonus
	rm num1
	rm dat/output.txt