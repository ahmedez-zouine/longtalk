# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 12:00:09 by aez-zoui          #+#    #+#              #
#    Updated: 2024/05/12 12:17:13 by aez-zoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror
GCC= gcc
RM= rm -rf
SERVER= server
CLIENT= client

CSR= Helper.c client.c
SSR= Helper.c server.c

all: $(SERVER) $(CLIENT)

$(SERVER) : $(SSR)
	$(GCC) $(FLAGS) $(SSR) -o server

$(CLIENT): $(CSR)
	$(GCC) $(FLAGS) $(CSR) -o client

clean:
	$(RM) $(SERVER) $(CLIENT)

