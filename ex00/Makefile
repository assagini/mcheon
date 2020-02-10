# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungtlee <jungtlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 09:01:07 by jungtlee          #+#    #+#              #
#    Updated: 2020/02/09 21:19:00 by jungtlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	= rush-02
KTARGET	= rush-02k
SRCS	= main.c divide_util.c divide.c parse.c solve.c sort.c split.c str_join.c str_util.c free.c parse_util.c
KSRCS	= main.c divide_util.c divide.c parse.c solve_k.c sort.c split.c str_join.c str_util.c free.c parse_util.c

# SRCS에 있는 파일의 확장자 .c를 .o로 바꿈
OBJS	= ${SRCS:.c=.o}
KOBJS	= ${KSRCS:.c=.o}

# 줄임말
WS		= -Wall -Wextra -Werror
INC1	= divide.h
INC2	= rush_header.h

# 최종 파일이 TARGET이다.
all: ${TARGET}

KO:	${KTARGET}

# gcc {-Wall -Wextra -Werror} -c {main.c} -o {main.o} -I {divide.h} -I {rush_header.h}
.c.o:
	gcc ${WS} -c $< -o ${<:.c=.o} -I ${INC1} -I ${INC2}

# 오른쪽이 최신이 아니면 > .c.o > 아래 명령(rush_02를 만든다.)
${TARGET}: ${OBJS}
	gcc ${WS} ${OBJS} -o ${TARGET}

${KTARGET}: ${KOBJS}
	gcc ${WS} ${KOBJS} -o ${KTARGET}

# /bin/rm -f {main.o divide_util.o divide.o parse.o solve.o sort.o split.o str_join.o str_util.o free.o parse_util.o} solve_k.o
clean:
	/bin/rm -f ${OBJS} solve_k.o

# /bin/rm -f {rush-02} {rush-02k}
fclean: clean
	/bin/rm -f ${TARGET} rush-02k

re: fclean all