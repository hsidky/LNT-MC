#pragma once 

#include <cmath>

namespace SAPHRON
{
	// Particle position.
	struct Position
	{
		double x, y, z;

		inline bool operator==(const Position& rhs) const
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
		}

		inline Position& operator=(const Position& rhs)
		{
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;
			return *this;
		}

		inline Position operator*(const double& rhs) const
		{
			Position lhs;
			lhs.x = x*rhs;
			lhs.y = y*rhs;
			lhs.z = z*rhs;

			return lhs;
		}

		inline double norm() const
		{
			return sqrt(x*x + y*y + z*z);
		}

		inline double normsq() const
		{
			return (x*x + y*y + z*z);
		}
	};

	inline Position operator+(Position lhs, const Position& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs;
	} 

	inline Position operator-(Position lhs, const Position& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		return lhs;
	} 

	inline Position operator*(double lhs, const Position& rhs)
	{
		return rhs*lhs;
	}
}