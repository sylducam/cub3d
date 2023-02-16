GREEN        		=    \033[32m

NAME				=	libcub3d.a
EXE					=	cub3d
LIBFT				=	libft.a
MLXDL				=	libmlx.dylib

LIBS				=	libft.a\
						libmlx.dylib\
						libcub3d.a

VLIBFT				=	libft/
VMLX				=	srcs/mlx/

SRCS_PATH			=	srcs
SRCS_FILE			=	main.c										\
						parsing/error_manager.c						\
						parsing/parse_id.c							\
						parsing/parsing_textures/textures.c			\
						parsing/parsing_textures/north_texture.c	\
						parsing/parsing_textures/south_texture.c	\
						parsing/parsing_textures/east_texture.c		\
						parsing/parsing_textures/west_texture.c		\
						parsing/colors/floor.c						\
						parsing/colors/ceiling.c					\
						parsing/map/parse_map.c						\
						parsing/map/store_map.c						\
						parsing/map/square_map.c					\
						parsing/map/check_map.c						\
						graphic/start_engine.c						\
						graphic/dda.c								\
						graphic/step.c								\
						graphic/draw_color.c						\
						graphic/key.c								\
						graphic/texture.c							\
						graphic/key_draw.c							\
						graphic/init_raycast.c						\
						graphic/utils_graphic.c
						
SRCS				=	$(addprefix $(SRCS_PATH)/, $(SRCS_FILE))

DIR					=	parsing						\
						parsing/parsing_textures	\
						parsing/colors				\
						parsing/map					\
						graphic						

OBJ_PATH			=	.obj
OBJS_FILES			=	$(SRCS_FILE:%.c=%.o)
OBJS				=	$(addprefix $(OBJ_PATH)/, $(OBJS_FILES))

INC_PATH			=	includes
INC					=	$(INC_PATH)/cub3d.h

COMP				=	clang -Wall -Wextra -Werror

RM					=	rm -rf

$(OBJ_PATH)/%.o		:	$(SRCS_PATH)/%.c $(INC)
						mkdir -p $(OBJ_PATH) $(addprefix $(OBJ_PATH)/, $(DIR))
						$(COMP) -I$(INC_PATH) -c $< -o $@

all					:	libs $(NAME) $(EXE)	

libs				:	
						$(MAKE) -C $(VLIBFT)
						ln -sf $(VLIBFT)$(LIBFT) .
						$(MAKE) -C $(VMLX)
						ln -sf $(VMLX)$(MLXDL) .

$(NAME)				:	$(OBJS)
						ar rcs $(NAME) $(OBJS)

$(EXE)				:	$(OBJS) $(LIBS)
						$(COMP) $(LIBS) -o $(EXE) -I$(INC_PATH)

clean				:
						$(RM) $(OBJ_PATH)
						$(MAKE) clean -C $(VLIBFT)
						$(MAKE) clean -C $(VMLX)

fclean				:	clean
						$(RM) $(LIBS) $(EXE)
						$(MAKE) fclean -C $(VLIBFT)
						$(MAKE) clean -C $(VMLX)

re					: 	fclean all

norm				:	
						@printf "$(RED)"
						@(norminette $(SRCS) $(INC) | grep "Error") || printf "$(BOLD)$(GREEN)Norminette $(EXE)\t[OK]\n"
						@printf "$(END)"

.PHONY: all libs clean fclean re libraries norm
