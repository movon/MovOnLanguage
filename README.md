# MovOnLanguage
Writing our own interpreted language, go mov_on!
will be ready soon.


Useful notes:
1).When creating a class, create a class and not a txt file. Also include it in CMakeLists.txt where all the classes go add -> src/class.cpp src/class.h

2).If your data becomes corrupted then add a case for it in tokTypeToString

3). -1 > 1 -> true! turn 1 to signed. happened in -1 >= .length()
