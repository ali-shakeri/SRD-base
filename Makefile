CPP = g++
CPPFLAGS = -O1 -g -pg -std=c++11

sources = $(wildcard src/*.cpp)
objects = $(addprefix bin/,$(notdir $(sources:.cpp=.o)))
	
srd: $(objects)
	$(CPP) -pg $(objects) -o $@

bin/%.o: src/%.cpp
	$(CPP) -c $(CPPFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm srd gmon.out bin/*.o