OBJECTS = ./ch9/newplace.o
cc = g++

external: $(OBJECTS)
	$(cc) -o ../exe/newplace $(OBJECTS)

#./ch9/external.o: ./ch9/support.cpp
#	$(cc) -c ./ch9/support.cpp

.PHONY: clean
clean:
	-rm ch9/*.o