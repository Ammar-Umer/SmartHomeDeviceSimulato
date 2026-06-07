# Makefile for Smart Home Device Simulator
# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17 -I./Include
# Target executable name
TARGET = SmartHomeSimulator.exe
# Source files
SRCS = Src/main.cpp \
       Src/SmartDevice.cpp \
       Src/SmartLight.cpp \
       Src/Thermostat.cpp \
       Src/SecurityCamera.cpp \
       Src/SmartAppliance.cpp \
       Src/SmartLock.cpp \
       Src/SmartSpeaker.cpp \
       Src/Room.cpp \
       Src/SmartHome.cpp \
       Src/Automation.cpp \
       Src/EnergyLog.cpp \
       Src/UserAuthentication.cpp \
       Src/menu.cpp

# Default target: build the executable
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean up build artifacts
clean:
	if exist $(TARGET) del $(TARGET)
