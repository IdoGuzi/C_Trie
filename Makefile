CC=gcc
FLAGS= -Wall -g

all:frequency frequency_r

frequency_r: frequency‬‬_r.o libtrie.so
	$(CC) $(FLAGS) -o frequency‬‬_r frequency‬‬_r.o ./libnode.so ./libtrie.so

frequency: frequency.o libtrie.so
	$(CC) $(FLAGS) -o frequency frequency.o ./libnode.so ./libtrie.so

libtrie.so: trie.o libnode.so
	$(CC) -shared -o libtrie.so trie.o ./libnode.so

libnode.so: node.o
	$(CC) -shared -o libnode.so node.o 

frequency‬‬_r.o: ‫‪frequency‬‬_r.c node.h trie.h
	$(CC) $(FLAGS) -c ‫‪frequency‬‬_r.c

‫‪frequency‬‬.o: ‫‪frequency‬‬.c node.h trie.h
	$(CC) $(FLAGS) -c ‫‪frequency‬‬.c

trie.o: trie.c trie.h
	$(CC) -fPIC $(FLAGS) -c trie.c

node.o: node.c node.h
	$(CC) -fPIC $(FLAGS) -c node.c

.PHONY:all clean

clean:
	rm -f *.o *.so frequency‬‬_r frequency