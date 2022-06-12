.PHONY: all clean install

CC			:= g++
CFLAGS		:= -g -w -std=c++17
LDFLAGS		:= $(shell pkg-config sdl2_mixer sdl2 sdl2_ttf sdl2_image --libs)
SOURCEDIR	:= src/
CXXFILES	:= $(wildcard $(SOURCEDIR)*.cpp)
OBJS		:= $(CXXFILES:.cpp=.o)
TARGET		:= libkoolengine.so

LOCAL		:= /usr/local/

# needed to install on windows

MINGW64 	:= C:/msys64/mingw64/
FIND_MGW 	:= C:/msys64/usr/bin/find.exe

ifeq ($(platform),windows)
install:: all
	@rm -rf $(MINGW64)include/KOOLengine/
	@mkdir $(MINGW64)include/KOOLengine/
	@$(FIND_MGW) $(SOURCEDIR) -name "*.hpp" -exec cp -r {} $(MINGW64)include/KOOLengine/ \;
	@rm -rf $(MINGW64)lib/libkoolengine.dll
	@cp libkoolengine.dll $(MINGW64)lib/
else
install:: all
	@mkdir -p $(LOCAL)include/KOOLengine/
	@find $(SOURCEDIR) -name "*.hpp" -exec cp -r {} $(LOCAL)include/KOOLengine/ \;
	@cp libkoolengine.so $(LOCAL)lib/
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking objs..."
	@$(CC) $(CFLAGS) -shared -o $@ $^ $(LDFLAGS)

$(SOURCEDIR)%.o: $(SOURCEDIR)%.cpp
	@echo "Compiling obj" $<
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning up objects"
	@rm -rf $(SOURCEDIR)*.o *.so
