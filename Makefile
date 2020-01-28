CC=gcc
FLAGS= -Wall -g
INC= -I inc


all: lib_folder obj_folder frequency trie_test 

trie_test: trie_test.o libtrie.so 
	$(CC) $(FLAGS) -o trie_test obj/trie_test.o ./lib/libnode.so ./lib/libtrie.so

frequency: frequency.o libtrie.so
	$(CC) $(FLAGS) -o frequency obj/frequency.o ./lib/libnode.so ./lib/libtrie.so

libtrie.so: trie.o libnode.so
	$(CC) -shared -o lib/libtrie.so obj/trie.o ./lib/libnode.so

libnode.so: node.o
	$(CC) -shared -o lib/libnode.so obj/node.o 

trie_test.o: trie_test.c node.h trie.h
	$(CC) $(FLAGS) -c trie_test.c
	-mv $@ obj

frequency.o: frequency.c node.h trie.h
	$(CC) $(FLAGS) -c frequency.c
	-mv $@ obj

trie.o: trie.c trie.h
	$(CC) -fPIC $(FLAGS) -c trie.c
	-mv $@ obj

node.o: node.c node.h
	$(CC) -fPIC $(FLAGS) -c node.c
	-mv $@ obj

.PHONY:all clean clean_lib lib_folder obj_folder


lib_folder:
	mkdir -p lib

obj_folder:
	mkdir -p obj

clean: clean_lib clean_obj
	rm -f *.o *.so frequency trie_test

clean_lib:
	rm -r -f lib

clean_obj:
	rm -r -f obj