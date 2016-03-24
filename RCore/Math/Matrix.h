#ifndef _MATRIX_H_ 
#define _MATRIX_H_
#include "Vector.h"

namespace Ray
{
	struct Matrix33
	{
		float _11,_12,_13;
		float _21,_22,_23;
		float _31,_32,_33;
		
		//
		Matrix33(){}
		Matrix33(float m11, float m12, float m13,
				 float m21, float m22, float m23,
				 float m31, float m32, float m33):
				_11(m11), _12(m12), _13(m13),
				_21(m21), _22(m22), _23(m23),
				_31(m31), _32(m32), _33(m33){}
		explicit Matrix33(const float* ar)
		{
			memcpy(this, ar, sizeof(Matrix33));
		}
		Matrix33(const Matrix33& mat)
		{
			memcpy(this, &mat, sizeof(Matrix33));
		}

		// basic operators
		Matrix33 operator + (const Matrix33& mat) const;
		Matrix33 operator - (const Matrix33& mat) const;
		Matrix33 operator * (const Matrix33& mat) const;
		Matrix33 operator * (float val) const;

		// unary operators
		Matrix33 operator + () const;
		Matrix33 operator - () const;

		// assignment operators
		Matrix33& operator =  (const Matrix33& mat);
		Matrix33& operator += (const Matrix33& mat);
		Matrix33& operator -= (const Matrix33& mat);
		Matrix33& operator *= (const Matrix33& mat);
		Matrix33& operator *= (float val);

		static const Matrix33 Identity;
		static const Matrix33 Zero;
	};

	struct Matrix44
	{
		float _11,_12,_13,_14;
		float _21,_22,_23,_24;
		float _31,_32,_33,_34;
		float _41,_42,_43,_44;

		//
		Matrix44(){}
		Matrix44(float m11, float m12, float m13, float m14,
				float m21, float m22, float m23, float m24,
				float m31, float m32, float m33, float m34,
				float m41, float m42, float m43, float m44):
				_11(m11), _12(m12), _13(m13), _14(m14),
				_21(m21), _22(m22), _23(m23), _24(m24),
				_31(m31), _32(m32), _33(m33), _34(m34),
				_41(m41), _42(m42), _43(m43), _44(m44){}
		explicit Matrix44(const float* ar)
		{
			memcpy(this, ar, sizeof(Matrix44));
		}
		Matrix44(const Matrix44& mat)
		{
			memcpy(this, &mat, sizeof(Matrix44));
		}

		// basic operators
		Matrix44 operator + (const Matrix44& mat) const;
		Matrix44 operator - (const Matrix44& mat) const;
		Matrix44 operator * (const Matrix44& mat) const;
		Matrix44 operator * (float val) const;

		// unary operators
		Matrix44 operator + () const;
		Matrix44 operator - () const;

		// assignment operators
		Matrix44& operator =  (const Matrix44& mat);
		Matrix44& operator += (const Matrix44& mat);
		Matrix44& operator -= (const Matrix44& mat);
		Matrix44& operator *= (const Matrix44& mat);
		Matrix44& operator *= (float val);

		static const Matrix44 Identity;
		static const Matrix44 Zero;
	};

	// Matrix33
	__forceinline Matrix33 Matrix33::operator + () const
	{
		return *this;
	}

	__forceinline Matrix33 Matrix33::operator - () const
	{
		return Matrix33(-_11, -_12, -_13,
						-_21, -_22, -_23,
						-_31, -_32, -_33);
	}

	__forceinline Matrix33 Matrix33::operator + (const Matrix33& mat) const
	{
		return Matrix33(_11 + mat._11, _12 + mat._12, _13 + mat._13,
						_21 + mat._21, _22 + mat._22, _23 + mat._23,
						_31 + mat._31, _32 + mat._32, _23 + mat._33);
	}

	__forceinline Matrix33 Matrix33::operator - (const Matrix33& mat) const
	{
		return Matrix33(_11 - mat._11, _12 - mat._12, _13 - mat._13,
						_21 - mat._21, _22 - mat._22, _23 - mat._23,
						_31 - mat._31, _32 - mat._32, _23 - mat._33);
	}

	__forceinline Matrix33 Matrix33::operator * (const Matrix33& mat) const
	{
		return Matrix33(_11*mat._11+_12*mat._21+_13*mat._31, _11*mat._12+_12*mat._22+_13*mat._32, _11*mat._13+_12*mat._23+_13*mat._33,
						_21*mat._11+_22*mat._21+_23*mat._31, _21*mat._12+_22*mat._22+_23*mat._32, _21*mat._13+_22*mat._23+_23*mat._33,
						_31*mat._11+_32*mat._21+_33*mat._31, _31*mat._12+_32*mat._22+_33*mat._32, _31*mat._13+_32*mat._23+_33*mat._33);
	}

	__forceinline Matrix33 Matrix33::operator * (float val) const 
	{
		return Matrix33(val*_11, val*_12, val*_13,
						val*_21, val*_22, val*_23,
						val*_31, val*_32, val*_33);
	}

	__forceinline Matrix33& Matrix33::operator = (const Matrix33& mat)
	{
		memcpy(this, &mat, sizeof(Matrix33));
		return *this;
	}

	__forceinline Matrix33& Matrix33::operator += (const Matrix33& mat)
	{
		_11 += mat._11; _12 += mat._12; _13 += mat._13;
		_21 += mat._21; _22 += mat._22; _23 += mat._23;
		_31 += mat._31; _32 += mat._32; _33 += mat._33;
		return *this;
	}

	__forceinline Matrix33& Matrix33::operator -= (const Matrix33& mat)
	{
		_11 -= mat._11; _12 -= mat._12; _13 -= mat._13;
		_21 -= mat._21; _22 -= mat._22; _23 -= mat._23;
		_31 -= mat._31; _32 -= mat._32; _33 -= mat._33;
		return *this;
	}

	__forceinline Matrix33& Matrix33::operator *= (const Matrix33& mat)
	{
		_11 = _11*mat._11+_12*mat._21+_13*mat._31; _12 = _11*mat._12+_12*mat._22+_13*mat._32; _13 = _11*mat._13+_12*mat._23+_13*mat._33;
		_21 = _21*mat._11+_22*mat._21+_23*mat._31; _22 = _21*mat._12+_22*mat._22+_23*mat._32; _23 = _21*mat._13+_22*mat._23+_23*mat._33;
		_31 = _31*mat._11+_32*mat._21+_33*mat._31; _32 = _31*mat._12+_32*mat._22+_33*mat._32; _33 = _31*mat._13+_32*mat._23+_33*mat._33;
		return *this;
	}

	__forceinline Matrix33& Matrix33::operator *= (float val)
	{
		_11 *= val; _12 *= val; _13 *= val;
		_21 *= val; _22 *= val; _23 *= val;
		_31 *= val; _32 *= val; _33 *= val;
		return *this;
	}


	// Matrix44
	__forceinline Matrix44 Matrix44::operator + () const
	{
		return *this;
	}

	__forceinline Matrix44 Matrix44::operator - () const
	{
		return Matrix44(-_11, -_12, -_13, -_14,
						-_21, -_22, -_23, -_24,
						-_31, -_32, -_33, -_34,
						-_41, -_42, -_43, -_44);
	}

	__forceinline Matrix44 Matrix44::operator + (const Matrix44& mat) const
	{
		return Matrix44(_11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
						_21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
						_31 + mat._31, _32 + mat._32, _23 + mat._33, _34 + mat._34,
						_41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44);
	}

	__forceinline Matrix44 Matrix44::operator - (const Matrix44& mat) const
	{
		return Matrix44(_11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
						_21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
						_31 - mat._31, _32 - mat._32, _23 - mat._33, _34 - mat._34,
						_41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44);
	}

	__forceinline Matrix44 Matrix44::operator * (const Matrix44& mat) const
	{
		return Matrix44(_11 * mat._11, _12 * mat._12, _13 * mat._13, _14 * mat._14,
						_21 * mat._21, _22 * mat._22, _23 * mat._23, _24 * mat._24,
						_31 * mat._31, _32 * mat._32, _23 * mat._33, _34 * mat._34,
						_41 * mat._41, _42 * mat._42, _43 * mat._43, _44 * mat._44);
	}

	__forceinline Matrix44 Matrix44::operator * (float val) const
	{
		return Matrix44(_11 * val, _12 * val, _13 * val, _14 * val,
						_21 * val, _22 * val, _23 * val, _24 * val,
						_31 * val, _32 * val, _23 * val, _34 * val,
						_41 * val, _42 * val, _43 * val, _44 * val);
	}

	__forceinline Matrix44& Matrix44::operator = (const Matrix44& mat)
	{
		memcpy(this, &mat, sizeof(Matrix44));
		return *this;
	}

	__forceinline Matrix44& Matrix44::operator += (const Matrix44& mat)
	{
		_11 += mat._11; _12 += mat._12; _13 += mat._13; _14 += mat._14;
		_21 += mat._21; _22 += mat._22; _23 += mat._23; _24 += mat._24;
		_31 += mat._31; _32 += mat._32; _33 += mat._33; _34 += mat._34;
		_44 += mat._44; _42 += mat._42; _43 += mat._43; _44 += mat._44;
		return *this;
	}

	__forceinline Matrix44& Matrix44::operator -= (const Matrix44& mat)
	{
		_11 -= mat._11; _12 -= mat._12; _13 -= mat._13; _14 -= mat._14;
		_21 -= mat._21; _22 -= mat._22; _23 -= mat._23; _24 -= mat._24;
		_31 -= mat._31; _32 -= mat._32; _33 -= mat._33; _34 -= mat._34;
		_44 -= mat._44; _42 -= mat._42; _43 -= mat._43; _44 -= mat._44;
		return *this;
	}

	__forceinline Matrix44& Matrix44::operator *= (const Matrix44& mat)
	{
		_11 = _11*mat._11+_12*mat._21+_13*mat._31+_14*mat._41; _12 = _11*mat._12+_12*mat._22+_13*mat._32+_14*mat._42; _13 = _11*mat._13+_12*mat._23+_13*mat._33+_14*mat._43; _14 = _11*mat._14+_12*mat._24+_13*mat._34+_14*mat._44;
		_21 = _21*mat._11+_22*mat._21+_23*mat._31+_24*mat._41; _22 = _21*mat._12+_22*mat._22+_23*mat._32+_24*mat._42; _23 = _21*mat._13+_22*mat._23+_23*mat._33+_24*mat._43; _24 = _21*mat._14+_22*mat._24+_23*mat._34+_24*mat._44;
		_31 = _31*mat._11+_32*mat._21+_33*mat._31+_34*mat._41; _32 = _31*mat._12+_32*mat._22+_33*mat._32+_34*mat._42; _33 = _31*mat._13+_32*mat._23+_33*mat._33+_34*mat._43; _34 = _31*mat._14+_32*mat._24+_23*mat._34+_34*mat._44;
		_41 = _41*mat._11+_42*mat._21+_43*mat._31+_44*mat._41; _42 = _41*mat._12+_42*mat._22+_43*mat._32+_44*mat._42; _33 = _41*mat._13+_42*mat._23+_43*mat._33+_44*mat._43; _34 = _41*mat._14+_42*mat._24+_43*mat._34+_44*mat._44;
		return *this;
	}

	__forceinline Matrix44& Matrix44::operator *= (float val)
	{
		_11 *= val; _12 *= val; _13 *= val; _14 *= val;
		_21 *= val; _22 *= val; _23 *= val; _24 *= val;
		_31 *= val; _32 *= val; _33 *= val; _34 *= val;
		_44 *= val; _42 *= val; _43 *= val; _44 *= val;
		return *this;
	}

	/////////////////////
	// 向量和矩阵的运算符重载
	__forceinline Vector3 operator * (const Vector3& vec, const Matrix33& mat)
	{
		return Vector3(vec.x*mat._11 + vec.y*mat._21 + vec.z*mat._31,
					   vec.x*mat._12 + vec.y*mat._22 + vec.z*mat._32,
					   vec.x*mat._13 + vec.y*mat._23 + vec.z*mat._33);
	}

	__forceinline Vector3 operator * (const Vector3& vec, const Matrix44& mat)
	{
		return Vector3(vec.x*mat._11 + vec.y*mat._21 + vec.z*mat._31 + mat._41,
					   vec.x*mat._12 + vec.y*mat._22 + vec.z*mat._32 + mat._42,
					   vec.x*mat._13 + vec.y*mat._23 + vec.z*mat._33 + mat._43);
	}

	__forceinline Vector4 operator * (const Vector4& vec, const Matrix44& mat)
	{
		return Vector4(vec.x*mat._11 + vec.y*mat._21 + vec.z*mat._31 + vec.w*mat._41,
					   vec.x*mat._12 + vec.y*mat._22 + vec.z*mat._32 + vec.w*mat._42,
					   vec.x*mat._13 + vec.y*mat._23 + vec.z*mat._33 + vec.w*mat._43,
					   vec.x*mat._14 + vec.y*mat._24 + vec.z*mat._34 + vec.w*mat._44);
	}
}; // end of ray
#endif