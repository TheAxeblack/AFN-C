CC = gcc
OPTIONS = -W -Wall -std=c89 -pedantic -O3
INCLUDE = -Iinc

principal: obj/ensemble.o obj/piles.o obj/automate.o obj/afn.o src/main.c
	$(CC) $(OPTIONS) src/main.c obj/ensemble.o obj/piles.o obj/automate.o obj/afn.o -o principal
obj/%.o: src/%.c
	$(CC) $(OPTIONS) $(INCLUDE) -c $< -o $@
clean:
	rm -rf obj/*.o principal