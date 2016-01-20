# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/24 15:59:47 by zhasni            #+#    #+#              #
#    Updated: 2015/02/27 16:25:46 by zhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NNAME = fts
INCLUDE = includes/
SRCPATH = ./srcs/
CFLAGS = -O3 -Wall -Werror -Wextra -g
C = \033[1;34m
SRCS =	ft_isascii.s \
		ft_isalpha.s \
		ft_isdigit.s \
		ft_isalnum.s \
		ft_isprint.s \
		ft_toupper.s \
		ft_tolower.s \
		ft_bzero.s \
		ft_strlen.s \
		ft_puts.s \
		ft_strcat.s \
		ft_memset.s \
		ft_memcpy.s \
		ft_strdup.s \
		ft_cat.s \
		ft_putchar.s \
		ft_putstr.s \
		ft_putchar_fd.s \
		ft_putstr_fd.s \
		ft_putendl.s \
		ft_putendl_fd.s \
		ft_isupper.s \
		ft_islower.s \
		ft_isblank.s \
		ft_iscntrl.s \
		ft_isgraph.s \
		ft_isspace.s \
		ft_isxdigit.s \
		ft_ispunct.s


NAME = lib$(NNAME).a
CLNAME = l$(NNAME)
V = 0
SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rc
RM = $(SILENCE)rm -rf
SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRC:.s=.o)
SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME):$(OBJS)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

%.o: %.s
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	~/.brew/bin/nasm -f macho64 -g $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"
test: re
#	sh tests/testputs.sh
	gcc ./tests/generic.c libfts.a -I .
	./a.out 7832738

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean
