G = g++
GFLAGS = -Wall -pedantic -g -std=c++14 -Iinc

tab: obj/main.o obj/item.o obj/solver.o obj/backpack.o obj/shop.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/item.o ./obj/solver.o ./obj/backpack.o ./obj/shop.o  -o projekt

obj/main.o: src/main.cpp inc/solver.hh inc/item.hh
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/item.o: src/item.cpp inc/item.hh
	$(G) $(GFLAGS) -c ./src/item.cpp -o ./obj/item.o

obj/solver.o: src/solver.cpp inc/solver.hh inc/item.hh
	$(G) $(GFLAGS) -c ./src/solver.cpp -o ./obj/solver.o

obj/backpack.o: src/backpack.cpp inc/backpack.hh inc/item.hh
	$(G) $(GFLAGS) -c ./src/backpack.cpp -o ./obj/backpack.o

obj/shop.o: src/shop.cpp inc/shop.hh
	$(G) $(GFLAGS) -c ./src/shop.cpp -o ./obj/shop.o
clean:
	rm -fr ./obj/*.o projekt
