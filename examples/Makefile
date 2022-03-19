LXX = g++
MINGW64_LFLAGS = C:/msys64/mingw64/lib/libkoolengine.dll

all:
	$(LXX) -std=c++17 -o entity_example entityexample.cpp -lkoolengine
	$(LXX) -std=c++17 -o scene_test scenetest.cpp -lkoolengine
	$(LXX) -std=c++17 -o entity_scene scenent.cpp -lkoolengine -lSDL2
	$(LXX) -std=c++17 -o sound_check soundchk.cpp -lkoolengine -lSDL2
	$(LXX) -std=c++17 -o bouncer bouncer.cpp -lkoolengine -lSDL2
mingw64:
	$(LXX) -std=c++17 -o entity_example entityexample.cpp $(MINGW64_LFLAGS)
	$(LXX) -std=c++17 -o scene_test scenetest.cpp $(MINGW64_LFLAGS)
	$(LXX) -std=c++17 -o entity_scene scenent.cpp $(MINGW64_LFLAGS) -lSDL2
	$(LXX) -std=c++17 -o sound_check soundchk.cpp $(MINGW64_LFLAGS) -lSDL2
	$(LXX) -std=c++17 -o bouncer bouncer.cpp $(MINGW64_LFLAGS) -lSDL2
m1:
	$(LXX) -I/opt/homebrew/include/ -std=c++17 -o entity_example entityexample.cpp -L/opt/homebrew/lib -lkoolengine
	$(LXX) -I/opt/homebrew/include/ -std=c++17 -o scene_test scenetest.cpp -L/opt/homebrew/lib -lkoolengine
	$(LXX) -I/opt/homebrew/include/ -std=c++17 -o entity_scene scenent.cpp -L/opt/homebrew/lib -lkoolengine -lSDL2
	$(LXX) -I/opt/homebrew/include/ -std=c++17 -o sound_check soundchk.cpp -L/opt/homebrew/lib -lkoolengine -lSDL2
	$(LXX) -I/opt/homebrew/include/ -std=c++17 -o bouncer bouncer.cpp -L/opt/homebrew/lib -lkoolengine -lSDL2 -lSDL2_ttf