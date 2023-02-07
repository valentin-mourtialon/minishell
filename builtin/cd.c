/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:31:07 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/07 12:17:11 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	cd(char *path)
{
	printf("%s", path);
	if (chdir(path) < 0)
		return (perror("failed cd"), 0);
	return (1);
}

int	main(int ac, char **av)
{
	
	if (ac == 1)
		return (0);
	if (ac != 2)
		return (perror("to many arguements"),1);
	cd(av[1]);
	return (0);
}
