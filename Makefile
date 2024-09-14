CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare

HEADERS = random-password.hpp database.hpp password-encryption.hpp hashtable.hpp
TEST_OBJECTS = test/test-cases.o database.o password-encryption.o hashtable.o
MAIN_OBJECTS = main.o database.o password-encryption.o hashtable.o
TEST_TARGET = test_executable
MAIN_TARGET = main_executable

all: $(TEST_TARGET) $(MAIN_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

runtest: $(TEST_TARGET)
	./$(TEST_TARGET)

runmain: $(MAIN_TARGET)
	./$(MAIN_TARGET)

%.o: test/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

database.o: database.cpp database.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

password-encryption.o: password-encryption.cpp password-encryption.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

hashtable.o: hashtable.cpp hashtable.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TEST_OBJECTS) $(MAIN_OBJECTS) $(TEST_TARGET) $(MAIN_TARGET) rawdata.txt encrypteddata.txt