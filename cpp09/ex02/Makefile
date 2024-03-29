# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 11:05:17 by nimai             #+#    #+#              #
#    Updated: 2024/03/11 08:05:59 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=  PmergeMe

LIBS_TARGET	:= 
LIBS		:= 

INCS		:= inc

SRC_DIR		:= src
SRCS		:= main.cpp  PmergeMe.cpp
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98 -pedantic
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))

RM			:= rm -f
RF			:= rm -rf
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#
#   ASCII ART                                    #
#------------------------------------------------#
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

define	ART
$(YELLOW)
        /^-^\         /^-----^\\
       / o o \        V  = =  V
      /   ▼   \        |  ▽  |  
      V \ ∧ / V         \ Q /  
        / - \\ ========= / - \\ 
       /    |   CPP09   |    \\	
      /     |    EX02   |     \\     
 (===/___) || ========= || (___\\====)$(CLR_RMV)
endef
export	ART

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $(NAME))
	@echo "$$ART"

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)
	$(RF) $(BUILD_DIR)
	$(info ELIMINATED $(NAME))

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: all clean fclean re
.SILENT: