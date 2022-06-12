LCC = gcc
LXX = g++
LCFLAGS = -g -w -std=c++17 $(shell pkg-config --cflags sdl2) $(shell pkg-config --cflags sdl2_image)
LLFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer
LOCAL = /usr/local/
MINGW64 = C:/msys64/mingw64/
FIND_MGW = C:/msys64/usr/bin/find.exe

entity:
	$(LXX) -c src/*.cpp $(LCFLAGS) $(LLFLAGS)

entity_rpi:
	$(LXX) -fPIC -c src/*.cpp $(LCFLAGS) $(LLFLAGS)	

m1:
	$(LXX) -I/opt/homebrew/include/ -g -w -std=c++17 -c src/*.cpp $(shell pkg-config sdl2 --libs) $(shell 	pkg-config sdl2_image --libs)

install: entity
	$(LXX) -shared -o libkoolengine.so *.o $(LCFLAGS) $(LLFLAGS)
	mkdir -p $(LOCAL)include/KOOLengine/
	find ./src -name "*.hpp" -exec cp -r {} $(LOCAL)include/KOOLengine/ \;
	cp libkoolengine.so $(LOCAL)lib/

install_m1: m1
	$(LXX) -shared -o libkoolengine.so *.o $(shell pkg-config sdl2 --libs) $(shell pkg-config sdl2_image --libs) $(shell pkg-config sdl2_mixer --libs)
	mkdir -p /opt/homebrew/include/KOOLengine/
	find ./src -name "*.hpp" -exec cp -r {} /opt/homebrew/include/KOOLengine/ \;
	cp libkoolengine.so /opt/homebrew/lib/

install_mingw64: entity
	$(LXX) -I/opt/homebrew/include/ -g -w -std=c++17 -shared -o libkoolengine.dll *.o $(LLFLAGS) -Wl,-Bstatic
	rm -rf $(MINGW64)include/KOOLengine/
	mkdir $(MINGW64)include/KOOLengine/
	$(FIND_MGW) ./src -name "*.hpp" -exec cp -r {} $(MINGW64)include/KOOLengine/ \;
	rm -rf $(MINGW64)lib/libkoolengine.dll
	cp libkoolengine.dll $(MINGW64)lib/

install_rpi: 
	$(LXX) -fPIC -shared -o libkoolengine.so *.o $(LCFLAGS) $(LLFLAGS)
	mkdir -p $(LOCAL)include/KOOLengine/
	find ./src -name "*.hpp" -exec cp -r {} $(LOCAL)include/KOOLengine/ \;
	cp libkoolengine.so $(LOCAL)lib/

clean:
	rm -rf *.so *.o *.dll
