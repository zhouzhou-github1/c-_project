#include "Circle.h"
ostream & operator<<(ostream & out, const  Circle & circle)
{
	out << "Ô²°ë¾¶£º"<<circle.radius<<"\t";
	out <<"Ô²Ãæ»ý"<< circle.area<<"\n";
	return out;
}