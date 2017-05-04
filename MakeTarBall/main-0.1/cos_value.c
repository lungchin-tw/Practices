#include <stdio.h>
#include <math.h>
#define pi 3.14159
float angle;

void cos_value(void)
{
	float value;
	value = cos ( angle / 180. * pi );
	printf ("The cos(%f) is: %5.2f\n",angle, value);
}
