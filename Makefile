NAME	= so_long
LIBMLX	= ./MLX42
LIBFT	= ./libft
HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT}
LIBS	= ${LIBMLX}/build/libmlx42.a ${LIBFT}/libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS	= -ldl -lglfw -pthread -lm

SRC = main.c \
		init_move.c \
		init_data.c \
		init_imgs.c \
		map.c \
		game_status.c \
		map_access.c \
		validate_map.c \
		validate_move.c \
		file_utils.c

OBJS = $(SRC:.c=.o)

all: libft libmlx $(NAME)

libft:
	$(MAKE) -C $(LIBFT)

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi
	@if [ ! -d "$(LIBMLX)/build" ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	rm -rf $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re libmlx libft
