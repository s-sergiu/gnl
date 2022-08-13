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
	fd = open("gnlTester/files/nl", O_RDWR);
	printf("%s", get_next_line(fd));
    system("leaks test");
}
