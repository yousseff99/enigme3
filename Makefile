

game:main.o fnc.o
	gcc main.o fnc.o -o game  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 

main.o:main.c
	gcc main.c -c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g


fnc.o:fnc.c
	gcc fnc.c -c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
