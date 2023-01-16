.SUFFIXES:
.SUFFIXES: .c .o
CLNT = client
SRVR = server
CFLAGS = -g -Wall

SRVR_OBJ = server.o add_xdr.o add_svc.o
CLNT_OBJ = client.o add_xdr.o add_clnt.o

.c.o:; gcc -c -o $@ $(CFLAGS) $<

default: $(CLNT) $(SRVR)

$(CLNT): $(CLNT_OBJ) add.h
	gcc -o $(CLNT) $(CLNT_OBJ)

$(SRVR): $(SRVR_OBJ) add.h
	gcc -o $(SRVR) $(SRVR_OBJ) -lm

clean:
	rm *.o $(CLNT) $(SRVR)
	rm -i *~
	rm core