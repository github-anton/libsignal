# PROG_NAME=
LOCAL_HEADERS=../include

all: $(PROG_NAME)

$(PROG_NAME): $(PROG_NAME).o libsignal.a 
	gcc -o $(PROG_NAME) $(PROG_NAME).o -L. -lsignal -g
	
$(PROG_NAME).o: ../$(PROG_NAME).c
	gcc -I$(LOCAL_HEADERS) -c ../$(PROG_NAME).c -g

clean:
	rm $(PROG_NAME).o $(PROG_NAME) 2>/dev/null; true
