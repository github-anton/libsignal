# PROG_NAME=

all: $(PROG_NAME)

$(PROG_NAME): $(PROG_NAME).o libsignal.a 
	gcc -o $(PROG_NAME) $(PROG_NAME).o -L. -lsignal -lm
	
$(PROG_NAME).o: ../$(PROG_NAME).c
	gcc -c ../$(PROG_NAME).c

clean:
	rm $(PROG_NAME).o $(PROG_NAME) 2>/dev/null; true
