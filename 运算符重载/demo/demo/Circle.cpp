#include "Circle.h"
ostream & operator<<(ostream & out, const  Circle & circle)
{
	out << "Բ�뾶��"<<circle.radius<<"\t";
	out <<"Բ���"<< circle.area<<"\n";
	return out;
}