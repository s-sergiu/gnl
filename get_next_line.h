/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:02:26 by ssergiu           #+#    #+#             */
/*   Updated: 2022/08/14 16:39:58 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
 #define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t      ft_strlen(const char *str);
char        *ft_strjoin(char const *s1, char const *s2, int flag);
char		*get_next_line(int fd);
char        *get_one_line(int fd);
int         check_input(int fd);
char        *ft_strdup(const char *s1);
int         has_newline(char *buffer);
int         get_newline_pos(char *buffer);
void        format_stash_and_line(char **line, char **stash);
void        *ft_calloc(size_t count, size_t size);

#endif
