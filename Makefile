CC:=clang
OUT:=main
CFLAGS:=-g -Wall -std=c17 -lm
RFLAGS:=-std=c17 -lm -DNDEBUG -O3
CFILES:=main.c

debug: $(CFILES)
	$(CC) $(CFLAGS) -o $(OUT) $(CFILES)

release: $(CFILES)
	$(CC) $(RFLAGS) -o $(OUT) $(CFILES)

clean:
	rm $(OUT)
