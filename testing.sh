# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testing.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troberts <troberts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 11:58:19 by troberts          #+#    #+#              #
#    Updated: 2022/05/11 20:48:28 by troberts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

rm gnl
echo "gnl removed."
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main-test.c -L. -lft -o gnl -g -D BUFFER_SIZE=20
echo "compiling done."

if [ $# -eq 0 ]
  then
	time ./gnl text.txt
    # diff <(./gnl text.txt) text.txt
fi

if [ $# -eq 1 ]
  then
	./gnl $1
    # vimdiff <(./gnl $1) $1
fi

if [ $# -gt 1 ]
  then
    echo "Too many arguments !"
fi