int settle(int k) {
	int 				i;
	int					hold;
	
	while (k && !(k & 15))
		k = k >> 4;
	if (k == 15)
		return 15;
	if (k == 4369 || k == 8738 || k == 13107 || k == 17476)
		return 4369;
	while (k && !(k & 4369))
	{
		i = -1;
		while (++i < 4)
		{
			hold = (k & (15 << (i * 4))) >> (i * 4);
			hold = ((hold & 7) << 1) | ((hold & 8) >> 3);
			k = (k & ~(15 << (i * 4))) | (hold << (i * 4));
		}
	}
	return k;
}

int	ispattern(char *p) {
	int	x, c, h;

	x = -1;
	c = 0;
	h = 0;
	while (++x < 20)
		if (p[x] == '#') {
			h++;
			c += (x < 15 && x % 4 != 3 && p[x] == p[x + 1])
				+ (x > 0 && x % 4 != 0 && p[x] == p[x - 1])
				+ (x + 4 <= 15 && p[x] == p[x + 4])
				+ (x - 4 >= 0 && p[x] == p[x - 4]);
		}
	return (h == 4 && (c == 6 || c == 8));
}
