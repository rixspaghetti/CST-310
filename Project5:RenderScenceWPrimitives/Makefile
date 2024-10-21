# Compiler and flags
CXX = /opt/homebrew/bin/g++-14
CXXFLAGS = -std=c++11 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lglfw -framework OpenGL -framework GLUT -lGLEW

# Target executable
TARGET = ./lobby

# Source file
SRCS = ./lobby.cpp

# Build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Clean up object files and the executable
clean:
	rm -f $(TARGET)

# Run the executable
run: clean $(TARGET)
	$(TARGET)
