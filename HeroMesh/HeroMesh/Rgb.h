#pragma once

namespace HeroMesh
{
	struct rgb
	{
		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;

		rgb() {}
		rgb(unsigned char _r, unsigned char _g, unsigned char _b)
		{
			r = _r;
			g = _g;
			b = _b;
		}

		inline rgb operator-(const rgb& _p) const
		{
			return rgb(r - _p.r, g - _p.g, b - _p.b);
		}

		inline rgb operator+(const rgb& _p) const
		{
			return rgb(r + _p.r, g + _p.g, b + _p.b);
		}
	};
}
