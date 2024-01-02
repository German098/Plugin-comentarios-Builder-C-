#ifndef GEO_POINT_3D_H
#define GEO_POINT_3D_H

#include "_gpoint.h"

// Resolucion geometrica y computacional para calculos internos.
// Para la pantalla dependera de la transformacion.
// Para discretizar las entidades del usuario.

using std::wostream;
using std::wistream;
using std::min;
using std::max;

namespace InesMath
{
	enum TNPlane { plXY, plXZ, plYZ, plNone };
	enum TNAxis { axX, axY, axZ, axNone };

	template<class T>
	class T3DSizeEx;
	template<class T>
	class T3DRectEx;
	template<class T>
	class T3DVectorEx;
	template<class T>
	class T3DLineEx;
	template<class T>
	class T3DVectorEx;
	template<class T>
	class TMatrixEx;

	// class TPointEx
	// ----- ------
	//
	template<class T>
	class T3DPointEx
	{
	  public:
		T x, y, z;

		// Constructors
		T3DPointEx( )
		{
			x = 0;
			y = 0;
			z = 0;
		}
		T3DPointEx( T _x, T _y, T _z )
		{
			x = _x;
			y = _y;
			z = _z;
		}
		T3DPointEx( const T3DSizeEx<T> &size )
		{
			x = size.cx;
			y = size.cy;
			z = size.cz;
		}

		T3DPointEx( const TPointEx<T> &point, TNPlane pl = plXY );
		T3DPointEx( const TSizeEx<T> &size, TNPlane pl = plXY );

		T3DPointEx( const TPoint &point, TNPlane pl = plXY );
		T3DPointEx( const TSize &size, TNPlane pl = plXY );

		void Set( const T3DPointEx<T> *P )
		{
			x = P->x;
			y = P->y;
			z = P->z;
		}

		// Indica si dos puntos son similares dentro de una tolerancia
		bool Similar( const T3DPointEx<T> &other, double tol = RES_GEOM )
		{
			double d;

			d = ( x - other.x ) * ( x - other.x ) + ( y - other.y ) * ( y - other.y ) + ( z - other.z ) * ( z - other.z );
			return ( d < ( tol * tol ) );
		}

		// Information functions/operators
		T3DPointEx<T> operator=( const T3DPointEx<T> &other );
		bool operator==( const T3DPointEx<T> &other ) const;
		bool operator!=( const T3DPointEx<T> &other ) const;
		bool operator>=( const T3DPointEx<T> &other ) const;
		bool operator<=( const T3DPointEx<T> &other ) const;
		bool operator>( const T3DPointEx<T> &other ) const;
		bool operator<( const T3DPointEx<T> &other ) const;
		double operator^( const T3DPointEx<T> &other ) const; // Coseno del angulo entre dos vectores

		// Functions/binary-operators that return points or sizes
		T3DPointEx<T> OffsetBy( T dx, T dy, T dz ) const
		{
			return T3DPointEx<T>( x + dx, y + dy, z + dz );
		}
		T3DPointEx<T> operator+( const T3DSizeEx<T> &size ) const;
		T3DSizeEx<T> operator-( const T3DPointEx<T> &point ) const;
		T3DPointEx<T> operator-( const T3DSizeEx<T> &size ) const;
		T3DPointEx<T> operator-( ) const
		{
			return T3DPointEx<T>( -x, -y, -z );
		}
		T3DPointEx<T> operator*( const T3DSizeEx<T> & ) const;
		T3DPointEx<T> operator/( const T3DSizeEx<T> & ) const;
		T3DPointEx<T> operator+( const T factor ) const;
		T3DPointEx<T> operator-( const T factor ) const;
		T3DPointEx<T> operator*( const T factor ) const;
		T3DPointEx<T> operator/( const T factor ) const;

		// Asociatividad contraria de los operadores

		friend T3DPointEx<T> operator+( const T &factor, const T3DPointEx<T> &P )
		{
			return P + factor;
		}
		friend T3DPointEx<T> operator*( const T &factor, const T3DPointEx<T> &P )
		{
			return P * factor;
		}

		// Functions/assignement-operators that modify this point
		T3DPointEx<T> &Normalize( );

		T3DPointEx<T> &Offset( T dx, T dy, T dz );
		T3DPointEx<T> &operator+=( const T3DSizeEx<T> &size );
		T3DPointEx<T> &operator-=( const T3DSizeEx<T> &size );
		T3DPointEx<T> &operator*=( const T3DSizeEx<T> & );
		T3DPointEx<T> &operator/=( const T3DSizeEx<T> & );
		T3DPointEx<T> &operator*=( const T factor );
		T3DPointEx<T> &operator/=( const T factor );

		//#ifndef _owl_not_supported_
		// 'Casting' al TPoint de las OWL
		//	 operator TPoint() { return TPoint( int(x), int(y) ); }
		//#endif

		void RotationX( const T &Angle )
		{
			T3DPointEx<T> OldP = *this;
			y = OldP.y * cos( Angle ) - OldP.z * sin( Angle );
			z = OldP.y * sin( Angle ) + OldP.z * cos( Angle );
		}
		void RotationY( const T &Angle )
		{
			T3DPointEx<T> OldP = *this;
			x = OldP.x * cos( Angle ) + OldP.z * sin( Angle );
			z = -OldP.x * sin( Angle ) + OldP.z * cos( Angle );
		}
		void RotationZ( const T &Angle )
		{
			T3DPointEx<T> OldP = *this;
			x = OldP.x * cos( Angle ) - OldP.y * sin( Angle );
			y = OldP.x * sin( Angle ) + OldP.y * cos( Angle );
		}

		void RotationCosSinX( const T &vcos, const T &vsin )
		{
			T3DPointEx<T> OldP = *this;
			y = OldP.y * vcos - OldP.z * vsin;
			z = OldP.y * vsin + OldP.z * vcos;
		}
		void RotationCosSinY( const T &vcos, const T &vsin )
		{
			T3DPointEx<T> OldP = *this;
			x = OldP.x * vcos + OldP.z * vsin;
			z = -OldP.x * vsin + OldP.z * vcos;
		}
		void RotationCosSinZ( const T &vcos, const T &vsin )
		{
			T3DPointEx<T> OldP = *this;
			x = OldP.x * vcos - OldP.y * vsin;
			y = OldP.x * vsin + OldP.y * vcos;
		}

		void Rotation( const T &Angle, const T3DPointEx<T> &P )
		{
			T3DPointEx<T> OldP = *this;
			double ca = cos( Angle );
			double sa = sin( Angle );
			x = OldP.x * ( ca + P.x * P.x * ( 1 - ca ) ) + OldP.y * ( P.x * P.y * ( 1 - ca ) + P.z * sa ) + OldP.z * ( P.x * P.z * ( 1 - ca ) - P.y * sa );
			y = OldP.x * ( P.x * P.y * ( 1 - ca ) - P.z * sa ) + OldP.y * ( ca + P.y * P.y * ( 1 - ca ) ) + OldP.z * ( P.y * P.z * ( 1 - ca ) + P.x * sa );
			z = OldP.x * ( P.x * P.z * ( 1 - ca ) + P.y * sa ) + OldP.y * ( P.y * P.z * ( 1 - ca ) - P.x * sa ) + OldP.z * ( ca + P.z * P.z * ( 1 - ca ) );
		}

		void Scale( const T3DPointEx<T> &P )
		{
			x *= P.x;
			y *= P.y;
			z *= P.z;
		}

		void ApplyMatrix( TMatrixEx<T> &M )
		{
			T X = x;
			T Y = y;
			T Z = z;

			x = X * M[ 0 ] + Y * M[ 4 ] + Z * M[ 8 ] + M[ 12 ];
			y = X * M[ 1 ] + Y * M[ 5 ] + Z * M[ 9 ] + M[ 13 ];
			z = X * M[ 2 ] + Y * M[ 6 ] + Z * M[ 10 ] + M[ 14 ];
		}

		double Distancia( const T3DPointEx<T> &P )
		{
			// distancia de un punto a otro
			double Aux = ( x - P.x ) * ( x - P.x ) + ( y - P.y ) * ( y - P.y ) + ( z - P.z ) * ( z - P.z );
			return ( Aux > RES_COMP2 ) ? sqrt( Aux ) : 0;
		}

		double Distancia2D( const T3DPointEx<T> &P, TNPlane plane )
		{
			T3DPointEx<T> P1, P2;

			P1 = *this;
			P2 = P;
			if ( plane == plXY ) {
				P1.z = 0;
				P2.z = 0;
			} else if ( plane == plXZ ) {
				P1.y = 0;
				P2.y = 0;
			} else if ( plane == plYZ ) {
				P1.x = 0;
				P2.x = 0;
			}
			return P1.Distancia( P2 );
		}

		double DistanciaSqr( const T3DPointEx<T> &P )
		{
			// distancia de un punto a otro
			return ( ( x - P.x ) * ( x - P.x ) + ( y - P.y ) * ( y - P.y ) + ( z - P.z ) * ( z - P.z ) );
		}

		double CosV( const T3DPointEx<T> &P )
		{
			double m1, m2, m3, aux;

			m1 = ( x * x ) + ( y * y ) + ( z * z );
			m2 = ( P.x * P.x ) + ( P.y * P.y ) + ( P.z * P.z );
			m3 = m1 * m2;
			if ( m3 > RES_COMP2 ) m3 = sqrt( m3 );
			if ( m3 <= RES_COMP2 ) return -1;
			aux = ( x * P.x + y * P.y + z * P.z ) / m3;
			if ( -1.0 <= aux && aux <= 1.0 ) return aux;
			return -1;
		}

		void SymAxis( const T3DPointEx<T> &P1, const T3DPointEx<T> &P2 )
		{
			T3DLineEx<T> r( P1, P2 );
			SymAxis( r );
		}
		void SymAxis( const T3DLineEx<T> &r )
		{
			T3DPointEx<T> p = r.ClosestPoint( *this );
			T3DVectorEx<T> v( *this, p );
			v.Modulo( v.Modulo( ) * 2.0 );
			*this += v.size;
		}

		friend wostream &operator<<( wostream &os, const T3DPointEx<T> &p )
		{
			return os << p.x << ' ' << ',' << ' ' << p.y << ' ' << ',' << ' ' << p.z;
		}
		friend wistream &operator>>( wistream &is, T3DPointEx<T> &p )
		{
			wchar_t c;
			return is >> p.x >> c >> p.y >> c >> p.z;
		}
	};

	//
	// class TSizeEx<T>
	// ----- -----
	//
	template<class T>
	class T3DSizeEx
	{
	  public:
		T cx, cy, cz;

		// Constructors
		T3DSizeEx( )
		{
			cx = cy = cz = 0;
		}
		T3DSizeEx( T dx, T dy, T dz )
		{
			cx = dx;
			cy = dy;
			cz = dz;
		}
		T3DSizeEx<T>( const T3DPointEx<T> &point )
		{
			cx = point.x;
			cy = point.y;
			cz = point.z;
		}

		T3DSizeEx<T>( const TSizeEx<T> &size, TNPlane pl = plXY );
		T3DSizeEx<T>( const TSize &size, TNPlane pl = plXY );

		// Information functions/operators
		T3DSizeEx<T> operator=( const T3DSizeEx<T> &other );
		bool operator==( const T3DSizeEx<T> &other ) const;
		bool operator!=( const T3DSizeEx<T> &other ) const;
		bool operator>=( const T3DSizeEx<T> &other ) const;
		bool operator<=( const T3DSizeEx<T> &other ) const;
		bool operator>( const T3DSizeEx<T> &other ) const;
		bool operator<( const T3DSizeEx<T> &other ) const;
		double Magnitude( ) const;

		bool Similar( const T3DSizeEx<T> &other, double tol = RES_GEOM )
		{
			double d;

			d = ( cx - other.cx ) * ( cx - other.cx ) + ( cy - other.cy ) * ( cy - other.cy ) + ( cz - other.cz ) * ( cz - other.cz );
			return ( d < ( tol * tol ) );
		}

		// Functions/binary-operators that return sizes
		T3DSizeEx<T> operator+( const T3DSizeEx<T> &size ) const;
		T3DSizeEx<T> operator-( const T3DSizeEx<T> &size ) const;
		T3DSizeEx<T> operator-( ) const
		{
			return T3DSizeEx<T>( -cx, -cy, -cz );
		}
		T3DSizeEx<T> operator*( const T3DSizeEx<T> &size ) const;
		T3DSizeEx<T> operator/( const T3DSizeEx<T> &size ) const;
		T3DSizeEx<T> operator+( const T factor ) const;
		T3DSizeEx<T> operator-( const T factor ) const;
		T3DSizeEx<T> operator*( const T factor ) const;
		T3DSizeEx<T> operator/( const T factor ) const;

		friend T3DSizeEx<T> operator+( const T &factor, const T3DSizeEx<T> &S )
		{
			return S + factor;
		}
		friend T3DSizeEx<T> operator*( const T &factor, const T3DSizeEx<T> &S )
		{
			return S * factor;
		}

		// Functions/assignement-operators that modify this size
		T3DSizeEx<T> &operator+=( const T3DSizeEx<T> &size );
		T3DSizeEx<T> &operator-=( const T3DSizeEx<T> &size );
		T3DSizeEx<T> &operator*=( const T factor );
		T3DSizeEx<T> &operator/=( const T factor );

		//#ifndef _owl_not_supported_
		// 'Casting' explicito al TSize de las OWL
		//	 operator TSize() { return TSize(int(cx), int(cy)); }
		//#endif

		friend wostream &operator<<( wostream &os, const T3DSizeEx<T> &s )
		{
			return os << "( " << s.cx << " x " << s.cy << " x " << s.cz << " )";
		}
		friend wistream &operator>>( wistream &is, T3DSizeEx<T> &s )
		{
			wchar_t c;
			return is >> c >> s.cx >> c >> s.cy >> c >> s.cz >> c;
		}
	};

	//
	// class TRectEx<T>
	// ----- -----
	//
	template<class T>
	class T3DRectEx
	{
	  public:
		T left, top, front, right, bottom, back;

		// Constructors
		T3DRectEx( )
		{
			left = top = front = right = bottom = back = 0;
		}
		/*    T3DRectEx( T3DRectEx<T> &rect ) { left = rect.left;  top = rect.top; front = rect.front;
														  right = rect.right; bottom = rect.bottom; back = rect.back; }*/
		T3DRectEx( T _left, T _top, T _front, T _right, T _bottom, T _back );
		T3DRectEx( const T3DPointEx<T> &upLeftFront, const T3DPointEx<T> &loRightBack );
		T3DRectEx( const T3DPointEx<T> &origin, const T3DSizeEx<T> &extent );

		// (re)Initializers
		void SetNull( );
		void SetEmpty( )
		{
			SetNull( );
		}
		void Set( T _left, T _top, T _front, T _right, T _bottom, T _back );

		// Type Conversion operators
		operator const T3DPointEx<T> *( ) const
		{
			return (const T3DPointEx<T> *) this;
		}
		operator T3DPointEx<T> *( )
		{
			return (T3DPointEx<T> *) this;
		}

		// Testing functions
		bool IsEmpty( ) const;
		bool IsNull( ) const;
		bool IsValid( ) const;
		bool IsPlain( ) const;
		T3DRectEx<T> operator=( const T3DRectEx<T> &other );
		bool operator==( const T3DRectEx<T> &other ) const;
		bool operator!=( const T3DRectEx<T> &other ) const;

		// Information/access functions(const and non-const)
		T3DPointEx<T> TopLeftFront( )
		{
			return T3DPointEx<T>( left, top, front );
		}
		T3DPointEx<T> TopLeftBack( )
		{
			return T3DPointEx<T>( left, top, back );
		}
		T3DPointEx<T> TopRightFront( )
		{
			return T3DPointEx<T>( right, top, front );
		}
		T3DPointEx<T> TopRightBack( )
		{
			return T3DPointEx<T>( right, top, back );
		}
		T3DPointEx<T> BottomLeftFront( )
		{
			return T3DPointEx<T>( left, bottom, front );
		}
		T3DPointEx<T> BottomLeftBack( )
		{
			return T3DPointEx<T>( left, bottom, back );
		}
		T3DPointEx<T> BottomRightFront( )
		{
			return T3DPointEx<T>( right, bottom, front );
		}
		T3DPointEx<T> BottomRightBack( )
		{
			return T3DPointEx<T>( right, bottom, back );
		}

		void ApplyMatrix( TMatrixEx<T> &M )
		{
			T X = left;
			T Y = top;
			T Z = front;

			left = X * M[ 0 ] + Y * M[ 4 ] + Z * M[ 8 ] + M[ 12 ];
			top = X * M[ 1 ] + Y * M[ 5 ] + Z * M[ 9 ] + M[ 13 ];
			front = X * M[ 2 ] + Y * M[ 6 ] + Z * M[ 10 ] + M[ 14 ];

			X = right;
			Y = bottom;
			Z = back;
			right = X * M[ 0 ] + Y * M[ 4 ] + Z * M[ 8 ] + M[ 12 ];
			bottom = X * M[ 1 ] + Y * M[ 5 ] + Z * M[ 9 ] + M[ 13 ];
			back = X * M[ 2 ] + Y * M[ 6 ] + Z * M[ 10 ] + M[ 14 ];

			if ( left > right ) {
				X = left;
				left = right;
				right = X;
			}
			if ( top > bottom ) {
				Y = top;
				top = bottom;
				bottom = Y;
			}
			if ( front > back ) {
				Z = front;
				front = back;
				back = X;
			}
		}

		T3DPointEx<T> Center( ) const
		{
			return T3DPointEx<T>( ( left + right ) / 2, ( top + bottom ) / 2, ( front + back ) / 2 );
		}
		T Width( ) const
		{
			return right - left;
		}
		T Height( ) const
		{
			return bottom - top;
		}
		T Depth( ) const
		{
			return back - front;
		}
		T3DSizeEx<T> Size( ) const
		{
			return T3DSizeEx<T>( Width( ), Height( ), Depth( ) );
		}
		double Volume( ) const
		{
			return ( (double) Width( ) ) * ( (double) Height( ) ) * ( (double) Depth( ) );
		}

		bool Contains( const T3DPointEx<T> &point ) const;
		bool Contains( const T3DRectEx<T> &other ) const;
		bool Touches( const T3DRectEx<T> &other ) const;
		T3DRectEx<T> OffsetBy( T dx, T dy, T dz ) const;
		T3DRectEx<T> operator+( const T3DSizeEx<T> &size ) const;
		T3DRectEx<T> operator-( const T3DSizeEx<T> &size ) const;
		T3DRectEx<T> InflatedBy( T dx, T dy, T dz ) const;
		T3DRectEx<T> InflatedBy( const T3DSizeEx<T> &size ) const;
		T3DRectEx<T> Normalized( ) const;
		T3DRectEx<T> operator&( T3DRectEx<T> &other );
		T3DRectEx<T> operator|( T3DRectEx<T> &other );

		// Manipulation functions/operators
		T3DRectEx<T> &Normalize( );
		T3DRectEx<T> &Offset( T dx, T dy, T dz );
		T3DRectEx<T> &operator+=( const T3DSizeEx<T> &delta );
		T3DRectEx<T> &operator-=( const T3DSizeEx<T> &delta );
		T3DRectEx<T> &Inflate( T dx, T dy, T dz );
		T3DRectEx<T> &Inflate( const T3DSizeEx<T> &delta );
		T3DRectEx<T> &operator&=( T3DRectEx<T> &other );
		T3DRectEx<T> &operator|=( T3DRectEx<T> &other );
		friend ostream &operator<<( ostream &os, const T3DRectEx<T> &r );
	};

	template<class T>
	class T3DVectorEx
	{
	  public:
		T3DPointEx<T> org; // origen del vector
		T3DSizeEx<T> size; // tamanyo del vector (x,y,z): puede ser negativo, ojo

		T3DVectorEx( ) { };
#if defined( _WIN64 ) || defined( __clang__ )
		T3DVectorEx( const T3DSizeEx<T> &_size, const T3DPointEx<T> &_org = T3DPointEx<T>( 0, 0, 0 ) )
		{
#else
		T3DVectorEx( const T3DSizeEx<T> &_size, const T3DPointEx<T> &_org = T3DPoint( 0, 0, 0 ) )
		{
#endif
			org = _org;
			size = _size;
		}
		T3DVectorEx( const T3DPointEx<T> &first, const T3DPointEx<T> &last )
		{
			org = first;
			size = last - first;
		}
		// Constructor de un vector a partir de las coordenadas esfericas
#if defined( _WIN64 ) || defined( __clang__ )
		T3DVectorEx( T Modulo, double AngleX, double AngleZ, const T3DPointEx<T> &_org = T3DPointEx<T>( 0, 0, 0 ) );
#else
		T3DVectorEx( T Modulo, double AngleX, double AngleZ, const T3DPointEx<T> &_org = T3DPointEx( 0, 0, 0 ) );
#endif

		double Modulo( ) const
		{
			return size.Magnitude( );
		}
		double Angulo( TNPlane ) const;
		double Angle( const T3DVectorEx<T> &V ) const;
		double AngleG( const T3DVectorEx<T> &V ) const;

		T3DVectorEx<T> Normal( const T3DVectorEx<T> & ) const;
		T3DVectorEx<T> Unitario( );

		T3DVectorEx<T> &Modulo( T ); // Cambiar el modulo del vector al nuevo modulo
		// T3DVectorEx<T>& Girar( const T3DVectorEx<T>&, const double );
		T3DVectorEx<T> &ApplyMatrix( TMatrixEx<T> &M );

		T3DVectorEx<T> operator=( const T3DVectorEx<T> & );
		bool operator==( const T3DVectorEx<T> & ) const;
		bool operator!=( const T3DVectorEx<T> & ) const;
		T3DVectorEx<T> operator+( const T3DVectorEx<T> & ) const;
		T3DVectorEx<T> operator-( const T3DVectorEx<T> & ) const;
		double operator*( const T3DVectorEx<T> & ) const; // Producto escalar
		double operator^( const T3DVectorEx<T> & ) const; // Coseno del angulo entre dos vectores

		T3DVectorEx<T> operator||( const T3DVectorEx<T> & ) const; // Producto vectorial
	};

	//
	// Clase TRecta: define las operaciones basicas a efectuar con una recta;
	//					  se tiene simultaneamente la recta en diferentes ecuaciones
	//					  (Ax+By+C = 0, y = mx+b, (x-x1)/(x2-x1) = (y-y1)/(y2-y1) )
	//
	//					  El metodo Offset devuelve una paralela a la recta original
	//					  por la derecha si el valor del parametro es positivo, o por la
	//					  izquierda si el valor del parametro es negativo
	//

	template<class T>
	class T3DLineEx
	{
	  protected:
		void Init( const T3DPointEx<T> &, const T3DPointEx<T> & );
		//		bool Vertical() const { return B==0; }

	  public:
		T3DPointEx<T> start, end; // ecuacion de la recta que pasa por 2 puntos
								  //		double pendiente, ordenada;   // ecuacion de la pendiente
								  //		double A , B, C;               // ecuacion en forma general

		T3DLineEx( )
		{
		}
		T3DLineEx( const T3DPointEx<T> &_org, const T3DVectorEx<T> &_dir )
		{
			Init( _org, _org + _dir.size );
		}
		T3DLineEx( const T3DPointEx<T> &_start, const T3DPointEx<T> &_end )
		{
			Init( _start, _end );
		}
		//		T3DLineEx( const double, const double, const double );
		//		T3DLineEx( const double, const double );

		// rectas paralelas
		bool operator||( const T3DLineEx<T> &R ) const;
		T3DPointEx<T> operator+( const T3DLineEx<T> & ) const; // interseccion de dos rectas

		//		T3DLineEx<T> 	Offset (const T) const;               // paralela a distancia X
		T3DVectorEx<T> Director( ) const
		{
			return T3DVectorEx<T>( start, end );
		}
		double Distancia( const T3DPointEx<T> & ) const; // distancia de un punto a una recta

		// funciones prestadas de Eliseo para calcular la verdadera distancia de un punto a una recta
		T3DPointEx<T> ClosestPoint( const T3DPointEx<T> & ) const;								  // punto de la recta mas proximo al punto
		bool ClosestPoint( const T3DPointEx<T> &P, T3DPointEx<T> &closest, double &param ) const; // devuelve punto de la recta mas proximo al punto y su valor parametrico.
		double Distance( const T3DPointEx<T> & ) const;											  // distancia de un punto a una recta

		bool IsValid( );

		bool Touches( const T3DPointEx<T> & ) const;
		bool Touches( const T3DLineEx<T> & ) const;
	};

	//****************************************************************************
	//****************************************************************************
	//
	// class T3DPlaneEx<T>
	// ----- -----
	//

	template<class T>
	class T3DPlaneEx
	{
	  public:
		T3DPointEx<T> pto;	   // Punto del Plano.
		T3DVectorEx<T> normal; // vector normal al plano.
		T a, b, c, d;		   // Coeficientes de la ecuacion del plano.
							   // LA ECUACION DE ESTOS PLANOS ES: ax+by+cz = d

		// Constructor por defecto
		T3DPlaneEx( )
		{
			a = 0;
			b = 0;
			c = 0;
			d = 0;
		}
		// Constructor con los coeficientes de la ecuacion del plano.
		T3DPlaneEx( T, T, T, T );
		// Constructor con los planos basicos
		T3DPlaneEx( TNPlane p )
		{
			pto = T3DPointEx<T>( 0, 0, 0 );
			normal.size = ( p == plXY ) ? T3DSizeEx<T>( 0, 0, 1 ) : ( p == plXZ ) ? T3DSizeEx<T>( 0, 1, 0 ) : T3DSizeEx<T>( 1, 0, 0 );
			normal.org = T3DPointEx<T>( 0, 0, 0 );
			a = normal.size.cx;
			b = normal.size.cy;
			c = normal.size.cz;
			d = ( pto.x * normal.size.cx ) + ( pto.y * normal.size.cy ) + ( pto.z * normal.size.cz );
			Normalizar( );
		}
		// Constructor con tres puntos del plano.
		T3DPlaneEx( const T3DPointEx<T> &first, const T3DPointEx<T> &second, const T3DPointEx<T> &third );
		// Constructor con un punto del plano y una normal.
		T3DPlaneEx( const T3DPointEx<T> &_pto, const T3DVectorEx<T> &_normal );

		void Set( const T3DPlaneEx<T> &plane );
		void Set( const T3DPointEx<T> &_pto, const T3DVectorEx<T> &_normal );

		bool IsValid( ) const;
		void Normalizar( );
		T DistPunto( T3DPointEx<T> &punto );
		T3DPointEx<T> ToPlane( const T3DPointEx<T> &punto, const T3DVectorEx<T> &vecdir );
		T3DPointEx<T> Simetric( T3DPointEx<T> punto );
		bool IsEqual( const T3DPlaneEx<T> &other );

		T3DPointEx<T> operator+( const T3DLineEx<T> & ) const; // interseccion del  plano con
															   // una recta.
		T3DLineEx<T> operator+( const T3DPlaneEx<T> & ) const; // Interseccion de un plano con otro

		// Funciones "prestadas" de Antonio para el calculo de intersecciones con uperficies discretas.
		T X( T y, T z );
		T Y( T x, T z );
		T Z( T x, T y );
		bool Intersect( T3DPointEx<T> &p1, T3DPointEx<T> &p2 );
		bool Intersect( T3DPointEx<T> &p1, T3DPointEx<T> &p2, T3DPointEx<T> &p3, T3DPointEx<T> &p4 );
		T3DPointEx<T> IntersectPoint( const T3DPointEx<T> &p1, const T3DPointEx<T> &p2 );
		T PointPosition( T3DPointEx<T> &p1 );

		T3DPlaneEx<T> &ApplyMatrix( TMatrixEx<T> &M );

		friend wostream &operator<<( wostream &os, const T3DPlaneEx<T> &pl )
		{
			return os << pl.pto << ' ' << ';' << ' ' << pl.normal.org << ' ' << ';' << ' ' << pl.normal.size;
		}
		friend wistream &operator>>( wistream &is, T3DPlaneEx<T> &pl )
		{
			wchar_t c;
			return is >> pl.pto >> c >> pl.normal.org >> c >> pl.normal.size;
		}

		T3DPlaneEx<T> operator=( const T3DPlaneEx<T> &other );
		bool operator==( const T3DPlaneEx<T> &other ) const;
		bool operator!=( const T3DPlaneEx<T> &other ) const;
	};

	//****************************************************************************
	//****************************************************************************
	//
	// class TMatxEx<T>   y derivadas....
	// ----- -----
	//
	template<class T>
	class TMatxEx
	{
	  private:
		T **mtx;
		int order;

	  public:
		TMatxEx( int ord = 4 );
		TMatxEx( const TMatxEx<T> &other );
		virtual ~TMatxEx( );

		T *Matrix( )
		{
			return *mtx;
		}
		T &Element( int i, int j )
		{
			return mtx[ j ][ i ];
		}
		const T &Element( int i, int j ) const
		{
			return mtx[ j ][ i ];
		}

		void LoadIdentity( );

		void Inverse( TMatxEx<T> * );
		double Determinant( ) const;
		void Transpose( );

		void TransformPoint( T x, T y, T z, T &xout, T &yout, T &zout );

		T &operator( )( const int &i, const int &j )
		{
			return mtx[ j ][ i ];
		}
		TMatxEx<T> &operator=( const TMatxEx<T> &other );
		TMatxEx<T> operator*( const TMatxEx<T> &other );
		TMatxEx<T> &operator*=( const TMatxEx<T> &other );
		TMatxEx<T> &operator/=( const double &fact );
	};

	template<class T>
	class TMatxCofactorEx : public TMatxEx<T>
	{
	  public:
		TMatxCofactorEx( const TMatxEx<T> &a, int corder, int aI, int aJ );
	};

	//****************************************************************************
	//****************************************************************************
	//
	// class TMatrixEx<T>   y derivadas....
	// ----- -----
	//
	template<class T>
	class TMatrixEx
	{
	  public:
		TMatrixEx( ); // Constructor matriz unitaria
		TMatrixEx( T *m );
		TMatrixEx( const TMatrixEx<T> &m );

		//	 double Determinant() const;

		bool IsTranslationMatrix( );
		bool IsRotationMatrix( );
		bool IsScaleMatrix( );
		bool IsIdentity( );

		void Identity( );
		TMatrixEx<T> Transposed( ) const;
		TMatrixEx<T> Inverse( ) const;

		T *GetData( )
		{
			return M;
		}
		void SetData( T *data );

		T &operator[]( const int &a )
		{
			return M[ a ];
		}

		TMatrixEx<T> operator*( TMatrixEx<T> &MP ) const;
		TMatrixEx<T> operator/( const T factor ) const;

		TMatrixEx<T> &operator=( const TMatrixEx<T> &MP );
		bool operator==( const TMatrixEx<T> &other ) const;
		bool operator!=( const TMatrixEx<T> &other ) const;

	  protected:
		T M[ 16 ];
	};

	template<class T>
	class TRotateMatrixEx : public TMatrixEx<T>
	{
	  public:
		TRotateMatrixEx( );							  // Constructor matriz unitaria
		TRotateMatrixEx( T alfa, T3DVectorEx<T> &v ); // Rotacion alrededor de vector
		TRotateMatrixEx( const TRotateMatrixEx<T> &v );
	};

	template<class T>
	class TScaleMatrixEx : public TMatrixEx<T>
	{
	  public:
		TScaleMatrixEx( );
		TScaleMatrixEx( T factorx, T factory, T factorz );
		TScaleMatrixEx( T f ); // Escalado proporcional
		TScaleMatrixEx( T factorx, T factory, T factorz, const T3DVectorEx<T> &axis );
	};

	template<class T>
	class TTraslationMatrixEx : public TMatrixEx<T>
	{
	  public:
		TTraslationMatrixEx( );
		TTraslationMatrixEx( T3DVectorEx<T> &v );
	};

	template<class T>
	class TAxisMatrixEx : public TMatrixEx<T>
	{
	  public:
		TAxisMatrixEx( );
		TAxisMatrixEx( T3DPointEx<T> p1old, T3DPointEx<T> p2old, T3DPointEx<T> p1new, T3DPointEx<T> p2new );
	};

	//----------------------------------------------------------------------------
	// TPoint
	//----------------------------------------------------------------------------

	template<class T>
	T3DPointEx<T>::T3DPointEx( const TPointEx<T> &point, TNPlane pl )
	{
		switch ( pl ) {
			case plXY:
				x = point.x;
				y = point.y;
				z = 0;
				break;
			case plXZ:
				x = point.x;
				y = 0;
				z = point.y;
				break;
			case plYZ:
				x = 0;
				y = point.y;
				z = point.x;
				break;
			default: break;
		}
	}

	template<class T>
	T3DPointEx<T>::T3DPointEx( const TSizeEx<T> &size, TNPlane pl )
	{
		switch ( pl ) {
			case plXY:
				x = size.cx;
				y = size.cy;
				z = 0;
				break;
			case plXZ:
				x = size.cx;
				y = 0;
				z = size.cy;
				break;
			case plYZ:
				x = 0;
				y = size.cy;
				z = size.cx;
				break;
			default: break;
		}
	}

	template<class T>
	T3DPointEx<T>::T3DPointEx( const TPoint &point, TNPlane pl )
	{
		switch ( pl ) {
			case plXY:
				x = point.x;
				y = point.y;
				z = 0;
				break;
			case plXZ:
				x = point.x;
				y = 0;
				z = point.y;
				break;
			case plYZ:
				x = 0;
				y = point.y;
				z = point.x;
				break;
			default: break;
		}
	}

	template<class T>
	T3DPointEx<T>::T3DPointEx( const TSize &size, TNPlane pl )
	{
		switch ( pl ) {
			case plXY:
				x = size.cx;
				y = size.cy;
				z = 0;
				break;
			case plXZ:
				x = size.cx;
				y = 0;
				z = size.cy;
				break;
			case plYZ:
				x = 0;
				y = size.cy;
				z = size.cx;
				break;
			default: break;
		}
	}

	//
	// Los operadores de comparacion se han definido todos en funcion del
	// operador >=. Esto implica mas llamadas a funcion por cada operador,
	// pero permite redefinir todos los operadores en funcion unicamente
	// de este.
	//

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator=( const T3DPointEx<T> &other )
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	template<class T>
	bool T3DPointEx<T>::operator==( const T3DPointEx<T> &other ) const
	{
		return other >= *this && *this >= other;
	}

	template<class T>
	bool T3DPointEx<T>::operator!=( const T3DPointEx<T> &other ) const
	{
		return !( other == *this );
	}

	template<class T>
	bool T3DPointEx<T>::operator>=( const T3DPointEx<T> &other ) const
	{
		return other.x <= x && other.y <= y && other.z <= z;
	}

	template<class T>
	bool T3DPointEx<T>::operator<=( const T3DPointEx<T> &other ) const
	{
		return other >= *this;
	}

	template<class T>
	bool T3DPointEx<T>::operator>( const T3DPointEx<T> &other ) const
	{
		return !( other >= *this );
	}

	template<class T>
	bool T3DPointEx<T>::operator<( const T3DPointEx<T> &other ) const
	{
		return !( *this >= other );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator+( const T3DSizeEx<T> &size ) const
	{
		return T3DPointEx<T>( x + size.cx, y + size.cy, z + size.cz );
	}

	template<class T>
	T3DSizeEx<T> T3DPointEx<T>::operator-( const T3DPointEx<T> &point ) const
	{
		return T3DSizeEx<T>( x - point.x, y - point.y, z - point.z );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator-( const T3DSizeEx<T> &size ) const
	{
		return T3DPointEx<T>( x - size.cx, y - size.cy, z - size.cz );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator/( const T3DSizeEx<T> &size ) const
	{
		PRECONDITION( size.cx > 0 && size.cy > 0 && size.cz > 0 );
		return T3DPointEx<T>( x / size.cx, y / size.cy, z / size.cz );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator*( const T3DSizeEx<T> &size ) const
	{
		return T3DPointEx<T>( x * size.cx, y * size.cy, z * size.cz );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator-( const T factor ) const
	{
		return T3DPointEx<T>( x - factor, y - factor, z - factor );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator+( const T factor ) const
	{
		return T3DPointEx<T>( x + factor, y + factor, z + factor );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator/( const T factor ) const
	{
		PRECONDITION( factor > 0 );
		return T3DPointEx<T>( x / factor, y / factor, z / factor );
	}

	template<class T>
	T3DPointEx<T> T3DPointEx<T>::operator*( const T factor ) const
	{
		return T3DPointEx<T>( x * factor, y * factor, z * factor );
	}

	template<class T>
	double T3DPointEx<T>::operator^( const T3DPointEx<T> &point ) const
	{
		double m1 = ( x * x ) + ( y * y ) + ( z * z );
		double m2 = ( point.x * point.x ) + ( point.y * point.y ) + ( point.z * point.z );
		double m3 = sqrt( m1 * m2 );
		if ( m3 <= RES_COMP2 ) return -1;
		double aux = ( x * point.x + y * point.y + z * point.z ) / m3;
		if ( ( aux <= 1.0 ) && ( aux >= -1.0 ) ) return aux;
		return -1;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::Offset( T dx, T dy, T dz )
	{
		x += dx;
		y += dy;
		z += dz;
		return *this;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::Normalize( )
	{
		double mod = x * x + y * y + z * z;
		mod = ( mod > RES_COMP2 ) ? sqrt( mod ) : 0.0;
		if ( mod > RES_COMP ) {
			x /= mod;
			y /= mod;
			z /= mod;
		}
		return *this;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::operator+=( const T3DSizeEx<T> &size )
	{
		x += size.cx;
		y += size.cy;
		z += size.cz;
		return *this;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::operator-=( const T3DSizeEx<T> &size )
	{
		x -= size.cx;
		y -= size.cy;
		z -= size.cz;
		return *this;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::operator/=( const T3DSizeEx<T> &size )
	{
		PRECONDITION( size.cx > 0 && size.cy > 0 && size.cz > 0 );
		x /= size.cx;
		y /= size.cy;
		z /= size.cz;
		return *this;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::operator*=( const T3DSizeEx<T> &size )
	{
		x *= size.cx;
		y *= size.cy;
		z *= size.cz;
		return *this;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::operator/=( const T factor )
	{
		PRECONDITION( factor > 0 );
		x /= factor;
		y /= factor;
		z /= factor;
		return *this;
	}

	template<class T>
	T3DPointEx<T> &T3DPointEx<T>::operator*=( const T factor )
	{
		x *= factor;
		y *= factor;
		z *= factor;
		return *this;
	}

	//------------------------------------------------------------------------------
	// TSize
	//------------------------------------------------------------------------------

	template<class T>
	T3DSizeEx<T>::T3DSizeEx( const TSizeEx<T> &size, TNPlane pl )
	{
		switch ( pl ) {
			case plXY:
				cx = size.cx;
				cy = size.cy;
				cz = 0;
				break;
			case plXZ:
				cx = size.cx;
				cy = 0;
				cz = size.cy;
				break;
			case plYZ:
				cx = 0;
				cy = size.cy;
				cz = size.cx;
				break;
			default: break;
		}
	}

	template<class T>
	T3DSizeEx<T>::T3DSizeEx( const TSize &size, TNPlane pl )
	{
		switch ( pl ) {
			case plXY:
				cx = size.cx;
				cy = size.cy;
				cz = 0;
				break;
			case plXZ:
				cx = size.cx;
				cy = 0;
				cz = size.cy;
				break;
			case plYZ:
				cx = 0;
				cy = size.cy;
				cz = size.cx;
				break;
			default: break;
		}
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator=( const T3DSizeEx<T> &other )
	{
		cx = other.cx;
		cy = other.cy;
		cz = other.cz;
		return *this;
	}

	template<class T>
	bool T3DSizeEx<T>::operator==( const T3DSizeEx<T> &other ) const
	{
		return other >= *this && *this >= other;
	}

	template<class T>
	bool T3DSizeEx<T>::operator!=( const T3DSizeEx<T> &other ) const
	{
		return !( other == *this );
	}

	template<class T>
	bool T3DSizeEx<T>::operator>=( const T3DSizeEx<T> &other ) const
	{
		return other.cx <= cx && other.cy <= cy && other.cz <= cz;
	}

	template<class T>
	bool T3DSizeEx<T>::operator<=( const T3DSizeEx<T> &other ) const
	{
		return other >= *this;
	}

	template<class T>
	bool T3DSizeEx<T>::operator>( const T3DSizeEx<T> &other ) const
	{
		return !( other >= *this );
	}

	template<class T>
	bool T3DSizeEx<T>::operator<( const T3DSizeEx<T> &other ) const
	{
		return !( *this >= other );
	}

	template<class T>
	double T3DSizeEx<T>::Magnitude( void ) const
	{
		double temp = dmult( cx, cx ) + dmult( cy, cy ) + dmult( cz, cz );
		return ( temp < RES_COMP2 ) ? 0.0 : sqrt( temp );
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator+( const T3DSizeEx<T> &size ) const
	{
		return T3DSizeEx<T>( cx + size.cx, cy + size.cy, cz + size.cz );
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator-( const T3DSizeEx<T> &size ) const
	{
		return T3DSizeEx<T>( cx - size.cx, cy - size.cy, cz - size.cz );
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator*( const T3DSizeEx<T> &size ) const
	{
		return T3DSizeEx<T>( cx * size.cx, cy * size.cy, cz * size.cz );
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator/( const T3DSizeEx<T> &size ) const
	{
		PRECONDITION( size.cx > 0 && size.cy > 0 && size.cz > 0 );
		return T3DSizeEx<T>( cx / size.cx, cy / size.cy, cz / size.cz );
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator/( const T factor ) const
	{
		PRECONDITION( factor > 0 );
		return T3DSizeEx<T>( cx / factor, cy / factor, cz / factor );
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator*( const T factor ) const
	{
		return T3DSizeEx<T>( cx * factor, cy * factor, cz * factor );
	}

	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator+( const T factor ) const
	{
		return T3DSizeEx<T>( cx + factor, cy + factor, cz + factor );
	}
	template<class T>
	T3DSizeEx<T> T3DSizeEx<T>::operator-( const T factor ) const
	{
		return T3DSizeEx<T>( cx - factor, cy - factor, cz - factor );
	}

	template<class T>
	T3DSizeEx<T> &T3DSizeEx<T>::operator+=( const T3DSizeEx<T> &size )
	{
		cx += size.cx;
		cy += size.cy, cz += size.cz;
		return *this;
	}

	template<class T>
	T3DSizeEx<T> &T3DSizeEx<T>::operator-=( const T3DSizeEx<T> &size )
	{
		cx -= size.cx;
		cy -= size.cy;
		cz -= size.cz;
		return *this;
	}

	template<class T>
	T3DSizeEx<T> &T3DSizeEx<T>::operator*=( const T factor )
	{
		cx *= factor;
		cy *= factor;
		cz *= factor;
		return *this;
	}

	template<class T>
	T3DSizeEx<T> &T3DSizeEx<T>::operator/=( const T factor )
	{
		cx /= factor;
		cy /= factor;
		cz /= factor;
		return *this;
	}

	//------------------------------------------------------------------------------
	// TRect
	//------------------------------------------------------------------------------

	template<class T>
	void T3DRectEx<T>::SetNull( )
	{
		left = top = front = right = bottom = back = 0;
	}

	template<class T>
	void T3DRectEx<T>::Set( T _left, T _top, T _front, T _right, T _bottom, T _back )
	{
		left = _left;
		top = _top;
		front = _front;
		right = _right;
		bottom = _bottom;
		back = _back;
	}

	template<class T>
	T3DRectEx<T>::T3DRectEx( T _left, T _top, T _front, T _right, T _bottom, T _back )
	{
		Set( _left, _top, _front, _right, _bottom, _back );
	}

	template<class T>
	T3DRectEx<T>::T3DRectEx( const T3DPointEx<T> &topLeftFront, const T3DPointEx<T> &bottomRightBack )
	{
		Set( topLeftFront.x, topLeftFront.y, topLeftFront.z, bottomRightBack.x, bottomRightBack.y, bottomRightBack.z );
	}

	template<class T>
	T3DRectEx<T>::T3DRectEx( const T3DPointEx<T> &origin, const T3DSizeEx<T> &extent )
	{
		Set( origin.x, origin.y, origin.z, origin.x + extent.cx, origin.y + extent.cy, origin.z + extent.cz );
	}

	template<class T>
	bool T3DRectEx<T>::IsEmpty( ) const
	{
		return left >= right || top >= bottom || front >= back;
	}

	template<class T>
	bool T3DRectEx<T>::IsNull( ) const
	{
		return !left && !right && !top && !bottom && !front && !back;
	}

	template<class T>
	bool T3DRectEx<T>::IsValid( ) const
	{
		return left <= right && top <= bottom && front <= back;
	}

	template<class T>
	bool T3DRectEx<T>::IsPlain( ) const
	{
		return left == right || top == bottom || front == back;
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::operator=( const T3DRectEx<T> &other )
	{
		left = other.left;
		top = other.top;
		front = other.front;
		right = other.right;
		bottom = other.bottom;
		back = other.back;
		return *this;
	}

	template<class T>
	bool T3DRectEx<T>::operator==( const T3DRectEx<T> &other ) const
	{
		return other.left == left && other.top == top && other.front == front && other.right == right && other.bottom == bottom && other.back == back;
	}

	template<class T>
	bool T3DRectEx<T>::operator!=( const T3DRectEx<T> &other ) const
	{
		return !( other == *this );
	}

	template<class T>
	bool T3DRectEx<T>::Contains( const T3DPointEx<T> &point ) const
	{
		return point.x >= left && point.x <= right && point.y >= top && point.y <= bottom && point.z >= front && point.z <= back;
	}

	template<class T>
	bool T3DRectEx<T>::Contains( const T3DRectEx<T> &other ) const
	{
		return other.left >= left && other.right <= right && other.top >= top && other.bottom <= bottom && other.front >= front && other.back <= back;
	}

	template<class T>
	bool T3DRectEx<T>::Touches( const T3DRectEx<T> &other ) const
	{
		return other.right >= left && other.left <= right && other.bottom >= top && other.top <= bottom && other.back >= front && other.front <= back;
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::OffsetBy( T dx, T dy, T dz ) const
	{
		return T3DRectEx<T>( left + dx, top + dy, front + dz, right + dx, bottom + dy, back + dz );
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::operator+( const T3DSizeEx<T> &size ) const
	{
		return OffsetBy( size.cx, size.cy, size.cz );
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::operator-( const T3DSizeEx<T> &size ) const
	{
		return OffsetBy( -size.cx, -size.cy, -size.cz );
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::InflatedBy( T dx, T dy, T dz ) const
	{
		return T3DRectEx<T>( left - dx, top - dy, front - dz, right + dx, bottom + dy, back + dz );
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::InflatedBy( const T3DSizeEx<T> &size ) const
	{
		return InflatedBy( size.cx, size.cy, size.cz );
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::Normalized( ) const
	{
		return T3DRectEx<T>( min( left, right ), min( top, bottom ), min( front, back ), max( left, right ), max( top, bottom ), max( front, back ) );
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::operator&( T3DRectEx<T> &other )
	{
		return T3DRectEx<T>( max( left, other.left ), max( top, other.top ), max( front, other.front ), min( right, other.right ), min( bottom, other.bottom ), min( back, other.back ) );
	}

	template<class T>
	T3DRectEx<T> T3DRectEx<T>::operator|( T3DRectEx<T> &other )
	{
		return T3DRectEx<T>( min( left, other.left ), min( top, other.top ), min( front, other.front ), max( right, other.right ), max( bottom, other.bottom ), max( back, other.back ) );
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::operator+=( const T3DSizeEx<T> &delta )
	{
		Offset( delta.cx, delta.cy, delta.cz );
		return *this;
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::operator-=( const T3DSizeEx<T> &delta )
	{
		return *this += -delta;
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::Inflate( const T3DSizeEx<T> &delta )
	{
		return Inflate( delta.cx, delta.cy, delta.cz );
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::Normalize( )
	{
		if ( left > right ) Swap( left, right );
		if ( top > bottom ) Swap( top, bottom );
		if ( front > back ) Swap( front, back );
		return *this;
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::Offset( T dx, T dy, T dz )
	{
		left += dx;
		top += dy;
		front += dz;
		right += dx;
		bottom += dy;
		back += dz;
		return *this;
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::Inflate( T dx, T dy, T dz )
	{
		left -= dx;
		top -= dy;
		front -= dz;
		right += dx;
		bottom += dy;
		back += dz;
		return *this;
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::operator&=( T3DRectEx<T> &other )
	{
		if ( !IsNull( ) ) {
			if ( other.IsNull( ) ) SetNull( );
			else {
				left = max( left, other.left );
				top = max( top, other.top );
				front = max( front, other.front );
				right = min( right, other.right );
				bottom = min( bottom, other.bottom );
				back = min( back, other.back );
			}
		}
		return *this;
	}

	template<class T>
	T3DRectEx<T> &T3DRectEx<T>::operator|=( T3DRectEx<T> &other )
	{
		if ( !other.IsNull( ) ) {
			if ( IsNull( ) ) *this = other;
			else {
				left = min( left, other.left );
				top = min( top, other.top );
				front = min( front, other.front );
				right = max( right, other.right );
				bottom = max( bottom, other.bottom );
				back = max( back, other.back );
			}
		}
		return *this;
	}

	template<class T>
	ostream &operator<<( ostream &os, const T3DRectEx<T> &r )
	{
		return os << '(' << r.left << ',' << r.top << ',' << r.front << '-' << r.right << ',' << r.bottom << ',' << r.back << ')';
	}

	//------------------------------------------------------------------------------
	// T3DVectorEx
	//------------------------------------------------------------------------------

	template<class T>
	T3DVectorEx<T>::T3DVectorEx( T Modulo, double AngleX, double AngleZ, const T3DPointEx<T> &_org )
	// AngleX->Angulo que forma la proyeccion del vector sobre el plano XY con el eje X.
	// AngleZ->Angulo que forma el vector con el eje Z.
	{
		org = _org;
		Modulo = max( Modulo, -Modulo );
		size.cx = T( Modulo * sin( AngleZ ) * cos( AngleX ) );
		size.cy = T( Modulo * sin( AngleZ ) * sin( AngleX ) );
		size.cz = T( Modulo * cos( AngleZ ) );
	}

	template<class T>
	T3DVectorEx<T> T3DVectorEx<T>::Unitario( )
	{
		return Modulo( 1 );
	}

	template<class T>
	T3DVectorEx<T> T3DVectorEx<T>::operator=( const T3DVectorEx<T> &V )
	{
		org = V.org;
		size = V.size;
		return *this;
	}

	template<class T>
	bool T3DVectorEx<T>::operator==( const T3DVectorEx<T> &V ) const
	{
		return V.org == org && V.size == size;
	}

	template<class T>
	bool T3DVectorEx<T>::operator!=( const T3DVectorEx<T> &V ) const
	{
		return !( V == *this );
	}

	template<class T>
	T3DVectorEx<T> T3DVectorEx<T>::operator+( const T3DVectorEx<T> &V ) const
	{
		return T3DVectorEx<T>( size + V.size, org );
	}

	template<class T>
	T3DVectorEx<T> T3DVectorEx<T>::operator-( const T3DVectorEx<T> &V ) const
	{
		return T3DVectorEx<T>( size - V.size, org );
	}

	template<class T>
	double T3DVectorEx<T>::operator*( const T3DVectorEx<T> &V ) const // Producto
	{																  // escalar
		return dmult( size.cx, V.size.cx ) + dmult( size.cy, V.size.cy ) + dmult( size.cz, V.size.cz );
	}

	template<class T>
	double T3DVectorEx<T>::operator^( const T3DVectorEx<T> &V ) const // Coseno del angulo entre
	{																  // dos vectores
		double cociente = Modulo( ) * V.Modulo( );

		double retValue = ( cociente == 0.0 ) ? 0.0 : this->operator*( V ) / cociente;

		if ( retValue > 1.0 ) retValue = 1.0;
		if ( retValue < -1.0 ) retValue = -1.0;

		return retValue;
	}

	//
	// El metodo del producto vectorial
	//

	template<class T>
	T3DVectorEx<T> T3DVectorEx<T>::operator||( const T3DVectorEx<T> &V ) const // Producto vectorial
	{
		return T3DVectorEx<T>( T3DSizeEx<T>( size.cy * V.size.cz - V.size.cy * size.cz, size.cz * V.size.cx - V.size.cz * size.cx, size.cx * V.size.cy - V.size.cx * size.cy ), org );
	}

	//
	// devuelve un valor del angulo entre 0 y 2*PI, entre el vector y uno de los planos
	//

	template<class T>
	double T3DVectorEx<T>::Angulo( TNPlane pl ) const
	{
		double angle;

		switch ( pl ) {
			case plXY: angle = size.cx == 0 ? size.cy > 0 ? M_PI / 2.0 : -M_PI / 2.0 : atan2( size.cy, size.cx ); break;
			case plXZ: angle = size.cx == 0 ? size.cz > 0 ? M_PI / 2.0 : -M_PI / 2.0 : atan2( size.cz, size.cx ); break;
			case plYZ: angle = size.cz == 0 ? size.cy > 0 ? M_PI / 2.0 : -M_PI / 2.0 : atan2( size.cy, size.cz ); break;
			default: break;
		}
		return angle;
	}

	template<class T>
	T3DVectorEx<T> T3DVectorEx<T>::Normal( const T3DVectorEx<T> &V ) const
	{
		return ( *this ) || V;
	}

	/*
	template<class T>
	T3DVectorEx<T>& T3DVectorEx<T>::Girar(const T3DVectorEx<T>&eje, const double angulo)
	{
		T3DVector Eje = eje;
		TNRotateMatrix Rotacion = TNRotateMatrix(angulo, Eje);

		org.ApplyMatrix(Rotacion);
		T3DPoint Temp = T3DPoint(org+size);
		Temp.ApplyMatrix(Rotacion);
		size = Temp-org;

		return *this;
	}
	*/

	template<class T>
	T3DVectorEx<T> &T3DVectorEx<T>::ApplyMatrix( TMatrixEx<T> &M )
	{
		T3DPointEx<T> Temp = T3DPointEx<T>( org + size );
		Temp.ApplyMatrix( M );
		org.ApplyMatrix( M );
		size = Temp - org;
		return *this;
	}

	template<class T>
	T3DVectorEx<T> &T3DVectorEx<T>::Modulo( T newMod )
	{
		double mod, factor;

		mod = Modulo( );
		if ( mod < RES_COMP ) return *this;

		factor = ddiv( newMod, mod );
		size.cx = T( factor * size.cx );
		size.cy = T( factor * size.cy );
		size.cz = T( factor * size.cz );
		return *this;
	}

	template<class T>
	double T3DVectorEx<T>::Angle( const T3DVectorEx<T> &V ) const
	{
		double pe = ( size.cx * V.size.cx + size.cy * V.size.cy + size.cz * V.size.cz );
		if ( pe > 1 ) pe = 1.0;
		if ( pe < -1 ) pe = -1.0;
		//		if ( pe == 0 ) return 0; // evita caso erroneo
		return ( acos( pe ) );
	}

	template<class T>
	double T3DVectorEx<T>::AngleG( const T3DVectorEx<T> &V ) const
	{
		return ( Angle( V ) * M_180_PI );
	}

	//------------------------------------------------------------------------------
	// TRecta
	//------------------------------------------------------------------------------
	//       7
	// Constructores
	// Cada uno de los constructores calcula la ecuacion de la recta en tres formas
	//

	template<class T>
	void T3DLineEx<T>::Init( const T3DPointEx<T> &_start, const T3DPointEx<T> &_end )
	{
		start = _start;
		end = _end;
		/*
		 A = end.y-start.y;
		 B = start.x-end.x;
		 C = -start.x*A-start.y*B;

		 pendiente = B!=0 ? A/-B : MAXDOUBLE;
		 ordenada  = B!=0 ?  start.y-start.x*pendiente : 0;*/
	}

	/*template<class T>
	T3DLineEx<T>::T3DLineEx( const double _A, const double _B, const double _C )
	{
	 A = _A; B = _B; C = _C;

	 PRECONDITION( A>0 || B>0 );

	 pendiente = B!=0 ? A/-B : MAXDOUBLE;
	 ordenada  = B!=0 ?  start.y : 0;

	 start.x = 0; start.y = T(ordenada);
	 end.y 	= 0; end.x 	 = -T(ordenada/pendiente);
	}

	template<class T>
	T3DLineEx<T>::T3DLineEx( const double _pendiente, const double _ordenada )
	{
	 A = pendiente = _pendiente;
	 C = ordenada  = _ordenada;
	 B = -1;

	 start.x = 0; start.y = -T(C/B);
	 if ( A>0 ) {
		end.x = -T(C/A); end.y = 0;
	 } else {
		end.x = 1; end.y = start.y;
		}
	} */

	//
	// Comprobacion de rectas paralelas. Caso especial: ambas son verticales
	//

	template<class T>
	bool T3DLineEx<T>::operator||( const T3DLineEx<T> &R ) const
	{
		return ( Director( ) || R.Director( ) ).size == T3DSizeEx<T>( 0, 0, 0 ); // Evita problemas de rectas verticales y los de
	}																			 // precision derivados de las divisiones reales

	//
	// El operador mas se sobrecarga de manera que la suma de dos rectas nos de
	// el punto de interseccion de ambas. Si las rectas son paralelas se devuelve
	// el punto 0,0 que puede o no pertenecer a las rectas. Lo correcto seria
	// comprobar primero que intersectan con el operador || (paralelas)
	//

	template<class T>
	T3DPointEx<T> T3DLineEx<T>::operator+( const T3DLineEx<T> &R ) const
	{
		// Vamos a resolver el sistema de ecuaciones de las 2 rectas
		//	Ecuacion recta 1:	(x-x1)/(x2-x1) = (y-y1)/(y2-y1) = (z-z1)/(z2-z1)
		//	Ecuacion recta 2:	(x-x1p)/(x2p-x1p) = (y-y1p)/(y2p-y1p) = (z-z1p)/(z2p-z1p)

		bool changeAxis;
		T3DPointEx<T> P( 0, 0, 0 );

		if ( !this->operator||( R ) ) // Comprobamos que no son paralelas
		{
			double x1 = start.x, y1 = start.y, z1 = start.z;
			double x2 = end.x, y2 = end.y, z2 = end.z;
			double x1p = R.start.x, y1p = R.start.y, z1p = R.start.z;
			double x2p = R.end.x, y2p = R.end.y, z2p = R.end.z;
			double za, zb, xa, xb;

			double v1 = x2 - x1;
			double v2 = y2 - y1;
			double v3 = z2 - z1;
			double v1p = x2p - x1p;
			double v2p = y2p - y1p;
			double v3p = z2p - z1p;

			if ( ( fabs( v1 ) < RES_COMP && fabs( v2 ) < RES_COMP && fabs( v3 ) < RES_COMP ) || ( fabs( v1p ) < RES_COMP && fabs( v2p ) < RES_COMP && fabs( v3p ) < RES_COMP ) ) return P;

			if ( ( fabs( v2 ) < RES_COMP ) && ( fabs( v3 ) < RES_COMP ) ) // Recta 1 paralela al eje X
			{
				if ( ( fabs( v1p ) < RES_COMP && fabs( v3p ) < RES_COMP && fabs( z1 - z1p ) > RES_COMP ) || ( fabs( v1p ) < RES_COMP && fabs( v2p ) < RES_COMP && fabs( y1 - y1p ) > RES_COMP ) ) return P; // Caso en que no hay interseccion siendo la recta 2 paralela al eje Y o Z
				P.y = y1;
				P.z = z1;
				if ( fabs( v2p ) > RES_COMP ) P.x = x1p + ( P.y - y1p ) * v1p / v2p;
				else
					P.x = x1p + ( P.z - z1p ) * v1p / v3p;
			} else if ( ( fabs( v1 ) < RES_COMP ) && ( fabs( v3 ) < RES_COMP ) ) // Recta 1 paralela al eje Y
			{
				if ( ( fabs( v2p ) < RES_COMP && fabs( v3p ) < RES_COMP && fabs( z1p - z1 ) > RES_COMP ) || ( fabs( v1p ) < RES_COMP && fabs( v2p ) < RES_COMP && fabs( x1 - x1p ) > RES_COMP ) ) return P; // Caso en que no hay interseccion siendo la recta 2 paralela al eje X o Z
				P.x = x1;
				P.z = z1;
				if ( fabs( v1p ) > RES_COMP ) P.y = y1p + ( P.x - x1p ) * v2p / v1p;
				else
					P.y = y1p + ( P.z - z1p ) * v2p / v3p;
			} else if ( ( fabs( v1 ) < RES_COMP ) && ( fabs( v2 ) < RES_COMP ) ) // Recta 1 paralela al eje Z
			{
				if ( ( fabs( v2p ) < RES_COMP && fabs( v3p ) < RES_COMP && fabs( y1 - y1p ) > RES_COMP ) || ( fabs( v1p ) < RES_COMP && fabs( v3p ) < RES_COMP && fabs( x1 - x1p ) > RES_COMP ) ) return P; // Caso en que no hay interseccion siendo la recta 2 paralela al eje X o Y
				P.x = x1;
				P.y = y1;
				if ( fabs( v1p ) > RES_COMP ) P.z = z1p + ( P.x - x1p ) * v3p / v1p;
				else
					P.z = z1p + ( P.y - y1p ) * v3p / v2p;
			} else {
				if ( fabs( v2p ) < RES_COMP && fabs( v3p ) < RES_COMP ) // Recta 2 paralela al eje X
				{
					P.y = y1p;
					P.z = z1p;
					if ( fabs( v2 ) > RES_COMP ) P.x = x1 + ( P.y - y1 ) * v1 / v2;
					else
						P.x = x1 + ( P.z - z1 ) * v1 / v3;
				} else if ( fabs( v1p ) < RES_COMP && fabs( v3p ) < RES_COMP ) // Recta 2 paralela al eje Y
				{
					P.x = x1p;
					P.z = z1p;
					if ( fabs( v1 ) > RES_COMP ) P.y = y1 + ( P.x - x1 ) * v2 / v1;
					else
						P.y = y1 + ( P.z - z1 ) * v2 / v3;
				} else if ( fabs( v1p ) < RES_COMP && fabs( v2p ) < RES_COMP ) // Recta 2 paralela al eje Z
				{
					P.x = x1p;
					P.y = y1p;
					if ( fabs( v1 ) > RES_COMP ) P.z = z1 + ( P.x - x1 ) * v3 / v1;
					else
						P.z = z1 + ( P.y - y1 ) * v3 / v2;
				} else // Ninguna de las dos rectas es paralela a ningun eje
				{
					changeAxis = false;
					if ( fabs( v2 ) < RES_COMP ) // Intercambiamos la y por la z
					{
						y1 = start.z, z1 = start.y;
						y2 = end.z, z2 = end.y;
						y1p = R.start.z, z1p = R.start.y;
						y2p = R.end.z, z2p = R.end.y;

						v2 = y2 - y1;
						v3 = z2 - z1;
						v2p = y2p - y1p;
						v3p = z2p - z1p;

						changeAxis = true;
					}

					if ( fabs( v1 ) > RES_COMP && fabs( v1p ) > RES_COMP ) {
						P.x = ( x1 * v2 / v1 - x1p * v2p / v1p + y1p - y1 ) / ( v2 / v1 - v2p / v1p );
						P.y = y1 + ( ( P.x - x1 ) * v2 / v1 );
						za = z1 + ( ( P.x - x1 ) * v3 / v1 );
						zb = z1p + ( ( P.x - x1p ) * v3p / v1p );
						if ( fabs( za - zb ) > RES_COMP ) {
							P.x = 0;
							P.y = 0;
							P.z = 0;
						} // No hay interseccion
						else
							P.z = za;

						if ( changeAxis ) {
							P.z = P.y;
							P.y = za;
						}
					} else if ( fabs( v3 ) > RES_COMP && fabs( v3p ) > RES_COMP ) {
						P.z = ( z1 * v2 / v3 - z1p * v2p / v3p + y1p - y1 ) / ( v2 / v3 - v2p / v3p );
						P.y = y1 + ( ( P.z - z1 ) * v2 / v3 );
						xa = x1 + ( ( P.z - z1 ) * v1 / v3 );
						xb = x1p + ( ( P.z - z1p ) * v1p / v3p );
						if ( fabs( xa - xb ) > RES_COMP ) {
							P.x = 0;
							P.y = 0;
							P.z = 0;
						} // No hay interseccion
						else
							P.x = xa;
					} else if ( fabs( v2 ) > RES_COMP && fabs( v2p ) > RES_COMP ) {
						P.y = ( y1 * v3 / v2 - y1p * v3p / v2p + z1p - z1 ) / ( v3 / v2 - v3p / v2p );
						P.x = x1 + ( ( P.y - y1 ) * v1 / v2 );
						za = z1 + ( ( P.y - y1 ) * v3 / v2 );
						zb = z1p + ( ( P.y - y1p ) * v3p / v2p );
						if ( fabs( za - zb ) > RES_COMP ) {
							P.x = 0;
							P.y = 0;
							P.z = 0;
						} // No hay interseccion
						else
							P.z = za;
					}
				}
			}
		}

		return P;
	}

	/*
	//
	// Calcula una recta paralela a la original, que se encuentra a una deter-
	// minada distancia, ya sea por la izq. (offset negativo) o por la dcha. (pos.)
	//

	template<class T>
	T3DLineEx<T> T3DLineEx<T>::Offset( const T offset ) const
	{
	 TVector<T> V = Director().Modulo(offset);

	 TPointEx<T> N = TPointEx<T>(V.size.cy, -V.size.cx);
	 return TRecta<T>(start+N, end+N);
	}
	*/
	//
	// Esta funcion calcula la distancia de un punto a una recta (ojo! devuelve
	// signo, con lo que se puede averiguar en que semiplano queda el punto
	// Obviamente, si la Distancia == 0, quiere decir que el punto pertenece a la
	// recta.
	//

	template<class T>
	double T3DLineEx<T>::Distancia( const T3DPointEx<T> &p ) const
	{ // Esta funcion no esta implementada en 3D...
		T3DPointEx<T> v1;
		v1.x = end.x - start.x;
		v1.y = end.y - start.y;
		v1.z = end.z - start.z;
		T3DPointEx<T> v2;
		v2.x = p.x - start.x;
		v2.y = p.y - start.y;
		v2.z = p.z - start.z;
		double div = ( v1.x * v1.x + v1.y * v1.y + v1.z * v1.z );
		if ( div == 0 ) return -1.0;
		double t = ( v2.x * v1.x + v2.y * v1.y + v2.z * v1.z ) / div;
		T3DPointEx<T> p3;
		p3.x = start.x + ( end.x - start.x ) * t;
		p3.y = start.y + ( end.y - start.y ) * t;
		p3.z = start.z + ( end.z - start.z ) * t;
		T3DPointEx<T> res;
		res.x = p3.x - p.x;
		res.y = p3.y - p.y;
		res.z = p3.z - p.z;
		double m = ( res.x * res.x ) + ( res.y * res.y ) + ( res.z * res.z );
		return ( m < RES_COMP2 ) ? 0.0 : sqrt( m );
	}

	//------------------------------------------------------------------------------
	// Esta funcion calcula el punto de una recta mas proximo a otro punto
	template<class T>
	T3DPointEx<T> T3DLineEx<T>::ClosestPoint( const T3DPointEx<T> &P ) const
	{
		T3DVectorEx<T> v1 = Director( );
		T3DVectorEx<T> v2( T3DSizeEx<T>( P - start ) );

		double div = ( v1.size.cx * v1.size.cx + v1.size.cy * v1.size.cy + v1.size.cz * v1.size.cz );
		if ( div < RES_COMP2 ) return T3DPointEx<T>( 0, 0, 0 );
		double t = ( v1 * v2 ) / div;
		return T3DPointEx<T>( start + ( end - start ) * t );
	}

	template<class T>
	bool T3DLineEx<T>::ClosestPoint( const T3DPointEx<T> &P, T3DPointEx<T> &closest, double &param ) const
	{
		double div;
		T3DVectorEx<T> v1, v2;

		v1 = Director( );
		v2 = T3DVectorEx<T>( T3DSizeEx<T>( P - start ) );
		div = ( v1.size.cx * v1.size.cx + v1.size.cy * v1.size.cy + v1.size.cz * v1.size.cz );
		if ( div < RES_COMP ) return false;
		param = ( v1 * v2 ) / div;
		closest = start + ( end - start ) * param;
		return true;
	}

	// Esta funcion calcula la distancia de un punto a una recta
	template<class T>
	double T3DLineEx<T>::Distance( const T3DPointEx<T> &P ) const
	{
		T3DPointEx<T> p = ClosestPoint( P );
		return T3DVectorEx<T>( T3DSizeEx<T>( p - P ) ).Modulo( );
	}

	//------------------------------------------------------------------------------

	template<class T>
	bool T3DLineEx<T>::IsValid( )
	{
		return !start.Similar( end, RES_COMP );
	}

	//------------------------------------------------------------------------------
	// La funcion Touches comprueba la proximidad en los extremos
	template<class T>
	bool T3DLineEx<T>::Touches( const T3DPointEx<T> &P ) const
	{
		return P == start || P == end;
	}

	template<class T>
	bool T3DLineEx<T>::Touches( const T3DLineEx<T> &R ) const
	{
		return Touches( R.start ) || Touches( R.end );
	}

	//------------------------------------------------------------------------------
	// Implementacion de los miembros de T3DPlaneEx
	//------------------------------------------------------------------------------
	template<class T>
	T3DPlaneEx<T>::T3DPlaneEx( const T3DPointEx<T> &_pto, const T3DVectorEx<T> &_normal )
	{
		pto = _pto;
		normal = _normal;
		a = _normal.size.cx;
		b = _normal.size.cy;
		c = _normal.size.cz;
		d = ( _pto.x * _normal.size.cx ) + ( _pto.y * _normal.size.cy ) + ( _pto.z * _normal.size.cz );
		Normalizar( );
	}

	template<class T>
	T3DPlaneEx<T>::T3DPlaneEx( T _a, T _b, T _c, T _d )
	{
		a = _a;
		b = _b;
		c = _c;
		d = _d;
		normal.size = T3DSizeEx<T>( a, b, c );
		if ( a != 0 ) pto = T3DPointEx<T>( d / a, 0, 0 );
		else if ( b != 0 )
			pto = T3DPointEx<T>( 0, d / b, 0 );
		else if ( c != 0 )
			pto = T3DPointEx<T>( 0, 0, d / c );
		else
			pto = T3DPointEx<T>( 0, 0, 0 );
		normal.org = pto;
		Normalizar( );
	}

	template<class T>
	T3DPlaneEx<T>::T3DPlaneEx( const T3DPointEx<T> &first, const T3DPointEx<T> &second, const T3DPointEx<T> &third )
	{
		pto = first;
		T3DVectorEx<T> v1 = T3DVectorEx<T>( first, second );
		T3DVectorEx<T> v2 = T3DVectorEx<T>( first, third );
		normal = v1.Normal( v2 );
		a = normal.size.cx;
		b = normal.size.cy;
		c = normal.size.cz;
		d = ( pto.x * normal.size.cx ) + ( pto.y * normal.size.cy ) + ( pto.z * normal.size.cz );
		Normalizar( );
	}

	template<class T>
	void T3DPlaneEx<T>::Set( const T3DPlaneEx<T> &plane )
	{
		pto = plane.pto;
		normal = plane.normal;
		a = normal.size.cx;
		b = normal.size.cy;
		c = normal.size.cz;
		d = ( pto.x * normal.size.cx ) + ( pto.y * normal.size.cy ) + ( pto.z * normal.size.cz );
		Normalizar( );
	}

	template<class T>
	void T3DPlaneEx<T>::Set( const T3DPointEx<T> &_pto, const T3DVectorEx<T> &_normal )
	{
		pto = _pto;
		normal = _normal;
		a = _normal.size.cx;
		b = _normal.size.cy;
		c = _normal.size.cz;
		d = ( _pto.x * _normal.size.cx ) + ( _pto.y * _normal.size.cy ) + ( _pto.z * _normal.size.cz );
		Normalizar( );
	}

	template<class T>
	bool T3DPlaneEx<T>::IsValid( ) const
	{
		return fabs( a ) > RES_COMP || fabs( b ) > RES_COMP || fabs( c ) > RES_COMP;
	}

	template<class T>
	bool T3DPlaneEx<T>::IsEqual( const T3DPlaneEx<T> &other )
	{
		return ( ( ( fabs( a - other.a ) < RES_GEOM && fabs( b - other.b ) < RES_GEOM && fabs( c - other.c ) < RES_GEOM ) || ( fabs( a + other.a ) < RES_GEOM && fabs( b + other.b ) < RES_GEOM && fabs( c + other.c ) < RES_GEOM ) ) && fabs( d - other.d ) < RES_GEOM );
	}

	template<class T>
	T3DPlaneEx<T> T3DPlaneEx<T>::operator=( const T3DPlaneEx<T> &other )
	{
		pto = other.pto;
		normal = other.normal;
		a = other.a;
		b = other.b;
		c = other.c;
		d = other.d;
		return *this;
	}

	template<class T>
	bool T3DPlaneEx<T>::operator==( const T3DPlaneEx<T> &other ) const
	{
		return ( ( a == other.a ) && ( b == other.b ) && ( c == other.c ) && ( d == other.d ) );
	}

	template<class T>
	bool T3DPlaneEx<T>::operator!=( const T3DPlaneEx<T> &other ) const
	{
		return !( other == *this );
	}

	template<class T>
	void T3DPlaneEx<T>::Normalizar( )
	{
		normal = normal.Unitario( );
		a = normal.size.cx;
		b = normal.size.cy;
		c = normal.size.cz;
		d = ( pto.x * normal.size.cx ) + ( pto.y * normal.size.cy ) + ( pto.z * normal.size.cz );
	}

	template<class T>
	T T3DPlaneEx<T>::DistPunto( T3DPointEx<T> &punto ) // 0 pertenece
	{												   // x por debajo // -x por encima
		float dist = a * punto.x + b * punto.y + c * punto.z - d;
		if ( dist < -0.001 ) return dist;
		if ( dist > 0.001 ) return dist;
		return 0;
	}

	template<class T>
	T3DPointEx<T> T3DPlaneEx<T>::ToPlane( const T3DPointEx<T> &punto, const T3DVectorEx<T> &vecdir )
	{
		T3DLineEx<T> recta = T3DLineEx<T>( punto, punto + vecdir.size );

		return this->operator+( recta );
	}

	template<class T>
	T3DPointEx<T> T3DPlaneEx<T>::Simetric( T3DPointEx<T> punto )
	{
		T3DPointEx<T> Paux = ToPlane( punto, normal );
		T3DVectorEx<T> Vec = T3DVectorEx<T>( Paux, punto );
		Vec.size = -Vec.size;

		return Vec.org + Vec.size;
	}

	template<class T>
	T3DPlaneEx<T> &T3DPlaneEx<T>::ApplyMatrix( TMatrixEx<T> &M )
	{
		pto.ApplyMatrix( M );
		normal.ApplyMatrix( M );
		Normalizar( );

		return *this;
	}

	//
	// El operador mas se sobrecarga de manera que la suma de un plano y una recta
	// nos de el punto de interseccion de ambas. Si la recta y el plano son paralelos
	// se devuelve el punto 0,0,0 que puede o no pertenecer al plano.
	//

	template<class T>
	T3DPointEx<T> T3DPlaneEx<T>::operator+( const T3DLineEx<T> &R ) const
	{
		T3DPointEx<T> P( 0, 0, 0 );
		T3DVectorEx<T> vd = R.Director( );
		vd.Unitario( );

		if ( normal ^ vd ) // No son perpendiculares
		{
			double cociente = a * vd.size.cx + b * vd.size.cy + c * vd.size.cz;
			if ( cociente == 0 ) return P;

			P.x = ( vd.size.cy * R.start.x - vd.size.cx * R.start.y ) * b + ( vd.size.cz * R.start.x - vd.size.cx * R.start.z ) * c + d * vd.size.cx;
			P.x /= cociente;

			P.y = ( vd.size.cx * R.start.y - vd.size.cy * R.start.x ) * a + ( vd.size.cz * R.start.y - vd.size.cy * R.start.z ) * c + d * vd.size.cy;
			P.y /= cociente;

			P.z = ( vd.size.cx * R.start.z - vd.size.cz * R.start.x ) * a + ( vd.size.cy * R.start.z - vd.size.cz * R.start.y ) * b + d * vd.size.cz;
			P.z /= cociente;
		}

		return P;
		//   NOTA: R.start es el punto a proyectar sobre el plano.
	}

	template<class T>
	T3DLineEx<T> T3DPlaneEx<T>::operator+( const T3DPlaneEx<T> &P ) const
	{
		double x1, x2, y1, y2, z1, z2;

		x1 = x2 = y1 = y2 = z1 = z2 = 0.0;

		if ( fabs( a ) > RES_COMP ) {
			if ( fabs( c ) < RES_COMP && fabs( b ) < RES_COMP ) {
				if ( fabs( P.c ) > RES_COMP ) {
					x2 = x1 = d / a;
					y1 = 0;
					y2 = 1;
					z1 = ( P.d - P.a * x1 - P.b * y1 ) / P.c;
					z2 = ( P.d - P.a * x2 - P.b * y2 ) / P.c;
				} else if ( fabs( P.b ) > RES_COMP ) {
					x2 = x1 = d / a;
					z1 = 0;
					z2 = 1;
					y1 = ( P.d - P.a * x1 - P.c * z1 ) / P.b;
					y2 = ( P.d - P.a * x2 - P.c * z2 ) / P.b;
				}
			} else {
				y1 = 0;
				y2 = 1;
				double valorAux = ( P.c - c * P.a / a );
				double valorAux2 = ( P.b - b * P.a / a ) * y1;
				if ( fabs( valorAux ) > RES_COMP ) {
					z1 = ( ( P.d - d * P.a / a ) + valorAux2 ) / valorAux;
					valorAux2 = ( P.b - b * P.a / a ) * y2;
					z2 = ( ( P.d - d * P.a / a ) + valorAux2 ) / valorAux;
					x1 = ( -b * y1 - c * z1 + d ) / a;
					x2 = ( -b * y2 - c * z2 + d ) / a;
				} else {
					z1 = 0;
					z2 = 1;
					valorAux = ( P.b - b * P.a / a );
					if ( fabs( valorAux ) > RES_COMP ) {
						valorAux2 = ( P.c - c * P.a / a ) * z1;
						y1 = ( ( P.d - d * P.a / a ) + valorAux2 ) / valorAux;
						valorAux2 = ( P.c - c * P.a / a ) * z2;
						y2 = ( ( P.d - d * P.a / a ) + valorAux2 ) / valorAux;
						x1 = ( -b * y1 - c * z1 + d ) / a;
						x2 = ( -b * y2 - c * z2 + d ) / a;
					}
				}
			}
		} else if ( fabs( b ) > RES_COMP ) {
			if ( fabs( c ) < RES_COMP ) {
				if ( fabs( P.c ) > RES_COMP ) {
					y2 = y1 = d / b;
					x1 = 0;
					x2 = 1;
					z1 = ( P.d - P.a * x1 - P.b * y1 ) / P.c;
					z2 = ( P.d - P.a * x2 - P.b * y2 ) / P.c;
				} else if ( fabs( P.a ) > RES_COMP ) {
					y2 = y1 = d / b;
					z1 = 0;
					z2 = 1;
					x1 = ( P.d - P.b * y1 - P.c * z1 ) / P.a;
					x2 = ( P.d - P.b * y2 - P.c * z2 ) / P.a;
				}
			} else {
				x1 = 0;
				x2 = 1;
				double valorAux = ( P.c - c * P.b / b );
				double valorAux2 = ( P.a - a * P.b / b ) * x1;
				if ( fabs( valorAux ) > RES_COMP ) {
					z1 = ( ( P.d - d * P.b / b ) + valorAux2 ) / valorAux;
					valorAux2 = ( P.a - a * P.b / b ) * x2;
					z2 = ( ( P.d - d * P.b / b ) + valorAux2 ) / valorAux;
					y1 = ( -a * x1 - c * z1 + d ) / b;
					y2 = ( -a * x2 - c * z2 + d ) / b;
				} else {
					z1 = 0;
					z2 = 1;
					valorAux = ( P.a - a * P.b / b );
					if ( fabs( valorAux ) > RES_COMP ) {
						valorAux2 = ( P.c - c * P.b / b ) * z1;
						x1 = ( ( P.d - d * P.b / b ) + valorAux2 ) / valorAux;
						valorAux2 = ( P.c - c * P.b / b ) * z2;
						x2 = ( ( P.d - d * P.b / b ) + valorAux2 ) / valorAux;
						y1 = ( -a * x1 - c * z1 + d ) / b;
						y2 = ( -a * x2 - c * z2 + d ) / b;
					}
				}
			}
		} else if ( fabs( c ) > RES_COMP ) {
			if ( fabs( P.b ) > RES_COMP ) {
				z1 = z2 = d / c;
				x1 = 0;
				x2 = 1;
				y1 = ( P.d - P.a * x1 - P.c * z1 ) / P.b;
				y2 = ( P.d - P.a * x2 - P.c * z2 ) / P.b;
			} else if ( fabs( P.a ) > RES_COMP ) {
				z1 = z2 = d / c;
				y1 = 0;
				y2 = 1;
				x1 = ( P.d - P.b * y1 - P.c * z1 ) / P.a;
				x2 = ( P.d - P.b * y2 - P.c * z2 ) / P.a;
			}
		}
		T3DPointEx<T> start = T3DPointEx<T>( x1, y1, z1 );
		T3DPointEx<T> end = T3DPointEx<T>( x2, y2, z2 );
		T3DLineEx<T> Recta( start, end );
		return Recta;
	}

	template<class T>
	T T3DPlaneEx<T>::X( T y, T z )
	{
		T3DPointEx<T> auxpt;

		auxpt = normal.size;
		if ( fabs( auxpt.x ) < RES_COMP2 ) return 0.0;
		return -( d + auxpt.z * z + auxpt.y * y ) / auxpt.x;
	}

	template<class T>
	T T3DPlaneEx<T>::Y( T x, T z )
	{
		T3DPointEx<T> auxpt;

		auxpt = normal.size;
		if ( fabs( auxpt.y ) < RES_COMP2 ) return 0.0;
		return -( d + auxpt.z * z + auxpt.x * x ) / auxpt.y;
	}

	template<class T>
	T T3DPlaneEx<T>::Z( T x, T y )
	{
		T3DPointEx<T> auxpt;

		auxpt = normal.size;
		if ( fabs( auxpt.z ) < RES_COMP2 ) return 0.0;
		return -( d + auxpt.x * x + auxpt.y * y ) / auxpt.z;
	}

	template<class T>
	bool T3DPlaneEx<T>::Intersect( T3DPointEx<T> &p1, T3DPointEx<T> &p2 )
	{
		return ( PointPosition( p1 ) * PointPosition( p2 ) > 0 ) ? false : true;
	}

	template<class T>
	bool T3DPlaneEx<T>::Intersect( T3DPointEx<T> &p1, T3DPointEx<T> &p2, T3DPointEx<T> &p3, T3DPointEx<T> &p4 )
	{
		int mask = 0;
		if ( PointPosition( p1 ) > 0 ) mask |= 1;
		if ( PointPosition( p2 ) > 0 ) mask |= 2;
		if ( PointPosition( p3 ) > 0 ) mask |= 4;
		if ( PointPosition( p4 ) > 0 ) mask |= 8;
		return ( mask != 0 ) && ( mask != 15 );
	}

	template<class T>
	T3DPointEx<T> T3DPlaneEx<T>::IntersectPoint( const T3DPointEx<T> &p1, const T3DPointEx<T> &p2 )
	{
		T cosv, landa;
		T3DSizeEx<T> v;

		if ( p1 == p2 ) return p1;
		v = p2 - p1;
		cosv = ( a * v.cx + b * v.cy + c * v.cz );
		if ( cosv == 0 ) return p1;
		landa = -( a * p1.x + b * p1.y + c * p1.z - d ) / cosv;
		return T3DPointEx<T>( p1.x + landa * v.cx, p1.y + landa * v.cy, p1.z + landa * v.cz );
	}

	template<class T>
	T T3DPlaneEx<T>::PointPosition( T3DPointEx<T> &p1 )
	{
		T3DSizeEx<T> vector = p1 - pto;
		return ( a * vector.cx + b * vector.cy + c * vector.cz );
	}

	//==============================================================================
	// 	Implementacion de los miembros de TMatxEx y derivadas
	//==============================================================================
	template<class T>
	TMatxEx<T>::TMatxEx( int ord )
	{
		int i;
		T *aux;

		order = ord;
		if ( order ) {
			aux = new T[ order * order ];
			mtx = new T *[ order ];
			for ( i = 0; i < order; i++ )
				mtx[ i ] = &( aux[ i * order ] );
			LoadIdentity( );
		} else
			mtx = 0;
	}

	//------------------------------------------------------------------------------

	template<class T>
	TMatxEx<T>::~TMatxEx( )
	{
		if ( mtx ) {
			delete[] * mtx;
			delete[] mtx;
		}
	}

	//------------------------------------------------------------------------------

	template<class T>
	TMatxEx<T>::TMatxEx( const TMatxEx<T> &other )
	{
		order = other.order;
		if ( order ) {
			T *aux = new T[ order * order ];
			mtx = new T *[ order ];
			for ( int i = 0; i < order; i++ )
				mtx[ i ] = &( aux[ i * order ] );
			*this = other;
		} else
			mtx = 0;
	}

	//------------------------------------------------------------------------------

	template<class T>
	void TMatxEx<T>::LoadIdentity( )
	{
		for ( int i = 0; i < order; i++ )
			for ( int j = i + 1; j < order; j++ )
				mtx[ i ][ j ] = mtx[ j ][ i ] = 0.0;

		for ( int i = 0; i < order; i++ )
			mtx[ i ][ i ] = 1.0;
	}

	//------------------------------------------------------------------------------

	template<class T>
	void TMatxEx<T>::Inverse( TMatxEx<T> *b )
	{
		for ( int i = 0; i < order; ++i )
			for ( int j = 0; j < order; ++j ) {
				int sgn = ( ( i + j ) % 2 ) ? -1 : 1;
				b->Element( i, j ) = (double) sgn * TMatxCofactorEx<T>( *this, order - 1, i, j ).Determinant( );
			}
		b->Transpose( );

		double det = Determinant( );
		// Modificado para poder hacer bien la inversa con determinantes negativos
		//	*b /= ( det > MATH_EPSILON )? det : 1.0;
		*b /= ( fabs( det ) > MATH_EPSILON ) ? det : 1.0;
	}

	//------------------------------------------------------------------------------

	template<class T>
	double TMatxEx<T>::Determinant( ) const
	{
		double d = 0.0;
		for ( int i = 0; i < order; ++i ) {
			int sgn = ( i % 2 ) ? -1 : 1;
			TMatxCofactorEx<T> cf( *this, order - 1, i, 0 );
			d += (double) sgn * Element( i, 0 ) * cf.Determinant( );
		}
		return ( order ) ? d : 1.0;
	}

	//------------------------------------------------------------------------------

	template<class T>
	void TMatxEx<T>::Transpose( )
	{
		for ( int i = 0; i < order; ++i ) {
			for ( int j = i + 1; j < order; ++j ) {
				T aux = Element( i, j );
				Element( i, j ) = Element( j, i );
				Element( j, i ) = aux;
			}
		}
	}

	//------------------------------------------------------------------------------

	template<class T>
	void TMatxEx<T>::TransformPoint( T x, T y, T z, T &xout, T &yout, T &zout )
	{
		if ( order != 4 ) return;

		xout = ( x * Element( 0, 0 ) ) + ( y * Element( 0, 1 ) ) + ( z * Element( 0, 2 ) ) + Element( 0, 3 );
		yout = ( x * Element( 1, 0 ) ) + ( y * Element( 1, 1 ) ) + ( z * Element( 1, 2 ) ) + Element( 1, 3 );
		zout = ( x * Element( 2, 0 ) ) + ( y * Element( 2, 1 ) ) + ( z * Element( 2, 2 ) ) + Element( 2, 3 );
	}

	//------------------------------------------------------------------------------

	template<class T>
	TMatxEx<T> &TMatxEx<T>::operator=( const TMatxEx<T> &other )
	{
		T *rp = (T *) *mtx;
		T *rp2 = (T *) *other.mtx;
		int order2 = order * order;
		for ( int pos = 0; pos < order2; pos++ )
			rp[ pos ] = rp2[ pos ];
		return *this;
	}

	//------------------------------------------------------------------------------

	template<class T>
	TMatxEx<T> TMatxEx<T>::operator*( const TMatxEx<T> &other )
	{
		TMatxEx a;
		for ( int i = 0; i < order; ++i )
			for ( int l = 0; l < order; ++l ) {
				T &x = a.Element( i, l ) = 0.0;
				for ( int j = 0; j < order; ++j )
					x += Element( i, j ) * other.Element( j, l );
			}
		return a;
	}

	//------------------------------------------------------------------------------

	template<class T>
	TMatxEx<T> &TMatxEx<T>::operator*=( const TMatxEx<T> &other )
	{
		TMatxEx a;
		a = *this;
		for ( int i = 0; i < order; ++i )
			for ( int l = 0; l < order; ++l ) {
				T &x = Element( i, l ) = 0.0;
				for ( int j = 0; j < order; ++j )
					x += a.Element( i, j ) * other.Element( j, l );
			}
		return *this;
	}

	//------------------------------------------------------------------------------

	template<class T>
	TMatxEx<T> &TMatxEx<T>::operator/=( const double &fact )
	{
		// Modificado para poder hacer bien la inversa con determinantes negativos
		//	assert( fact > MATH_EPSILON );
		assert( fabs( fact ) > MATH_EPSILON );

		T *rp = (T *) *mtx;
		int order2 = order * order;
		for ( int pos = 0; pos < order2; pos++ )
			rp[ pos ] /= fact;
		return *this;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------

	template<class T>
	TMatxCofactorEx<T>::TMatxCofactorEx( const TMatxEx<T> &a, int corder, int aI, int aJ ): TMatxEx<T>( corder )
	{
		for ( int i = 0, k = 0; i < ( corder + 1 ); ++i ) {
			if ( i != aI ) {
				for ( int j = 0, l = 0; j < ( corder + 1 ); ++j ) {
					if ( j != aJ ) {
						this->Element( k, l ) = a.Element( i, j );
						++l;
					}
				}
				++k;
			}
		}
	}

	//==============================================================================
	// 	Implementacion de los miembros de TMatrixEx y derivadas
	//==============================================================================

	//----------------------------------------------------------------------------
	//  Constructor copia
	//----------------------------------------------------------------------------
	template<class T>
	TMatrixEx<T>::TMatrixEx( const TMatrixEx<T> &m )
	{
		memcpy( M, m.M, sizeof( T ) * 16 );
	}

	//----------------------------------------------------------------------------
	//  Constructor de una matriz a partir de un array de 16 numeros
	//----------------------------------------------------------------------------
	template<class T>
	TMatrixEx<T>::TMatrixEx( T *m )
	{
		for ( int i = 0; i < 16; i++ )
			M[ i ] = m[ i ];
	}

	//----------------------------------------------------------------------------
	//  Constructor de una matriz unidad.
	//----------------------------------------------------------------------------
	template<class T>
	TMatrixEx<T>::TMatrixEx( )
	{
		M[ 0 ] = 1;
		M[ 1 ] = 0;
		M[ 2 ] = 0;
		M[ 3 ] = 0;
		M[ 4 ] = 0;
		M[ 5 ] = 1;
		M[ 6 ] = 0;
		M[ 7 ] = 0;
		M[ 8 ] = 0;
		M[ 9 ] = 0;
		M[ 10 ] = 1;
		M[ 11 ] = 0;
		M[ 12 ] = 0;
		M[ 13 ] = 0;
		M[ 14 ] = 0;
		M[ 15 ] = 1;
	}

	//----------------------------------------------------------------------------
	//  Operador =
	//----------------------------------------------------------------------------
	template<class T>
	TMatrixEx<T> &TMatrixEx<T>::operator=( const TMatrixEx<T> &MP )
	{
		memcpy( M, MP.M, sizeof( T ) * 16 );
		return *this;
	}

	//----------------------------------------------------------------------------
	//  Operador ==
	//----------------------------------------------------------------------------

	template<class T>
	bool TMatrixEx<T>::operator==( const TMatrixEx<T> &other ) const
	{
		int i;

		for ( i = 0; i < 16; i++ )
			if ( fabs( M[ i ] - other.M[ i ] ) > RES_COMP ) return false;
		return true;
	}

	//----------------------------------------------------------------------------
	//  Operador !=
	//----------------------------------------------------------------------------

	template<class T>
	bool TMatrixEx<T>::operator!=( const TMatrixEx<T> &other ) const
	{
		return !( other == *this );
	}

	//----------------------------------------------------------------------------
	//  Determinante de la matriz.
	//----------------------------------------------------------------------------

	/*
	template<class T> double TMatrixEx<T>::Determinant() const
	{
	  double det  =
			M[ 3] * M[ 6] * M[ 9] * M[12]-M[ 2] * M[ 7] * M[ 9] * M[12]-M[ 3] * M[ 5] * M[10] * M[12]+M[ 1] * M[ 7] * M[10] * M[12]+
			M[ 2] * M[ 5] * M[11] * M[12]-M[ 1] * M[ 6] * M[11] * M[12]-M[ 3] * M[ 6] * M[ 8] * M[13]+M[ 2] * M[ 7] * M[ 8] * M[13]+
			M[ 3] * M[ 4] * M[10] * M[13]-M[ 0] * M[ 7] * M[10] * M[13]-M[ 2] * M[ 4] * M[11] * M[13]+M[ 0] * M[ 6] * M[11] * M[13]+
			M[ 3] * M[ 5] * M[ 8] * M[14]-M[ 1] * M[ 7] * M[ 8] * M[14]-M[ 3] * M[ 4] * M[ 9] * M[14]+M[ 0] * M[ 7] * M[ 9] * M[14]+
			M[ 1] * M[ 4] * M[11] * M[14]-M[ 0] * M[ 5] * M[11] * M[14]-M[ 2] * M[ 5] * M[ 8] * M[15]+M[ 1] * M[ 6] * M[ 8] * M[15]+
			M[ 2] * M[ 4] * M[ 9] * M[15]-M[ 0] * M[ 6] * M[ 9] * M[15]-M[ 1] * M[ 4] * M[10] * M[15]+M[ 0] * M[ 5] * M[10] * M[15];

	  return det;
	}
	*/

	//----------------------------------------------------------------------------
	//  Tipo de matriz
	//----------------------------------------------------------------------------
	inline bool _IsZero( double value )
	{
		if ( -RES_GEOM < value && value < RES_GEOM ) return true;
		return false;
	}

	template<class T>
	bool TMatrixEx<T>::IsTranslationMatrix( )
	{
		if ( M[ 0 ] == 1 && _IsZero( M[ 4 ] ) && _IsZero( M[ 8 ] ) && _IsZero( M[ 1 ] ) && M[ 5 ] == 1 && _IsZero( M[ 9 ] ) && _IsZero( M[ 2 ] ) && _IsZero( M[ 6 ] ) && M[ 10 ] == 1 && _IsZero( M[ 3 ] ) && _IsZero( M[ 7 ] ) && _IsZero( M[ 11 ] ) && M[ 15 ] == 1 && ( !_IsZero( M[ 12 ] ) || !_IsZero( M[ 13 ] ) || !_IsZero( M[ 14 ] ) ) ) return true;
		return false;
	}

	template<class T>
	bool TMatrixEx<T>::IsRotationMatrix( )
	{
		return false;
	}

	template<class T>
	bool TMatrixEx<T>::IsScaleMatrix( )
	{
		return false;
	}

	template<class T>
	bool TMatrixEx<T>::IsIdentity( )
	{
		TMatrixEx<T> m;
		return this->operator==( m );
	}

	//----------------------------------------------------------------------------
	//  Matriz identidad.
	//----------------------------------------------------------------------------

	template<class T>
	void TMatrixEx<T>::Identity( )
	{
		M[ 0 ] = 1;
		M[ 1 ] = 0;
		M[ 2 ] = 0;
		M[ 3 ] = 0;
		M[ 4 ] = 0;
		M[ 5 ] = 1;
		M[ 6 ] = 0;
		M[ 7 ] = 0;
		M[ 8 ] = 0;
		M[ 9 ] = 0;
		M[ 10 ] = 1;
		M[ 11 ] = 0;
		M[ 12 ] = 0;
		M[ 13 ] = 0;
		M[ 14 ] = 0;
		M[ 15 ] = 1;
	}

	//----------------------------------------------------------------------------
	//  Matriz traspuesta.
	//----------------------------------------------------------------------------

	template<class T>
	TMatrixEx<T> TMatrixEx<T>::Transposed( ) const
	{
		T m[ 16 ];

		m[ 0 ] = M[ 0 ];
		m[ 1 ] = M[ 4 ];
		m[ 2 ] = M[ 8 ];
		m[ 3 ] = M[ 12 ];
		m[ 4 ] = M[ 1 ];
		m[ 5 ] = M[ 5 ];
		m[ 6 ] = M[ 9 ];
		m[ 7 ] = M[ 13 ];
		m[ 8 ] = M[ 2 ];
		m[ 9 ] = M[ 6 ];
		m[ 10 ] = M[ 10 ];
		m[ 11 ] = M[ 14 ];
		m[ 12 ] = M[ 3 ];
		m[ 13 ] = M[ 7 ];
		m[ 14 ] = M[ 11 ];
		m[ 15 ] = M[ 15 ];

		return TMatrixEx<T>( m );
	}

	//----------------------------------------------------------------------------
	//  Matriz inversa. Si no existe devuelve la original
	//----------------------------------------------------------------------------

	template<class T>
	TMatrixEx<T> TMatrixEx<T>::Inverse( ) const
	{
		int i, j;
		T data[ 16 ];
		TMatxEx<T> mat, mat2;

		memcpy( data, M, sizeof( T ) * 16 );

		for ( i = 0; i < 4; i++ )
			for ( j = 0; j < 4; j++ )
				mat( i, j ) = data[ ( i * 4 ) + j ];

		mat.Inverse( &mat2 );

		for ( i = 0; i < 4; i++ )
			for ( j = 0; j < 4; j++ )
				data[ ( i * 4 ) + j ] = mat2( i, j );

		return TMatrixEx<T>( data );
	}

	//----------------------------------------------------------------------------

	template<class T>
	void TMatrixEx<T>::SetData( T *data )
	{
		int i;

		for ( i = 0; i < 16; i++ )
			M[ i ] = data[ i ];
	}

	//----------------------------------------------------------------------------
	//  Operador producto de matrices.
	//----------------------------------------------------------------------------
	template<class T>
	TMatrixEx<T> TMatrixEx<T>::operator*( TMatrixEx<T> &MP ) const
	{
		T m[ 16 ];
		for ( int i = 0; i < 16; i++ ) {
			int f = i / 4;
			int c = i % 4;

			// Comentado TO_RES_COMP para que los resultados sean igual de precisos
			// que en hormas

			m[ i ] = /*TO_RES_COMP(*/ M[ f * 4 ] * MP[ c ] + M[ f * 4 + 1 ] * MP[ c + 4 ] + M[ f * 4 + 2 ] * MP[ c + 8 ] + M[ f * 4 + 3 ] * MP[ c + 12 ] /*)*/;
		}
		return TMatrixEx<T>( m );
	}

	//----------------------------------------------------------------------------
	//  Operador division de matriz.
	//----------------------------------------------------------------------------
	template<class T>
	TMatrixEx<T> TMatrixEx<T>::operator/( const T factor ) const
	{
		PRECONDITION( factor > 0 );
		T m[ 16 ];

		// Comentado TO_RES_COMP para que los resultados sean igual de precisos
		// que en hormas

		for ( int i = 0; i < 16; i++ )
			m[ i ] = /*TO_RES_COMP(*/ M[ i ] / factor /*)*/;

		return TMatrixEx<T>( m );
	}

	//----------------------------------------------------------------------------

	template<class T>
	TRotateMatrixEx<T>::TRotateMatrixEx( ): TMatrixEx<T>( )
	{
	}

	//----------------------------------------------------------------------------
	// Constructor de una matriz de rotacion de alfa grados sobre el vector v.
	//----------------------------------------------------------------------------
	template<class T>
	TRotateMatrixEx<T>::TRotateMatrixEx( T angle, T3DVectorEx<T> &v ): TMatrixEx<T>( )
	{
		T mod = v.Modulo( );
		if ( ( fabs( angle ) < RES_COMP2 ) || ( mod < RES_COMP2 ) ) { // Devuelvo la matriz identidad
			this->M[ 0 ] = 1;
			this->M[ 1 ] = 0;
			this->M[ 2 ] = 0;
			this->M[ 3 ] = 0;
			this->M[ 4 ] = 0;
			this->M[ 5 ] = 1;
			this->M[ 6 ] = 0;
			this->M[ 7 ] = 0;
			this->M[ 8 ] = 0;
			this->M[ 9 ] = 0;
			this->M[ 10 ] = 1;
			this->M[ 11 ] = 0;
			this->M[ 12 ] = 0;
			this->M[ 13 ] = 0;
			this->M[ 14 ] = 0;
			this->M[ 15 ] = 1;
			return;
		}
		T vm = v.size.cx * v.size.cx + v.size.cy * v.size.cy;
		vm = ( vm < RES_COMP2 ) ? 0 : sqrt( vm );
		T ca = vm / mod;
		T sa = v.size.cz / mod;
		T cb = ( vm > 0 ) ? v.size.cx / vm : 1;
		T sb = ( vm > 0 ) ? -v.size.cy / vm : 0;
		T cg = cos( angle );
		T sg = sin( angle );
		T pca2 = ca * ca;
		T psa2 = sa * sa;
		T pcb2 = cb * cb;
		T psb2 = sb * sb;

		this->M[ 0 ] = pca2 * pcb2 + psa2 * pcb2 * cg + psb2 * cg;
		this->M[ 1 ] = pca2 * sb * cb * ( cg - 1 ) + sa * sg;
		this->M[ 2 ] = ca * ( sb * sg - sa * cb * ( cg - 1 ) );
		this->M[ 3 ] = 0;
		this->M[ 4 ] = pca2 * sb * cb * ( cg - 1 ) - sa * sg;
		this->M[ 5 ] = pca2 * psb2 + psa2 * psb2 * cg + pcb2 * cg;
		this->M[ 6 ] = ca * ( sa * sb * ( cg - 1 ) + cb * sg );
		this->M[ 7 ] = 0;
		this->M[ 8 ] = -ca * ( sa * cb * ( cg - 1 ) + sb * sg );
		this->M[ 9 ] = ca * ( sa * sb * ( cg - 1 ) - cb * sg );
		this->M[ 10 ] = pca2 * cg + psa2;
		this->M[ 11 ] = 0;
		this->M[ 12 ] = pca2 * ( v.org.y * sb * cb - v.org.x * pcb2 ) + ca * ( sa * cb * ( v.org.z * cg - v.org.z ) + v.org.z * sb * sg ) + psa2 * ( v.org.y * sb * cb * cg - v.org.x * pcb2 * cg ) + v.org.y * sa * sg - v.org.y * sb * cb * cg - v.org.x * psb2 * cg + v.org.x;
		this->M[ 13 ] = pca2 * ( v.org.x * sb * cb - v.org.y * psb2 ) + ca * ( v.org.z * cb * sg - sa * sb * ( v.org.z * cg - v.org.z ) ) + psa2 * ( v.org.x * sb * cb * cg - v.org.y * psb2 * cg ) - v.org.x * sa * sg - v.org.y * pcb2 * cg - v.org.x * sb * cb * cg + v.org.y;
		this->M[ 14 ] = pca2 * ( v.org.z - v.org.z * cg ) + ca * ( sa * ( cb * ( v.org.x * cg - v.org.x ) + sb * ( v.org.y - v.org.y * cg ) ) - v.org.y * cb * sg - v.org.x * sb * sg );
		this->M[ 15 ] = 1;
	}

	//----------------------------------------------------------------------------
	//  Constructor de una matriz de escalado de factores x,y,z segun
	//  el vector de escalado v.
	//----------------------------------------------------------------------------

	template<class T>
	TScaleMatrixEx<T>::TScaleMatrixEx( ): TMatrixEx<T>( )
	{
	}

	//----------------------------------------------------------------------------

	template<class T>
	TScaleMatrixEx<T>::TScaleMatrixEx( T factorx, T factory, T factorz ): TMatrixEx<T>( )
	{
		this->M[ 0 ] = factorx;
		this->M[ 1 ] = 0;
		this->M[ 2 ] = 0;
		this->M[ 3 ] = 0;
		this->M[ 4 ] = 0;
		this->M[ 5 ] = factory;
		this->M[ 6 ] = 0;
		this->M[ 7 ] = 0;
		this->M[ 8 ] = 0;
		this->M[ 9 ] = 0;
		this->M[ 10 ] = factorz;
		this->M[ 11 ] = 0;
		this->M[ 12 ] = 0;
		this->M[ 13 ] = 0;
		this->M[ 14 ] = 0;
		this->M[ 15 ] = 1;
	}

	//----------------------------------------------------------------------------

	template<class T>
	TScaleMatrixEx<T>::TScaleMatrixEx( T f ): TMatrixEx<T>( )
	{
		this->M[ 0 ] = f;
		this->M[ 1 ] = 0;
		this->M[ 2 ] = 0;
		this->M[ 3 ] = 0;
		this->M[ 4 ] = 0;
		this->M[ 5 ] = f;
		this->M[ 6 ] = 0;
		this->M[ 7 ] = 0;
		this->M[ 8 ] = 0;
		this->M[ 9 ] = 0;
		this->M[ 10 ] = f;
		this->M[ 11 ] = 0;
		this->M[ 12 ] = 0;
		this->M[ 13 ] = 0;
		this->M[ 14 ] = 0;
		this->M[ 15 ] = 1;
	}

	//----------------------------------------------------------------------------

	template<class T>
	TScaleMatrixEx<T>::TScaleMatrixEx( T factorx, T factory, T factorz, const T3DVectorEx<T> &axis ): TMatrixEx<T>( )
	{
		if ( axis.Modulo( ) <= RES_COMP ) return;

		double ca = axis.size.cx / axis.Modulo( );
		double sa = axis.size.cz / axis.Modulo( );
		double f = 1 + factorx;
		double g = 1 + factory;
		double h = 1 + factorz;
		double pca2 = ca * ca;

		this->M[ 0 ] = ( f - h ) * pca2 + h;
		this->M[ 1 ] = 0;
		this->M[ 2 ] = ( f - h ) * sa * ca;
		this->M[ 3 ] = 0;
		this->M[ 4 ] = 0;
		this->M[ 5 ] = g;
		this->M[ 6 ] = 0;
		this->M[ 7 ] = 0;
		this->M[ 8 ] = ( f - h ) * sa * ca;
		this->M[ 9 ] = 0;
		this->M[ 10 ] = ( h - f ) * pca2 + f;
		this->M[ 11 ] = 0;
		this->M[ 12 ] = axis.org.x * ( h - f ) * pca2 + axis.org.z * ( h - f ) * sa * ca + axis.org.x * ( 1 - h );
		this->M[ 13 ] = axis.org.y * ( 1 - g );
		this->M[ 14 ] = axis.org.z * ( f - h ) * pca2 + axis.org.x * ( h - f ) * sa * ca + axis.org.z * ( 1 - f );
		this->M[ 15 ] = 1;
	}

	//----------------------------------------------------------------------------
	// Constructor de una matriz de traslacion de desplazamiento el vector v.
	//----------------------------------------------------------------------------

	template<class T>
	TTraslationMatrixEx<T>::TTraslationMatrixEx( ): TMatrixEx<T>( )
	{
	}

	//----------------------------------------------------------------------------

	template<class T>
	TTraslationMatrixEx<T>::TTraslationMatrixEx( T3DVectorEx<T> &v )
	{
		this->M[ 0 ] = 1;
		this->M[ 1 ] = 0;
		this->M[ 2 ] = 0;
		this->M[ 3 ] = 0;
		this->M[ 4 ] = 0;
		this->M[ 5 ] = 1;
		this->M[ 6 ] = 0;
		this->M[ 7 ] = 0;
		this->M[ 8 ] = 0;
		this->M[ 9 ] = 0;
		this->M[ 10 ] = 1;
		this->M[ 11 ] = 0;
		this->M[ 12 ] = v.size.cx;
		this->M[ 13 ] = v.size.cy;
		this->M[ 14 ] = v.size.cz;
		this->M[ 15 ] = 1;
	}

	//----------------------------------------------------------------------------
	// Constructor de una matriz de eje a partir de los 4 puntos
	//----------------------------------------------------------------------------

	template<class T>
	TAxisMatrixEx<T>::TAxisMatrixEx( ): TMatrixEx<T>( )
	{
	}

	//----------------------------------------------------------------------------

	template<class T>
	TAxisMatrixEx<T>::TAxisMatrixEx( T3DPointEx<T> p1old, T3DPointEx<T> p2old, T3DPointEx<T> p1new, T3DPointEx<T> p2new ): TMatrixEx<T>( )
	{
		T3DVectorEx<T> vec, v1, v2;
		T angle;

		if ( ( p1new == p2new ) || ( p2old == p2new ) ) return;

		vec = T3DVectorEx<T>( T3DSizeEx<T>( p1new - p1old ), p1old );
		TTraslationMatrixEx<T> TM( vec );

		p1old.ApplyMatrix( TM );
		p2old.ApplyMatrix( TM );

		T3DPlaneEx<T> plane( p1new, p2old, p2new );

		v1 = T3DVectorEx<T>( T3DSizeEx<T>( p2old - p1old ), p1old );
		v1.Unitario( );
		if ( fabs( v1.Modulo( ) - 1.0 ) > RES_GEOM ) {
			memcpy( this->M, TM.GetData( ), sizeof( T ) * 16 );
			return;
		}

		v2 = T3DVectorEx<T>( T3DSizeEx<T>( p2new - p1new ), p1new );
		v2.Unitario( );
		if ( fabs( v2.Modulo( ) - 1.0 ) > RES_GEOM ) {
			memcpy( this->M, TM.GetData( ), sizeof( T ) * 16 );
			return;
		}

		angle = v1.size.cx * v2.size.cx + v1.size.cy * v2.size.cy + v1.size.cz * v2.size.cz;
		if ( angle > 1.0 ) angle = 1.0;
		if ( angle < -1.0 ) angle = -1.0;
		angle = acos( angle ); // * M_180_PI;

		if ( fabs( angle ) < 0.0001 ) {
			memcpy( this->M, TM.GetData( ), sizeof( T ) * 16 );
			return;
		}

		vec = T3DVectorEx<T>( p1new, p1new + plane.normal.size );
		TRotateMatrixEx<T> RM( angle, vec );

		TMatrixEx<T> AuxM = TM * RM;
		memcpy( this->M, AuxM.GetData( ), sizeof( T ) * 16 );
	}

	//------------------------------------------------------------------------------
	// INSTANCIACION DE TIPOS
	//------------------------------------------------------------------------------

	// Definicion de tipos con doubles

	typedef T3DSizeEx<double> T3DSize;
	typedef T3DPointEx<double> T3DPoint;
	typedef T3DRectEx<double> T3DRect;
	typedef T3DVectorEx<double> T3DVector;
	typedef T3DPlaneEx<double> T3DPlane;
	typedef T3DLineEx<double> T3DLine;

	typedef TMatxEx<float> TMatx;
	typedef TMatrixEx<double> TNMatrix;
	typedef TRotateMatrixEx<double> TNRotateMatrix;
	typedef TTraslationMatrixEx<double> TNTraslationMatrix;
	typedef TAxisMatrixEx<double> TNAxisMatrix;
	typedef TScaleMatrixEx<double> TNScaleMatrix;

	// Definicion de tipos con float

	typedef T3DPointEx<float> T3DPointF;
	typedef T3DLineEx<float> T3DLineF;
} // namespace InesMath

#endif

