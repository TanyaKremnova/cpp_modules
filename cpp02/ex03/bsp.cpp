#include "Point.hpp"

static Fixed	sign(Point const &a, Point const &b, Point const &p)
{
	return ( (b.getX() - a.getX()) * (p.getY() - a.getY())
			- (b.getY() - a.getY()) * (p.getX() - a.getX()) );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	s1;
	Fixed	s2;
	Fixed	s3;
	bool	has_neg;
	bool	has_pos;

	s1 = sign(a, b, point);
	s2 = sign(b, c, point);
	s3 = sign(c, a, point);

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (false);

	has_neg = (s1 < 0) || (s2 < 0) || (s3 < 0);
	has_pos = (s1 > 0) || (s2 > 0) || (s3 > 0);

	return ( !(has_neg && has_pos) );
}

// Inside = all cross products have the same sign
// Outside = signs are mixed