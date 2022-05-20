all:
	g++	-Isrc/include	-Lsrc/lib	-o	main main.cpp CommonFunc.cpp dog.cpp game.cpp land.cpp lib.cpp pipe.cpp sound.cpp heart.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf