# Nombre del compilador
CXX = g++

# Opciones del compilador
CXXFLAGS = -std=c++11 -Wall -Wextra

# Archivos fuente del proyecto principal
SRC_MAIN = ejemploUso.cpp practica.cpp

# Archivos fuente de las pruebas
SRC_TEST = tests/test_practica.cpp practica.cpp

# Archivos objeto del proyecto principal
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)

# Archivos objeto de las pruebas
OBJ_TEST = $(SRC_TEST:.cpp=.o)

# Nombre del ejecutable del proyecto principal
TARGET_MAIN = ejemploUso

# Nombre del ejecutable de las pruebas
TARGET_TEST = testsPractica

# Directorio de datos
DATA_DIR = data

# Reglas para compilar el proyecto principal
all: $(TARGET_MAIN)
	@echo "Programa compilado"
	@echo "Pruebe con alguno de estos comandos:"
	@echo "   make ejemplo"
	@echo "   make test"

ejemplo: $(TARGET_MAIN)
	./$(TARGET_MAIN)

$(TARGET_MAIN): $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp practica.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reglas para compilar y ejecutar las pruebas
test: $(TARGET_TEST)
	./$(TARGET_TEST)

$(TARGET_TEST): $(OBJ_TEST) 
	$(CXX) $(CXXFLAGS) -o $@ $^

tests/test_practica.o: tests/test_practica.cpp practica.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJ_MAIN) $(TARGET_MAIN) $(OBJ_TEST) $(TARGET_TEST) $(DATA_DIR)/*

.PHONY: all test clean
