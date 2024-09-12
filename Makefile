CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare

HEADERS = random-password.hpp database.hpp password-encryption.hpp
OBJECTS = test/test-cases.o database.o password-encryption.o
TARGET = test_executable

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

runtest: $(TARGET)
	./$(TARGET)

%.o: test/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

database.o: database.cpp database.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

password-encryption.o: password-encryption.cpp password-encryption.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET) rawdata.txt