/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:37:10 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/11/10 15:37:10 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub.h"

int exit_error(t_game *game, char const *str)
{
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	exit_game(game, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    t_game game;

    //init_game(&game);
    if (argc != 2)
        return (exit_error(&game, ERR_USAGE));
    if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 4))
        return (exit_error(&game, ERR_FILE_NOT_CUB));
    return (EXIT_SUCCESS);
}
