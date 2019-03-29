CC=g++
FLAG=-lhiredis 

redis:redis.h redis.cpp
	$(CC) redis.cpp -o redis  $(FLAG) -g
	
clean:
	rm -f redis