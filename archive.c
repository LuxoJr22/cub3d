/*                    DRAW LINE            */


/*
#define SGN(_x) ((_x) < 0 ? -1 : ((_x) > 0 ? 1 : 0))

void	draw_line(t_game *game, t_pos p1, t_pos p2, int color)
{
	int	x0 = p1.x;
	int	x1 = p2.x;
	int	y0 = p1.y;
	int	y1 = p2.y;
	int	dx = x1 - x0;
	int	dy = y1 - y0;
	int	incX = SGN(dx);
	int	incY = SGN(dy);
	int	x;
	int	y;
	int	slope;
	int	error;
	int	errorInc;

	dx = abs(dx);
	dy = abs(dy);
	if (dy == 0)
	{
		x = x0;
		while (x != x1)
		{
			my_mlx_pixel_put(&game->frame1, x, y0, color);
			x += incX;
		}
	}
	else if (dx == 0)
	{
		y = y0;
		while (y != y1 + incY)
		{
			my_mlx_pixel_put(&game->frame1, x0, y, color);
			y += incY;
		}
	}
	else if (dx >= dy)
	{
		slope = 2 * dy;
		error = -dx;
		errorInc = -2 * dx;
		y = y0;
		x = x0;
		while (x != x1 + incX)
		{
			my_mlx_pixel_put(&game->frame1, x, y, color);
			error += slope;
			if (error >= 0)
			{
				y += incY;
				error += errorInc;
			}
			x += incX;
		}
	}
	else
	{
		slope = 2 * dx;
		error = -dy;
		errorInc = -2 * dy;
		x = x0;
		y = y0;
		while( y != y1 + incY)
		{
			my_mlx_pixel_put(&game->frame1, x, y, color);
			error += slope;
			if (error >= 0)
			{
				x += incX;
				error += errorInc;
			}
			y += incY;
		}
	}
}

*/


/*                  ANCIEN KEYMANAGER            */

/*int key_manager(int keycode, t_game *game)
{
	if (keycode == 100)
	{
		//game->player->cm = 1;
		game->player->pa += 0.1;
		if (game->player->pa > 2 * PI)
			game->player->pa -= 2 * PI;
		game->player->pdx = cos(game->player->pa) * 20;
		game->player->pdy = sin(game->player->pa) * 20;
	}
	if (keycode == 113)
	{
		//game->player->cm = -1;
		game->player->pa -= 0.1;
		if (game->player->pa < 0)
			game->player->pa += 2 * PI;
		game->player->pdx = cos(game->player->pa) * 20;
		game->player->pdy = sin(game->player->pa) * 20;
	}
	if (keycode == 115)
	{
		game->player->dy = 1;
	}
	if (keycode == 122)
		game->player->dy = -1;
	return (1);
}

int relinput(int keycode, t_game *game)
{
	if (keycode == 100)
		game->player->cm = 0;
	if (keycode == 113)
		game->player->cm = 0;
	if (keycode == 115)
		game->player->dy = 0;
	if (keycode == 122)
		game->player->dy = 0;
	return (1);
}*/


/*				VIEUX RAYCASTER TOUT POURRI            */

	/*int dx, dy, p, x, y;
 
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
 
	x = p1.x;
	y = p1.y;
 
	p = 2 * dy - dx;
	while(x < p2.x)
	{
		if(p >= 0)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x00FF0000);
			y ++;
			p += 2 * dy - 2 * dx;
		}
		else
		{

			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x00FF0000);
			p += 2 * dy;
		}
		x ++;
	}
	mlx_pixel_put(game->mlx, game->mlx_win, p1.x, p1.y, 0x0000FF00);
	mlx_pixel_put(game->mlx, game->mlx_win, p2.x, p2.y, 0x0000FF00);*/
	
	/*int dx, dy, p, end;
    float x1, x2, y1, y2, x, y;
	
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;

	dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    p = 2 * dy - dx;
    if(x1 > x2)
    {
        x = x2;
        y = y2;
        end = x1;
    }
    else
    {
        x = x1;
        y = y1;
        end = x2;
    }
    mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x00FF0000);
    while(x < end)
    {
        x = x + 1;
        if(p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            y = y + 1;
            p = p + 2 * (dy - dx);
        }
        mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x00FF0000);
    }*/


    		/*int vmt = 0;
		int hmt = 0;
		// Horizontal line
		dof = 0;
		float disH= 1000000, hx = game->player->px, hy = game->player->py;
		aTan= -1/tan(ra);
		if (ra > PI)
		{
			ry = (((int)game->player->py / 64) * 64) - 0.0001;
			rx = (game->player->py - ry) * aTan + game->player->px;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = ((int)game->player->py / 64) * 64 + 64;
			rx = (game->player->py - ry) * aTan + game->player->px;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || (ra >= 3.1 && ra <= 3.2))
		{
			rx = game->player->px;
			ry = game->player->py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx / 64;
			my = (int)ry / 64;
			mp = my * 8 + mx;
			if (mp < 64 && game->map[mp] >= 1)
			{
				hmt = game->map[mp] - 1;
				hx = rx;
				hy = ry;
				disH = dist(game->player->px, game->player->py, hx, hy);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		// Vertical line
		dof = 0;
		float disV= 1000000, vx = game->player->px, vy = game->player->py;
		nTan= -tan(ra);
		if (ra > P2 && ra < P3)
		{
			rx = (((int)game->player->px / 64) * 64) - 0.0001;
			ry = (game->player->px - rx) * nTan + game->player->py;
			xo = -64;
			yo = -xo * nTan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = ((int)game->player->px / 64) * 64 + 64;
			ry = (game->player->px - rx) * nTan + game->player->py;
			xo = 64;
			yo = -xo * nTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = game->player->px;
			ry = game->player->py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx / 64;
			my = (int)ry / 64;
			mp = my * 8 + mx;
			if (mp < 64 && game->map[mp] >= 1)
			{
				vmt = game->map[mp] - 1;
				vx = rx;
				vy = ry;
				disV = dist(game->player->px, game->player->py, vx, vy);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}*/