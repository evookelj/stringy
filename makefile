stringy: stringy.c
	gcc stringy.c -o strtest

clean:
	rm *~

run: strtest
	./strtest
