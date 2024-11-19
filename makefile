TARGET = app

CXX = g++

CXXFLAGS = -Wall -g

SOURCE_FOLDER = ./src

OUTPUT_FOLDER = ./out

OBJS_FOLDER = ./objs

OBJS = $(OBJS_FOLDER)/main.o

TESTS_FOLDER = $(SOURCE_FOLDER)/test

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(OUTPUT_FOLDER)/$(TARGET)

testArray: 
	$(CXX) $(CXXFLAGS) $(TESTS_FOLDER)/ArrayList/ArrayListTest.cpp -o $(OUTPUT_FOLDER)/testArray
	$(OUTPUT_FOLDER)/testArray

testTree:
	$(CXX) $(CXXFLAGS) $(TESTS_FOLDER)/Tree/BSTreeTest.cpp -o $(OUTPUT_FOLDER)/testTree
	$(OUTPUT_FOLDER)/testTree


$(OBJS_FOLDER)/%.o: $(SOURCE_FOLDER)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) -c $< -o $@



clean:
	rm $(OBJS_FOLDER)/*.o

run:
	$(OUTPUT_FOLDER)/$(TARGET)
