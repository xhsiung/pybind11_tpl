CXX:=g++
CLFGS:=-std=c++11 -Wall -O3 -fPIC -shared -Ipybind11/include -Ipybind11/include $(shell python3-config --includes)  
LIBS:=$(shell python3-config --libs)

SORUCE=main.cpp
OBJS=$(SORUCE:.cpp=.o)
OUT:= my.so

all:test main
main: $(OBJS)
	$(CXX) -o $(OUT)  $^  $(CLFGS)  $(LIBS)

%.o: %.cpp
	$(CXX)  -c   $<  $(CLFGS)  $(LIBS)

install:
	install  -D  $(OUT)  mylibs/$(OUT)  -m 755

test:
	echo "test"

clean:
	rm -rf mylibs
	rm -rf *.o
	rm -rf *.so
	rm -rf  $(OUT)
