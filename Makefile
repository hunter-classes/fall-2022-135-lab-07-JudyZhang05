main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

# tests: tests.o funcs.o
# 	g++ -o tests tests.o funcs.o


unindent.o: unindent.cpp edit.h

indent.o: indent.cpp edit.h

main.o: main.cpp edit.h

# tests.o: tests.cpp doctest.h funcs.h

clean:
	rm -f main.o unindent.o indent.o
