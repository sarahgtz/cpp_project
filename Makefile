CXXFLAGS=-O3 -MMD -MP -g -Wall -fsanitize=address -std=c++11
CC=$(CXX)

PROGRAMS=programm
OBJECTS=person.o personlist.o bloodrelatives.o id.o

ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

programm: $(OBJECTS)

clean:
	-rm -f $(ALLOBJECTS) $(ALLOBJECTS:%.o=%.d) $(PROGRAMS)

-include $(ALLOBJECTS:%.o=%.d)

