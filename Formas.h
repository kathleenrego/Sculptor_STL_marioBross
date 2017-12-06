#ifndef _FORMAS_H_
#define _FORMAS_H_

#include "Hipermatriz.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solid : protected Voxel {
protected:
  VETOR_3D <float> pos;
  Matriz_3D TM;  //Matriz_3D das Transformações

  virtual VETOR_3D <float> getLimMin() const = 0;
  virtual VETOR_3D <float> getLimMax() const = 0;

public:
  inline Solid (
    float x=0.0,
    float y=0.0,
    float z=0.0,
    float r=0.0, float g=0.0, float b=0.0, float a=1.0,
    bool on=true
  ) : pos(x, y, z), Voxel::Voxel (r, g, b, a, on) { }

  
  
  virtual void sculpt(Hipermatriz& c) const = 0;

  inline void translate(float x, float y, float z) {
    TM = TranslationMatrix(VETOR_3D <float>(x, y, z)) * TM;
  }

  inline void rotate(float angleX, float angleY, float angleZ) {
    TM = TranslationMatrix(pos) * RotationMatrix(angleX, angleY, angleZ) * TranslationMatrix(-pos) * TM;
  }

  int getMaxX() const;
  int getMaxY() const;
  int getMaxZ() const;

  int getMinX() const;
  int getMinY() const;
  int getMinZ() const;

  inline void setColor(float r, float g, float b) {
    R = r; G = g; B = b;
  }

  inline void setPos(float x, float y, float z) {
    pos.x = x; pos.y = y; pos.z = z;
  }
  inline virtual ~Solid() {}

};


class Box : public Solid {
protected:
  VETOR_3D <float> getLimMin() const;
  VETOR_3D <float> getLimMax() const;

  unsigned int width, length, height;
public:
  inline Box(
    float x=0.0, float y=0.0, float z=0.0,
    float r=0.0, float g=0.0, float b=0.0, float a=1.0,
    bool on=true,
    unsigned int w=1, unsigned int l=1, unsigned int h=1
  ) : Solid(x, y, z, r, g, b, a, on), width(w), length(l), height(h) { }

  void sculpt(Hipermatriz& c) const;
};

class Cylinder : public Solid{
protected:
  VETOR_3D <float> getLimMin() const;
  VETOR_3D <float> getLimMax() const;

  float radius, height;
public:
  inline Cylinder (
    float x=0.0, float y=0.0, float z=0.0,
    float r=0.0, float g=0.0, float b=0.0, float a=1.0,
    bool on=true,
    unsigned int rad=1.0, unsigned int h=1
  ) : Solid(x, y, z, r, g, b, a, on), radius(rad), height(h) {}

  void sculpt(Hipermatriz& c) const;
};

class Ellipsoid : public Solid{
protected:
  VETOR_3D <float> getLimMin() const;
  VETOR_3D <float> getLimMax() const;

  float x_radius, y_radius, z_radius;
public:
    inline Ellipsoid (
        float x=0.0, float y=0.0, float z=0.0,
        float r=0.0, float g=0.0, float b=0.0, float a = 1.0,
        bool on = true,
        float rx = 1.0, float ry = 1.0, float rz = 1.0
      ) : Solid(x, y, z, r, g, b, a, on), x_radius(rx), y_radius(ry), z_radius(rz){}

      void sculpt(Hipermatriz& c) const;
};

class Ring : public Solid {
protected:
  VETOR_3D <float> getLimMin() const;
  VETOR_3D <float> getLimMax() const;

  float t_radius, p_radius;
public:
    inline Ring (
        float x=0.0, float y=0.0, float z=0.0,
        float r=0.0, float g=0.0, float b=0.0, float a = 1.0,
        bool on = true,
        float tR = 1.0, float pR = 1.0
      ) : Solid(x, y, z, r, g, b, a, on), t_radius(tR), p_radius(pR) {}

      void sculpt(Hipermatriz& c) const;
};

class Cone : public Solid {
protected:
  VETOR_3D <float> getLimMin() const;
  VETOR_3D <float> getLimMax() const;

  float x_radius, y_radius, height;
public:
  inline Cone (
    float x=0.0, float y=0.0, float z=0.0,
    float r=0.0, float g=0.0, float b=0.0, float a = 1.0,
    bool on = true,
    float xR = 1.0, float yR = 1.0, float h = 1.0
  ) : Solid(x, y, z, r, g, b, a, on), x_radius(xR), y_radius(yR), height(h) {}

  void sculpt(Hipermatriz& c) const;
};

typedef Solid *pSolid;

#endif //_FORMAS_H_
