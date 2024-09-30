CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++11
DEPS = modulo.hpp
OBJ = main.o

ifeq ($(OS),Windows_NT) 
RM=del /Q /F
EXT=.exe
else
RM=rm -rf
EXT=
endif

all: main

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ) modulo.o main.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	-$(RM) main$(EXT) *.o

