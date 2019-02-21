unsigned int		to_rgb(unsigned int a, unsigned int r,
		unsigned int g, unsigned int b)
{
	return ((((a > 0xff) ? 0xff : a) << 24) |
			(((r > 0xff) ? 0xff : r) << 16) |
			(((g > 0xff) ? 0xff : g) << 8) |
			((b > 0xff) ? 0xff : b));
}
