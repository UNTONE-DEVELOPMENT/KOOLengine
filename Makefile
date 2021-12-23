LCC = g++

LCFLAGS = -g -w -std=c++11 -I/usr/local/include/ -L/usr/local/lib/
LLFLAGS = -lSDL2 -lSDL2_image

entity:
	$(LCC) -o engine src/*.cpp $(LCFLAGS) $(LLFLAGS)