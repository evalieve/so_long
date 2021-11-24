#include <stdio.h> // for printf > delete later!

#include <fcntl.h> // for open & read
#include <unistd.h> // for write
#include <stdlib.h> // for malloc

typedef struct s_map // structure for checks on valid values
{
	int p;
	int e;
	int c;
}				t_map;