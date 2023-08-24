/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:52:23 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/24 21:29:37 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing/parsing.h"
#include"signal/signal.h"

// when ctrl + D -> eof. print exit.
// ========================================== //
// valid_command_line has execute and parsing
// ========================================== //
int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	init_env(argc, argv, envp);
	while (1)
	{
		default_signal();
		line = readline(" $> ");
		if (line == 0)
		{
			printf("\033[A\b\b\b $> exit\n");
			break ;
		}
		if (line[0] != 0)
			add_history(&line[0]);
		if (line[0] != 0 && !is_whitespace(line))
			valid_command_line(line);
		free(line);
	}
	return (0);
}
