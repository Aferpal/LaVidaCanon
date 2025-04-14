TARGET = app

CXX = g++

CXXFLAGS = -Wall -g

INCLUDE = -I/usr/include/mysql-cppconn

LINK = -L/usr/lib/x86_64-linux-gnu 

DYNAMIC_LIBS = -lmysqlcppconnx

SOURCE_FOLDER = ./src

OUTPUT_FOLDER = ./out

OBJS_FOLDER = ./objs

OBJS = $(OBJS_FOLDER)/main.o $(OBJS_FOLDER)/CommandEngine/CommandEngine.o $(OBJS_FOLDER)/DataBase/DataBaseMysql.o

TESTS_FOLDER = $(SOURCE_FOLDER)/test

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(OUTPUT_FOLDER)/$(TARGET) $(LINK) $(DYNAMIC_LIBS)

testArray: 
	$(CXX) $(CXXFLAGS) $(TESTS_FOLDER)/ArrayList/ArrayListTest.cpp -o $(OUTPUT_FOLDER)/testArray
	$(OUTPUT_FOLDER)/testArray

testTree:
	$(CXX) $(CXXFLAGS) $(TESTS_FOLDER)/Tree/BSTreeTest.cpp -o $(OUTPUT_FOLDER)/testTree
	$(OUTPUT_FOLDER)/testTree

testMap:
	$(CXX) $(CXXFLAGS) $(TESTS_FOLDER)/Map/TreeMap.cpp -o $(OUTPUT_FOLDER)/testMap
	$(OUTPUT_FOLDER)/testMap


$(OBJS_FOLDER)/DataBase/DataBaseMysql.o : $(SOURCE_FOLDER)/DataBase/DataBaseMysql.cpp
	@mkdir -p $(OBJS_FOLDER)/DataBase
	$(CXX) $(INCLUDE) -c $(SOURCE_FOLDER)/DataBase/DataBaseMysql.cpp -o $(OBJS_FOLDER)/DataBase/DataBaseMysql.o 


$(OBJS_FOLDER)/%.o: $(SOURCE_FOLDER)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@



clean:
	rm $(OBJS_FOLDER)/*.o

run:
	$(OUTPUT_FOLDER)/$(TARGET)
