TARGET = LIFX

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

SRC_EXT = cc
OBJ_EXT = o

SOURCES = $(shell find $(SRC_DIR) -type f)
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.$(SRC_EXT)=.$(OBJ_EXT)))

CXXFLAGS = -Wall -Wfatal-errors

INC = -I$(INC_DIR)
LIBS = -lcurl

.PHONY: clean mrproper

default: $(TARGET)

$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $(BIN_DIR)/$(TARGET) $^ $(LIBS)

clean:
	@$(RM) -rf $(BIN_DIR)

mrproper:
	@$(RM) -rf $(BIN_DIR) $(OBJ_DIR)
