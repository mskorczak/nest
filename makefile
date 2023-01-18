NAME=nest
IDIR=./include
CC=gcc
CFLAGS=-I$(IDIR) -L$(LDIR)
ODIR=obj
LDIR=./lib
LIBS=
_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
 
_OBJ = nest.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
 
$(ODIR)/%.o : src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
 
run: 
	make
	./nest

.PHONY: clean
 
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
