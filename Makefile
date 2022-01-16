LCC = gcc
LXX = g++
LCFLAGS = -g -w -std=c++17 -I/usr/local/include/ -L/usr/local/lib/
LLFLAGS = -lSDL2 -lSDL2_image
LOCAL = /usr/local/

entity:
	$(LXX) -c src/*.cpp $(LCFLAGS) $(LLFLAGS)

m1:
	$(LXX) -I/opt/homebrew/include/ -o engine src/*.cpp -g -w -std=c++11 $(shell pkg-config sdl2 --libs) $(shell pkg-config sdl2_image --libs)

install: entity
	$(LXX) -shared -o libkoolengine.so *.o $(LCFLAGS) $(LLFLAGS)
	mkdir -p $(LOCAL)include/KOOLengine/
	find ./src -name "*.hpp" -exec cp -r {} $(LOCAL)include/KOOLengine/ \;
	cp libkoolengine.so $(LOCAL)lib/

clean:
	rm -rf *.so *.o