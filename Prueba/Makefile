# Definir el compilador
CXX=g++

# Definir las banderas de compilación
CXXFLAGS=-std=c++11

# Definir el nombre del ejecutable
TARGET=pruebaPrograma

# Definir los directorios de los archivos fuente
SRC_DIR=.
ARCHIVO1_DIR=Archivo1
ARCHIVO2_DIR=Archivo2

# Definir los archivos objeto
OBJS=$(SRC_DIR)/main.o $(ARCHIVO1_DIR)/math_utils.o $(ARCHIVO2_DIR)/text_utils.o

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Cómo construir main.o
$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp $(ARCHIVO1_DIR)/math_utils.h $(ARCHIVO2_DIR)/text_utils.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o

# Cómo construir math_utils.o
$(ARCHIVO1_DIR)/math_utils.o: $(ARCHIVO1_DIR)/math_utils.cpp $(ARCHIVO1_DIR)/math_utils.h
	$(CXX) $(CXXFLAGS) -c $(ARCHIVO1_DIR)/math_utils.cpp -o $(ARCHIVO1_DIR)/math_utils.o

# Cómo construir text_utils.o
$(ARCHIVO2_DIR)/text_utils.o: $(ARCHIVO2_DIR)/text_utils.cpp $(ARCHIVO2_DIR)/text_utils.h
	$(CXX) $(CXXFLAGS) -c $(ARCHIVO2_DIR)/text_utils.cpp -o $(ARCHIVO2_DIR)/text_utils.o

# Limpia el proyecto
clean:
	rm -f $(TARGET) $(OBJS)
