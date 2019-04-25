#ifndef XOR_H
#define XOR_H

int XOR(int a, int b)
{
	int number = 0;
	int x = 128, n, m;
	for (int i = 0; i < 8; i++)
	{
		n = a & x;
		m = b & x;
		if (n != m)
			number |= (1 << 7 - i);
		else
			number &= ~(1 << 7 - i);
		x = x >> 1;
	}
	return number;
}

#endif // !XOR_H
