# sudokuSolver
Sudoku Solver

Had a challenge with some friends to write a 9x9 sudoku solver in pure c with no libraries (this is in accordance with the french school 42's "norme" standard). This is the rough working result. It took 1 hour 57 minutes and 38 seconds from first line to working. The commits after the inital one is just me being pedantic as i learn more.

usage:

gcc *.c -o sudoku

./sudoku line0 line1 line2 line3 line4 line5 line6 line7 line8

eg ./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."

a bit of a harder one:
./sudoku ".63......" "...2.8..1" ".....9.52" "8..6....." "59......." ".......75" "....7..4." ".3....91." ".57.3...."

just for fun
./sudoku "........." "........." "........." "........." "........." "........." "........." "........." "........."

this one has a pretty visualiser but i was just too lazy to norme (School 42's standard for c) it.
