#ifndef GEO_POINT_H
#define GEO_POINT_H

#include <checks.h>
#include <values.h>
#if defined( _WIN64 ) || defined( __clang__ )
#include <iostream>
#else
#include <iostream.h>
#endif
#include <windows.hpp>
#include <algorithm> // std::min

#ifndef dmult											 // definicion de
#define dmult( x, y ) ( ( ( (double) ( x ) ) ) * ( y ) ) // producto doble
#define ddiv( x, y )  ( ( ( (double) ( x ) ) ) / ( y ) )
#endif

#ifdef HIGH_PRECISION
#define MATH_EPSILON 1e-12
#else
#define MATH_EPSILON 1e-7
#endif

#define RES_RASTER		   0.01

#define RES_GEOM		   0.01
#define RES_GEOM2		   0.0001
#define RES_1_GEOM		   100.0

#define RES_COMP		   0.00001
#define RES_COMP2		   0.0000000001
#define RES_1_COMP		   100000.0

#define RES_PARAM		   0.00001
#define MAX_PARAM		   1000.0
#define MAX_1_PARAM		   0.001
#define RES_1_PARAM		   100000.0
#define MAX_RES_1_PARAM	   1000000000000.0

#define DEGENERATED_AREA   0.05

#define RES_TESSELATION	   0.1

#define TO_RES_RASTER( X ) ( ( X >= 0 ) ? ( ( floor( (X) *100.0 ) ) / 100 ) : ( ( ceil( (X) *100.0 ) ) / 100 ) )
#define TO_RES_GEOM( X )   ( ( X >= 0 ) ? ( ( floor( (X) *100.0 ) ) / 100 ) : ( ( ceil( (X) *100.0 ) ) / 100 ) )
#define TO_RES_COMP( X )   ( ( X >= 0 ) ? ( ( floor( (X) *100000.0 ) ) / 100000 ) : ( ( ceil( (X) *100000.0 ) ) / 100000 ) )
#define TO_RES( X, Y )	   ( ( ( X ) >= 0 ) ? ( ( floor( (X) *1e##Y + 5e-1 ) ) / 1e##Y ) : ( ( ceil( (X) *1e##Y - 5e-1 ) ) / 1e##Y ) )

#define sqr( x )		   ( ( x ) * ( x ) )

#define M_PI_180		   0.01745329251994
#define M_180_PI		   57.29577951308

//
// Misc support functions
//
namespace InesMath
{
	template<class T>
	void SwapBis( T far &a, T far &b )
	{
		T t = a;
		a = b;
		b = t;
	}

	template<class T>
	T MinBis( T a, T b )
	{
		return a < b ? a : b;
	}
	template<class T>
	T MaxBis( T a, T b )
	{
		return a > b ? a : b;
	}
	// Adaptar estas funciones para que se llame a una u otra

	template<class T>
	class TSizeEx;
	template<class T>
	class TRectEx;

	//
	// class TPointEx
	// ----- ------
	//
	template<class T>
	class TPointEx
	{
	  public:
		T x, y;

		// Constructors
		TPointEx( )
		{
			x = 0;
			y = 0;
		}
		TPointEx( T _x, T _y )
		{
			x = _x;
			y = _y;
		}
		TPointEx( const TSizeEx<T> &size )
		{
			x = size.cx;
			y = size.cy;
		}

#ifndef _owl_not_supported_
		TPointEx( const TPoint &point )
		{
			x = point.x;
			y = point.y;
		}
		TPointEx( const TSize &size )
		{
			x = size.cx;
			y = size.cy;
		}
#endif

		// Information functions/operators
		bool operator==( const TPointEx<T> &other ) const;
		bool operator!=( const TPointEx<T> &other ) const;
		bool operator>=( const TPointEx<T> &other ) const;
		bool operator<=( const TPointEx<T> &other ) const;
		bool operator>( const TPointEx<T> &other ) const;
		bool operator<( const TPointEx<T> &other ) const;

		// Functions/binary-operators that return points or sizes
		TPointEx<T> OffsetBy( T dx, T dy ) const
		{
			return TPointEx<T>( x + dx, y + dy );
		}
		TPointEx<T> operator+( const TSizeEx<T> &size ) const;
		TSizeEx<T> operator-( const TPointEx<T> &point ) const;
		TPointEx<T> operator-( const TSizeEx<T> &size ) const;
		TPointEx<T> operator-( ) const
		{
			return TPointEx<T>( -x, -y );
		}
		TPointEx<T> operator*( const TSizeEx<T> & ) const;
		TPointEx<T> operator/( const TSizeEx<T> & ) const;
		TPointEx<T> operator+( const T factor ) const;
		TPointEx<T> operator-( const T factor ) const;
		TPointEx<T> operator*( const T factor ) const;
		TPointEx<T> operator/( const T factor ) const;

		// Asociatividad contraria de los operadores

		friend TPointEx<T> operator+( const T &factor, const TPointEx<T> &P )
		{
			return P + factor;
		}
		friend TPointEx<T> operator*( const T &factor, const TPointEx<T> &P )
		{
			return P * factor;
		}

		// Functions/assignement-operators that modify this point
		TPointEx<T> &Offset( T dx, T dy );
		TPointEx<T> &operator+=( const TSizeEx<T> &size );
		TPointEx<T> &operator-=( const TSizeEx<T> &size );
		TPointEx<T> &operator*=( const TSizeEx<T> & );
		TPointEx<T> &operator/=( const TSizeEx<T> & );
		TPointEx<T> &operator*=( const T factor );
		TPointEx<T> &operator/=( const T factor );

#ifndef _owl_not_supported_ // 'Casting' al TPoint de las OWL
#ifdef __WIN32__
		operator TPoint( )
		{
			return TPoint( long( x ), long( y ) );
		}
#else
		operator TPoint( )
		{
			return TPoint( int( x ), int( y ) );
		}
#endif
#endif

		//------------------------------------ RAFA -----------------------------
		void Rotation( const T &Angle )
		{
			TPointEx<T> OldP = *this;
			x = OldP.x * cos( Angle ) - OldP.y * sin( Angle );
			y = OldP.x * sin( Angle ) + OldP.y * cos( Angle );
		}
		//-----------------------------------------------------------------------

		double Distancia( const TPointEx<T> &P )
		{
			double Aux = ( x - P.x ) * ( x - P.x ) + ( y - P.y ) * ( y - P.y );
			return ( Aux > RES_COMP ) ? sqrt( Aux ) : 0;
		}

		friend std::wostream &operator<<( std::wostream &os, const TPointEx<T> &p )
		{
			return os << p.x << ',' << p.y;
		}
		friend std::wistream &operator>>( std::wistream &is, TPointEx<T> &p )
		{
			wchar_t c;
			return is >> p.x >> c >> p.y;
		}
	};

	//
	// class TSizeEx<T>
	// ----- -----
	//
	template<class T>
	class TSizeEx
	{
	  public:
		T cx, cy;

		// Constructors
		TSizeEx( )
		{
		}
		TSizeEx( T dx, T dy )
		{
			cx = dx;
			cy = dy;
		}
		TSizeEx<T>( const TPointEx<T> &point )
		{
			cx = point.x;
			cy = point.y;
		}

#ifndef _owl_not_supported_
		TSizeEx<T>( const TSize &size )
		{
			cx = size.cx;
			cy = size.cy;
		}
#endif

		// Information functions/operators
		bool operator==( const TSizeEx<T> &other ) const;
		bool operator!=( const TSizeEx<T> &other ) const;
		bool operator>=( const TSizeEx<T> &other ) const;
		bool operator<=( const TSizeEx<T> &other ) const;
		bool operator>( const TSizeEx<T> &other ) const;
		bool operator<( const TSizeEx<T> &other ) const;
		double Magnitude( ) const;

		// Functions/binary-operators that return sizes
		TSizeEx<T> operator+( const TSizeEx<T> &size ) const;
		TSizeEx<T> operator-( const TSizeEx<T> &size ) const;
		TSizeEx<T> operator-( ) const
		{
			return TSizeEx<T>( -cx, -cy );
		}
		TSizeEx<T> operator*( const TSizeEx<T> &size ) const;
		TSizeEx<T> operator/( const TSizeEx<T> &size ) const;
		TSizeEx<T> operator+( const T factor ) const;
		TSizeEx<T> operator-( const T factor ) const;
		TSizeEx<T> operator*( const T factor ) const;
		TSizeEx<T> operator/( const T factor ) const;

		friend TSizeEx<T> operator+( const T &factor, const TSizeEx<T> &S )
		{
			return S + factor;
		}
		friend TSizeEx<T> operator*( const T &factor, const TSizeEx<T> &S )
		{
			return S * factor;
		}

		// Functions/assignement-operators that modify this size
		TSizeEx<T> &operator+=( const TSizeEx<T> &size );
		TSizeEx<T> &operator-=( const TSizeEx<T> &size );
		TSizeEx<T> &operator*=( const T factor ) const;
		TSizeEx<T> &operator/=( const T factor ) const;

#ifndef _owl_not_supported_ // 'Casting' explicito al TSize de las OWL
#ifdef __WIN32__
		operator TSize( )
		{
			return TSize( long( cx ), long( cy ) );
		}
#else
		operator TSize( )
		{
			return TSize( int( cx ), int( cy ) );
		}
#endif
#endif

		friend std::wostream &operator<<( std::wostream &os, const TSizeEx<T> &s )
		{
			return os << '(' << s.cx << 'x' << s.cy << ')';
		}
		friend std::wistream &operator>>( std::wistream &is, TSizeEx<T> &s )
		{
			wchar_t c;
			return is >> c >> s.cx >> c >> s.cy >> c;
		}
	};

	//
	// class TRectEx<T>
	// ----- -----
	//
	template<class T>
	class TRectEx
	{
	  public:
		T left, top, right, bottom;

		// Constructors
		TRectEx( )
		{
		}
		TRectEx( T _left, T _top, T _right, T _bottom );
		TRectEx( const TPointEx<T> &upLeft, const TPointEx<T> &loRight );
		TRectEx( const TPointEx<T> &origin, const TSizeEx<T> &extent );

		// (re)Initializers
		void SetNull( );
		void SetEmpty( )
		{
			SetNull( );
		}
		void Set( T _left, T _top, T _right, T _bottom );

		// Type Conversion operators
		operator const TPointEx<T> *( ) const
		{
			return (const TPointEx<T> *) this;
		}
		operator TPointEx<T> *( )
		{
			return (TPointEx<T> *) this;
		}

		// Testing functions
		bool IsEmpty( ) const;
		bool IsNull( ) const;
		bool IsValid( ) const;
		bool IsPlain( ) const;
		bool operator==( const TRectEx<T> &other ) const;
		bool operator!=( const TRectEx<T> &other ) const;

		// Information/access functions(const and non-const)
		const TPointEx<T> &TopLeft( ) const
		{
			return *(TPointEx<T> *) &left;
		}
		TPointEx<T> &TopLeft( )
		{
			return *(TPointEx<T> *) &left;
		}
		TPointEx<T> TopRight( ) const
		{
			return TPointEx<T>( right, top );
		}
		TPointEx<T> BottomLeft( ) const
		{
			return TPointEx<T>( left, bottom );
		}
		const TPointEx<T> &BottomRight( ) const
		{
			return *(TPointEx<T> *) &right;
		}
		TPointEx<T> &BottomRight( )
		{
			return *(TPointEx<T> *) &right;
		}
		TPointEx<T> Center( ) const
		{
			return TPointEx<T>( ( left + right ) / 2.0, ( top + bottom ) / 2.0 );
		}
		T Width( ) const
		{
			return right - left;
		}
		T Height( ) const
		{
			return bottom - top;
		}
		TSizeEx<T> Size( ) const
		{
			return TSizeEx<T>( Width( ), Height( ) );
		}
		double Area( ) const
		{
			return dmult( Width( ), Height( ) );
		}

		bool Contains( const TPointEx<T> &point ) const;
		bool Contains( const TRectEx<T> &other ) const;
		bool Touches( const TRectEx<T> &other ) const;
		TRectEx<T> OffsetBy( T dx, T dy ) const;
		TRectEx<T> operator+( const TSizeEx<T> &size ) const;
		TRectEx<T> operator-( const TSizeEx<T> &size ) const;
		TRectEx<T> InflatedBy( T dx, T dy ) const;
		TRectEx<T> InflatedBy( const TSizeEx<T> &size ) const;
		TRectEx<T> Normalized( ) const;
		TRectEx<T> operator&( TRectEx<T> &other );
		TRectEx<T> operator|( TRectEx<T> &other );

		// Manipulation functions/operators
		TRectEx<T> &Normalize( );
		TRectEx<T> &Offset( T dx, T dy );
		TRectEx<T> &operator+=( const TSizeEx<T> &delta );
		TRectEx<T> &operator-=( const TSizeEx<T> &delta );
		TRectEx<T> &Inflate( T dx, T dy );
		TRectEx<T> &Inflate( const TSizeEx<T> &delta );
		TRectEx<T> &operator&=( TRectEx<T> &other );
		TRectEx<T> &operator|=( TRectEx<T> &other );

#ifndef _owl_not_supported_ //'Casting' explicito al TRect de las OWL
#ifdef __WIN32__
		operator TRect( )
		{
			return TRect( long( left ), long( top ), long( right ), long( bottom ) );
		}
#else
		operator TRect( )
		{
			return TRect( int( left ), int( top ), int( right ), int( bottom ) );
		}
#endif
#endif

		friend std::wostream &operator<<( std::wostream &os, const TRectEx<T> &r );
		friend std::wistream &operator>>( std::wistream &is, TRectEx<T> &r );
	};

	template<class T>
	class TVector
	{
	  public:
		TPointEx<T> org; // origen del vector
		TSizeEx<T> size; // tamanyo del vector (x,y): puede ser negativo, ojo

		TVector( ) { };
#if defined( _WIN64 ) || defined( __clang__ )
		TVector( const TSizeEx<T> &_size, const TPointEx<T> &_org = TPointEx<T>( 0, 0 ) )
		{
			org = _org;
			size = _size;
		}
#else
		TVector( const TSizeEx<T> &_size, const TPointEx<T> &_org = ( 0, 0 ) )
		{
			org = _org;
			size = _size;
		}
#endif
		TVector( const TPointEx<T> &first, const TPointEx<T> &last )
		{
			org = first;
			size = last - first;
		}
#if defined( _WIN64 ) || defined( __clang__ )
		TVector( T, double, const TPointEx<T> &_org = TPointEx<T>( 0, 0 ) );
#else
		TVector( T, double, const TPointEx<T> &_org = ( 0, 0 ) );
#endif

		double Modulo( ) const
		{
			return size.Magnitude( );
		}
		double Angulo( ) const;

		TVector<T> Normal( ) const;
		TVector<T> Unitario( ) const;

		TVector<T> &Modulo( T ); // Cambiar el modulo del vector al nuevo modulo
		TVector<T> &Girar( const double );

		TVector<T> operator+( const TVector<T> & ) const;
		TVector<T> operator-( const TVector<T> & ) const;
		double operator*( const TVector<T> & ) const; // Producto escalar
		double operator^( const TVector<T> & ) const; // Angulo entre dos vectores

		//		T			  Z (const TVector<T>&) const;           // Producto vectorial
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
	class TRecta
	{
	  protected:
		void Init( const TPointEx<T> &, const TPointEx<T> & );
		bool Vertical( ) const
		{
			return B == 0;
		}

	  public:
		TPointEx<T> start, end;		// ecuacion de la recta que pasa por 2 puntos
		double pendiente, ordenada; // ecuacion de la pendiente
		double A, B, C;				// ecuacion en forma general

		TRecta( )
		{
			pendiente = ordenada = A = B = C = 0.0;
		}
		TRecta( const TPointEx<T> &_org, const TVector<T> &_dir )
		{
			Init( _org, _org + _dir.size );
		}
		TRecta( const TPointEx<T> &_start, const TPointEx<T> &_end )
		{
			Init( _start, _end );
		}
		TRecta( const double, const double, const double );
		TRecta( const double, const double );

		// rectas paralelas
		bool operator||( const TRecta<T> &R ) const;
		TPointEx<T> operator+( const TRecta<T> & ) const; // interseccion de dos rectas
		bool Intersect( const TRecta<T> &R, TPointEx<T> &P ) const;

		TRecta<T> Offset( const T ) const; // paralela a distancia X
		TVector<T> Director( ) const
		{
			return TVector<T>( start, end );
		}
		double Distancia( const TPointEx<T> & ) const; // distancia de un punto a una recta

		bool Touches( const TPointEx<T> & ) const;
		bool Touches( const TRecta<T> & ) const;
	};

#include <math.h> // sqrt

	//----------------------------------------------------------------------------
	// TPoint
	//----------------------------------------------------------------------------

	template<class T>
	bool TPointEx<T>::operator==( const TPointEx<T> &other ) const
	{
		return other.x == x && other.y == y;
	}

	template<class T>
	bool TPointEx<T>::operator!=( const TPointEx<T> &other ) const
	{
		return !( other == *this );
	}

	template<class T>
	bool TPointEx<T>::operator>=( const TPointEx<T> &other ) const
	{
		return other.x <= x && other.y <= y;
	}

	template<class T>
	bool TPointEx<T>::operator<=( const TPointEx<T> &other ) const
	{
		return other.x >= x && other.y >= y;
	}

	template<class T>
	bool TPointEx<T>::operator>( const TPointEx<T> &other ) const
	{
		return x > other.x && y > other.y;
	}

	template<class T>
	bool TPointEx<T>::operator<( const TPointEx<T> &other ) const
	{
		return x < other.x && y < other.y;
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator+( const TSizeEx<T> &size ) const
	{
		return TPointEx<T>( x + size.cx, y + size.cy );
	}

	template<class T>
	TSizeEx<T> TPointEx<T>::operator-( const TPointEx<T> &point ) const
	{
		return TSizeEx<T>( x - point.x, y - point.y );
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator-( const TSizeEx<T> &size ) const
	{
		return TPointEx<T>( x - size.cx, y - size.cy );
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator/( const TSizeEx<T> &size ) const
	{
		PRECONDITION( size.cx > 0 && size.cy > 0 );
		return TPointEx<T>( x / size.cx, y / size.cy );
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator*( const TSizeEx<T> &size ) const
	{
		return TPointEx<T>( x * size.cx, y * size.cy );
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator-( const T factor ) const
	{
		return TPointEx<T>( x - factor, y - factor );
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator+( const T factor ) const
	{
		return TPointEx<T>( x + factor, y + factor );
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator/( const T factor ) const
	{
		PRECONDITION( factor > 0 );
		return TPointEx<T>( x / factor, y / factor );
	}

	template<class T>
	TPointEx<T> TPointEx<T>::operator*( const T factor ) const
	{
		return TPointEx<T>( x * factor, y * factor );
	}

	template<class T>
	TPointEx<T> &TPointEx<T>::Offset( T dx, T dy )
	{
		x += dx;
		y += dy;
		return *this;
	}

	template<class T>
	TPointEx<T> &TPointEx<T>::operator+=( const TSizeEx<T> &size )
	{
		x += size.cx;
		y += size.cy;
		return *this;
	}

	template<class T>
	TPointEx<T> &TPointEx<T>::operator-=( const TSizeEx<T> &size )
	{
		x -= size.cx;
		y -= size.cy;
		return *this;
	}

	template<class T>
	TPointEx<T> &TPointEx<T>::operator/=( const TSizeEx<T> &size )
	{
		PRECONDITION( size.cx > 0 && size.cy > 0 );
		x /= size.cx;
		y /= size.cy;
		return *this;
	}

	template<class T>
	TPointEx<T> &TPointEx<T>::operator*=( const TSizeEx<T> &size )
	{
		x *= size.cx;
		y *= size.cy;
		return *this;
	}

	template<class T>
	TPointEx<T> &TPointEx<T>::operator/=( const T factor )
	{
		PRECONDITION( factor > 0 );
		x /= factor;
		y /= factor;
		return *this;
	}

	template<class T>
	TPointEx<T> &TPointEx<T>::operator*=( const T factor )
	{
		x *= factor;
		y *= factor;
		return *this;
	}

	//------------------------------------------------------------------------------
	// TSize
	//------------------------------------------------------------------------------

	template<class T>
	bool TSizeEx<T>::operator==( const TSizeEx<T> &other ) const
	{
		return other.cx == cx && other.cy == cy;
	}

	template<class T>
	bool TSizeEx<T>::operator!=( const TSizeEx<T> &other ) const
	{
		return !( other == *this );
	}

	template<class T>
	bool TSizeEx<T>::operator>=( const TSizeEx<T> &other ) const
	{
		return other.cx <= cx && other.cy <= cy;
	}

	template<class T>
	bool TSizeEx<T>::operator<=( const TSizeEx<T> &other ) const
	{
		return other.cx >= cx && other.cy >= cy;
	}

	template<class T>
	bool TSizeEx<T>::operator>( const TSizeEx<T> &other ) const
	{
		return cx > other.cx && cy > other.cy;
	}

	template<class T>
	bool TSizeEx<T>::operator<( const TSizeEx<T> &other ) const
	{
		return cx < other.cx && cy < other.cy;
	}

	template<class T>
	double TSizeEx<T>::Magnitude( void ) const
	{
		double result = dmult( cx, cx ) + dmult( cy, cy );
		if ( result < 0.001 ) return result;
		return sqrt( result );
	}

	template<class T>
	TSizeEx<T> TSizeEx<T>::operator+( const TSizeEx<T> &size ) const
	{
		return TSizeEx<T>( cx + size.cx, cy + size.cy );
	}

	template<class T>
	TSizeEx<T> TSizeEx<T>::operator-( const TSizeEx<T> &size ) const
	{
		return TSizeEx<T>( cx - size.cx, cy - size.cy );
	}

	template<class T>
	TSizeEx<T> TSizeEx<T>::operator*( const TSizeEx<T> &size ) const
	{
		return TSizeEx<T>( cx * size.cx, cy * size.cy );
	}

	template<class T>
	TSizeEx<T> TSizeEx<T>::operator/( const TSizeEx<T> &size ) const
	{
		PRECONDITION( size.cx > 0 && size.cy > 0 );
		return TSizeEx<T>( cx / size.cx, cy / size.cy );
	}

	template<class T>
	TSizeEx<T> TSizeEx<T>::operator/( const T factor ) const
	{
		PRECONDITION( factor > 0 );
		return TSizeEx<T>( cx / factor, cy / factor );
	}

	template<class T>
	TSizeEx<T> TSizeEx<T>::operator*( const T factor ) const
	{
		return TSizeEx<T>( cx * factor, cy * factor );
	}

	template<class T>
	TSizeEx<T> TSizeEx<T>::operator+( const T factor ) const
	{
		return TSizeEx<T>( cx + factor, cy + factor );
	}
	template<class T>
	TSizeEx<T> TSizeEx<T>::operator-( const T factor ) const
	{
		return TSizeEx<T>( cx - factor, cy - factor );
	}

	template<class T>
	TSizeEx<T> &TSizeEx<T>::operator+=( const TSizeEx<T> &size )
	{
		cx += size.cx;
		cy += size.cy;
		return *this;
	}

	template<class T>
	TSizeEx<T> &TSizeEx<T>::operator-=( const TSizeEx<T> &size )
	{
		cx -= size.cx;
		cy -= size.cy;
		return *this;
	}

	//------------------------------------------------------------------------------
	// TRect
	//------------------------------------------------------------------------------

	template<class T>
	void TRectEx<T>::SetNull( )
	{
		left = top = right = bottom = 0;
	}

	template<class T>
	void TRectEx<T>::Set( T _left, T _top, T _right, T _bottom )
	{
		left = _left;
		top = _top;
		right = _right;
		bottom = _bottom;
	}

	template<class T>
	TRectEx<T>::TRectEx( T _left, T _top, T _right, T _bottom )
	{
		Set( _left, _top, _right, _bottom );
	}

	template<class T>
	TRectEx<T>::TRectEx( const TPointEx<T> &topLeft, const TPointEx<T> &bottomRight )
	{
		Set( topLeft.x, topLeft.y, bottomRight.x, bottomRight.y );
	}

	template<class T>
	TRectEx<T>::TRectEx( const TPointEx<T> &origin, const TSizeEx<T> &extent )
	{
		Set( origin.x, origin.y, origin.x + extent.cx, origin.y + extent.cy );
	}

	template<class T>
	bool TRectEx<T>::IsEmpty( ) const
	{
		return left >= right || top >= bottom;
	}

	template<class T>
	bool TRectEx<T>::IsNull( ) const
	{
		return !left && !right && !top && !bottom;
	}

	template<class T>
	bool TRectEx<T>::IsValid( ) const
	{
		return left <= right && top <= bottom;
	}

	template<class T>
	bool TRectEx<T>::IsPlain( ) const
	{
		return left == right || top == bottom;
	}

	template<class T>
	bool TRectEx<T>::operator==( const TRectEx<T> &other ) const
	{
		return other.left == left && other.top == top && other.right == right && other.bottom == bottom;
	}

	template<class T>
	bool TRectEx<T>::operator!=( const TRectEx<T> &other ) const
	{
		return !( other == *this );
	}

	template<class T>
	bool TRectEx<T>::Contains( const TPointEx<T> &point ) const
	{
		return ( point.x > left || fabs( point.x - left ) < RES_COMP ) && ( point.x < right || fabs( point.x - right ) < RES_COMP ) && ( point.y > top || fabs( point.y - top ) < RES_COMP ) && ( point.y < bottom || fabs( point.y - bottom ) < RES_COMP );
	}

	template<class T>
	bool TRectEx<T>::Contains( const TRectEx<T> &other ) const
	{
		return other.left >= left && other.right <= right && other.top >= top && other.bottom <= bottom;
	}

	template<class T>
	bool TRectEx<T>::Touches( const TRectEx<T> &other ) const
	{
		return other.right >= left && other.left <= right && other.bottom >= top && other.top <= bottom;
	}

	template<class T>
	TRectEx<T> TRectEx<T>::OffsetBy( T dx, T dy ) const
	{
		return TRectEx<T>( left + dx, top + dy, right + dx, bottom + dy );
	}

	template<class T>
	TRectEx<T> TRectEx<T>::operator+( const TSizeEx<T> &size ) const
	{
		return OffsetBy( size.cx, size.cy );
	}

	template<class T>
	TRectEx<T> TRectEx<T>::operator-( const TSizeEx<T> &size ) const
	{
		return OffsetBy( -size.cx, -size.cy );
	}

	template<class T>
	TRectEx<T> TRectEx<T>::InflatedBy( T dx, T dy ) const
	{
		return TRectEx<T>( left - dx, top - dy, right + dx, bottom + dy );
	}

	template<class T>
	TRectEx<T> TRectEx<T>::InflatedBy( const TSizeEx<T> &size ) const
	{
		return InflatedBy( size.cx, size.cy );
	}

	template<class T>
	TRectEx<T> TRectEx<T>::Normalized( ) const
	{
		return TRectEx<T>( MinBis( left, right ), MinBis( top, bottom ), MaxBis( left, right ), MaxBis( top, bottom ) );
	}

	template<class T>
	TRectEx<T> TRectEx<T>::operator&( TRectEx<T> &other )
	{
		return TRectEx<T>( MaxBis( left, other.left ), MaxBis( top, other.top ), MinBis( right, other.right ), MinBis( bottom, other.bottom ) );
	}

	template<class T>
	TRectEx<T> TRectEx<T>::operator|( TRectEx<T> &other )
	{
		return TRectEx<T>( MinBis( left, other.left ), MinBis( top, other.top ), MaxBis( right, other.right ), MaxBis( bottom, other.bottom ) );
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::operator+=( const TSizeEx<T> &delta )
	{
		Offset( delta.cx, delta.cy );
		return *this;
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::operator-=( const TSizeEx<T> &delta )
	{
		return *this += -delta;
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::Inflate( const TSizeEx<T> &delta )
	{
		return Inflate( delta.cx, delta.cy );
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::Normalize( )
	{
		if ( left > right ) SwapBis( left, right );
		if ( top > bottom ) SwapBis( top, bottom );
		return *this;
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::Offset( T dx, T dy )
	{
		left += dx;
		top += dy;
		right += dx;
		bottom += dy;
		return *this;
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::Inflate( T dx, T dy )
	{
		left -= dx;
		top -= dy;
		right += dx;
		bottom += dy;
		return *this;
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::operator&=( TRectEx<T> &other )
	{
		if ( !IsNull( ) ) {
			if ( other.IsNull( ) ) SetNull( );
			else {
				left = MaxBis( left, other.left );
				top = MaxBis( top, other.top );
				right = MinBis( right, other.right );
				bottom = MinBis( bottom, other.bottom );
			}
		}
		return *this;
	}

	template<class T>
	TRectEx<T> &TRectEx<T>::operator|=( TRectEx<T> &other )
	{
		if ( !other.IsNull( ) ) {
			if ( IsNull( ) ) *this = other;
			else {
				left = MinBis( left, other.left );
				top = MinBis( top, other.top );
				right = MaxBis( right, other.right );
				bottom = MaxBis( bottom, other.bottom );
			}
		}
		return *this;
	}

	template<class T>
	ostream &operator<<( ostream &os, const TRectEx<T> &r )
	{
		return os << '(' << r.left << ',' << r.top << '-' << r.right << ',' << r.bottom << ')';
	}

	template<class T>
	std::wistream &operator>>( std::wistream &is, TRectEx<T> &r )
	{
		wchar_t c;
		return is >> /*c >> */ r.left >> c >> r.top >> c >> r.right >> c >> r.bottom /* >> c*/;
	}

	//------------------------------------------------------------------------------
	// TVector
	//------------------------------------------------------------------------------

	template<class T>
	TVector<T>::TVector( T Modulo, double Angulo, const TPointEx<T> &_org )
	{
		org = _org;
		Modulo = max( Modulo, -Modulo );
		size.cx = T( Modulo * cos( Angulo ) );
		size.cy = T( Modulo * sin( Angulo ) );
	}

	template<class T>
	TVector<T> TVector<T>::Unitario( ) const
	{
		return TVector<T>( 1, Angulo( ), org );
	}

	template<class T>
	TVector<T> TVector<T>::operator+( const TVector<T> &V ) const
	{
		return TVector<T>( size + V.size, org );
	}

	template<class T>
	TVector<T> TVector<T>::operator-( const TVector<T> &V ) const
	{
		return TVector<T>( size - V.size, org );
	}

	template<class T>
	double TVector<T>::operator*( const TVector<T> &V ) const // Producto
	{														  // escalar
		return dmult( size.cx, V.size.cx ) + dmult( size.cy, V.size.cy );
	}

	template<class T>
	double TVector<T>::operator^( const TVector<T> &V ) const // Angulo entre
	{														  // dos vectores
		double cociente = Modulo( ) * V.Modulo( );

		return cociente == 0 ? 0 : this->operator*( V ) / cociente;
	}

	//
	// El metodo del producto vectorial devuelve unicamente la componente 'Z' del
	// vector que resultaria del producto
	//
	/*
	template<class T>
	T TVector<T>::Z (const TVector<T>& V) const   // Producto vectorial
	{
	 return size.cx*V.size.cy-V.size.cx*size.cy;
	}
	*/
	//
	// devuelve un valor del angulo entre 0 y 2*PI
	//

	template<class T>
	double TVector<T>::Angulo( ) const
	{
		return size.cx == 0 ? size.cy > 0 ? M_PI / 2 : -M_PI / 2 : atan2( size.cy, size.cx );
	}

	template<class T>
	TVector<T> TVector<T>::Normal( ) const
	{
		return TVector<T>( TSizeEx<T>( size.cy, -size.cx ), org );
	}

	template<class T>
	TVector<T> &TVector<T>::Girar( const double angulo )
	{
		T aux;

		aux = size.cx;
		size.cx = T( size.cx * cos( angulo ) - size.cy * sin( angulo ) );
		size.cy = T( aux * sin( angulo ) + size.cy * cos( angulo ) );
		return *this;
	}

	template<class T>
	TVector<T> &TVector<T>::Modulo( T newMod )
	{
		double mod = Modulo( );
		if ( mod < RES_COMP ) return *this;
		double factor = ddiv( newMod, mod );
		size.cx = T( factor * size.cx );
		size.cy = T( factor * size.cy );
		return *this;
	}

	//------------------------------------------------------------------------------
	// TRecta
	//------------------------------------------------------------------------------
	//
	// Constructores
	// Cada uno de los constructores calcula la ecuacion de la recta en tres formas
	//

	template<class T>
	void TRecta<T>::Init( const TPointEx<T> &_start, const TPointEx<T> &_end )
	{
		start = _start;
		end = _end;

		A = end.y - start.y;
		B = start.x - end.x;
		C = -start.x * A - start.y * B;

		pendiente = B != 0 ? A / -B : MAXDOUBLE;
		ordenada = B != 0 ? start.y - start.x * pendiente : 0;
	}

	template<class T>
	TRecta<T>::TRecta( const double _A, const double _B, const double _C )
	{
		A = _A;
		B = _B;
		C = _C;

		PRECONDITION( A > 0 || B > 0 );

		pendiente = B != 0 ? A / -B : MAXDOUBLE;
		ordenada = B != 0 ? start.y : 0;

		start.x = 0;
		start.y = T( ordenada );
		end.y = 0;
		end.x = -T( ordenada / pendiente );
	}

	template<class T>
	TRecta<T>::TRecta( const double _pendiente, const double _ordenada )
	{
		A = pendiente = _pendiente;
		C = ordenada = _ordenada;
		B = -1;

		start.x = 0;
		start.y = -T( C / B );
		if ( A > 0 ) {
			end.x = -T( C / A );
			end.y = 0;
		} else {
			end.x = 1;
			end.y = start.y;
		}
	}

	//
	// Comprobacion de rectas paralelas. Caso especial: ambas son verticales
	//

	template<class T>
	bool TRecta<T>::operator||( const TRecta<T> &R ) const
	{
		return R.B * A == B * R.A; // Evita problemas de rectas verticales y los de
	}							   // precision derivados de las divisiones reales

	//
	// El operador mas se sobrecarga de manera que la suma de dos rectas nos de
	// el punto de interseccion de ambas. Si las rectas son paralelas se devuelve
	// el punto 0,0 que puede o no pertenecer a las rectas. Lo correcto seria
	// comprobar primero que intersectan con el operador || (paralelas)
	//

	template<class T>
	TPointEx<T> TRecta<T>::operator+( const TRecta<T> &R ) const
	{
		TPointEx<T> P( 0, 0 );
		double cociente = ( R.B * A - B * R.A );

		if ( cociente > 0.0 || cociente < -0.0 ) { // No son paralelas
			P.y = T( ( C * R.A - R.C * A ) / cociente );
			P.x = T( ( B * R.C - R.B * C ) / cociente );
		}
		return P;
	}

	template<class T>
	bool TRecta<T>::Intersect( const TRecta<T> &R, TPointEx<T> &P ) const
	{
		double cociente;

		cociente = ( R.B * A - B * R.A );
		if ( fabs( cociente ) < RES_COMP ) return false;

		P.y = T( ( C * R.A - R.C * A ) / cociente );
		P.x = T( ( B * R.C - R.B * C ) / cociente );

		return true;
	}

	//
	// Calcula una recta paralela a la original, que se encuentra a una deter-
	// minada distancia, ya sea por la izq. (offset negativo) o por la dcha. (pos.)
	//

	template<class T>
	TRecta<T> TRecta<T>::Offset( const T offset ) const
	{
		TVector<T> V = Director( ).Modulo( offset );

		TPointEx<T> N = TPointEx<T>( V.size.cy, -V.size.cx );
		return TRecta<T>( start + N, end + N );
	}

	//
	// Esta funcion calcula la distancia de un punto a una recta (ojo! devuelve
	// signo, con lo que se puede averiguar en que semiplano queda el punto
	// Obviamente, si la Distancia == 0, quiere decir que el punto pertenece a la
	// recta.
	//

	template<class T>
	double TRecta<T>::Distancia( const TPointEx<T> &P ) const
	{
		PRECONDITION( A > 0 || B > 0 );
		return ( A * P.x + B * P.y + C ) / sqrt( A * A + B * B );
	}

	//
	// La funcion Touches comprueba la proximidad en los extremos
	//

	template<class T>
	bool TRecta<T>::Touches( const TPointEx<T> &P ) const
	{
		return P == start || P == end;
	}

	template<class T>
	bool TRecta<T>::Touches( const TRecta<T> &R ) const
	{
		return Touches( R.start ) || Touches( R.end );
	}

	//------------------------------------------------------------------------------
	// INSTANCIACION DE TIPOS
	//------------------------------------------------------------------------------

	typedef TSizeEx<double> TLSize;
	typedef TPointEx<double> TLPoint;
	typedef TRectEx<double> TLRect;
	typedef TVector<double> TLVector;
	typedef TRecta<double> TLRecta;

	typedef TPointEx<float> TFPoint;
	typedef TRectEx<float> TFRect;
	typedef TRecta<float> TFRecta;

	//------------------------------------------------------------------------------
} // namespace InesMath
#endif

