# **Programming Assignment 1:** #
- There are examples for every input file in the dat folder currently, but they do not work as input for the files since none of them are actually named 'input.txt'. 
- Also in the dat folder, is a png of the plot for the quick sort analysis bonus problem. It is titled 'BonusPlot.png'.
- When you are done, type ``make clean`` into the progAssign1 terminal and it will delete all intermediarry files as well as the 'output.txt'.
<br/><br/>

### **Topological (Question 1):** ###
##### **findTop.h, findTop.cpp, main1.cpp:** #####
This program reads in an input ASCII file named 'input.txt' located inside the dat folder. 'input.txt' should contain an adjacency matrix filled with values of 0 and 1 with a space in between each column and a new line for each row. The program will then check to see if the graph is either a fully-completed, star, or ring toplogy in that order. The program then prints out which type of toplogy it is, or if it is none of them, as well as the execution time in microseconds into a file named 'output.txt' in the dat folder.

#### **Usage:** ####
While in the progAssign1 folder, type ``make num1`` and then ``./num1``. The 'output.txt' file will be located in the dat folder.
<br/><br/>

### **QuickSort (Question 2):** ###
##### **quickSort.h, quickSort.cpp, main2.cpp** #####
This program first reads in an input ASCII file named ‘input.txt’ located inside the dat folder. 'input.txt' should contain the unsorted float-point numbers separated by blank space. The program will then sort it using the QuickSort algorithm, then prints the sorted algorithm as well as the time it takes to complete into a file named 'output.txt' in the dat folder. 'output.txt' contians the sorted float-point numbers separated by blank space.

#### **Usage:** ####
While in the progAssign1 folder, type ``make num2`` and then ``./num2``. The 'output.txt' file will be located in the dat folder.
<br/><br/>

### **QuickSort Empirical Analysis (Bonus):** ###
##### **quickSort.h, quickSort.cpp, mainB.cpp** #####
This program is to study the time complexity of QuickSort using the different input sizes 10, 100, 1000, 10000, and 100000. It randomly fills 100 arrays of each size. Each one is sorted using the QuickSort algorithm and the execution time is averaged for each size. This averaged time is then printed out into a file named 'output.txt' in the dat folder.

#### **Usage:** ####
While in the progAssign1 folder, type ``make bonus`` and then ``./bonus``. The 'output.txt' file will be located in the dat folder.
<br/><br/>
