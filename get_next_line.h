/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:02:26 by ssergiu           #+#    #+#             */
/*   Updated: 2022/08/15 15:37:13 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t      ft_strlen(const char *str);
char        *ft_strjoin(char const *s1, char const *s2, int flag);
char		*get_next_line(int fd);
char        *read_line(int fd);
int         check_input(int fd);
char        *ft_strdup(const char *s1);
int         has_newline(char *buffer);
int         get_newline_pos(char *buffer);
char        *get_line(char *stash);
char        *get_rest(char *string);

#endif
