CXX = g++

CXXFLAGS = -g -Wall -std=c++11
OBJFILES = main.o Sorts.o Utilities.o
OUTFILES = out_MergeSort.txt out_QuickSort.txt
TARGET = CS317Sorting

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES)
	rm $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) $(OUTFILES)
