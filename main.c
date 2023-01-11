/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:59:52 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/10 15:57:36 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "get_next_line.h"
#include "test.h"

/*void	handle_sigint(int sig)
{
		printf("dosminishell\n");
}*/

/*void	handle_sigquit(int sig)
{
	if (sig == EOF)
			exit(0);
}*/

void handle_sigquit(int sig)
{
	(void)sig;
}
void handle_sigint(int sig)
{
	(void)sig;
    printf("\ndossminishell ");
}

int	main(void)
{
	char	*s;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
//	signal(SIGQUIT, handle_sigquit);
	while(1)
	{
		s = get_next_line(0);
		if (!ft_strchr(s, EOF))
		{
			free(s);
			break;
		}
		free(s);
	}	
	return (0);
}
