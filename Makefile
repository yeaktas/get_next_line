# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 19:44:39 by yaktas            #+#    #+#              #
#    Updated: 2022/03/22 20:38:53 by yaktas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

git: 
	git add .
	git commit -m "$m"
	git push git@github.com:yeaktas/get_next_line.git

.PHONY git