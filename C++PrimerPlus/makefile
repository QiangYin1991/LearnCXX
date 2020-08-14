OBJECTS = ./ch10/stock10.o ./ch10/usestock10.o
cc = g++

usestock10: $(OBJECTS)
	$(cc) -o ../exe/usestock10 $(OBJECTS)

./ch10/usestock10.o: ./ch10/usestock10.cpp ./ch10/stock10.h
	$(cc) -o ./ch10/usestock10.o -c ./ch10/usestock10.cpp

./ch10/stock10.o: ./ch10/stock10.cpp
	$(cc) -o ./ch10/stock10.o -c ./ch10/stock10.cpp

#./ch9/external.o: ./ch9/support.cpp
#	$(cc) -c ./ch9/support.cpp

.PHONY: clean
clean:
	-rm ch10/*.o