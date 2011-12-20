include ../Makefile.common

OBJS = udttransport.o 

all: libudttransport.so libudttransport.a

%.o: %.cpp
	$(C++) -fPIC $(CCFLAGS) $< -c

libudttransport.so: $(OBJS)
	$(C++) -shared -o $@ $^ $(LDFLAGS) ../src/libudt.a

libudttransport.a: $(OBJS)
	ar -rcs $@ $^

clean:
	rm -f *.o *.so *.a

install:
	export LD_LIBRARY_PATH=$(DIR):$$LD_LIBRARY_PATH

