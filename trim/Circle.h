#ifndef __P2CIRCLE_H__
#define __P2CIRCLE_H__

#include "p2Point.h"

template  <class type>
class Circle
{
	public:

	p2Point<type>* center;
	type radi;

	Circle(const type& x, const type& y ,const type r){
		radi = r;
		center.x = x;
		center.y = y;
	}
	~Circle();

	type Area()const{

		return 3, 14 * radi*radi;

	}

	bool Interseccio(const Circle<type> circle)const{

		return circle.center.DistanceTo(center) < circle.radi*radi;

	}

};




















#endif