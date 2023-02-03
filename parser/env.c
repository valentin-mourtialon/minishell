/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:47:11 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/30 14:39:54 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	copyenv(t_env **env, char **realenv)
{
	t_env	*tmp;
	*env = newenv(NULL);
	while (*realenv)
	{
		tmp = newenv(*realenv);
		envaddback(env, tmp);;
		realenv++;
	}
	print_env(*env);
}
