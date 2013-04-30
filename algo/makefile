CC = g++
NAME = algotest
DEBUG = -g3 -D_DEBUG
CFLAGS = -Wall -Wextra -Wconversion -std=c++0x
LFLAGS = 
VERSION = 1.0
ARCHIVE = $(NAME)-$(VERSION)

SRC = testing/main.cpp algo.cpp
OBJ = $(SRC:.cpp=.o)

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LFLAGS)

clean:
	rm $(OBJ) $(NAME)

dist:
	cd ..; tar czf $(ARCHIVE).tar.gz $(NAME); mv $(ARCHIVE).tar.gz $(NAME)

distclean:
	rm $(ARCHIVE).tar.gz

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(DEBUG)
