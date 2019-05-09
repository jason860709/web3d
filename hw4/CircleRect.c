/*
Fast Circle-Rectangle Intersection Checking
by Clifford A. Shaffer
from "Graphics Gems", Academic Press, 1990
*/

#include "GraphicsGems.h"
#include "stdio.h"
#include "stdlib.h"

boolean Check_Intersect(Box2 *R,Point2 *C,double Rad)

/* Return TRUE iff rectangle R intersects circle with centerpoint C and
   radius Rad. */
   /*
 Box2 *R;
 Point2 *C;
 double Rad;
 */
{
 double Rad2;

 Rad2 = Rad * Rad;
 /* Translate coordinates, placing C at the origin. */
 R->max.x -= C->x;  R->max.y -= C->y;
 R->min.x -= C->x;  R->min.y -= C->y;

 if (R->max.x < 0) 			/* R to left of circle center */
   	if (R->max.y < 0) 		/* R in lower left corner */
     		return ((R->max.x * R->max.x + R->max.y * R->max.y) < Rad2);
   	else if (R->min.y > 0) 	/* R in upper left corner */
     		return ((R->max.x * R->max.x + R->min.y * R->min.y) < Rad2);
   	else 					/* R due West of circle */
     		return(ABS(R->max.x) < Rad);
 	else if (R->min.x > 0)  	/* R to right of circle center */
   		if (R->max.y < 0) 	/* R in lower right corner */
     			return ((R->min.x * R->min.x + R->max.y * R->max.y) < Rad2);
   	else if (R->min.y > 0)  	/* R in upper right corner */
     		return ((R->min.x * R->min.x + R->min.y * R->min.y) < Rad2);
   	else 				/* R due East of circle */
     		return (R->min.x < Rad);
 	else				/* R on circle vertical centerline */
   		if (R->max.y < 0) 	/* R due South of circle */
     		return (ABS(R->max.y) < Rad);
   	else if (R->min.y > 0)  	/* R due North of circle */
     		return (R->min.y < Rad);
   	else 				/* R contains circle centerpoint */
     		return(TRUE);
}

int main(int argc,char *argv[]){

    Box2 R;
	Point2 C;
	double Rad;

	int check;

 	R.max.x = atof (argv[1]);
 	R.max.y = atof (argv[2]);
 	R.min.x = atof (argv[3]);
 	R.min.y = atof (argv[4]);
 	C.x = atof (argv[5]);
 	C.y = atof (argv[6]);
 	Rad = atof (argv[7]);

	check = Check_Intersect(&R, &C, Rad);

	printf("%d",check);
}
