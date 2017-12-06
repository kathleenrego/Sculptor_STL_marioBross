#include "Sculptor.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;



// ESCREVE NO ARQUIVO OFF
void Sculptor::write(const char *Arq)
{
  ofstream fout(Arq);

  draw();

  fout << "OFF" << endl;
  fout << getNVertices() << " " << getNFaces() << " " << 0 << endl;

  for (int i = 0; i < dimX + 1; i++) {
    for (int j = 0; j < dimY + 1; j++) {
      for (int k = 0; k < dimZ + 1; k++) {
        VETOR_3D <int> pos(i, j, k);
        VETOR_3D <float> current = VETOR_3D <float> (-0.5, -0.5, -0.5) + pos;
        fout << current << endl;
      }
    }
  }

  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      for (int k = 0; k < dimZ; ++k) {

        VETOR_3D <int> pos(i, j, k);
		
		//AJUSTE DO TAMANHO DOS VOXELS
        unsigned P0 = getVoxel(pos.x, pos.y, pos.z),
                 P1 = getVoxel(pos.x + 1, pos.y, pos.z),
                 P2 = getVoxel(pos.x + 1, pos.y, pos.z + 1),
                 P3 = getVoxel(pos.x, pos.y, pos.z + 1),
                 P4 = getVoxel(pos.x, pos.y + 1, pos.z + 1),
                 P5 = getVoxel(pos.x, pos.y + 1, pos.z),
                 P6 = getVoxel(pos.x + 1, pos.y + 1, pos.z),
                 P7 = getVoxel(pos.x + 1, pos.y + 1, pos.z + 1);

				 
        Voxel v = eixo(pos);

        if (v.is_on){
        	
        	
          // Face 0
          if (pos.y == 0 or !eixo(pos.x, pos.y - 1, pos.z).is_on )
          fout << 4 << " " << P0 << " " << P1 << " " << P2 << " " << P3 << " " << v.R << " " << v.G << " " << v.B << " " << v.transparency << endl;
          // Face 1
          if (pos.x == 0 or !eixo(pos.x - 1, pos.y, pos.z).is_on )
          fout << 4 << " " << P0 << " " << P3 << " " << P4 << " " << P5 << " " << v.R << " " << v.G << " " << v.B << " " << v.transparency << endl;
          // Face 2
          if (pos.z == 0 or !eixo(pos.x, pos.y, pos.z - 1).is_on )
          fout << 4 << " " << P0 << " " << P5 << " " << P6 << " " << P1 << " " << v.R << " " << v.G << " " << v.B << " " << v.transparency << endl;
          // Face 3
          fout << 4 << " " << P5 << " " << P4 << " " << P7 << " " << P6 << " " << v.R << " " << v.G << " " << v.B << " " << v.transparency << endl;
          // Face 4
          fout << 4 << " " << P1 << " " << P6 << " " << P7 << " " << P2 << " " << v.R << " " << v.G << " " << v.B << " " << v.transparency << endl;
          // Face 5
          fout << 4 << " " << P3 << " " << P2 << " " << P7 << " " << P4 << " " << v.R << " " << v.G << " " << v.B << " " << v.transparency << endl;
        }
      }
    }
  }
}


void Sculptor::putVoxel(int X, int Y, int Z) {
  l.push_back(new Box(X + 1 / 2.0, Y + 1 / 2.0, Z + 1 / 2.0, R, G, B, transparency, true, 1, 1, 1));
  cout << "putVoxel finalizado!" << endl;
}

void Sculptor::cutVoxel(int X, int Y, int Z) {
  l.push_back(new Box(X + 1 / 2.0, Y + 1 / 2.0, Z + 1 / 2.0, 0.0, 0.0, 0.0, 0.0, false, 1, 1, 1));
  cout << "cutVoxel finalizado!" << endl;
}

void Sculptor::putEllipsoid(int Xc, int Yc, int Zc, int Rx, int Ry, int Rz, float angleX, float angleY, float angleZ) {
  l.push_back (new Ellipsoid(Xc, Yc, Zc, R, G, B, transparency, true, abs(Rx), abs(Ry), abs(Rz) ));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "putEllipsoid finalizado!" << endl;
}
void Sculptor::cutEllipsoid(int Xc, int Yc, int Zc, int Rx, int Ry, int Rz, float angleX, float angleY, float angleZ) {
    if (Rx == 0 || Ry == 0 || Rz == 0  ) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else{
	l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, transparency, false, abs(Rx), abs(Ry), abs(Rz) ));
	(*l.back()).rotate(angleX, angleY, angleZ);
	cout << "cutEllipsoid finalizado!" << endl;
  }
}

void Sculptor::putSphere(int Xc, int Yc, int Zc, int r, float angleX, float angleY, float angleZ) {
   if (r == 0) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else{
  l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, transparency, true, abs(r), abs(r), abs(r) ));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "putSphere finalizado!" << endl;
  }
}

void Sculptor::cutSphere(int Xc, int Yc, int Zc, int r, float angleX, float angleY, float angleZ) {
  if (r == 0) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else{
  l.push_back(new Ellipsoid(Xc, Yc, Zc, R, G, B, transparency, false, abs(r), abs(r), abs(r) ));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "cutSphere finalizado!" << endl;
  }
}

void Sculptor::putBox(int X0, int X1, int Y0, int Y1, int Z0, int Z1, float angleX, float angleY, float angleZ) {
       
  if (X0 == X1) {
	   X1++;}
  if (Y0 == Y1) {
  	   Y1++;}
  if (Z0 == Z1) {
       Z1++;}
            
  l.push_back(new Box((X1 + X0) / 2.0, (Y1 + Y0) / 2.0, (Z1 + Z0) / 2.0, R, G, B, transparency, true, abs(X1 - X0), abs(Y1 - Y0), abs(Z1 - Z0)));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "putBox finalizado!" << endl; 
}


void Sculptor::cutBox(int X0, int X1, int Y0, int Y1, int Z0, int Z1, float angleX, float angleY, float angleZ) {
  
  if (X0 == X1) {
	   X1++;}
  if (Y0 == Y1) {
  	   Y1++;}
  if (Z0 == Z1) {
       Z1++;}

  l.push_back(new Box((X1 + X0) / 2.0, (Y1 + Y0) / 2.0, (Z1 + Z0) / 2.0, R, G, B, transparency, false, abs(X1 - X0), abs(Y1 - Y0), abs(Z1 - Z0)));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "cutBox finalizado!" << endl;

}

void Sculptor::putCylinder(int Xc, int Zc, int Y0, int Y1, int r, float angleX, float angleY, float angleZ) {
  if (Y0 == Y1 || r == 0  ) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else {
  l.push_back(new Cylinder(Xc, (Y0 + Y1) / 2.0, Zc, R, G, B, transparency, true, abs(r), abs(Y1 - Y0) ));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "putCylinder finalizado!" << endl;
  }
}
void Sculptor::cutCylinder(int Xc, int Zc, int Y0, int Y1, int r, float angleX, float angleY, float angleZ) {
  if (Y0 == Y1 || r == 0  ) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else {
  l.push_back(new Cylinder(Xc, (Y0 + Y1) / 2.0, Zc, R, G, B, transparency, false, abs(r), abs(Y1 - Y0) ));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "cutCylinder finalizado!" << endl;
  }
}

void Sculptor::putRing(int Xc, int Yc, int Zc, int Rt, int Rp, float angleX, float angleY, float angleZ) {
  if (Rt == 0 || Rp == 0  ) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else {
  l.push_back(new Ring(Xc, Yc, Zc, R, G, B, transparency, true, abs(Rt), abs(Rp)) );
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "putRing finalizado!" << endl;
  }
}

void Sculptor::cutRing(int Xc, int Yc, int Zc, int Rt, int Rp, float angleX, float angleY, float angleZ) {
  if (Rt == 0 || Rp == 0  ) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else {
  l.push_back(new Ring(Xc, Yc, Zc, R, G, B, transparency, false, abs(Rt), abs(Rp)) );
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "cutRing finalizado!" << endl;
  }
}


void Sculptor::putCone(int Xc, int Yc, int Z0, int Z1, int r, float angleX, float angleY, float angleZ) {
  if (Z0 == Z1 || r == 0  ) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else {
  l.push_back(new Cone(Xc, Yc, (Z0 + Z1) / 2.0, R, G, B, transparency, true, abs(r), abs(r), abs(Z1 - Z0) ));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "putCone finalizado!" << endl;
  }
}
void Sculptor::cutCone(int Xc, int Yc, int Z0, int Z1, int r, float angleX, float angleY, float angleZ) {
  if (Z0 == Z1 || r == 0  ) {
  	 cerr << " Erro: DimensÆo invalida!" << endl;
  } else {
  l.push_back(new Cone(Xc, Yc, (Z0 + Z1) / 2.0, R, G, B, transparency, false, abs(r), abs(r), abs(Z1 - Z0) ));
  (*l.back()).rotate(angleX, angleY, angleZ);
  cout << "cutCone finalizado!" << endl;
  }
}

void Sculptor::putPyramid(int x, int y, int z, int lx, int lz, int h, float angleX, float angleY, float angleZ) {
  
  	int a((lx/2)/h), b((lz/2)/h),y0(y-h/2);
	for (int i =0; i<h; i++)
  {
  	putBox((x-(lx/2)+(a*i)), (x+(lx/2)-(a*i)), (y0+i), (y0+i+1), (z-(lz/2)+(b*i)), (z+(lz/2)-(b*i)));
  }
  cout << "putPyramid finalizado!" << endl;
}

void Sculptor::cutPyramid(int x, int y, int z, int lx,int lz, int h, float angleX, float angleY, float angleZ) {
   	int a((lx/2)/h), b((lz/2)/h),y0(y-h/2);
	for (int i =0; i<h; i++)
  {
  	cutBox((x-(lx/2)+(a*i)), (x+(lx/2)-(a*i)), (y0+i), (y0+i+1), (z-(lz/2)+(b*i)), (z+(lz/2)-(b*i)));
  }
  cout << "cutPyramid finalizado!" << endl;
 }



VETOR_3D <int> Sculptor::getMinXYZ() {
  VETOR_3D <int> minXYZ;

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
    VETOR_3D <int> current( (*i)->getMinX(), (*i)->getMinY(), (*i)->getMinZ() );
    
    if (i == l.begin()) minXYZ = current;
    if (minXYZ.x > current.x ) minXYZ.x = current.x;
    if (minXYZ.y > current.y ) minXYZ.y = current.y;
    if (minXYZ.z > current.z ) minXYZ.z = current.z;
  }

  return minXYZ;
}

VETOR_3D <int> Sculptor::getMaxXYZ() {
  VETOR_3D <int> maxXYZ;

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
  	
    VETOR_3D <int> current( (*i)->getMaxX(), (*i)->getMaxY(), (*i)->getMaxZ() );

    if (i == l.begin()) maxXYZ = current;
    if (maxXYZ.x < current.x ) maxXYZ.x = current.x;
    if (maxXYZ.y < current.y ) maxXYZ.y = current.y;
    if (maxXYZ.z < current.z ) maxXYZ.z = current.z;
  }

  return maxXYZ;
}

void Sculptor::draw() {

  VETOR_3D <int> max = getMaxXYZ(), min = getMinXYZ();
  VETOR_3D <int> size = max - min;

  initialize(size.x, size.y, size.z, min.x, min.y, min.z);

  for (pSolidIterator i = l.begin(); i != l.end(); ++i){
    (*i)->sculpt(*this);
  }

  cleanVoxels();

}