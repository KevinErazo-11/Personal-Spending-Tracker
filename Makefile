<<<<<<< HEAD
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

SRCS = main.cpp Menu.cpp FinanceManager.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = finance_manager.exe
=======
TARGET = FinanceManager

SRCS = main.cpp Menu.cpp FinanceManager.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

PYTHON_SCRIPT = show_balance.py
CSV_FILE = balance_data.csv
>>>>>>> a77ca22 (Update)

all: $(TARGET)

$(TARGET): $(OBJS)
<<<<<<< HEAD
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
=======
	$(CXX) $(CXXFLAGS) -o $@ $^
>>>>>>> a77ca22 (Update)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
<<<<<<< HEAD
	$(TARGET)

clean:
	del /f /q $(OBJS) $(TARGET)

.PHONY: all clean run
=======
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o $(CSV_FILE)


plot: $(CSV_FILE)
	python $(PYTHON_SCRIPT) $(CSV_FILE)

.PHONY: all clean run plot
>>>>>>> a77ca22 (Update)
