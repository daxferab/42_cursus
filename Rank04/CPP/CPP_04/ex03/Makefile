NAME = interfaces

CXX= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = obj
INC_DIR = inc
SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR),\
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		Icharacter.cpp \
		IMateriaSource.cpp \
		MateriaSource.cpp \
		main.cpp \
		)

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean
