/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:00:52 by sel-maar          #+#    #+#             */
/*   Updated: 2023/02/09 14:26:11 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int pwd(void)
{
	char	buff[1024];
		
	if (getcwd(buff, sizeof(buff)))
		printf("%s\n", buff);
	else
		return (perror("pwd failed"), 0);
	return (1);
}

/*int	main()
{
	pwd();
	return (0);
}*/
