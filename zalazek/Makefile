__start__: obj __lines_for_space__ interp __plugin__
	export LD_LIBRARY_PATH="./libs"; ./interp

obj:
	mkdir -p obj

__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo

__plugin__:
	cd plugin; make

# ====== Flagi kompilacji i linkowania ======
CPPFLAGS=-Wall -pedantic -std=c++17 -Iinc
LDFLAGS=-Wall
LDLIBS=-lxerces-c -ldl

# ====== Pliki źródłowe i obiektowe ======
SRC = src/main.cpp src/xmlinterp.cpp
OBJ = $(SRC:src/%.cpp=obj/%.o)

# ====== Budowanie programu ======
interp: $(OBJ)
	g++ $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

# ====== Reguła ogólna dla kompilacji plików .cpp ======
obj/%.o: src/%.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

# ====== Dokumentacja ======
doc:
	cd dox; make

# ====== Czyszczenie ======
clean:
	rm -f obj/* interp core*

clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
