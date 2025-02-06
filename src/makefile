CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lrt

SRC = helpers_func.cpp

OBJ = $(SRC:.cpp=.o)

EXEC_CREATE = create_shared_memory_program
EXEC_READ = read_delete_shrm_program

all: $(EXEC_CREATE) $(EXEC_READ)

$(EXEC_CREATE): create_shared_memory.o $(OBJ)
	$(CXX) create_shared_memory.o $(OBJ) -o $(EXEC_CREATE) $(LDFLAGS)

$(EXEC_READ): read_delete_shrm.o $(OBJ)
	$(CXX) read_delete_shrm.o $(OBJ) -o $(EXEC_READ) $(LDFLAGS)

create_shared_memory.o: create_shared_memory.cpp helpers_func.hpp
	$(CXX) $(CXXFLAGS) -c create_shared_memory.cpp -o create_shared_memory.o

read_delete_shrm.o: read_delete_shrm.cpp helpers_func.hpp
	$(CXX) $(CXXFLAGS) -c read_delete_shrm.cpp -o read_delete_shrm.o

helpers_func.o: helpers_func.cpp helpers_func.hpp
	$(CXX) $(CXXFLAGS) -c helpers_func.cpp -o helpers_func.o

clean:
	rm -f *.o $(EXEC_CREATE) $(EXEC_READ)

run_create: $(EXEC_CREATE)
	./$(EXEC_CREATE)

run_read: $(EXEC_READ)
	./$(EXEC_READ)