# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 11:05:17 by nimai             #+#    #+#              #
#    Updated: 2023/07/28 11:57:12 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= BraiiiiiiinnnzzzZ...

LIBS_TARGET	:= 
LIBS		:= 

INCS		:= inc

SRC_DIR		:= src
SRCS		:= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -pedantic -std=c++98
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
       /^-^\        "/^-----^\\"
      / o o \       "V  @ @  V"
     /   ▼   \       "|  ▽  |" BraiiiiiiinnnzzzZ...
     V \ ∧ / V        "\ Q / "
       / - \\ ========= / - \\
      /    |   CPP01   |    \\
("   /     |    EX00   |     \\     )"
 ===/___) || ========= || (___\\====$(CLR_RMV)
endef
export	ART

all: $(NAME)

$(NAME): $(OBJS) #$(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(MFLAGS) -o $(NAME)
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
#	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
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

.PHONY: clean fclean re
.SILENT: