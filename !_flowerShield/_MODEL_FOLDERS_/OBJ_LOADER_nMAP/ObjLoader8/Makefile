GTK_INCLUDES= `pkg-config --cflags gtk+-2.0`
GTK_LIBS    = `pkg-config --cflags --libs gtk+-2.0`

INCLUDES    = -I../CommonLib -I/usr/X11R6/include $(GTK_INCLUDES)
LIB         = -L../CommonLib -L/usr/X11R6/lib $(GTK_LIBS)

#COMPILE    = gcc -g  -DDEBUG   $(INCLUDES)
COMPILE     = gcc -O2 -DRELEASE $(INCLUDES)

OUTPUT  = ../objload8

OBJECTS = ObjLoader.o

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(COMPILE) -o $(OUTPUT) $(OBJECTS) $(LIB) -lCommon -lGL -lGLU -lglut -lstdc++ -lXmu -lXi 
		
ObjLoader.o: ObjLoader.c ObjLoader.h
	$(COMPILE) -c ObjLoader.c

clean:
	rm $(OUTPUT) $(OBJECTS);
