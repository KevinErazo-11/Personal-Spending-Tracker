CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

SRCS = main.cpp Menu.cpp FinanceManager.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = finance_manager.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

clean:
	del /f /q $(OBJS) $(TARGET)

.PHONY: all clean run
