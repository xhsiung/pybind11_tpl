CXX:=g++
CLFGS:=-Ipybind11/include $(shell python3-config --includes)
LIBS:=$(shell python3-config --libs)

SORUCE=main.cpp
OBJS=$(SORUCE:.cpp=.o)
OUT:= main

all:test main
main: main.o
	$(CXX) -o $(OUT)  $^  $(CLFGS)  $(LIBS)

%.o: %.cpp
	$(CXX)  -c   $<  $(CLFGS)  $(LIBS)

test:
	echo "test"

clean:
	rm -rf *.o
	rm -rf  $(OUT)
