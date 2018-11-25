CC = g++ -std=c++11
#OPT = -O3 -m32
OPT = -g -m32
WARN = -Wall
CFLAGS = $(OPT) $(WARN) $(INC) $(LIB)

# List all your .cc files here (source files, excluding header files)
SIM_SRC = main.cpp
DLL_SRC = doubleLL.cpp

# List corresponding compiled object files here (.o files)
SIM_OBJ = main.o
DLL_OBJ = doubleLL.o
 
#################################

# default rule

all: sim dll
	@echo "my work is done here..."


# rule for making sim

sim: $(SIM_OBJ)
	$(CC) -o sim $(CFLAGS) $(SIM_OBJ) -lm
	@echo "-----------DONE WITH SIM-----------"

# rule for making double LL

dll: $(DLL_OBJ)
	$(CC) -o dll $(CFLAGS) $(DLL_OBJ) -lm
	@echo "-----------DONE WITH DLL-----------"
	

# generic rule for converting any .cc file to any .o file
 
.cc.o:
	$(CC) $(CFLAGS)  -c $*.cc


# type "make clean" to remove all .o files plus the sim binary

clean:
	rm -f *.o sim dll


# type "make clobber" to remove all .o files (leaves sim binary)

clobber:
	rm -f *.o


# Debugging instructions
# >gdb
# >make clean
# >make
# >file sim
#Don't write > ./sim bimodal 7 0 0 ./traces/gcc_trace.txt
#Instead write > r bimodal 7 0 0 ./traces/gcc_trace.txt
# The 'r' above is important
# Then follow up with whatever you need, use commands like, n, s, l, break, etc




