#pragma once

#include <string>
#include <cmath>

namespace HeroMesh
{

	class Point3d
	{
	public:
		union {
			struct
			{
				double x, y, z;
			};
			double m[3];
		};

		inline Point3d()
		{
			x = 0.0;
			y = 0.0;
			z = 0.0;
		}

		inline Point3d(double _x, double _y, double _z)
		{
			x = _x;
			y = _y;
			z = _z;
		}

		inline Point3d(const double* const p)
		{
			x = p[0];
			y = p[1];
			z = p[2];
		}

		inline Point3d& operator=(const Point3d& param)
		{
			x = param.x;
			y = param.y;
			z = param.z;
			return *this;
		}

		inline bool operator==(const Point3d& param)
		{
			return (x == param.x) && (y == param.y) && (z == param.z);
		}

		inline Point3d operator-(const Point3d& _p) const
		{
			return Point3d(x - _p.x, y - _p.y, z - _p.z);
		}

		inline Point3d operator-() const
		{
			return Point3d(-x, -y, -z);
		}

		inline Point3d operator+(const Point3d& _p) const
		{
			return Point3d(x + _p.x, y + _p.y, z + _p.z);
		}

		inline Point3d operator*(const double d) const
		{
			return Point3d(x * d, y * d, z * d);
		}

		inline Point3d operator/(const double d) const
		{
			return Point3d(x / d, y / d, z / d);
		}

		inline Point3d normalize() const
		{
			double d = std::sqrt(x * x + y * y + z * z);
			return Point3d(x / d, y / d, z / d);
		}

		inline double size() const
		{
			double d = x * x + y * y + z * z;
			if (d == 0.0)
			{
				return 0.0;
			}

			return sqrt(d);
		}

		inline double size2() const
		{
			return x * x + y * y + z * z;
		}

		friend double dist(const Point3d& p1, const Point3d& p2);

		friend double dot(const Point3d& p1, const Point3d& p2);
		friend Point3d cross(const Point3d& a, const Point3d& b);
		friend Point3d proj(Point3d& e, Point3d& a);
	};

	inline double dist(const Point3d& p1, const Point3d& p2)
	{
		return (p1 - p2).size();
	}

	inline double dot(const Point3d& p1, const Point3d& p2)
	{
		return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
	}

	inline Point3d cross(const Point3d& a, const Point3d& b)
	{
		Point3d vc;
		vc.x = a.y * b.z - a.z * b.y;
		vc.y = a.z * b.x - a.x * b.z;
		vc.z = a.x * b.y - a.y * b.x;

		return vc;
	}

	inline Point3d proj(Point3d& e, Point3d& a)
	{
		return e * (dot(e, a) / dot(e, e));
	}

} // namespace HeroMesh
