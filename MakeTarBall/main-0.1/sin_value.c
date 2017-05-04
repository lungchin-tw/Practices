#include <stdio.h>
#include <math.h>
#define pi 3.14159
float angle;

void sin_value(void)
{
	float value;
	value = sin ( angle / 180. * pi );
	printf ("\nThe sin(%f) is: %5.2f\n",angle, value);
}
