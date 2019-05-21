/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "Geometry.h"


int sign( double d1 )
{
  return (d1>0)?1:-1;
}
double ConvertAngle2(double angle)
{
	if (angle > 0)
	{
		angle += 0.5;
	}
	else	if (angle < 0)
	{
		angle -= 0.5;
	}

	return angle;
}

double max( double d1, double d2 )
{
  return (d1>d2)?d1:d2;
}

double min( double d1, double d2 )
{
  return (d1<d2)?d1:d2;
}

double Rad2Deg( double x )
{
  return ( x * 180 / M_PI );
}


double Deg2Rad( double x )
{
  return ( x * M_PI / 180 );
}


double cosDeg( double x )
{
  return ( cos( Deg2Rad( x ) ) );
}


double sinDeg( double x )
{
  return ( sin( Deg2Rad( x ) ) );
}


double tanDeg( double x )
{
  return ( tan( Deg2Rad( x ) ) );
}


double atanDeg( double x )
{
  return ( Rad2Deg( atan( x ) ) );
}


double atan2Deg( double x, double y )
{
  if( fabs( x ) < EPSILON && fabs( y ) < EPSILON )
    return ( 0.0 );

  return ( Rad2Deg( atan2( x, y ) ) );
}


double acosDeg( double x )
{
  if( x >= 1 )
    return ( 0.0 );
  else if( x <= -1 )
    return ( 180.0 );

  return ( Rad2Deg( acos( x ) ) );
}


double asinDeg( double x )
{
  if( x >= 1 )
    return ( 90.0 );
  else if ( x <= -1 )
    return ( -90.0 );

  return ( Rad2Deg( asin( x ) ) );
}


bool isAngInInterval( double ang, double angMin, double angMax )
{
  
  if( ( ang    + 360 ) < 360 ) ang    += 360;
  if( ( angMin + 360 ) < 360 ) angMin += 360;
  if( ( angMax + 360 ) < 360 ) angMax += 360;

  if( angMin < angMax )
    return angMin < ang && ang < angMax ;
  else
    return !( angMax < ang && ang < angMin );
}


double getBisectorTwoAngles( double angMin, double angMax )
{
  return Vector2D::normalizeAngle(
            atan2Deg( (sinDeg( angMin) + sinDeg( angMax ) )/2.0,
                      (cosDeg( angMin) + cosDeg( angMax ) )/2.0 ) );
}
double normalize_angle( double dir )
{
	if ( dir < -360.0 || 360.0 < dir )
	{
	dir = fmod( dir, 360.0 );
	}

	if ( dir < -180.0 )
	{
	dir += 360.0;
	}

	if ( dir > 180.0 )
	{
	dir -= 360.0;
	}

	return dir;
}
double getFirstGeomSeries( double dSum, double dRatio, double dLength)
{
  // s = a + ar + ar^2 + .. + ar^n-1 and thus sr = ar + ar^2 + .. + ar^n
  // subtract: s - sr = a - ar^n) =>  s = a(1-r^n)/(1-r) => a = s*(1-r)/(1-r^n)
  return dSum *  ( 1 - dRatio )/( 1 - pow( dRatio, dLength ) ) ;
}

/**
------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------
	Vector2D class
**/
Vector2D::Vector2D ( )
{

}
Vector2D::Vector2D (double dX, double dY)
{
	setX (dX);
	setY (dY);
}
bool Vector2D::setX  ( double  dX )
{
	x = dX;
	return (true);
}
double Vector2D::getX  (      ) const
{
	return x;
}
bool   Vector2D::setY  ( double  dY )
{
	y = dY;
	return (true);
}
Vector2D & Vector2D::setlength( const double & len )
      {
          double mag = this->getMagnitude();
          if ( mag < EPSILON )
          {
              return *this;
          }
          return scale( len / mag );
      }
Vector2D & Vector2D::scale( const double & scalar )
      {
          x *= scalar;
          y *= scalar;
          return *this;
      }
double Vector2D::getY  (      ) const
{
	return y;
}
double Vector2D::getDistanceTo( const Vector2D    p  )
{
	return ( ( *this - p ).getMagnitude( ) );
}
Vector2D Vector2D::setMagnitude ( double  d  )
{
	if( getMagnitude( ) > EPSILON )
     		( *this ) *= ( d / getMagnitude( ) );

  	return ( *this );
}
double   Vector2D::getMagnitude (      ) const
{
	return ( sqrt( x * x + y * y ) );
}
double   Vector2D::getDirection (      ) const
{
	return ( atan2Deg( y, x ) );
}
bool     Vector2D::isInFrontOf  ( const Vector2D &p  	   )
{
	return ( ( x > p.getX( ) ) ? true : false );
}
bool     Vector2D::isInFrontOf  ( const double      &d )
{
	return ( ( x > d ) ? true : false );
}
bool     Vector2D::isBehindOf   ( const Vector2D &p 	   )
{
	return ( ( x < p.getX( ) ) ? true : false );
}
bool     Vector2D::isBehindOf   ( const double      &d )
{
	return ( ( x < d ) ? true : false );
}
bool     Vector2D::isLeftOf     ( const Vector2D &p    )
{
	return ( ( y < p.getY( ) ) ? true : false );
}
bool     Vector2D::isLeftOf     ( const double      &d )
{
	return ( ( y < d ) ? true : false );
}
bool     Vector2D::isRightOf    ( const Vector2D &p    )
{
	return ( ( y > p.getY( ) ) ? true : false );
}
bool     Vector2D::isRightOf    ( const double      &d )
{
	return ( ( y > d ) ? true : false );
}
bool     Vector2D::isBetweenX   ( const Vector2D &p1,const Vector2D &p2   )
{
	return ( ( isInFrontOf( p1 ) && isBehindOf( p2 ) ) ? true : false );
}
bool     Vector2D::isBetweenX   ( const double      &d1,const double      &d2)
{
	return ( ( isInFrontOf( d1 ) && isBehindOf( d2 ) ) ? true : false );
}
bool     Vector2D::isBetweenY   ( const Vector2D &p1,const Vector2D &p2   )
{
	return ( ( isRightOf( p1 ) && isLeftOf( p2 ) ) ? true : false );
}
bool     Vector2D::isBetweenY   ( const double      &d1,const double      &d2)
{
	return ( ( isRightOf( d1 ) && isLeftOf( d2 ) ) ? true : false );
}	
Vector2D Vector2D::normalize    (  )
{
	return ( setMagnitude( 1.0 ) );
}
Vector2D Vector2D::rotate( double  angle )
{
	double dMag    = this->getMagnitude( );
  	double dNewDir = this->getDirection( ) + angle;  // add rotation angle to phi
  	setX( dMag );
	setY( dNewDir );
  	return ( *this );
}
Vector2D Vector2D::globalToRelative( Vector2D orig,double  ang)
{
	*this -= orig;
  	return ( rotate( -ang ) );
}
Vector2D Vector2D::relativeToGlobal( Vector2D orig,double  ang)
{
	rotate( ang );
  	*this += orig;
  	return ( *this );
}
Vector2D Vector2D::getVector2DOnLineFraction( Vector2D  &p,double  dFrac )
{
	return ( ( *this ) * ( 1.0 - dFrac ) + ( p * dFrac ) );
}
Vector2D    Vector2D::getVector2DFromPolar( double  dMag, double  ang)
{
	return ( Vector2D( dMag * cosDeg( ang ), dMag * sinDeg( ang ) ) );
}
double      Vector2D::normalizeAngle  ( double  angle )
{
	while( angle > 180.0  ) angle -= 360.0;
  	while( angle < -180.0 ) angle += 360.0;

  	return ( angle );
}
/**
------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------
	Circle2D class
**/
Circle2D::Circle2D( )
{
	setCircle( Vector2D(-1000.0,-1000.0), 0);
}
Circle2D::Circle2D( Vector2D pos, double dR )
{
	setCircle( pos, dR );
}
bool Circle2D::setCircle  ( Vector2D pos,double      dR  )
{
	setCenter( pos );
  	return setRadius( dR  );
}
bool Circle2D::setRadius  ( double dR       )
{
	if( dR > 0 )
  	{
  		dRadius = dR;
    		return true;
 	}
  	else
  	{
    		dRadius = 0.0;
    		return false;
  	}
}
double Circle2D::getRadius  (                 )
{
	return dRadius;
}
bool Circle2D::setCenter   ( Vector2D    pos )
{
	posCenter = pos;
  	return true;
}
Vector2D Circle2D::getCenter  (                 )
{
	return posCenter;
}
double Circle2D::getCircumference   (                 )
{
	return 2.0*M_PI*getRadius();
}
double Circle2D::getArea   (                 )
{
	return M_PI*getRadius()*getRadius();
}
bool Circle2D::isInside  ( Vector2D   pos )
{
	return posCenter.getDistanceTo( pos ) < getRadius() ;
}
int Circle2D::getIntersectionPoints ( Circle2D  c, Vector2D *p1,Vector2D *p2    )
{
	double x0, y0, r0;
    	double x1, y1, r1;
    	x0 = getCenter( ).getX();
    	y0 = getCenter( ).getY();
    	r0 = getRadius( );
    	x1 = c.getCenter( ).getX();
    	y1 = c.getCenter( ).getY();
    	r1 = c.getRadius( );
    	double      d, dx, dy, h, a, x, y, p2_x, p2_y;
    	dx = x1 - x0;
   	dy = y1 - y0;
    	d = sqrt(dx*dx + dy*dy);
    	dx /= d; dy /= d;
	a = (r0*r0 + d*d - r1*r1) / (2.0 * d);
    	double      arg = r0*r0 - a*a;
    	h = (arg > 0.0) ? sqrt(arg) : 0.0;
	p2_x = x0 + a * dx;
    	p2_y = y0 + a * dy;
    	x =  p2_x - h * dy;
    	y =  p2_y + h * dx;
    	p1->setX( x );
	p1->setY( y );
    	x =  p2_x + h * dy;
    	y =  p2_y - h * dx;
    	p2->setX( x );
	p2->setY( y );
    	return (arg < 0.0) ? 0 : ((arg == 0.0 ) ? 1 :  2);
}
double Circle2D::getIntersectionArea   ( Circle2D c   )
{
	Vector2D pos1, pos2, pos3;
  	double d, h, dArea;
  	double ang;

  	d = getCenter().getDistanceTo( c.getCenter() );
  	if( d > c.getRadius() + getRadius() )
    		return 0.0;
  	if( d <= fabs(c.getRadius() - getRadius() ) )
  	{
    		double dR = min( c.getRadius(), getRadius() );
    		return M_PI*dR*dR;
  	}

  	int iNrSol = getIntersectionPoints( c, &pos1, &pos2 );
  	if( iNrSol != 2 )
    		return 0.0;
  	pos3 = pos1.getVector2DOnLineFraction( pos2, 0.5 );
  	d = pos1.getDistanceTo( pos3 );
  	h = pos3.getDistanceTo( getCenter() );
  	ang = asin( d / getRadius() );
  	dArea = ang*getRadius()*getRadius();
  	dArea = dArea - d*h;
  	h = pos3.getDistanceTo( c.getCenter() );
  	ang = asin( d / c.getRadius() );
  	dArea = dArea + ang*c.getRadius()*c.getRadius();
  	dArea = dArea - d*h;
  	return dArea;
}
/**
------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------
	Line2D class
**/
Line2D::Line2D( double a, double b, double c )
{
	la = a;
  	lb = b;
  	lc = c;
}

Vector2D  Line2D::getIntersection  ( Line2D   line  )
{
	Vector2D pos;
  	double x, y;
  	if( ( la / lb ) ==  (line.getACoefficient() / line.getBCoefficient() ))
    		return pos;
  	if( la == 0 )
  	{
    		x = -lc/lb;
    		y = line.getYGivenX(x);
  	}
  	else if( line.getACoefficient() == 0 )
  	{
   		x = -line.getCCoefficient()/line.getBCoefficient();
   		y = getYGivenX(x);
  	}
  	else
  	{
    		x = (la*line.getCCoefficient() - line.getACoefficient()*lc)/
                    	(line.getACoefficient()*lb - la*line.getBCoefficient());
    		y = getYGivenX(x);
  	}

  	return Vector2D( x, y );
}

int Line2D::getCircleIntersectionPoints( Circle2D      circle, Vector2D *posSolution1,Vector2D *posSolution2 )
{
	int    iSol;
  	double dSol1=0, dSol2=0;
  	double h = circle.getCenter().getX();
  	double k = circle.getCenter().getY();
  	if( fabs(la) < EPSILON )
  	{
    		iSol = abcFormula( 1, -2*k, ((-lc/lb) - h)*((-lc/lb) - h)
              		+ k*k - circle.getRadius()*circle.getRadius(), &dSol1, &dSol2);
    		posSolution1->setX( (-lc/lb));
		posSolution1->setY( ( dSol1));
    		posSolution2->setX( (-lc/lb));
		posSolution2->setY( ( dSol2));
    		return iSol;
  	}
  	double da = -lb/la;
  	double db = -lc/la;
  	double dA = 1 + da*da;
  	double dB = 2*( da*db - h - k*da );
  	double dC = h*h + db*db-2*k*db + k*k - circle.getRadius()*circle.getRadius();

  	iSol = abcFormula( dA, dB, dC, &dSol1, &dSol2 );
  	posSolution1->setX( dSol1         );
  	posSolution1->setY( da*dSol1 + db );
	posSolution2->setX( dSol2         );
  	posSolution2->setY( da*dSol2 + db );
	return iSol;
}

Line2D Line2D::getTangentLine ( Vector2D pos  )
{
	return Line2D( lb, -la, la*pos.getX() - lb*pos.getY() );
}

Vector2D Line2D::getPointOnLineClosestTo ( Vector2D pos  )
{
	Line2D l2 = getTangentLine( pos );
  	return getIntersection( l2 );
}

double Line2D::getDistanceWithPoint ( Vector2D pos  )
{
	return pos.getDistanceTo( getPointOnLineClosestTo( pos ) );
}

bool Line2D::isInBetween  ( Vector2D pos,Vector2D point1,Vector2D point2  )
{
	pos          = getPointOnLineClosestTo( pos );
  	double dDist = point1.getDistanceTo( point2 );
  	return pos.getDistanceTo( point1 ) <= dDist && pos.getDistanceTo( point2 ) <= dDist;
}
double Line2D::getYGivenX ( double      x )
{
	if( la == 0 )
 	{
   		return 0;
 	}
  	return -(lb*x+lc)/la;
}

double Line2D::getXGivenY  ( double      y )
{
	if( lb == 0 )
 	{
   		return 0;
 	}
  	return -(la*y+lc)/lb;
}

double Line2D::getACoefficient  (     ) const
{
	return la;
}

double Line2D::getBCoefficient  (    ) const
{
	return lb;
}

double Line2D::getCCoefficient  (   ) const
{
	return lc;
}

Line2D Line2D::makeLineFromTwoPoints ( Vector2D pos1, Vector2D pos2    )
{
	double dA, dB, dC;
  	double dTemp = pos2.getX() - pos1.getX();
  	if( fabs(dTemp) < EPSILON )
  	{
   		 dA = 0.0;
   		 dB = 1.0;
  	}
  	else
  	{
    		dA = 1.0;
    		dB = -(pos2.getY() - pos1.getY())/dTemp;
  	}
  	dC =  - dA*pos2.getY()  - dB * pos2.getX();
  	return Line2D( dA, dB, dC );
}

Line2D Line2D::makeLineFromPositionAndAngle( Vector2D vec, double angle    )
{
	return makeLineFromTwoPoints( vec, vec+Vector2D(1,angle));
}
int Line2D::abcFormula(double a, double b, double c, double *s1, double *s2)
{
  double dDiscr = b*b - 4*a*c;
  if (fabs(dDiscr) < EPSILON )
  {
    *s1 = -b / (2 * a);
    return 1;
  }
  else if (dDiscr < 0)
    return 0;
  else
  {
    dDiscr = sqrt(dDiscr);
    *s1 = (-b + dDiscr ) / (2 * a);
    *s2 = (-b - dDiscr ) / (2 * a);
    return 2;
  }
}
/**
------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------
	Rec2D class
**/
Rec2D::Rec2D( Vector2D pos, Vector2D pos2 )
{
  setRectanglePoints( pos, pos2 );
}
void Rec2D::setRectanglePoints( Vector2D pos1, Vector2D pos2 )
{
  m_posLeftTop.setX    ( max( pos1.getX(), pos2.getX() ) );
  m_posLeftTop.setY    ( min( pos1.getY(), pos2.getY() ) );
  m_posRightBottom.setX( min( pos1.getX(), pos2.getX() ) );
  m_posRightBottom.setY( max( pos1.getY(), pos2.getY() ) );
}
bool Rec2D::isInside( Vector2D pos )
{
  return pos.isBetweenX( m_posRightBottom.getX(), m_posLeftTop.getX() ) &&
         pos.isBetweenY( m_posLeftTop.getY(),     m_posRightBottom.getY() );

}
bool Rec2D::setPosLeftTop( Vector2D pos )
{
  m_posLeftTop = pos;
  return true;
}
Vector2D Rec2D::getPosLeftTop(  )
{
  return m_posLeftTop;
}
bool Rec2D::setPosRightBottom( Vector2D pos )
{
  m_posRightBottom = pos;
  return true;
}
Vector2D Rec2D::getPosRightBottom(  )
{
  return m_posRightBottom;
}
