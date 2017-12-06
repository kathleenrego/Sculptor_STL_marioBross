#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>

#include "Hipermatriz.h"
using namespace std;


//FUNÇÂO QUE CONTA O NUMERO DE FACES
unsigned Hipermatriz::getNFaces() const {
unsigned faces = 0;

  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      for (int k = 0; k < dimZ; ++k) {

        // Vê se o voxel estah ON
        if (eixo(i, j, k).is_on ) {
          faces += 3;
          
          if (i == 0 or !eixo(i - 1, j, k).is_on ) ++faces;
          if (j == 0 or !eixo(i, j - 1, k).is_on ) ++faces;
          if (k == 0 or !eixo(i, j, k - 1).is_on ) ++faces;
          
        }
      }
    }
  }
  return faces;
}

typedef VETOR_3D <int> pInt;

//FUNÇÃO CLEANVOLXELS
void Hipermatriz::cleanVoxels() {

  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      for (int k = 0; k < dimZ; ++k) {
        if (i != 0 && j != 0 && k != 0 && eixo(i, j, k).is_on  &&
            i < (dimX - 1) && j < (dimY - 1) && k < (dimZ - 1) &&
 	        eixo(i - 1, j, k).is_on && eixo(i + 1, j, k).is_on &&
 	        eixo(i, j - 1, k).is_on && eixo(i, j + 1, k).is_on &&
 	        eixo(i, j, k - 1).is_on && eixo(i, j, k + 1).is_on ) 
		{ 		
          	  eixo(i, j, k).transparency = 0.0;
		}
      }
    }
  }
    for (int i = 0; i < dimX; ++i) {
      for (int j = 0; j < dimY; ++j) {
        for (int k = 0; k < dimZ; ++k) {
          if (eixo(i, j, k).transparency == 0.0 ) {
			  eixo(i, j, k).is_on = false;
		  }         
        }
      }
    }
}
