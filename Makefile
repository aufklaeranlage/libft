# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 15:21:49 by abronner          #+#    #+#              #
#    Updated: 2026/02/12 16:20:46 by abronner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include colors.mk

NAME		:= libft.a

# * DIRECTORIES ************************************************************** #

SRC_DIR		:= src
SUB_DIR		:= ctype std string split put list gnl
OBJ_DIR		:= obj
INC_DIR		:= include

# * SOURCES & OBJECTS ******************************************************** #

DEPS		:= 

vpath %.c $(SRC_DIR)/ctype
SRC_CTYPE	:= alpha.c
SRC_CTYPE	+= digit.c
SRC_CTYPE	+= alnum.c
SRC_CTYPE	+= graph.c
SRC_CTYPE	+= print.c
SRC_CTYPE	+= special.c
SRC_CTYPE	+= convertchr.c

OBJ_CTYPE	:= $(SRC_CTYPE:.c=.o)
OBJ_CTYPE	:= $(addprefix $(OBJ_DIR)/, $(OBJ_CTYPE))
DEPS		+= $(OBJ_CTYPE:%.o=%.d)

vpath %.c $(SRC_DIR)/std
SRC_STD		:= mem.c
SRC_STD		+= mem_create.c
SRC_STD		+= strtol.c
SRC_STD		+= ltostr.c
SRC_STD		+= convertstr_utils.c
SRC_STD		+= convertstr_wrappers.c

OBJ_STD		:= $(SRC_STD:.c=.o)
OBJ_STD		:= $(addprefix $(OBJ_DIR)/, $(OBJ_STD))
DEPS		+= $(OBJ_STD:%.o=%.d)

vpath %.c $(SRC_DIR)/string
SRC_STRING	:= check.c
SRC_STRING	+= copy.c
SRC_STRING	+= search.c
SRC_STRING	+= create.c
SRC_STRING	+= striter.c

OBJ_STRING	:= $(SRC_STRING:.c=.o)
OBJ_STRING	:= $(addprefix $(OBJ_DIR)/, $(OBJ_STRING))
DEPS		+= $(OBJ_STRING:%.o=%.d)

vpath %.c $(SRC_DIR)/split
SRC_SPLIT	:= split.c

OBJ_SPLIT	:= $(SRC_SPLIT:.c=.o)
OBJ_SPLIT	:= $(addprefix $(OBJ_DIR)/, $(OBJ_SPLIT))
DEPS		+= $(OBJ_SPLIT:%.o=%.d)

vpath %.c $(SRC_DIR)/put
SRC_PUT		:= putstr.c
SRC_PUT		+= putnbr.c

OBJ_PUT		:= $(SRC_PUT:.c=.o)
OBJ_PUT		:= $(addprefix $(OBJ_DIR)/, $(OBJ_PUT))
DEPS		+= $(OBJ_PUT:%.o=%.d)

vpath %.c $(SRC_DIR)/list
SRC_LIST	:= listnew.c
SRC_LIST	+= listutils.c
SRC_LIST	+= listdel.c
SRC_LIST	+= stack.c
SRC_LIST	+= queue.c

OBJ_LIST	:= $(SRC_LIST:.c=.o)
OBJ_LIST	:= $(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
DEPS		+= $(OBJ_LIST:%.o=%.d)

vpath %.c $(SRC_DIR)/gnl
SRC_GNL		:= get_next_line.c
SRC_GNL		+= get_next_line_utils.c

OBJ_GNL		:= $(SRC_GNL:.c=.o)
OBJ_GNL		:= $(addprefix $(OBJ_DIR)/, $(OBJ_GNL))

vpath %.c $(SRC_DIR)/scratch
SRC_SCRATCH	:= scratch_buffer.c

OBJ_SCRATCH	:= $(SRC_SCRATCH:.c=.o)
OBJ_SCRATCH	:= $(addprefix $(OBJ_DIR)/, $(OBJ_SCRATCH))

DEPS		+= $(OBJ_GNL:%.o=%.d)

# * MISC ********************************************************************* #

DOTFILES	:= .ctype .std .string .split .put .list .gnl .scratch

# * COMMANDS ***************************************************************** #

CC			:= cc
LD			:= cc
RM			:= rm -rf
AR			:= ar
PRNT		:= printf

# * FLAGS ******************************************************************** #

CFLAGS		?=	-Wall -Wextra -Werror

CPPFLAGS	:=
CPPFLAGS	+= -MMD -MP
CPPFLAGS	+= $(addprefix -I, $(INC_DIR))

LDFLAGS		:=

ifneq "$(or $(DEBUG), $(or $(UB), $(or $(ASAN), $(LSAN))))" ""
	CFLAGS += -O0
	CFLAGS += -g3
else
	CFLAGS += -O3
endif

ifeq ($(UB), 1)
	CFLAGS += -fsanitize=undefined
	LDFLAGS += -fsanitize=undefined
endif

ifeq ($(ASAN), 1)
	CFLAGS += -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

ifeq ($(LSAN), 1)
	CFLAGS += -fsanitize=leak
	LDFLAGS += -fsanitize=leak
endif

# * RULES ******************************************************************** #

all: $(NAME)

ctype: .ctype

.ctype: $(OBJ_DIR) $(OBJ_CTYPE)
	@touch .ctype
	@$(AR) rcs $(NAME) $(OBJ_CTYPE)
	@$(PRNT) "Adding $(P_CTYPE) files to $(P_NAME).\n"

std: .std

.std: $(OBJ_DIR) ctype $(OBJ_STD)
	@touch .std
	@ar rcs $(NAME) $(OBJ_STD)
	@$(PRNT) "Adding $(P_STD) files to $(P_NAME).\n"

string: .string

.string: $(OBJ_DIR) std $(OBJ_STRING)
	@touch .string
	@ar rcs $(NAME) $(OBJ_STRING)
	@$(PRNT) "Adding $(P_STRING) files to $(P_NAME).\n"

split: .split

.split: $(OBJ_DIR) string $(OBJ_SPLIT)
	@touch .split
	@ar rcs $(NAME) $(OBJ_SPLIT)
	@$(PRNT) "Adding $(P_SPLIT) files to $(P_NAME).\n"

put: .put

.put: $(OBJ_DIR) string $(OBJ_PUT)
	@ar rcs $(NAME) $(OBJ_PUT)
	@$(PRNT) "Adding $(P_PUT) files to $(P_NAME).\n"

list: .list

.list: $(OBJ_DIR) $(OBJ_LIST)
	@ar rcs $(NAME) $(OBJ_LIST)
	@$(PRNT) "Adding $(P_LIST) files to $(P_NAME).\n"

gnl: .gnl

.gnl: $(OBJ_DIR) list string $(OBJ_GNL)
	@touch .gnl
	@ar rcs $(NAME) $(OBJ_GNL)
	@$(PRNT) "Adding $(P_GNL) files to $(P_NAME).\n"

scratch: .scratch

.scratch: $(OBJ_DIR) std $(OBJ_SCRATCH)
	@touch .scratch
	@ar rcs $(NAME) $(OBJ_SCRATCH)
	@$(PRNT) "Adding $(P_SCRATCH) files to $(P_NAME).\n"

$(NAME): p_name

p_name: ctype std string split put list gnl
	@$(PRNT) "Creating library $(P_NAME).\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@$(PRNT) "Creating $(P_ODIR) directory.\n"

$(OBJ_DIR)/%.o: %.c 
	@$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@
	@$(PRNT) "Compiling $(P_AT).\n"

-include $(DEPS)

re: fclean all

clean:
	@$(RM) $(OBJ_DIR) $(DOTFILES)
	@$(PRNT) "Deleting object files for $(P_NAME).\n"

fclean: clean
	@$(RM) $(NAME)
	@$(PRNT) "Deleting library $(P_NAME).\n"

.PHONY: all bonus re clean fclean make \
	ctype std string split stack gnl sctach

# * PRINTING PRESETS ********************************************************************** #

P_NAME=$(C_RED)$(BLD)$(NAME)$(RESET)

P_ODIR=$(C_BLU)$(BLD)$(OBJ_DIR)$(RESET)

P_FLAG=$(C_MAG)$(BLD)-g$(RESET)

P_CTYPE=$(C_YLW)$(BLD)ctype$(RESET)

P_STD=$(C_YLW)$(BLD)std$(RESET)

P_STRING=$(C_YLW)$(BLD)string$(RESET)

P_SPLIT=$(C_YLW)$(BLD)split$(RESET)

P_PUT=$(C_YLW)$(BLD)put$(RESET)

P_LIST=$(C_YLW)$(BLD)list$(RESET)

P_GNL=$(C_YLW)$(BLD)gnl$(RESET)

P_SCRATCH=$(C_YLW)$(BLD)scratch$(RESET)

P_AT=$(C_GRN)$(BLD)$@$(RESET)
