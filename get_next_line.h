/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:02:26 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/22 02:29:55 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char		*get_next_line(int fd);
char        *get_one_line(int fd);
int         check_input(int fd);
char        *read_line(int fd);
int         has_newline(char *buffer);

#endif
