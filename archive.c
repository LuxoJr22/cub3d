
           1111111111111111111111111
           1000000000110000000000001
           1011000001110000000000001
           1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111


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