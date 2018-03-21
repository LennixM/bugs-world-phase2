#======COMPILING OPTIONS====#
CC = g++ -std=c++11
CFLAGS = -Wall

#===========================#
main = main.cpp cell.h marker.h bug.h world.cpp world.h
test_bug = tests/BugTest.cpp bug.h 
test_cell = tests/CellTest.cpp cell.h
test_marker = tests/MarkerTest.cpp marker.h


#==========RUNNING==========#
test: run_bug run_cell run_marker

run_main: main
	./main.o

run_bug: test_bug
	./testBug.o

run_cell: test_cell
	./testCell.o

run_marker: test_marker
	./testMarker.o

#==========COMPILING==========#
all: main test_bug test_cell test_marker

main: $(main)
	$(CC) $(CFLAGS) -o main.o $(main)

test_bug: $(test_bug)
	$(CC) $(CFLAGS) -o testBug.o $(test_bug)

test_cell: $(test_cell)
	$(CC) $(CFLAGS) -o testCell.o $(test_cell)

test_marker: $(test_marker)
	$(CC) $(CFLAGS) -o testMarker.o $(test_marker)


#==========CLEANING==========#
clean_main:
	rm -f main.o

clean_bug:
	rm -f testBug.o

clean_cell:
	rm -f testCell.o

clean_marker:
	rm -f testMarker.o

clean_test:
	rm -f test*.o

clean:
	rm -f *.o
