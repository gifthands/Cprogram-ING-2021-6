#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


int main()
{
	int n;
	char s[100][101];
	scanf("%d%*d", &n);
	while (n--)
	{
		int a, e, i, o, u;
		for (int i = 0, j = 0; i < n; i++)
		{
			gets(s[i]);
			a = e = i = o = u = 0;
			while (s[i++] != '\0')
			{
				switch (s[i - 1][j++])
				{
				case 'a':
					a++;
					break;
				case 'e':
					e++;
					break;
				case 'i':
					i++;
					break;
				case 'o':
					o++;
					break;
				case 'u':
					u++;
					break;
				default:
					break;
				}
			}
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i, o, u);
			if (i != n - 1) printf("\n");
		}

	}
	return 0;
}

