# PROJECT NAME
NAME = so_long

# DIRECTORIES
SRC_DIR = src
INCLUDES = includes
MLX42_DIR = $(SRC_DIR)/MLX42
MLX_INCLUDES = $(MLX42_DIR)/include
HEADERS = $(INCLUDES) $(MLX_INCLUDES)
LIBS = $(MLX42_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJ_DIR = objs
LIBFT_DIR = $(SRC_DIR)/libft
FT_PRINTF_DIR = $(SRC_DIR)/ft_printf
GNL_DIR = $(SRC_DIR)/get_next_line
SO_LONG_DIR = $(SRC_DIR)/so_long

# SOURCE FILES
LIBFT_FLS = $(LIBFT_DIR)/ft_calloc.c \
			$(LIBFT_DIR)/ft_strlen.c \
			$(LIBFT_DIR)/ft_strdup.c \
			$(LIBFT_DIR)/ft_memset.c \
			$(LIBFT_DIR)/ft_bzero.c \
			$(LIBFT_DIR)/ft_memcpy.c \
			$(LIBFT_DIR)/ft_memmove.c \
			$(LIBFT_DIR)/ft_memchr.c \
			$(LIBFT_DIR)/ft_memcmp.c \
			$(LIBFT_DIR)/ft_strchr.c \
			$(LIBFT_DIR)/ft_strrchr.c \
			$(LIBFT_DIR)/ft_strnstr.c \
			$(LIBFT_DIR)/ft_strncmp.c \
			$(LIBFT_DIR)/ft_atoi.c \
			$(LIBFT_DIR)/ft_isdigit.c \
			$(LIBFT_DIR)/ft_isalpha.c \
			$(LIBFT_DIR)/ft_isalnum.c \
			$(LIBFT_DIR)/ft_isascii.c \
			$(LIBFT_DIR)/ft_isprint.c \
			$(LIBFT_DIR)/ft_toupper.c \
			$(LIBFT_DIR)/ft_tolower.c \
			$(LIBFT_DIR)/ft_striteri.c \
			$(LIBFT_DIR)/ft_strmapi.c \
			$(LIBFT_DIR)/ft_substr.c \
			$(LIBFT_DIR)/ft_strjoin.c \
			$(LIBFT_DIR)/ft_strtrim.c \
			$(LIBFT_DIR)/ft_lstadd_back.c \
			$(LIBFT_DIR)/ft_putendl_fd.c \
			$(LIBFT_DIR)/ft_lstadd_front.c \
			$(LIBFT_DIR)/ft_lstdelone.c \
			$(LIBFT_DIR)/ft_split.c \
			$(LIBFT_DIR)/ft_lstclear.c \
			$(LIBFT_DIR)/ft_lstlast.c \
			$(LIBFT_DIR)/ft_lstsize.c \
			$(LIBFT_DIR)/ft_putstr.c \
			$(LIBFT_DIR)/ft_free_split.c


FT_PRINTF_FLS = $(FT_PRINTF_DIR)/ft_itoalen.c \
				$(FT_PRINTF_DIR)/ft_printf.c \
				$(FT_PRINTF_DIR)/ft_utoa.c \
				$(FT_PRINTF_DIR)/ft_write_chr.c \
				$(FT_PRINTF_DIR)/ft_write_hex.c \
				$(FT_PRINTF_DIR)/ft_write_nbrs.c \
				$(FT_PRINTF_DIR)/ft_write_ptr.c

GNL_FLS = $(GNL_DIR)/get_next_line.c \

SO_LONG_FLS = $(SO_LONG_DIR)/main.c \
				$(SO_LONG_DIR)/init_move.c \
				$(SO_LONG_DIR)/init_setup.c \
				$(SO_LONG_DIR)/init_imgs.c \
				$(SO_LONG_DIR)/map.c \
				$(SO_LONG_DIR)/game_status.c \
				$(SO_LONG_DIR)/map_access.c \
				$(SO_LONG_DIR)/validate_map.c \
				$(SO_LONG_DIR)/validate_move.c \
				$(SO_LONG_DIR)/utils.c \


# ALL SOURCE FILES
SRC_FILES = $(LIBFT_FLS) $(FT_PRINTF_FLS) $(GNL_FLS) $(SO_LONG_FLS)

# OBJS FILES
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# DEPENDENCIES
DEPS = $(OBJS:.o=.d)

# FLAGS
CC = cc
RM = rm -rf
CFLGS = -Wall -Werror -Wextra
IFLGS = -I$(INCLUDES) -I$(MLX_INCLUDES)

# RULES
.PHONY: all clean fclean re

# Default target
all: libmlx $(NAME)

libmlx:
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && make -C $(MLX42_DIR)/build -j4

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

# Create the executable
$(NAME): $(OBJS)
	$(CC) $(CFLGS) -o $(NAME) $(OBJS) $(IFLGS) $(LIBS)

# Clean object files
clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(MLX42_DIR)/build

# Clean everything (object files and executable)
fclean: clean
	$(RM) $(NAME)

# Rebuild the project
re: fclean all

# Include dependencies
-include $(DEPS)
