# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 12:00:09 by aez-zoui          #+#    #+#              #
#    Updated: 2024/05/13 23:09:32 by aez-zoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror
GCC= gcc
RM= rm -rf
SERVER= server
CLIENT= client
B_CLIENT= client_bonus
B_SERVER= server_bonus

CSR= Helper.c client.c
SSR= Helper.c server.c
B_SSR= Helper.c server_bonus.c
B_CL= Helper.c client_bonus.c


all: $(SERVER) $(CLIENT)

$(SERVER): $(SSR)
	$(GCC) $(FLAGS) $(SSR) -o server

$(CLIENT): $(CSR)
	$(GCC) $(FLAGS) $(CSR) -o client

bonus: $(B_CLIENT) $(B_SERVER)

$(B_CLIENT): $(B_CL)
	$(GCC) $(FLAGS) $(B_CL) -o client_bonus

$(B_SERVER): $(B_SSR)
	$(GCC) $(FLAGS) $(B_SSR) -o server_bonus
clean:
	$(RM) $(SERVER) $(CLIENT)

