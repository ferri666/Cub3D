#Program name
NAME	= cub3d
BONUS	= cub3d_bonus

#FOLDERS PATH
SRCS_DIR	= src/
OBJ_DIR		= obj/
INC_DIR		= includes/
BONUS_DIR	= bonus/
B_OBJ_DIR	= bonus/obj/

UNAME 		= $(shell uname)

#MLX FOR LINUX && MAC
ifeq ($(UNAME), Darwin)
	MLX_DIR = ./minilibx
else
	MLX_DIR = ./minilibx-linux
endif

ifeq ($(UNAME), Darwin)
	MFLAGS = -ldl -lmlx -L${MLX_DIR} -framework OpenGL -framework AppKit -lz
else
	MFLAGS = -L ${MLX_DIR} -lmlx -lXext -lX11 -lm -lbsd
endif

MLX_PATH = ${MLX_DIR}/libmlx.a

#HEADERS
INC = 	cub3d.h

#SRC

SRC_FILES = main utils game raycast init ceiling_and_floor error_exit\
			map_2 map_utils parse player vtextures
MAIN_FILES = gun hooks move textures map_1 images
BONUS_FILES = door gun_bonus hooks_bonus minimap move_bonus textures_bonus parse_map_bonus \
			images_bonus

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
BONUS_SRC	= $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
OBJS1 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJS2 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(MAIN_FILES)))
B_S_OBJ		= $(addprefix $(B_OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_OBJS		= $(addprefix $(B_OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))
INCLUDES	= $(addprefix $(INC_DIR), $(INC))

#LIBft
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a
LIBFT_FILES = ${LIBFT_DIR}/*.c


#COMPILE

GCC = gcc
CFLAGS =   -I $(INC_DIR) -Wall -Werror -Wextra #-g3 -fsanitize=address 
LFLAGS:= -L $(LIBFT_DIR) -lft
RM = rm -f

$(NAME): $(LIBFT_PATH) $(OBJS1) $(OBJS2) $(MLX_PATH)
	@$(GCC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS) $^
	@echo  "[🕋 FINISHED OK]"

$(BONUS): $(LIBFT_PATH) $(B_OBJS) $(B_S_OBJ)
	@$(GCC) $(CFLAGS) $(LFLAGS) -o $(BONUS) $(MFLAGS) $^
	@echo  "[🕋 BONUS OK]"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(GCC) $(CFLAGS) -o $@ -c $^

$(B_OBJ_DIR)%.o: $(SRCS_DIR)%.c
				@mkdir -p $(B_OBJ_DIR)
				@$(GCC) $(CFLAGS) -o $@ -c $^

$(B_OBJ_DIR)%.o: $(BONUS_DIR)%.c
				@mkdir -p $(B_OBJ_DIR)
				@$(GCC) $(CFLAGS) -o $@ -c $^

$(LIBFT_PATH): $(LIBFT_FILES)
		@cd $(LIBFT_DIR) && $(MAKE)

$(MLX_PATH):
		@make -C $(MLX_DIR)

all: $(NAME) bonus


bonus: $(BONUS)

clean:
	@${RM} ${OBJS}
	@${RM} -r ${OBJ_DIR}
	@${RM} -r ${B_OBJ_DIR}
	@make -C ${LIBFT_DIR} clean
	@make -C ${MLX_DIR} clean

fclean: clean
	@${RM} ${NAME}
	@${RM} ${BONUS}
	@make -C ${LIBFT_DIR} fclean

norm:          
		@norminette $(BONUS_DIR) $(LIBFT_DIR) $(INC_DIR) $(SRCS_DIR) | grep -v "OK" || echo "\033[0;34m\n==> \033[0;36mNo norm errors!!\033[0m 🆗🆗🆗\n"

re: fclean all

.PHONY: all bonus clean fclean norm re
