CC=g++
CFLAGS=`sdl2-config --libs --cflags` -D_REENTRANT -O0 -Wall -lSDL2_image -lm
EXE=simpleSDLWindow

EXE:$(EXE).o
	$(CC) $(EXE).cpp -o $(EXE) $(CFLAGS)

clean:
	rm $(EXE) *.o
