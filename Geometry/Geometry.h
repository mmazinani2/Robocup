/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _GEOMETRY_
#define _GEOMETRY_

#include <cstdio>
#include <cmath>

#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#define EPSILON 0.0001
using namespace std;

double normalize_angle( double dir );
int sign( double d1 );
double max( double d1, double d2 );
double min( double d1, double d2 );
double Rad2Deg( double x );
double Deg2Rad( double x );
double cosDeg( double x );
double sinDeg( double x );
double tanDeg( double x );
double atanDeg( double x );
double atan2Deg( double x, double y );
double acosDeg( double x );
double asinDeg( double x );
bool isAngInInterval( double ang, double angMin, double angMax );
double getBisectorTwoAngles( double angMin, double angMax );
double ConvertAngle2(double angle);
double getFirstGeomSeries( double dSum, double dRatio, double dLength);
inline double GetNormalizeAngleDeg(double ang, const double min_ang = -180.0)
{
	if (ang < min_ang) {
		do {
			ang += 360.0;
		} while (ang < min_ang);
	}
	else {
		const double max_ang = 360.0 + min_ang;

		while (ang >= max_ang){
			ang -= 360.0;
		}
	}

	return ang;
}
inline double calc_first_term_geom_series( const double & sum,
              		                   const double & r,
                            		   const int len )
{
    return sum * ( 1.0 - r ) / ( 1.0 - pow( r, len ) );
}
template < typename  T >
const T &
min_max( const T & low, const T & x, const T & high )
{
    return min( max( low, x ), high );
}
class Vector2D 
{
	private :
		double x;
		double y;
		double Magnitude;
	public :
		Vector2D ( );
		Vector2D (double , double);
		Vector2D operator -() { return Vector2D(-x, -y); }
 		Vector2D operator +(const Vector2D &a) { return Vector2D(x + a.x, y + a.y); }
		Vector2D operator +(const double &a) { return Vector2D(x + a, y + a); }
 		Vector2D operator -(const Vector2D &a) { return Vector2D(x - a.x, y - a.y); }
 		Vector2D operator *(const float &a) { return Vector2D(x * a, y * a); }
 		Vector2D operator *(const Vector2D &a) { return Vector2D(x * a.x, y * a.y); }
		Vector2D operator /(const float &a) { return Vector2D(x / a, y / a); }
		Vector2D operator /(const Vector2D &a) { return Vector2D(x / a.x, y / a.y); }
		bool operator ==(const Vector2D &a) {return ((this->x == a.x) && (this->y == a.y));}
		bool operator >(const Vector2D &a) {return ((this->x > a.x) && (this->y > a.y));}
 		void operator =(const float &a) { x = a; y = a; }
 		void operator +=(const Vector2D &a) { x += a.x;  y += a.y; }
		void operator +=(const float &a) { x += a;  y += a; }
		void operator -=(const Vector2D &a) { x -= a.x;  y -= a.y; }
		void operator -=(const float &a) { x -= a;  y -= a; }
		void operator *=(const float &a) { x *= a;  y *= a; }
		void operator /=(const float &a) { x /= a;  y /= a; }
		bool               setVector              ( double dX ,double dY ) {setX (dX);setY(dY);}
		Vector2D	   & setlength		  ( const double & len );
		Vector2D 	   & scale		  ( const double & scalar );
		bool               setX                   ( double            dX           );
  		double             getX                   (                          ) const;
  		bool               setY                   ( double            dY           );
  		double             getY                   (                          ) const;
  		double             getDistanceTo          ( const Vector2D    p            );
  		Vector2D           setMagnitude           ( double            d            );
 		double             getMagnitude           (                          ) const;
  		double             getDirection           (                          ) const;
  		bool               isInFrontOf            ( const Vector2D &p         	   );
  		bool               isInFrontOf            ( const double      &d           );
  		bool               isBehindOf             ( const Vector2D &p        	   );
  		bool               isBehindOf             ( const double      &d           );
  		bool               isLeftOf               ( const Vector2D &p              );
  		bool               isLeftOf               ( const double      &d           );
  		bool               isRightOf              ( const Vector2D &p              );
  		bool               isRightOf              ( const double      &d           );
  		bool               isBetweenX             ( const Vector2D &p1,
                                              const Vector2D &p2             );
  		bool               isBetweenX             ( const double      &d1,
                                              const double      &d2          );
  		bool               isBetweenY             ( const Vector2D &p1,
                                              const Vector2D &p2             );
  		bool               isBetweenY             ( const double      &d1,
                                              const double      &d2          );

  		Vector2D           normalize              (                                );
  		Vector2D           rotate                 ( double            angle        );
  		Vector2D           globalToRelative       ( Vector2D       orig,
                                              double            ang          );
  		Vector2D           relativeToGlobal       ( Vector2D       orig,
                                              double            ang          );
  		Vector2D           getVector2DOnLineFraction( Vector2D  &p,
                                              double            dFrac        );
  		static Vector2D    getVector2DFromPolar( double            dMag,
                                              double            ang          );
  		static double      normalizeAngle         ( double            angle        );
		

};
class Circle2D
{
    		Vector2D    posCenter;
    		double      dRadius;

	public:
    		Circle2D( );
    		Circle2D( Vector2D pos, double dR );
    		bool        setCircle             ( Vector2D pos,double      dR  );
    		bool        setRadius             ( double dR       );
    		double      getRadius             (                 );
    		bool        setCenter             ( Vector2D    pos );
   		Vector2D    getCenter             (                 );
    		double      getCircumference      (                 );
    		double      getArea               (                 );
    		bool        isInside              ( Vector2D   pos );
    		int         getIntersectionPoints ( Circle2D      c, Vector2D *p1,Vector2D *p2    );
    		double      getIntersectionArea   ( Circle2D c        );


};
class Line2D
{
  		double la;
  		double lb;
  		double lc;

	public:
  		Line2D( double a, double b, double c );
		Line2D(){}
  		Vector2D    getIntersection            ( Line2D        line                  );
  		int         getCircleIntersectionPoints( Circle2D      circle,
                                           Vector2D *posSolution1,
                                           Vector2D *posSolution2         );
  		Line2D      getTangentLine             ( Vector2D pos                   );
  		Vector2D getPointOnLineClosestTo    ( Vector2D pos                   );
  		double      getDistanceWithPoint       ( Vector2D pos                   );
  		bool        isInBetween                ( Vector2D pos,
                                           Vector2D point1,
                                           Vector2D point2                );
  		double      getYGivenX                 ( double      x );
  		double      getXGivenY                 ( double      y );
  		double      getACoefficient            (               ) const;
  		double      getBCoefficient            (               ) const;
  		double      getCCoefficient            (               ) const;
  		static Line2D makeLineFromTwoPoints      ( Vector2D pos1,
                                           Vector2D pos2                  );
  		static Line2D makeLineFromPositionAndAngle( Vector2D vec,
                                           double angle                      );
		int    abcFormula(double a, double b, double c, double *s1, double *s2);
};
class Rec2D
{
  		Vector2D m_posLeftTop;
  		Vector2D m_posRightBottom;

	public:
  		Rec2D                        ( Vector2D pos, Vector2D pos2    );
  		bool        isInside          ( Vector2D pos                   );
  		void        setRectanglePoints( Vector2D pos1, Vector2D pos2   );
  		bool        setPosLeftTop     ( Vector2D pos                   );
  		Vector2D    getPosLeftTop     (                                );
  		bool        setPosRightBottom ( Vector2D pos                   );
  		Vector2D    getPosRightBottom (                                );
	
};

#endif
