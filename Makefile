CC=g++
NAME=golgol
DEBUG=-g3 -D_DEBUG=1 -O
CFLAGS=-Wall -Wextra -Wconversion -std=c++0x $(shell pkg-config --cflags gtk+-3.0)
LFLAGS=$(shell pkg-config --libs gtk+-3.0)
VERSION=0.1
ARCHIVE=$(NAME)-$(VERSION)

SRC=main.cpp
OBJ=$(SRC:.cpp=.o)
PRE=$(SRC:.cpp=.ii)
ASM=$(SRC:.cpp=.s)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJ) lib$(NAME).a

dist:
	cd ..; tar czf $(ARCHIVE).tar.gz $(NAME); mv $(ARCHIVE).tar.gz $(NAME)

distclean:
	rm -f $(ARCHIVE).tar.gz

preprocess: $(PRE)

preprocessclean:
	rm -f $(PRE)

assembler: $(ASM)

assemblerclean:
	rm -f $(ASM)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(DEBUG)

%.ii: %.cpp
	$(CC) -E $< -o $@ $(CFLAGS) $(DEBUG)

%.s: %.cpp
	$(CC) -S $< -o $@ $(CFLAGS) $(DEBUG)
