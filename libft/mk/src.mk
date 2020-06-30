# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 04:34:13 by nicolasv          #+#    #+#              #
#    Updated: 2019/10/09 07:58:14 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MATH =					ft_sqrt.c\
							ft_power.c\
							ft_is_prime.c\
							ft_find_next_prime.c\
							ft_factorial.c

SRC_MATH := $(addprefix math/, $(SRC_MATH))
OBJ_MATH := $(addprefix math/, $(addsuffix .o, $(basename $(notdir $(SRC_MATH)))))

SRC_STRING =				ft_atoi.c\
							ft_atol.c\
							ft_itoa.c\
							ft_isalnum.c\
							ft_isalpha.c\
							ft_isascii.c\
							ft_isdigit.c\
							ft_isprint.c\
							ft_strncat.c\
							ft_strrchr.c\
							ft_strchr.c\
							ft_strcpy.c\
							ft_strdup.c\
							ft_strequ.c\
							ft_striter.c\
							ft_striteri.c\
							ft_strlen.c\
							ft_strmap.c\
							ft_strmapi.c\
							ft_strcat.c\
							ft_strcmp.c\
							ft_strncpy.c\
							ft_strnequ.c\
							ft_strnstr.c\
							ft_strstr.c\
							ft_strncmp.c\
							ft_strlcat.c\
							ft_strnew.c\
							ft_strdel.c\
							ft_strclr.c\
							ft_strsub.c\
							ft_strjoin.c\
							ft_strnjoinf.c\
							ft_strtrim.c\
							ft_strsplit.c\
							ft_tolower.c\
							ft_toupper.c

SRC_STRING := $(addprefix string/, $(SRC_STRING))
OBJ_STRING := $(addprefix string/, $(addsuffix .o, $(basename $(notdir $(SRC_STRING)))))

SRC_MEMORY =				ft_bzero.c\
							ft_memset.c\
							ft_memcpy.c\
							ft_memccpy.c\
							ft_memmove.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_memalloc.c\
							ft_memdel.c\
							ft_swap.c\
							ft_swap_int.c\
							ft_realloctab.c
		
SRC_MEMORY := $(addprefix memory/, $(SRC_MEMORY))
OBJ_MEMORY := $(addprefix memory/, $(addsuffix .o, $(basename $(notdir $(SRC_MEMORY)))))

SRC_LIST =					ft_lstnew.c\
							ft_lstdelone.c\
							ft_lstdel.c\
							ft_lstadd.c\
							ft_lstiter.c\
							ft_lstmap.c

SRC_LIST := $(addprefix list/, $(SRC_LIST))
OBJ_LIST := $(addprefix list/, $(addsuffix .o, $(basename $(notdir $(SRC_LIST)))))

SRC_WRITE = 				ft_putchar.c\
							ft_putchar_fd.c\
							ft_putendl.c\
							ft_putendl_fd.c\
							ft_putnbr.c\
							ft_putnbr_fd.c\
							ft_putstr.c\
							ft_putstr_fd.c

SRC_WRITE := $(addprefix write/, $(SRC_WRITE))
OBJ_WRITE := $(addprefix write/, $(addsuffix .o, $(basename $(notdir $(SRC_WRITE)))))

SRC_READ =					get_next_line.c\
							old_gnl

SRC_READ := $(addprefix read/, $(SRC_READ))
OBJ_READ := $(addprefix read/, $(addsuffix .o, $(basename $(notdir $(SRC_READ)))))

SRC_PRINTF =				ft_printf.c\
							parse.c\
							else.c\
							print_per.c\
							print_b.c\
							print_c.c\
							print_s.c\
							print_p.c\
							print_i.c\
							print_o.c\
							print_u.c\
							print_x.c\
							print_f.c\
							print_ff.c\
							width_csp.c\
							width_dioux.c\
							convert_base.c

SRC_PRINTF := $(addprefix ft_printf/, $(SRC_PRINTF))
OBJ_PRINTF := $(addprefix ft_printf/, $(addsuffix .o, $(basename $(notdir $(SRC_PRINTF)))))

SRC_TIME =				time_exe.c\
						print_time.c\
						extra_func.c\

SRC_TIME := $(addprefix time/, $(SRC_TIME))
OBJ_TIME := $(addprefix time/, $(addsuffix .o, $(basename $(notdir $(SRC_TIME)))))

SRC_LIBFT := $(addprefix $(SRC_PATH), $(SRC_MATH))
SRC_LIBFT += $(addprefix $(SRC_PATH), $(SRC_STRING))
SRC_LIBFT += $(addprefix $(SRC_PATH), $(SRC_MEMORY))
SRC_LIBFT += $(addprefix $(SRC_PATH), $(SRC_LIST))
SRC_LIBFT += $(addprefix $(SRC_PATH), $(SRC_WRITE))
SRC_LIBFT += $(addprefix $(SRC_PATH), $(SRC_READ))
SRC_LIBFT += $(addprefix $(SRC_PATH), $(SRC_PRINTF))
SRC_LIBFT += $(addprefix $(SRC_PATH), $(SRC_TIME))

OBJ_LIBFT := $(addprefix $(OBJ_PATH), $(OBJ_MATH))
OBJ_LIBFT += $(addprefix $(OBJ_PATH), $(OBJ_STRING))
OBJ_LIBFT += $(addprefix $(OBJ_PATH), $(OBJ_MEMORY))
OBJ_LIBFT += $(addprefix $(OBJ_PATH), $(OBJ_LIST))
OBJ_LIBFT += $(addprefix $(OBJ_PATH), $(OBJ_WRITE))
OBJ_LIBFT += $(addprefix $(OBJ_PATH), $(OBJ_READ))
OBJ_LIBFT += $(addprefix $(OBJ_PATH), $(OBJ_PRINTF))
OBJ_LIBFT += $(addprefix $(OBJ_PATH), $(OBJ_TIME))
