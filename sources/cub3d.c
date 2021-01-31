/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:44:01 by msafflow          #+#    #+#             */
/*   Updated: 2020/10/17 20:18:25 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			draw_frame(t_game *game)
{
	if (!(game->w || game->left || game->right
	|| game->a || game->s || game->d))
		return (0);
	check_state(game);
	game->conf.data.img = mlx_new_image(game->conf.mlx,
		game->conf.width, game->conf.height);
	game->conf.data.addr = mlx_get_data_addr(game->conf.data.img,
		&game->conf.data.bpp, &game->conf.data.l_len, &game->conf.data.enan);
	raycasting(&game->conf);
	mlx_put_image_to_window(game->conf.mlx,
		game->win, game->conf.data.img, 0, 0);
	mlx_destroy_image(game->conf.mlx, game->conf.data.img);
	game->conf.data.img = 0;
	return (0);
}

void		first_frame(t_game *game)
{
	game->win = mlx_new_window(game->conf.mlx,
		game->conf.width, game->conf.height, "Cub3d");
	game->conf.data.img = mlx_new_image(game->conf.mlx,
		game->conf.width, game->conf.height);
	game->conf.data.addr = mlx_get_data_addr(game->conf.data.img,
		&game->conf.data.bpp, &game->conf.data.l_len, &game->conf.data.enan);
	tex_init(game->conf.tex, &game->conf);
	raycasting(&game->conf);
	mlx_put_image_to_window(game->conf.mlx,
		game->win, game->conf.data.img, 0, 0);
}

void		init(t_game *game)
{
	game->w = 0;
	game->a = 0;
	game->s = 0;
	game->d = 0;
	game->conf.floor_cl = -1;
	game->conf.ceil_cl = -1;
	game->conf.width = -1;
	game->conf.height = -1;
	game->conf.error = 0;
	game->right = 0;
	game->left = 0;
	game->conf.num_sprs = 0;
	game->conf.no = 0;
	game->conf.so = 0;
	game->conf.ea = 0;
	game->conf.we = 0;
	game->conf.sprt = 0;
	game->conf.map = 0;
	game->conf.sprite = 0;
	game->conf.ymp = 0;
}

int			main(int argc, char **argv)
{
	t_game	game;

	init(&game);
	if (argc > 3 || argc < 2)
		nval(&game.conf, 8);
	check_tag(&game.conf, argv[1], ".cub");
	parsing(argv[1], &game.conf);
	game.conf.mlx = mlx_init();
	if (argv[2])
	{
		if (!(ft_strncmp(argv[2], "--save", 7)))
			ft_bitmap(&game.conf);
		else
			nval(&game.conf, 8);
	}
	first_frame(&game);
	mlx_loop_hook(game.conf.mlx, draw_frame, &game);
	mlx_hook(game.win, 2, (1L << 0), key_press, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game.conf);
	mlx_hook(game.win, 3, (1L << 1), key_unpress, &game);
	mlx_loop(game.conf.mlx);
}
