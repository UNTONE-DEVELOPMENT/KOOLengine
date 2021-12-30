LCC = g++
LCFLAGS = -g -w -std=c++11 -I/usr/local/include/ -L/usr/local/lib/
LLFLAGS = -lSDL2 -lSDL2_image

entity:
	$(LCC) -o engine src/*.cpp $(LCFLAGS) $(LLFLAGS)

m1:
	$(LCC) -I/opt/homebrew/include/ -o engine src/*.cpp -g -w -std=c++11 $(shell pkg-config sdl2 --libs) $(shell pkg-config sdl2_image --libs)