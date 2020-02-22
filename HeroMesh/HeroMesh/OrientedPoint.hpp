#pragma once

#include "Point3d.hpp"

namespace HeroMesh
{

	struct OrientedPoint
	{
		Point3d p; // 3 * float : 3 * 4 = 12 Bytes : (one float is 4 Bytes : 3.4E +/- 38 (7 digits) )
		Point3d n; // 3 * float : 3 * 4 = 12  Bytes
		float sim; // 4-Bytes : 3.4E +/- 38 (7 digits)
		// TOTAL: 12 + 12 + 4 = 28 Bytes

		OrientedPoint()
		{
			p = Point3d();
			n = Point3d();
			sim = 1.0f;
		}

		OrientedPoint(const Point3d& _p, const Point3d& _n, float _sim)
		{
			sim = _sim;
			p = _p;
			n = _n;
		}

		OrientedPoint& operator=(const OrientedPoint& param)
		{
			p = param.p;
			n = param.n;
			sim = param.sim;
			return *this;
		}

		bool operator>(const OrientedPoint& param) const
		{
			return (sim > param.sim);
		}
	};

} // namespace HeroMesh
