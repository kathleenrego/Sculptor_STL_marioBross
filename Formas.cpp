#include "Formas.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

inline VETOR_3D <int> round (VETOR_3D <float> pos) {
  return VETOR_3D <int> ( round(pos.x), round(pos.y), round(pos.z) );
}

void Box::sculpt(Hipermatriz& c) const
{
  VETOR_3D <float> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i < maxP.x - 0.5; i += 0.5) {
    for (float j = minP.y; j < maxP.y - 0.5; j += 0.5) {
      for (float k = minP.z; k < maxP.z - 0.5; k += 0.5) {
          VETOR_3D <float> p = TM.transform(VETOR_3D <float>(i,j,k) );

          if (p < c.getMaxPos()){
            p = c.getNormalPos(p.x, p.y, p.z );

            c.eixo(p) = (*this);
          }
      }
    }
  }
}

int Solid::getMaxX() const {
  VETOR_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();
  int max;

  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        VETOR_3D <float> current = round(TM.transform(VETOR_3D <float> (i, j, k)));

        if (VETOR_3D <int> (i, j, k) == minP ) max = round(current.x);
        if (current.x > max) max = round(current.x);
      }
    }
  }
  return max;
}

int Solid::getMaxY() const {
  VETOR_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int max;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        VETOR_3D <float> current = round(TM.transform(VETOR_3D <float> (i, j, k)));

        if (VETOR_3D <int> (i, j, k) == minP ) max = round(current.x);
        if (current.y > max) max = round(current.y);
      }
    }
  }
  return max;
}
int Solid::getMaxZ() const {
  VETOR_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int max;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        VETOR_3D <float> current = round(TM.transform(VETOR_3D <float> (i, j, k)));

        if (VETOR_3D <int> (i, j, k) == minP ) max = round(current.x);
        if (current.z > max) max = round(current.z);
      }
    }
  }
  return max;
}


int Solid::getMinX() const {
  VETOR_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        VETOR_3D <float> current = round(TM.transform(VETOR_3D <float> (i, j, k)));

        if (VETOR_3D <int> (i, j, k) == minP ) min = round(current.x);
        if (current.x < min) {
          min = round(current.x);
        }
      }
    }
  }

  return min;
}
int Solid::getMinY() const {
  VETOR_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
        VETOR_3D <float> current = round(TM.transform(VETOR_3D <float> (i, j, k)));

        if (VETOR_3D <int> (i, j, k) == minP ) min = round(current.y);
        if (current.y < min) min = round(current.y);
      }
    }
  }
  return min;
}
int Solid::getMinZ() const {
  VETOR_3D <float> minP = this->getLimMin(), maxP = this->getLimMax();

  int min;
  for (int i = minP.x; i <= maxP.x; i++) {
    for (int j = minP.y; j <= maxP.y; j++) {
      for (int k = minP.z; k <= maxP.z; k++) {
       VETOR_3D <float> current = round(TM.transform(VETOR_3D <float> (i, j, k)));

        if (VETOR_3D <int> (i, j, k) == minP ) min = round(current.z);
        if (current.z < min) min = round(current.z);
      }
    }
  }
  return min;
}

inline VETOR_3D <float> Box::getLimMin() const {
  return VETOR_3D <float> ( pos.x - (width / 2.0), pos.y - (length / 2.0), pos.z - (height / 2.0) );
}

inline VETOR_3D <float> Box::getLimMax() const {
  return VETOR_3D <float> ( pos.x + (width / 2.0), pos.y + (length / 2.0), pos.z + (height / 2.0) );
}


void Ellipsoid::sculpt(Hipermatriz& c) const
{
  VETOR_3D <float> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i < maxP.x; i += 0.5) {
    for (float j = minP.y; j < maxP.y; j += 0.5) {
      for (float k = minP.z; k < maxP.z; k += 0.5) {
      	
        if (pow(float(i) - pos.x, 2) / pow(x_radius, 2) +
            pow(float(j) - pos.y, 2) / pow(y_radius, 2) +
            pow(float(k) - pos.z, 2) / pow(z_radius, 2) < 1)
		{
          VETOR_3D <int> p = round( TM.transform(VETOR_3D <float>(i,j,k)) );

          if (p < c.getMaxPos()){
            p = c.getNormalPos(p.x, p.y, p.z );
            c.eixo(p) = (*this);
          }
        }
      }
    }
  }
}

inline VETOR_3D <float> Ellipsoid::getLimMax() const {
  return VETOR_3D <int> (pos.x + x_radius, pos.y + y_radius, pos.z + z_radius );
}

inline VETOR_3D <float> Ellipsoid::getLimMin() const {
  return VETOR_3D <int> (pos.x - x_radius, pos.y - y_radius, pos.z - z_radius );
}


void Cylinder::sculpt(Hipermatriz& c) const
{
  VETOR_3D <float> minP = getLimMin(), maxP = getLimMax();

  for (float i = minP.x; i < maxP.x; i += 0.5) {
    for (float j = minP.y; j < maxP.y; j += 0.5) {
      for (float k = minP.z; k < maxP.z; k += 0.5) {
      	
          if ((pow(i - pos.x, 2) + pow( k - pos.z, 2)) < pow(radius, 2)){
              VETOR_3D <float> p = round( TM.transform(VETOR_3D <float>(i,j,k)) );

              if (p < c.getMaxPos()){
                p = c.getNormalPos(p.x, p.y, p.z );
                c.eixo(p) = (*this);
              }
            }
        }
      }
    }
}

inline VETOR_3D <float> Cylinder::getLimMax() const {
  return VETOR_3D <int> ( pos.x + radius, pos.y + (height / 2.0), pos.z + radius );
}

inline VETOR_3D <float> Cylinder::getLimMin() const {
  return VETOR_3D <int> ( pos.x - radius, pos.y - (height / 2.0), pos.z - radius );
}


void Cone::sculpt(Hipermatriz& c) const
{
VETOR_3D <float> minP = getLimMin(), maxP = getLimMax();
    for (float i = minP.x; i < maxP.x - 0.5; i += 0.5) {
      for (float j = minP.y; j < maxP.y - 0.5; j += 0.5) {
        for (float k = minP.z; k < maxP.z - 0.5; k += 0.5) {
            // Verifica se o ponto faz parte do cilindro
            if ( pow(i - pos.x, 2) + pow(j - pos.y, 2) < pow((height - (k - minP.z )) * (x_radius / height), 2) ) {
              VETOR_3D <int> p = round( TM.transform(VETOR_3D <float>(i,j,k)) );

              if (p < c.getMaxPos()){
                p = c.getNormalPos(p.x, p.y, p.z );
                c.eixo(p) = (*this);
              }
            }
        }
      }
    }
}

inline VETOR_3D <float> Cone::getLimMax() const {
  return VETOR_3D <int> ( pos.x + x_radius, pos.y + y_radius, pos.z + height / 2.0 );
}

inline VETOR_3D <float> Cone::getLimMin() const {
  return VETOR_3D <int> ( pos.x - x_radius, pos.y - y_radius, pos.z - height / 2.0 );
}



void Ring::sculpt(Hipermatriz& c) const
{	
    VETOR_3D <float> minP = getLimMin(), maxP = getLimMax();

      for (float i = minP.x; i < maxP.x - 0.5; i += 0.5) {
        for (float j = minP.y; j < maxP.y - 0.5; j += 0.5) {
          for (float k = minP.z; k < maxP.z - 0.5; k += 0.5) {
        // Verifica se o ponto faz parte do anel
            if (
              pow( t_radius - sqrt( pow(i - pos.x, 2) + pow(j - pos.y, 2) ), 2) + pow(k - pos.z, 2) < pow(p_radius, 2)
            ){
              VETOR_3D <int> p = round( TM.transform(VETOR_3D <float>(i,j,k)) );

              if (p < c.getMaxPos()){
                p = c.getNormalPos(p.x, p.y, p.z );
                c.eixo(p) = (*this);
              }
            }
          }
        }
      }
}
inline VETOR_3D <float> Ring::getLimMax() const {
  return VETOR_3D <int> (pos.x + p_radius + t_radius, pos.y + p_radius + t_radius, pos.z + p_radius + t_radius);
}

inline VETOR_3D <float> Ring::getLimMin() const {
  return VETOR_3D <int> (pos.x - p_radius - t_radius, pos.y - p_radius - t_radius, pos.z - p_radius - t_radius);
}
