#ifndef _HIPERMATRIZ_H_
#define _HIPERMATRIZ_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;


struct Voxel {
  float R, G, B;  // Colors
  float transparency;  // Transparency
  bool is_on;   // Included or not


  // Seta o voxel
  Voxel (
    float r=0.0,
    float g=0.0,
    float b=0.0,
    float a=1.0,
    bool on=false ) : R(r), G(g), B(b), transparency(a), is_on(on) {}
};


// Guarda um vetor no Espaço Tridimensional
//VETOR_3D - Vetor Posição na matriz 3D
template <class Type>
struct VETOR_3D {
  Type x, y, z;

  VETOR_3D (Type px=0, Type py=0, Type pz=0): x(px), y(py), z(pz) { }

  inline friend ostream & operator << (ostream & out, const VETOR_3D <Type> & pos) { out << pos.x << " " << pos.y << " " << pos.z; return out; }

  template <class Type2>
  VETOR_3D (VETOR_3D <Type2> pos) {
    x = pos.x; y = pos.y; z = pos.z;
  }
  
  
  //Sobrecarga de Operadores para o vetor posição
  
  inline VETOR_3D operator+ (VETOR_3D pos) const {
    return VETOR_3D (x + pos.x, y + pos.y, z + pos.z);
  }

  inline VETOR_3D operator- (VETOR_3D pos) const {
    return (*this) + (-pos);
  }
  
  inline friend VETOR_3D operator- (VETOR_3D pos) {
    return VETOR_3D (-pos.x, -pos.y, -pos.z);
  }

  inline Type operator* (VETOR_3D pos) const{
    return (x * pos.x) +  (y * pos.y) +  (z * pos.z);
  }

  inline bool operator == (VETOR_3D pos) {
    return (x == pos.x && y == pos.y && z == pos.z);
  }
  
  inline bool operator != (VETOR_3D pos) {
    return ! (*this == pos);
  }

  inline bool operator < (VETOR_3D pos) {
    return (x < pos.x && y < pos.y && z < pos.z);
  }
};

const VETOR_3D <unsigned int> origin(0, 0, 0);

template <class Type>
Type distance(VETOR_3D <Type> a, VETOR_3D <Type> b) {
  return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

enum AXIS{
  X, Y, Z
};



//Mudanças geometricas das formas
//Matriz_3D -> Matriz das transformações (Translação e Rotação)

class Matriz_3D {
protected:
  float m[4][4];
  inline void fill (bool is_identity = false) {
    for (unsigned i = 0; i < 4; i++) {
      for (unsigned j = 0; j < 4; j++) {
        if (is_identity && i == j)  m[i][j] = 1;     // DECLARAÇÃO DA MATRIZ IDENTIDADE
        else m[i][j] = 0;
      }
    }
  }
public:
  Matriz_3D (bool is_identity = true) {
    fill(is_identity);
  }

  
  //Operador multiplicação unaria da matriz
  inline const Matriz_3D operator * (Matriz_3D matrix) const {
    Matriz_3D tmp(false);
    return tmp = (*this ) * matrix;
  }
  
  // Operador multiplicação binaria de matrizes
  inline Matriz_3D & operator * (Matriz_3D matrix) {
    Matriz_3D tmp(false);
    for (unsigned i = 0; i < 4; i++) {
      for (unsigned j = 0; j < 4; j++) {            
        for (unsigned k = 0; k < 4; k++) {
          tmp.m[i][j] += m[i][k] * matrix.m[k][j];
        }
      }
    }

    return *this = tmp;
  }
  
  
  // Operador impressão das matrizes
  inline friend ostream & operator << (ostream & out, const Matriz_3D & m ) {
    for (unsigned i = 0; i < 4; i++) {
      for (unsigned j = 0; j < 4; j++) {
        out << m.m[i][j] << " ";
      }

      out << endl;
    }

    return out;
  }


  // GERA O VETOR RESULTANTE
  VETOR_3D <float> transform (VETOR_3D <float> pos) const {
    return VETOR_3D <float> (
      pos.x * m[0][0] + pos.y * m[0][1] + pos.z * m[0][2] + m[0][3],
      pos.x * m[1][0] + pos.y * m[1][1] + pos.z * m[1][2] + m[1][3],
      pos.x * m[2][0] + pos.y * m[2][1] + pos.z * m[2][2] + m[2][3]
    );
  }

};

// Translação das formas
class TranslationMatrix : public Matriz_3D {
public:
  inline TranslationMatrix (VETOR_3D <float> v) : Matriz_3D(){m[0][3] = v.x; m[1][3] = v.y; m[2][3] = v.z;}};


// Rotação das formas
class RotationMatrix : public Matriz_3D {
public:
  RotationMatrix (float angleX, float angleY, float angleZ) {
    fill(true);
	// Z por Y
	
	if (angleX != 0.0)
	{
		// Eixo x
        m[1][1] = cos(angleX);   m[1][2] = sin(angleX);
        m[2][1] = -sin(angleX);  m[2][2] = cos(angleX);
	}
	else if (angleZ != 0.0)
	{
		// Eixo Z
        m[0][0] = cos(angleZ);  m[0][2] = -sin(angleZ);
        m[2][0] = sin(angleZ);  m[2][2] = cos(angleZ);
	}
	
	else if (angleY != 0.0)
	{
		// Eixo Y
        m[0][0] = cos(angleY);   m[0][1] = sin(angleY);
        m[1][0] = -sin(angleY);  m[1][1] = cos(angleY);
	}
	
    	
	
	//Matriz de Rotação 
      /*  m[0][0] = (cos(angleX)*cos(angleY))-(sin(angleX)*cos(angleZ)*sin(angleY));  
		m[0][1] = (sin(angleX)*cos(angleY))+(cos(angleX)*cos(angleZ)*sin(angleY)); 
		m[0][2] = sin(angleZ)*sin(angleY);
        m[1][0] = (-cos(angleX)*sin(angleY))-(sin(angleX)*cos(angleZ)*cos(angleY));  
		m[1][1] = (-sin(angleX)*cos(angleY))+(cos(angleX)*cos(angleZ)*cos(angleY)); 
		m[1][2] = sin(angleZ)*cos(angleY);
        m[2][0] = sin(angleZ)*sin(angleY);  
		m[2][1] = -cos(angleX)*sin(angleZ); 
		m[2][2] = cos(angleZ);
    */

    }
};

// ----------------------------------------------------------------------


// MODIFICAÇÕES DE PREENCHIMENTO DA MATRIZ

//vector de volxels criado
typedef vector<Voxel>::iterator VoxelIterator;

// Classe Hipermtriz
class Hipermatriz{
protected:
  unsigned int dimX, dimY, dimZ;
  vector <Voxel> x;
  VETOR_3D <int> minXYZ;
  
  // TAMANHO DA HIPERMATRIZ
  inline void initialize(unsigned dx, unsigned dy, unsigned dz, int mx=0, int my=0, int mz=0)
  {
    minXYZ = VETOR_3D <int> (mx, my, mz); dimX = unsigned(dx); dimY = unsigned(dy); dimZ = unsigned(dz);
    
    
    if (dimX * dimX * dimX > 0)
      x = vector <Voxel> (dimX * dimY * dimZ, Voxel());
  }
public:
	
  inline VETOR_3D <unsigned int> getNormalPos (int x, int y, int z) { return VETOR_3D <unsigned int> ( (x - minXYZ.x), (y - minXYZ.y), (z - minXYZ.z) ); }
  inline Hipermatriz (unsigned dx=0, unsigned dy=0, unsigned dz=0, int mx=0, int my=0, int mz=0) { initialize(dx, dy, dz, mx, my, mz); }
  
  inline const Voxel & eixo(unsigned i, unsigned j, unsigned k) const {
      return x.at (i * dimY * dimZ + j * dimZ + k );
  }

  // Devolve X, Y e Z maxima da hipermatriz
  inline VETOR_3D <int> getMaxPos() const {
    return minXYZ + VETOR_3D <int> (dimX, dimY, dimZ);
  }

  // Devolve X, Y e Z minimo da hipermatriz
  inline VETOR_3D <int> getMinPos() const {
    return minXYZ;
  }

  
  inline Voxel & eixo(unsigned i, unsigned j, unsigned k) {
    return x.at (i * dimY * dimZ + j * dimZ + k);
  }

  inline const Voxel & eixo(const VETOR_3D <unsigned int> pos) const {
      return eixo(pos.x, pos.y, pos.z);
  }

  inline Voxel & eixo(const VETOR_3D <unsigned int> pos) {
    return eixo(pos.x, pos.y, pos.z);
  }
  
  inline unsigned getNVertices() const { return (dimX + 1) * (dimY + 1) * (dimZ + 1); } // Obtem o numero de vertices da hipermatriz
  unsigned getNFaces() const; // Obtem o numero total de faces da hipermatriz
  void cleanVoxels();

  inline unsigned int getVoxel(unsigned i, unsigned j, unsigned k) {
    return i * (dimZ + 1) * (dimY + 1) + j * (dimZ + 1) + k;
  }

  inline unsigned int getVoxel(VETOR_3D <unsigned int> pos) {
    getVoxel(pos.x, pos.y, pos.z);
  }
};

#endif //_HIPERMATRIZ_H_
