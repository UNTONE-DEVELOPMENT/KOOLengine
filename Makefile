LCC = gcc
LXX = g++
LCFLAGS = -g -w -std=c++17 $(shell pkg-config --cflags sdl2) $(shell pkg-config --cflags sdl2_image)
LLFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer
LOCAL = /usr/local/
MINGW64 = C:/msys64/mingw64/
FIND_MGW = C:/msys64/usr/bin/find.exe

entity:
	$(LXX) -c src/*.cpp $(LCFLAGS) $(LLFLAGS)

m1:
	$(LXX) -I/opt/homebrew/include/ -o engine src/*.cpp -g -w -std=c++11 $(shell pkg-config sdl2 --libs) $(shell pkg-config sdl2_image --libs)

install: entity
	$(LXX) -shared -o libkoolengine.so *.o $(LCFLAGS) $(LLFLAGS)
	mkdir -p $(LOCAL)include/KOOLengine/
	find ./src -name "*.hpp" -exec cp -r {} $(LOCAL)include/KOOLengine/ \;
	cp libkoolengine.so $(LOCAL)lib/

install_mingw64: entity
	$(LXX) $(LCFLAGS) -shared -o libkoolengine.dll *.o $(LLFLAGS) -Wl,-Bstatic
	rm -rf $(MINGW64)include/KOOLengine/
	mkdir $(MINGW64)include/KOOLengine/
	$(FIND_MGW) ./src -name "*.hpp" -exec cp -r {} $(MINGW64)include/KOOLengine/ \;
	cp libkoolengine.dll $(MINGW64)lib/

clean:
	rm -rf *.so *.o *.dll