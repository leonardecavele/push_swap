# structure
NAME = push_swap
BONUS_NAME = checker
CC = cc
INCDIR = includes
BUILD = build

# flags
CFLAGS = -MMD -MP -Wall -Wextra -Werror -I $(INCDIR)
MAKEFLAGS+= -j $$(nproc)

# files
SRCS =\

OBJS = $(SRCS:%.c=$(BUILD)/%.o)
DEPS = $(OBJS:.o=.d)

# rules
all: $(NAME) $(BONUS_NAME)

$(NAME):
	@mkdir -p $(BUILD)/$(NAME)
	@$(MAKE) build --no-print-directory

$(BONUS_NAME):
	@mkdir -p $(BUILD)/$(BONUS_NAME)
	@$(MAKE) build SRCS="$(BSRCS)" NAME="$(BONUS_NAME)" --no-print-directory

build: $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(BUILD)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean
	@$(MAKE) all --no-print-directory

# miscellaneous
.PHONY: all bonus clean fclean re
-include $(DEPS)
