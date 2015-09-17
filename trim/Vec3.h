#ifndef __VEC3_H__
#define __VEC3_H__

#include <math.h>

class Vector3
{
public:

	float x, y, z;


	Vector3& create(float x, float y){
		
		this->x = x;
		this->y = y;
		this->z = z;

		return(*this);

	}


	Vector3& create(const Vector3& vec){

		x = vec.x;
		y = vec.y;
		z = vec.z;

		return(*this);

	}

	// Math
	Vector3 operator -(const Vector3& vec) const{

		Vector3 r;
		
		r.x = x-vec.x;
		r.y = y-vec.y;
		r.z =z- vec.z;

		return r;
	}
	Vector3 operator +(const Vector3& vec) const{

		Vector3 r;

		r.x = x + vec.x;
		r.y = y + vec.y;
		r.z = z + vec.z;

		return r;
	}

	const Vector3& operator -=(const Vector3& vec){

		x -= vec.x;
		y -= vec.y;
		z -= vec.z;

		return(*this);
	}
	const Vector3& operator +=(const Vector3& vec){

		x += vec.x;
		y += vec.y;
		z += vec.z;

		return(*this);
	}

	// Compare
	bool operator ==(const Vector3& vec) const{

		return (x == vec.x && y == vec.y && z == vec.z);

	}
	bool operator !=(const Vector3& vec) const{
	
		return (x != vec.x || y != vec.y || z != vec.z);
	
	}

	// Utils
	bool IsZero() const{

		if (x == 0.0f && y == 0.0f && z == 0.0f) return true;
		else false;

	}
	Vector3& SetToZero(){


		x = y = z = 0.0f;

		return(*this);

	}
	Vector3& Negate(){

		x = -x;
		y = -y;
		z = -z;

		return(*this);

	// Distance
	float DistanceTo(const Vector3& v) const{


		float fx = x - v.x;
		float fy = y - v.y;
		float fz = z - v.z;

		return sqrtf((fx*fx) + (fy*fy) + (fz*fz));

	}
	float DistanceNoSqrt(const Vector3& v) const{
	
		float fx = x - v.x;
		float fy = y - v.y;
		float fz = z - v.z;
		return (fx*fx) + (fy*fy) + (fz*fz);
	
	}

};




















#endif