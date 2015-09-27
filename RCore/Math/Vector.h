#ifndef _VECTOR_H_
#define _VECTOR_H_
#include "MathConst.h"

namespace Ray
{
	// Vector2
	struct Vector2
	{
		float x,y;

		//
		Vector2(){};
		Vector2(float _x, float _y):x(_x),y(_y){}
		explicit Vector2(float* data):x(data[0]),y(data[1]){}
		Vector2(const Vector2& vec):x(vec.x),y(vec.y){}

		// basic operators
		Vector2 operator + (const Vector2& vec) const;
		Vector2 operator - (const Vector2& vec) const;
		Vector2 operator * (const Vector2& vec) const;
		Vector2 operator * (float val) const;

		// unary operators
		Vector2 operator + () const;
		Vector2 operator - () const;

		// assignment operators
		Vector2& operator =  (const Vector2& vec);
		Vector2& operator += (const Vector2& vec);
		Vector2& operator -= (const Vector2& vec);
		Vector2& operator *= (const Vector2& vec);
		Vector2& operator /= (float val);
		Vector2& operator *= (float val);

		static const Vector2 Zero;
		static const Vector2 Uint_X;
		static const Vector2 Uint_Y;
	};

	// Vector3
	struct Vector3
	{
		float x,y,z;

		//
		Vector3(){};
		Vector3(float _x, float _y, float _z) : x(_x),y(_y),z(_z){}
		explicit Vector3(float* data) : x(data[0]),y(data[1]),z(data[2]){}
		Vector3(const Vector3& vec) : x(vec.x),y(vec.y),z(vec.z){}

		// basic operator
		Vector3 operator + (const Vector3& vec) const;
		Vector3 operator - (const Vector3& vec) const;
		Vector3 operator * (float val) const;
		Vector3 operator * (const Vector3& vec) const;

		// unary operator
		Vector3 operator + () const;
		Vector3 operator - () const;

		// assignment operator
		Vector3& operator =  (const Vector3& vec);
		Vector3& operator += (const Vector3& vec);
		Vector3& operator -= (const Vector3& vec);
		Vector3& operator *= (const Vector3& vec);
		Vector3& operator *= (float val);
		Vector3& operator /= (float val);

		static const Vector3 Zero;
		static const Vector3 Uint_X;
		static const Vector3 Uint_Y;
		static const Vector3 Uint_Z;
	};

	// Vector4
	struct Vector4
	{
		float x,y,z,w;

		//
		Vector4(){};
		Vector4(float _x, float _y, float _z,float _w):x(_x),y(_y),z(_z),w(_w){}
		explicit Vector4(float* data):x(data[0]),y(data[1]),z(data[2]),w(data[3]){}
		Vector4(const Vector4& vec):x(vec.x),y(vec.y),z(vec.z),w(vec.w){}

		// basic operator
		Vector4 operator + (const Vector4& vec) const;
		Vector4 operator - (const Vector4& vec) const;
		Vector4 operator * (const Vector4& vec) const;
		Vector4 operator * (float val) const;

		// unary operator
		Vector4 operator + () const;
		Vector4 operator - () const;

		// assignment operator
		Vector4& operator =  (const Vector4& val);
		Vector4& operator += (const Vector4& val);
		Vector4& operator -= (const Vector4& val);
		Vector4& operator *= (const Vector4& val);
		Vector4& operator *= (float val);
		Vector4& operator /= (float val);

		static const Vector4 Zero;
		static const Vector4 Uint_X;
		static const Vector4 Uint_Y;
		static const Vector4 Uint_Z;
		static const Vector4 Uint_W;
	};

	// 
	__forceinline float VectorLength(const Vector2& vec)
	{
		return sqrt(vec.x*vec.x + vec.y*vec.y);
	}

	__forceinline float VectorLength(const Vector3& vec)
	{
		return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
	}

	__forceinline float VectorLength(const Vector4& vec)
	{
		return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w);
	}

	__forceinline const Vector2 VectorNormalize(const Vector2& vec)
	{
		float length = VectorLength(vec);
		if(length > REps)
			return vec*(1.0f/length);

		return vec;
	}

	__forceinline Vector3 VectorNormalize(const Vector3& vec)
	{
		float length = VectorLength(vec);
		if(length > REps)
			return vec*(1.0f/length);

		return vec;
	}

	__forceinline Vector4 VectorNormalize(const Vector4& vec)
	{
		float length = VectorLength(vec);
		if(length > REps)
			return vec*(1.0f/length);

		return vec;
	}

	__forceinline float Vector2Dot(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x*rhs.y + lhs.y*rhs.y;
	}

	__forceinline float Vector3Dot(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x*rhs.y + lhs.y*rhs.y + lhs.z*rhs.z;
	}

	__forceinline float Vector4Dot(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x*rhs.y + lhs.y*rhs.y + lhs.z*rhs.z + lhs.w*rhs.w;
	}

	__forceinline Vector3 Vector3Cross(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(lhs.y*rhs.z-lhs.z*rhs.y, lhs.z*rhs.x-lhs.x*rhs.z, lhs.x*rhs.y-lhs.y*rhs.x);
	}

	// Vector2
	__forceinline Vector2 Vector2::operator +() const
	{
		return *this;
	}

	__forceinline Vector2 Vector2::operator -() const
	{
		return Vector2(-x,-y);
	}

	__forceinline Vector2 Vector2::operator +(const Vector2& vec) const
	{
		return Vector2(x+vec.x, y+vec.y);
	}

	__forceinline Vector2 Vector2::operator -(const Vector2& vec) const
	{
		return Vector2(x-vec.x, y-vec.y);
	}

	__forceinline Vector2 Vector2::operator *(float val) const
	{
		return Vector2(x*val, y*val);
	}

	__forceinline Vector2 Vector2::operator *(const Vector2& vec) const
	{
		return Vector2(x*vec.x, y*vec.y);
	}

	__forceinline Vector2& Vector2::operator =(const Vector2& vec)
	{
		x=vec.x;
		y=vec.y;
		return *this;
	}

	__forceinline Vector2& Vector2::operator +=(const Vector2& vec)
	{
		x+=vec.x;
		y+=vec.y;
		return *this;
	}

	__forceinline Vector2& Vector2::operator -=(const Vector2& vec)
	{
		x-=vec.x;
		y-=vec.y;
		return *this;
	}

	__forceinline Vector2& Vector2::operator *=(float val)
	{
		x*=val;
		y*=val;
		return *this;
	}

	__forceinline Vector2& Vector2::operator /=(float val)
	{
		x/=val;
		y/=val;
		return *this;
	}


	// Vector3 
	__forceinline Vector3 Vector3::operator +() const
	{
		return *this;
	}

	__forceinline Vector3 Vector3::operator -() const
	{
		return Vector3(-x, -y, -z);
	}

	__forceinline Vector3 Vector3::operator +(const Vector3& vec) const
	{
		return Vector3(x+vec.x, y+vec.y, z+vec.z);
	}

	__forceinline Vector3 Vector3::operator -(const Vector3& vec) const
	{
		return Vector3(x-vec.x, y-vec.y, z-vec.z);
	}

	__forceinline Vector3 Vector3::operator *(const Vector3& vec) const
	{
		return Vector3(x*vec.x, y*vec.y, z*vec.z);
	}

	__forceinline Vector3 Vector3::operator *(float val) const
	{
		return Vector3(x*val, y*val, z*val);
	}

	__forceinline Vector3& Vector3::operator =(const Vector3& vec)
	{
		x=vec.x;
		y=vec.y;
		z=vec.z;
		return *this;
	}

	__forceinline Vector3& Vector3::operator +=(const Vector3& vec)
	{
		x+=vec.x;
		y+=vec.y;
		z+=vec.z;
		return *this;
	}

	__forceinline Vector3& Vector3::operator -=(const Vector3& vec)
	{
		x-=vec.x;
		y-=vec.y;
		z-=vec.z;
		return *this;
	}

	__forceinline Vector3& Vector3::operator *=(const Vector3& vec)
	{
		x*=vec.x;
		y*=vec.y;
		z*=vec.z;
		return *this;
	}
	__forceinline Vector3& Vector3::operator *=(float val)
	{
		x*=val;
		y*=val;
		z*=val;
		return *this;
	}

	__forceinline Vector3& Vector3::operator /=(float val)
	{
		x/=val;
		y/=val;
		z/=val;
		return *this;
	}


	// Vector4
	__forceinline Vector4 Vector4::operator +() const
	{
		return *this;
	}

	__forceinline Vector4 Vector4::operator -() const
	{
		return Vector4(-x,-y,-z,-w);
	}

	__forceinline Vector4 Vector4::operator +(const Vector4& vec) const
	{
		return Vector4(x+vec.x, y+vec.y, z+vec.z, w+vec.w);
	}

	__forceinline Vector4 Vector4::operator -(const Vector4& vec) const
	{
		return Vector4(x-vec.x, y-vec.y, z-vec.z, w-vec.w);
	}

	__forceinline Vector4 Vector4::operator *(const Vector4& vec) const
	{
		return Vector4(x*vec.x, y*vec.y, z*vec.z, w*vec.w);
	}

	__forceinline Vector4 Vector4::operator *(float val) const
	{
		return Vector4(x*val, y*val, z*val, w*val);
	}
	__forceinline Vector4& Vector4::operator =(const Vector4& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
		return *this;
	}

	__forceinline Vector4& Vector4::operator += (const Vector4& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		w += vec.w;
		return *this;
	}

	__forceinline Vector4& Vector4::operator -= (const Vector4& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		w -= vec.w;
		return *this;
	}

	__forceinline Vector4& Vector4::operator *= (const Vector4& vec)
	{
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		w *= vec.w;
		return *this;
	}

	__forceinline Vector4& Vector4::operator *= (float val)
	{
		x *= val;
		y *= val;
		z *= val;
		w *= val;
		return *this;
	}

	__forceinline Vector4& Vector4::operator /= (float val)
	{
		x /= val;
		y /= val;
		z /= val;
		w /= val;
		return *this;
	}
};// end of ray
#endif