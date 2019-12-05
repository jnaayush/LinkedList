CXX = c++ 
CXXFLAGS = -std=c++0x #Remove restriction to use local types of arguments
main: main.o UnitTest.o
	${CXX} ${CXXFLAGS} -o a.out main.o UnitTest.o

clean:
	@echo "Cleaning up..."
	rm -rvf *.o


