NAME = Webserv

CC = c++

FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
		ServerBlock.cpp \
		parsingConfigFile.cpp \
		parser.cpp \
		split_line_to_tokens.cpp \
		split_token_with_del.cpp \
		checkForAcoladeLocation.cpp \
		checkForAcoladeServ.cpp \
		find_del.cpp \
		LocationBlock.cpp\



all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm $(NAME)
	
re: clean all