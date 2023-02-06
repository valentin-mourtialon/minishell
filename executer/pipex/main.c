/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:21:28 by valentin          #+#    #+#             */
/*   Updated: 2023/02/06 16:30:30 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	nbr_of_pipes(t_parser *parser)
{
	int	i;

	if (parser == NULL)
		return (-1);
	i = 0;
	while (*parser)
	{
		i++;
		parser = parser->nextblock;
	}
	return (i - 1);
}

/*
	ac >= 5: At least: "file1 cmd1 cmd2 file2"

	Warning case with ac=5 and here_doc:
		./pipex here_doc LIM cmd1 outfile
		ac = 5
*/
int	main(t_parser **parser, t_env **env)
{
	int	exit_code;

	/*
	if (ac < 5)
		return (alert_msg(ARGS_INPUT_ALERT), 0);
	*/
	if (nbr_of_pipes(*parser) > MAX_FDS)
		return (alert_msg(MAX_FDS_ALERT), 0);
		
	if (ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		if (ac == 5)
			return (alert_msg(ARGS_INPUT_ALERT), 0);
		exit_code = here_doc(ac - 4, av, envp);
	}
	else
		exit_code = multi_pipes(ac - 3, av, envp);
	return (exit_code);
}
