/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:21:15 by ssergiu           #+#    #+#             */
/*   Updated: 2022/07/22 13:28:34 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int main(void)
{
	int fd;
    char *tmp;
	fd = open("gnlTester/files/multiple_nlx5", O_RDWR);

    tmp = get_next_line(fd);
    free(tmp);
    tmp = get_next_line(fd);
    free(tmp);
}
