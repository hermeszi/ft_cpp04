# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 14:53:29 by myuen             #+#    #+#              #
#    Updated: 2025/08/05 18:52:08 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -g -MMD -MP -pedantic 

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/main.cpp \
	   $(SRC_DIR)/Animal.cpp \
	   $(SRC_DIR)/Dog.cpp \
	   $(SRC_DIR)/Cat.cpp \
	   $(SRC_DIR)/WrongAnimal.cpp \
	   $(SRC_DIR)/WrongCat.cpp \
	   $(SRC_DIR)/Brain.cpp

# Object files and dependencies
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Default target to build the executable
all: $(NAME)

# Build the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile each .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependencies
-include $(DEPS)

# Clean up object files and dependencies
clean:
	rm -rf $(OBJ_DIR) $(DEPS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re