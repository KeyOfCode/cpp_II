################################################################################
#                                     CONFIG                                   #
################################################################################

NAME:= 		iter
CC:= 		c++
FLAGS:= 	-Wall -Wextra -Werror -std=c++98 -g

VALGRIND=	valgrind --leak-check=full --show-leak-kinds=all
VAL_FLAGS=	--child-silent-after-fork=yes \
			--read-inline-info=yes \
			--track-origins=yes --read-var-info=yes \
			--log-file=valgrind.rpt ./val
 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS:=	main.cpp

OBJS:= ${SRCS:.cpp=.o}

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
CURSIVE		= \e[33;3m
RM			:= rm -f

${NAME}:	${OBJS}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	${CC} ${FLAGS} -o ${NAME} ${OBJS}
	@echo "$(GREEN)$(NAME) created ${CLR_RMV} ✔️"

all:		${NAME}

bonus:		all

clean:
	@ ${RM} *.o */*.o */*/*.o
	@ ${RM} *.replace
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
	@ ${RM} ${NAME}
	@$(RM) val
	@$(RM) debug
	@$(RM) valgrind.rpt
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re

exe:
	@make
	./$(NAME)

val: $(OBJS) 
	$(CC) $(FLAGS) -o val $(OBJS)
	$(VALGRIND)  $(VAL_FLAGS)


debug:	${OBJS}
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}debug ${CLR_RMV}..."
	${CC} ${FLAGS} -g -o debug ${OBJS}
	@echo "$(GREEN)$(NAME) created ${CLR_RMV} ✔️"
