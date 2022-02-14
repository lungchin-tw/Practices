namespace hive
{

inline float SIGN( float x ) 
{ 
	return ( x >= 0.0f )? 1.0f : -1.0f;  
}

//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>::Quaternion() :
    x(0),
    y(0),
    z(0),
    w(1)
{
} // End of Constructor for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>::Quaternion(  const Quaternion<Type>& rhs ) :
    x(rhs.x),
    y(rhs.y),
    z(rhs.z),
    w(rhs.w)
{
} // End of Constructor for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>::Quaternion(  Type _x,  Type _y,  Type _z,  Type _w ) :
    x(_x),
    y(_y),
    z(_z),
    w(_w)
{
} // End of Constructor for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>::~Quaternion()
{
} // End of Destructor for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>
Quaternion<Type>::operator +  (  const Quaternion<Type>& q ) const
{    
    return Quaternion<Type>( x + q.x, y + q.y, z + q.z, w + q.w);
} // End of operator + for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>& 
Quaternion<Type>::operator += (  const Quaternion<Type>& q )
{
    x += q.x;
    y += q.y;
    z += q.z;
    w += q.w;

    return (*this);
} // End of operator += for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>
Quaternion<Type>::operator -  (  const Quaternion<Type>& q ) const
{    
    return Quaternion<Type>( x - q.x, y - q.y, z - q.z, w - q.w );
} // End of operator - for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>&
Quaternion<Type>::operator -= (  const Quaternion<Type>& q )
{
    x -= q.x;
    y -= q.y;
    z -= q.z;
    w -= q.w;

    return (*this);
} // End of operator -= for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type> 
Quaternion<Type>::operator * (  const Quaternion<Type>& q ) const
{    
    return Quaternion<Type>( y * q.z - z * q.y + x * q.w + w * q.x,
                                z * q.x - x * q.z + y * q.w + w * q.y,
                                x * q.y - y * q.x + z * q.w + w * q.z,
                                w * q.w - x * q.x - y * q.y - z * q.z );
} // End of operator * for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>&
Quaternion<Type>::operator *= (  const Quaternion<Type>& q )
{
    Type X,Y,Z,W;

    X = y * q.z - z * q.y + x * q.w + w * q.x;

    Y = z * q.x - x * q.z + y * q.w + w * q.y;

    Z = x * q.y - y * q.x + z * q.w + w * q.z;

    W = w * q.w - x * q.x - y * q.y - z * q.z;

    x = X;
    y = Y;
    z = Z;
    w = W;

    return (*this);
} // End of operator *= for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>
Quaternion<Type>::operator * (  Type scale ) const
{    
    return Quaternion<Type>( x * scale, y * scale, z * scale, w * scale );
} // End of operator * for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>&
Quaternion<Type>::operator *= (  Type scale )
{
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;

    return (*this);
} // End of operator *= for Quaternion

//--------------------------------------------------------------------------
template<class Type>
Type&
Quaternion<Type>::operator[] ( uint iIndex )
{
	if ( iIndex == 0 )
		return x;
	if ( iIndex == 1 )
		return y;
	if ( iIndex == 2 )
		return z;
	if ( iIndex == 3 )
		return w;
}

//--------------------------------------------------------------------------
template<class Type>
Type
	Quaternion<Type>::operator[] ( uint iIndex ) const
{
	if ( iIndex == 0 )
		return x;
	else if ( iIndex == 1 )
		return y;
	else if ( iIndex == 2 )
		return z;
	else
		return w;
}

//--------------------------------------------------------------------------
template<class Type>
Type 
Quaternion<Type>::Norm() const
{
    Type sum = x*x + y*y + z*z + w*w;

    return sqrt( sum );
} // End of Norm for Quaternion


//--------------------------------------------------------------------------
template<class Type>
void 
Quaternion<Type>::Normalize()
{
    Type norm = Norm();    
 
    Type inv = 1 / norm;

    x *= inv;
    y *= inv;
    z *= inv;
    w *= inv;    
} // End of Normalize for Quaternion


//--------------------------------------------------------------------------
template<class Type>
void
Quaternion<Type>::Conjugate()
{
    x *= -1;
    y *= -1;
    z *= -1;       
} // End of Conjugate for Quaternion


//--------------------------------------------------------------------------
template<class Type>
void
Quaternion<Type>::Inverse()
{
    Type d = x*x + y*y + z*z + w*w;    

    Type inv = 1 / d;

    x = -x * inv;
    y = -y * inv;
    z = -z * inv;
    w =  w * inv;    
} // End of Inverse for Quaternion


//--------------------------------------------------------------------------
template<class Type>
void 
Quaternion<Type>::Slerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out ) 
{
	(static_cast< const Quaternion<Type>& >(*this) ).Slerp(rhs, t, out);
}

template<class Type>
void 
Quaternion<Type>::Slerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out ) const 
{
      if ( t < 0 )
          t = 0;
      else if ( t > 1 )
          t = 1;

      Quaternion<Type> rhs2 = rhs;           

      Type v = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;

      if ( v < 0 )
      {
          v = -v;

          rhs2 *= -1;
      } // End if         

	  if( v > 1 )	//by Shao
	  {
		  v = 1;
	  }

      Type angle = acos( v );

      if ( angle == 0 )
      {
          out.x = rhs.x;
          out.y = rhs.y;
          out.z = rhs.z;
          out.w = rhs.w;

          return;
      } // End if

      Type a = sin( angle * ( 1 - t ) );
      Type b = sin( angle * t  );
      Type c = 1 / sin( angle );

      Type l = a * c;
      Type r = b * c;

      out.x = l * x + r * rhs2.x;
      out.y = l * y + r * rhs2.y;
      out.z = l * z + r * rhs2.z;
      out.w = l * w + r * rhs2.w;      
} // End of Slerp for Quaternion


//--------------------------------------------------------------------------
template<class Type>
void 
	Quaternion<Type>::Nlerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out ) 
{
	(static_cast< const Quaternion<Type>& >(*this) ).Nlerp(rhs, t, out);
}

template<class Type>
void 
	Quaternion<Type>::Nlerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out ) const 
{
	if ( t < 0 )
		t = 0;
	else if ( t > 1 )
		t = 1;
	
	// Vector's Dot
	float v = ( x * rhs.x ) + ( y * rhs.y ) + ( z * rhs.z );	
	
	float invWeight = 1 - t;

	// CHECKME :: test before invWeight ????  or after ?????		Ethan
	if ( v < 0.0 )
		t *= -1;

	out = rhs * t + (*this) * invWeight;

} // End of Slerp for Quaternion


//--------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>
Quaternion<Type>::ConvertToMatrix3() const
{
	Matrix3x3<Type> out;

	Type *pEntries = out.GetEntries();

	const Type tx  = 2.0*x;
	const Type ty  = 2.0*y;
	const Type tz  = 2.0*z;
	const Type twx = tx*w;
	const Type twy = ty*w;
	const Type twz = tz*w;
	const Type txx = tx*x;
	const Type txy = ty*x;
	const Type txz = tz*x;
	const Type tyy = ty*y;
	const Type tyz = tz*y;
	const Type tzz = tz*z;

	pEntries[ 3 * 0 + 0 ] = 1.0f - (tyy + tzz);
	pEntries[ 3 * 1 + 0 ] = txy-twz;        
	pEntries[ 3 * 2 + 0 ] = txz+twy;

	pEntries[ 3 * 0 + 1 ] = txy+twz;        
	pEntries[ 3 * 1 + 1 ] = 1.0f-(txx+tzz); 
	pEntries[ 3 * 2 + 1 ] = tyz-twx;

	pEntries[ 3 * 0 + 2 ] = txz-twy;        	
	pEntries[ 3 * 1 + 2 ] = tyz+twx;        	
	pEntries[ 3 * 2 + 2 ] = 1.0f-(txx+tyy);	

	return out;
} // End of ConvertToMatrix3 for Quaternion

//--------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>
Quaternion<Type>::ConvertToMatrix4() const
{
    Matrix4x4<Type> out;

    Type *pEntries = out.GetEntries();

    pEntries[ 4 * 0 + 0 ] = 1 - 2 * ( y*y + z*z );
    pEntries[ 4 * 0 + 1 ] = 2 * ( x*y + w*z );
    pEntries[ 4 * 0 + 2 ] = 2 * ( x*z - w*y );
    pEntries[ 4 * 0 + 3 ] = 0;

    pEntries[ 4 * 1 + 0 ] = 2 * ( x*y - w*z );
    pEntries[ 4 * 1 + 1 ] = 1 - 2 * ( x*x + z*z );
    pEntries[ 4 * 1 + 2 ] = 2 * ( y*z + w*x );
    pEntries[ 4 * 1 + 3 ] = 0;

    pEntries[ 4 * 2 + 0 ] = 2 * ( x*z + w*y );
    pEntries[ 4 * 2 + 1 ] = 2 * ( y*z - w*x );
    pEntries[ 4 * 2 + 2 ] = 1 - 2 * ( x*x + y*y );
    pEntries[ 4 * 2 + 3 ] = 0;

    pEntries[ 4 * 3 + 0 ] = 0;
    pEntries[ 4 * 3 + 1 ] = 0;
    pEntries[ 4 * 3 + 2 ] = 0;
    pEntries[ 4 * 3 + 3 ] = 1;

    return out;
} // End of ConvertToMatrix4 for Quaternion

//--------------------------------------------------------------------------
template<class Type>
void
Quaternion<Type>::ConvertFromMatrix( const Matrix4x4<Type>& matrix)
{
	float qw2 = 0.25f * ( matrix.GetEntries()[0] + matrix.GetEntries()[5] + matrix.GetEntries()[10] + 1.0f );
	float qx2 = 0.25f * ( matrix.GetEntries()[0] - matrix.GetEntries()[5] - matrix.GetEntries()[10] + 1.0f );
	float qy2 = 0.25f * (-matrix.GetEntries()[0] + matrix.GetEntries()[5] - matrix.GetEntries()[10] + 1.0f );
	float qz2 = 0.25f * (-matrix.GetEntries()[0] - matrix.GetEntries()[5] + matrix.GetEntries()[10] + 1.0f );

	qw2 = ( qw2 < 0.0f )? 0.0f : sqrt(qw2);
	qx2 = ( qx2 < 0.0f )? 0.0f : sqrt(qx2);
	qy2 = ( qy2 < 0.0f )? 0.0f : sqrt(qy2);
	qz2 = ( qz2 < 0.0f )? 0.0f : sqrt(qz2);


	const int i = (qw2 > qx2) ?
		((qw2 > qy2) ? ((qw2 > qz2) ? 0 : 3) : ((qy2 > qz2) ? 2 : 3)) :
		((qx2 > qy2) ? ((qx2 > qz2) ? 1 : 3) : ((qy2 > qz2) ? 2 : 3));

	switch(i)
	{
	case 0:
		{
			w = qw2;
			x = qx2 * SIGN(matrix.GetEntries()[6] - matrix.GetEntries()[9]);
			y = qy2 * SIGN(matrix.GetEntries()[8] - matrix.GetEntries()[2]);
			z = qz2 * SIGN(matrix.GetEntries()[1] - matrix.GetEntries()[4]);
			break;
		}

	case 1:
		{
			w = qw2 * SIGN(matrix.GetEntries()[6] - matrix.GetEntries()[9]);
			x = qx2;			
			y = qy2 * SIGN(matrix.GetEntries()[1] + matrix.GetEntries()[4]);
			z = qz2 * SIGN(matrix.GetEntries()[8] + matrix.GetEntries()[2]);
			break;
		}

	case 2:
		{
			w = qw2 * SIGN(matrix.GetEntries()[8] - matrix.GetEntries()[2]);
			x = qx2 * SIGN(matrix.GetEntries()[1] + matrix.GetEntries()[4]);
			y = qy2;			
			z = qz2 * SIGN(matrix.GetEntries()[6] + matrix.GetEntries()[9]);
			break;
		}

	case 3:
		{			
			w = qw2 * SIGN(matrix.GetEntries()[1] - matrix.GetEntries()[4]);
			x = qx2 * SIGN(matrix.GetEntries()[2] + matrix.GetEntries()[8]);
			y = qy2 * SIGN(matrix.GetEntries()[6] + matrix.GetEntries()[9]);
			z = qz2;
			break;
		}
	}


	Normalize();



	//const float qw2 = 0.25f * (matrix.GetEntries()[0] + matrix.GetEntries()[5] + matrix.GetEntries()[10] + 1.0f);
	//const float qx2 = qw2 - 0.5f	* (matrix.GetEntries()[5]  + matrix.GetEntries()[10]);
	//const float qy2 = qw2 - 0.5f	* (matrix.GetEntries()[10] + matrix.GetEntries()[0]);
	//const float qz2 = qw2 - 0.5f	* (matrix.GetEntries()[0]  + matrix.GetEntries()[5]);

	//const int i = (qw2 > qx2) ?
	//	((qw2 > qy2) ? ((qw2 > qz2) ? 0 : 3) : ((qy2 > qz2) ? 2 : 3)) :
	//	((qx2 > qy2) ? ((qx2 > qz2) ? 1 : 3) : ((qy2 > qz2) ? 2 : 3));

	//switch(i)
	//{
	//case 0:
	//	{
	//		w = (float) sqrt(qw2);
	//		const float tmp = 0.25f / w;
	//		x = (matrix.GetEntries()[6] - matrix.GetEntries()[9]) * tmp;
	//		y = (matrix.GetEntries()[8] - matrix.GetEntries()[2]) * tmp;
	//		z = (matrix.GetEntries()[1] - matrix.GetEntries()[4]) * tmp;
	//		break;
	//	}

	//case 1:
	//	{
	//		x = (float) sqrt(qx2);
	//		const float tmp = 0.25f / x;
	//		w = (matrix.GetEntries()[6] - matrix.GetEntries()[9]) * tmp;
	//		y = (matrix.GetEntries()[4] - matrix.GetEntries()[1]) * tmp;
	//		z = (matrix.GetEntries()[8] - matrix.GetEntries()[2]) * tmp;
	//		break;
	//	}

	//case 2:
	//	{
	//		y = (float) sqrt(qy2);
	//		const float tmp = 0.25f / y;
	//		w = (matrix.GetEntries()[8] - matrix.GetEntries()[2]) * tmp;
	//		z = (matrix.GetEntries()[9] - matrix.GetEntries()[6]) * tmp;
	//		x = (matrix.GetEntries()[1] - matrix.GetEntries()[4]) * tmp;
	//		break;
	//	}

	//case 3:
	//	{
	//		z = (float) sqrt(qz2);
	//		const float tmp = 0.25f / z;
	//		w = (matrix.GetEntries()[1] - matrix.GetEntries()[4]) * tmp;
	//		x = (matrix.GetEntries()[2] - matrix.GetEntries()[8]) * tmp;
	//		y = (matrix.GetEntries()[6] - matrix.GetEntries()[9]) * tmp;
	//		break;
	//	}
	//}

	//if ( w < 0 ) *this = SetMinus(*this);

	//Normalize();
} // End of ConvertFromMatrix for Quaternion

//--------------------------------------------------------------------------
template<class Type>
void 
Quaternion<Type>::SetZero()
{
	x = y = z = w = 0;
} // End of SetZero for Quaternion

//--------------------------------------------------------------------------
template<class Type>
void
Quaternion<Type>::SetIdentity(void)
{
	x = y = z = w = 1;
} // End of SetIdentity for Quaternion

//--------------------------------------------------------------------------
template<class Type>
void
Quaternion<Type>::GetAxisAngle(Vector3D<Type>& Axis, float& Angle) const
{
	Type sum = x*x + y*y + z*z;

	if ( sum < 1.0e-6f )
	{
		Angle = 0.0f;
		Axis = Vector3D<float>(1.0f, 0.0f, 0.0f);
		return;
	}

	float OneOver = 1.0f/(float)sqrtf( sum );
	Axis = Vector3D<float>(OneOver * x, OneOver * y, OneOver * z);
	float w = w;

	if ( abs(w - 1.0f) < 1.0e-6f)
	{
		Angle = 0.0f;
	}
	else
	{
		Angle = 2.0f * (float)acosf( w );
	}
} // End of GetAxisAngle for Quaternion

//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>&
Quaternion<Type>::SetMinus(const Quaternion<Type> &q)
{
	x = -q.x;
	y = -q.y;
	z = -q.z;
	w = -q.w;
	return (*this); //Quaternion<Type>(-q.x, -q.y, -q.z, -q.w);
} // End of SetMinus for Quaternion

//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>&
Quaternion<Type>::SetQuat(const Vector3D<Type>& vec, float _w)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = _w;

	return (*this);
} // End of SetQuat for Quaternion

//--------------------------------------------------------------------------
template<class Type>
Quaternion<Type>&
Quaternion<Type>::SetQuat(float angle, const Vector3D<Type>& axis)
{
	float halfAngle = angle *0.5f;
	float sinHalfAngle = sinf(halfAngle);
	float cosHalfAngle = cosf(halfAngle);
	Vector3D<float> tmp = axis * sinHalfAngle;

	SetQuat(tmp, cosHalfAngle);

	return (*this);
} // End of SetQuat for Quaternion

template<class Type>
Vector3D<Type> Quaternion<Type>::XAxis() const
{
	const Type ty  = y*2;
	const Type tz  = z*2;
	const Type twy = ty*w;
	const Type twz = tz*w;
	const Type txy = ty*x;
	const Type txz = tz*x;
	const Type tyy = ty*y;
	const Type tyz = tz*y;
	const Type tzz = tz*z;

	return Vector3D<Type>(1.0f - (tyy + tzz), txy-twz, txz+twy);
}

template<class Type>
Vector3D<Type> Quaternion<Type>::YAxis() const
{
	const Type tx  = x*2;
	const Type ty  = y*2;
	const Type tz  = z*2;
	const Type twx = tx*w;
	const Type twy = ty*w;
	const Type twz = tz*w;
	const Type txx = tx*x;
	const Type txy = ty*x;
	//const Type txz = tz*x;
	//const Type tyy = ty*y;
	const Type tyz = tz*y;
	const Type tzz = tz*z;

	return Vector3D<Type>(txy+twz, 1.0f-(txx+tzz), tyz-twx);

}

template<class Type>
Vector3D<Type> Quaternion<Type>::ZAxis() const
{
	const Type tx  = x*2;
	const Type ty  = y*2;
	const Type tz  = z*2;
	const Type twx = tx*w;
	const Type twy = ty*w;
	//const Type twz = tz*w;
	const Type txx = tx*x;
	//const Type txy = ty*x;
	const Type txz = tz*x;
	const Type tyy = ty*y;
	const Type tyz = tz*y;
	//const Type tzz = tz*z;

	return Vector3D<Type>(txz-twy, tyz+twx, 1.0f-(txx+tyy));

}

template<class Type>
Vector3D<Type> Quaternion<Type>::TransformVector3D(const Vector3D<Type>& v) const
{
	Quaternion<Type> inv(x, y, z, w);
	inv.Inverse();

	Quaternion<Type> input(v.x, v.y, v.z, 0);

	Quaternion<Type> output = (*this) * input * inv;

	return Vector3D<Type>(output.x, output.y, output.z);
}

} // End of namespace hive