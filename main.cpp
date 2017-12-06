#include "Sculptor.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

//#define PI 3.14159265359
#define N 1 //Scale

// Coordenadas do Luigi
#define Xc -80 // X-position
#define Yc 34 // Y-position
#define Zc 10 // Z-position

int main(){
	   
  Sculptor s;
   
  
  // ------------------------------ CENARIO ------------------------------ //
  
    //carnivora
    s.setColor(0.0,100/255,0.0,1.0);
    s.putCylinder(150,10,5,20,3);
    s.setColor(160/255.,32/255,240/255,1.0);
    s.putSphere(150,35,10, 20);
    s.cutBox(138,162,33,57,-2,22);
    s.cutBox(137,163,32,58,-3,23,0.0,0.0,M_PI/4.0);
    // cilindro direita
    s.setColor(1.0,1.0,0.0,1.0);
    s.putCylinder(150,10,-25,5,12);
    s.putCylinder(150,10,-5,10,13);
    
    s.putCylinder(150,10,80,82,9,M_PI/2.0);
    s.putCylinder(120,10,100,102,9,M_PI/4.0);
    s.putCylinder(180,10,110,112,9,M_PI/2.0);
    s.putCylinder(205,10,90,92,9,M_PI/4.0);
    

    //obstaculos
    s.setColor(218/255.0,165/255.0,32/255.0,1.0);
    s.putBox(90,100,50,60,5,15);
    s.putBox(68,78,50,60,5,15);
    s.putBox(57,67,50,60,5,15);
    s.putBox(46,56,50,60,5,15);
    s.setColor(1.0,1.0,0.0,1.0);
    s.putBox(79,89,50,60,5,15);
    
    //INTERROGAÇÃO
    s.setColor(1.0,1.0,1.0,1.0);
    s.putRing(83,55,15,2,1);
    s.cutBox(82,85,53,57,12,20);

    //piso verde
    s.setColor(0.0,1.0,0.0,1.0);
    s.putBox(-200,200,-25,-29,-100,50);
    //piso marrom
    s.setColor(205/255.0,133.0/255.0,63.0/255.0,1.0);
    s.putBox(-200,200,-29,-39,-100,50);
    
    //cilindo esquerda
    s.setColor(0.0,0.0,1.0,1.0);
    s.putCylinder(-80,10,-25,5,18);
    s.putCylinder(-80,10,-5,10,19);
  
    //piramide verde grande
    s.setColor(0.0,1.0,0.0,1.0);
    s.putPyramid(25, 60, -75, 350,50, 170);
    //central verde
    s.setColor(205/255.0,133.0/255.0,63.0/255.0,1.0);
    s.putPyramid(-20, 0, -50, 200, 26, 50);
  
    //piramide central branca
    s.setColor(1.0,1.0,1.0,1.0);
    s.putPyramid(-150, 0, -85, 200, 26, 50);

    //piramide lateral marrom
    s.setColor(205/255.0,133.0/255.0,63.0/255.0,1.0);
    s.putPyramid(-200, 0, -75, 200, 50, 50);
    s.cutBox(-300,-200,-25,25,-100,-50);

    //placar 1
    s.setColor(1.0,0.0,0.0,1.0);
    s.putBox(-180, -140, 110, 120, -30, -25);
    //placar 2
    s.putBox(-90, -50,110, 120, -30, -25);
    //placar 3
    s.putBox(0, 40, 110, 120, -30, -25);
    
    //placar 4
    s.putBox(90, 140, 110, 120, -30, -25);

  //fundo
  s.setColor(175.0/255.0,238.0/255.0,238.0/255.0,1.0);
  s.putBox(-200, 200, -39, 150,-100,-99);
  
  //-----------------------------------------------------------------------
  
  
  
  
  
  
  // ------------------------------ MARIO ------------------------------ //

  // Dorso
  s.setColor(1.0,0.0,0.0,1.0);
  s.putCylinder(0, 0, N*33, N*6, N*5, 0.0, M_PI/2.0, 0.0);
  
  //Braco esquerdo
  
  s.putCylinder(N*16, 0, N*24, 0, N*4, 0.0, -M_PI/4.8, 0.0);
  
  //Braco direito
  
  s.putCylinder(-N*16, 0, N*24, 0, N*4, 0.0, M_PI/4.8, 0.0);
  
  
  //AJUSTES BD
  
  s.cutSphere(-N*13,N*22,0,N*5);
  s.setColor(1.0,0.0,0.0,1.0);
  s.putSphere(-N*8,N*15,0,N*8);
  //s.putBox(-N*8,-N*9, N*23, N*24, -N*3, N*4);
  s.cutBox(-N*27,-N*2,-N*10,N*28,N*4,N*10);
  s.cutBox(-N*27,-N*2,-N*9,N*28,-N*3,-N*8);
  
  //AJUSTES BE
  
  
  s.cutSphere(N*12,N*22,0,N*5);
  s.setColor(1.0,0.0,0.0,1.0);
  s.putSphere(N*8,N*15,0,N*8);
  //s.putBox(N*8,N*9, N*24, N*25, -N*2, N*3);
  //s.putBox(N*8,N*9, N*23, N*24, -N*3, N*4);
  //s.putBox(N*9,N*10, N*23, N*24, -N*3, N*4);
  s.cutBox(N*2,N*27,-N*10,N*28,N*4,N*10);
  s.cutBox(N*2,N*27,-N*9,N*28,-N*3,-N*8);
  
  
  //Mão esquerda
  
  s.setColor(1.0, 1.0, 1.0, 1.0);
  s.putEllipsoid(N*24, N*1, 0,  N*5, N*4 ,N*5, 0.0, -M_PI/3.8, 0.0);
  s.putCylinder(N*21, 0, 8, 15, 5, 0.0, -M_PI/4.8, 0.0);
  s.getLastSolid().translate(2, -8, 0);
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putBox(N*23, N*25, 0,N*2, N*2, 6,0.0,0.0,0.0);
  s.putBox(N*23, N*25, 0,N*2, -5, -N*3,0.0,0.0,0.0);
  
  
  //Mão esquerda
  
  s.setColor(1.0, 1.0, 1.0, 1.0);
  s.putEllipsoid(-N*24, N*1, 0,  N*5, N*4 ,N*5, 0.0, M_PI/3.8, 0.0);
  s.putCylinder(-N*21, 0, 8, 15, 5, 0.0, M_PI/4.8, 0.0);
  s.getLastSolid().translate(-2, -8, 0);
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putBox(-N*23, -N*25, 0,N*2, N*2, 6,0.0,0.0,0.0);
  s.putBox(-N*23, -N*25, 0,N*2, -5, -N*3,0.0,0.0,0.0);
  
  
  
  
  //----------------------- CABEÇA ---------------------------------
  
  //Pescoço 
  
  s.setColor(1.0,0.0,0.0,1.0);
  s.putCylinder(0,0, N*24, N*30, N*3);
  
  
  //Cabelo
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putEllipsoid(0,N*38, 0, N*11, N*11, N*11 );
  s.cutBox(-N*11,N*13,N*25,N*50,N*8,N*14);
  
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putEllipsoid(0,N*37, -N*1-1, N*12, N*12, N*11 );
  
  
  //Cabeça
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(0,N*36, 0, N*12, N*11, N*11 );
  
  s.cutBox(-N*11,N*13,N*25,N*50,N*8,N*12);
  s.cutBox(-N*10+1,-N*12,N*25,N*50,-N*12,N*12);
  s.cutBox(N*10,N*13,N*25,N*50,-N*12,N*12);
  
  
  //Cavanhaque
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putBox(N*8,N*10,N*38,N*42+1,N*4,N*6);
  s.putBox(N*8,N*10,N*36,N*43+1,N*2,N*4);
  s.putBox(N*8,N*10,N*34,N*44+1,N*0,N*2);
  s.putBox(N*8,N*10,N*36,N*43+1,-N*2,N*0);
  s.putBox(N*8,N*10,N*34,N*43+1,-N*4,-N*2);
  s.putBox(N*8,N*10,N*32,N*43+1,-N*6,-N*4);
  s.putBox(N*8,N*10,N*33,N*43,-N*8,-N*6);
  
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putBox(-N*8,-N*10+1,N*38,N*42+1,N*4,N*6);
  s.putBox(-N*8,-N*10+1,N*36,N*43+1,N*2,N*4);
  s.putBox(-N*8,-N*10+1,N*34,N*43,N*0,N*2);
  s.putBox(-N*8,-N*10+1,N*36,N*42,-N*2,N*0);
  s.putBox(-N*8,-N*10+1,N*34,N*42,-N*4,-N*2);
  s.putBox(-N*8,-N*10+1,N*32,N*42,-N*6,-N*4);
  s.putBox(-N*8,-N*10+1,N*33,N*42,-N*7-1,-N*6);
  
  
  
  //FACE
  
  //s.setColor(255.0,164.0,96.0,1.0);
  //s.putSphere(0, 29, 2, 9);
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putSphere(0, N*30, N*3, N*5);
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putSphere(N*5, N*32, N*4, N*5);
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putSphere(-N*5, N*32, N*4, N*5);
  
  
  //Olhos
  s.cutEllipsoid(N*3, N*39, N*7, N*2-1, N*3-1, N*2);
  s.cutEllipsoid(-N*3, N*39, N*7, N*2-1, N*3-1, N*2);    //CAVIDADE OCULAR
  
  s.setColor(1.0,1.0,1.0,1.0);
  s.putEllipsoid(N*3, N*39, N*6, N*2-1, N*3-1, N*1);
  s.putEllipsoid(-N*3, N*39, N*6, N*2-1, N*3-1, N*1);  //GLOBO OCULAR
  s.putVoxel(N*2, N*41, N*7);
  s.putVoxel(-N*2, N*41, N*7);
  
  s.setColor(30.0/255.0,144.0/255.0,1.0,1.0);
  s.putBox(N*2, N*4, N*38, N*41, N*8-1, N*8);    // IRIS
  s.putBox(-N*2+1, -N*4+1, N*38, N*41, N*8-1, N*8);
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putBox(N*2, N*4-1, N*38, N*41-1, N*8-1, N*8);
  s.putBox(-N*1, -N*2, N*38, N*41-1, N*8-1, N*8);   //PUPILA
  
  
  
  //NARIZ
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(0, N*36-1, N*11, N*3-1, N*3-1, N*3+1);
  
  //Bigode
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putRing(0, N*35, N*5, N*5+1, N*2-1, M_PI/3.0, 0.0, M_PI/2.0);
  
  
  // ORELHAS
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(N*11, N*36-1, N*0, N*3-1, N*3+1, N*2-1, 0.0, 0.0, -M_PI/4.0);
  s.cutEllipsoid(N*11, N*36-1, N*2, N*1, N*3+1, N*2, 0.0, 0.0, -M_PI/4.0);
  
   s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(-N*11, N*36-1, N*0, N*3-1, N*3+1, N*2-1, 0.0, 0.0, M_PI/4.0);
  s.cutEllipsoid(-N*11, N*36-1, N*2, N*1, N*3+1, N*2, 0.0, 0.0, M_PI/4.0);
  
  //CHAPEU MARIO
  
  s.setColor(1.0,0.0,0.0,1.0);
  s.putEllipsoid(0, N*46, 0, N*11, N*7, N*11, M_PI/5.0, 0.0, 0.0);
  s.putEllipsoid(0, N*43, -N*6+1, N*10, N*7, N*9, M_PI/6.0, 0.0, 0.0);
  s.putEllipsoid(0, N*44+1, N*8, N*10, N*2-1, N*8, M_PI/14.0, 0.0, 0.0);
  s.cutEllipsoid(0, N*43-1, N*11, N*10, N*2, N*3, M_PI/14.0, 0.0, 0.0);
  
  s.setColor(1.0,1.0,1.0,1.0);
  s.putCylinder(0, N*9, N*50, N*53, N*3+1, M_PI/1.8, M_PI/2.0, 0.0);
  s.getLastSolid().translate(0, -N*2, 0);
  
  //Letra M
  
  s.setColor(1.0, 0.0, 0.0, 1.0);
  s.putBox(-N*2,-N*1, N*49, N*52, N*10, N*12);
  s.putVoxel(-N*1, N*51, N*11);
  s.putVoxel(N*0, N*50, N*11);
  s.putVoxel(N*1, N*51, N*11);
  s.putBox(N*2, N*3, N*49, N*52, N*10, N*12);
  
  
  

  
  //-------------------------------------------------------------

  
  //Barriga
  s.setColor(0.0,0.0,1.0,1.0);
  s.putSphere(0, N*10, 0, N*13);
  
  //Alça macacao
  
  s.putRing(N*7,N*20, 0, N*4, N*2, 0.0, -M_PI/2.0,-M_PI/2.0);
  s.putRing(-N*7,N*20, 0, N*4, N*2, 0.0, -M_PI/2.0,-M_PI/2.0);
  
  //Botões
  
  s.setColor(1.0, 1.0, 0.0, 1.0);
  s.putCylinder(-N*7,7,N*20, N*21, N*1, M_PI/2.0, 0.0, M_PI/12.0);
  s.putCylinder(N*7,7,N*20, N*21, N*1, M_PI/2.0, 0.0, M_PI/12.0);
  
  
  
  //Pernas
  s.setColor(0.0,0.0,1.0,1.0);
  s.putCylinder(-N*7, 0, N*2, -N*18, N*5, 0.0, M_PI/14.0, 0.0);
  s.putCylinder(N*7, 0, N*2, -N*18, N*5, 0.0, -M_PI/14.0, 0.0);
  
  
  
  // Sapato da esquerda
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putEllipsoid(-N*10, -N*20, N*3,  N*4, -N*4 ,N*8, 0.0,0.0, M_PI/10.0);
  
  // Sapato da direita
  s.putEllipsoid(N*10, -N*20, N*3,  N*4, -N*4 ,N*8, 0.0, 0.0, -M_PI/10.0);
  
  
  
  // --------------------------------------------------------------------------- //
  
  
  
  
  
  
  
  
  
  // ------------------------------ LUIGI ----------------------------------- //
  
  
  // Dorso
  s.setColor(0.0,1.0,0.0,1.0);
  s.putCylinder(0+Xc, 0+Zc, N*33+Yc, N*6+Yc, N*5, 0.0, M_PI/2.0, 0.0);
  
  //Braco esquerdo
  
  s.putCylinder(N*16+Xc, 0+Zc, N*24+Yc, 0+Yc, N*4, 0.0, -M_PI/4.8, 0.0);
  
  //Braco direito
  
  s.putCylinder(-N*16+Xc, 0+Zc, N*24+Yc, 0+Yc, N*4, 0.0, M_PI/4.8, 0.0);
  
  
  //AJUSTES BD
  
  s.cutSphere(-N*13+Xc,N*22+Yc,0+Zc,N*5);
  s.setColor(0.0,1.0,0.0,1.0);
  s.putSphere(-N*8+Xc,N*15+Yc,0+Zc,N*8);
  //s.putBox(-N*8,-N*9, N*23, N*24, -N*3, N*4);
  s.cutBox(-N*27+Xc,-N*2+Xc,-N*10+Yc,N*28+Yc,N*4+Zc,N*10+Zc);
  s.cutBox(-N*27+Xc,-N*2+Xc,-N*9+Yc,N*28+Yc,-N*3+Zc,-N*8+Zc);
  
  //AJUSTES BE
  
  
  s.cutSphere(N*12+Xc,N*22+Yc,0+Zc,N*5);
  s.setColor(0.0,1.0,0.0,1.0);
  s.putSphere(N*8+Xc,N*15+Yc,0+Zc,N*8);
  //s.putBox(N*8,N*9, N*24, N*25, -N*2, N*3);
  //s.putBox(N*8,N*9, N*23, N*24, -N*3, N*4);
  //s.putBox(N*9,N*10, N*23, N*24, -N*3, N*4);
  s.cutBox(N*2+Xc,N*27+Xc,-N*10+Yc,N*28+Yc,N*4+Zc,N*10+Zc);
  s.cutBox(N*2+Xc,N*27+Xc,-N*9+Yc,N*28+Yc,-N*3+Zc,-N*8+Zc);
  
  
  //Mão esquerda
  
  s.setColor(1.0, 1.0, 1.0, 1.0);
  s.putEllipsoid(N*24+Xc, N*1+Yc, 0+Zc,  N*5, N*4 ,N*5, 0.0, -M_PI/3.8, 0.0);
  s.putCylinder(N*21+Xc, 0+Zc, 8+Yc, 15+Yc, 5, 0.0, -M_PI/4.8, 0.0);
  s.getLastSolid().translate(2, -8, 0);
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putBox(N*23+Xc, N*25+Xc, 0+Yc,N*2+Yc, N*2+Zc, 6+Zc,0.0,0.0,0.0);
  s.putBox(N*23+Xc, N*25+Xc, 0+Yc,N*2+Yc, -5+Zc, -N*3+Zc,0.0,0.0,0.0);
  
  
  //Mão esquerda
  
  s.setColor(1.0, 1.0, 1.0, 1.0);
  s.putEllipsoid(-N*24+Xc, N*1+Yc, 0+Zc,  N*5, N*4 ,N*5, 0.0, M_PI/3.8, 0.0);
  s.putCylinder(-N*21+Xc, 0+Zc, 8+Yc, 15+Yc, 5, 0.0, M_PI/4.8, 0.0);
  s.getLastSolid().translate(-2, -8, 0);
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putBox(-N*23+Xc, -N*25+Xc, 0+Yc,N*2+Yc, N*2+Zc, 6+Zc,0.0,0.0,0.0);
  s.putBox(-N*23+Xc, -N*25+Xc, 0+Yc,N*2+Yc, -5+Zc, -N*3+Zc,0.0,0.0,0.0);
  
  
  
  
  //----------------------- CABEÇA ---------------------------------
  
  //Pescoço 
  
  s.setColor(0.0,1.0,0.0,1.0);
  s.putCylinder(0+Xc,0+Zc, N*24+Yc, N*30+Yc, N*3);
  
  
  //Cabelo
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putEllipsoid(0+Xc,N*38+Yc, 0+Zc, N*11, N*11, N*11 );
  s.cutBox(-N*11+Xc,N*13+Xc,N*25+Yc,N*50+Yc,N*8+Zc,N*14+Zc);
  
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putEllipsoid(0+Xc,N*37+Yc, -N*1-1+Zc, N*12, N*12, N*11 );
  
  
  //Cabeça
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(0+Xc,N*36+Yc, 0+Zc, N*11-1, N*12, N*11 );
  
  s.cutBox(-N*11+Xc,N*13+Xc,N*25+Yc,N*50+Yc,N*8+Zc,N*12+Zc);
  s.cutBox(-N*10+1+Xc,-N*12+Xc,N*25+Yc,N*50+Yc,-N*12+Zc,N*12+Zc);
  s.cutBox(N*10+Xc,N*13+Xc,N*25+Yc,N*50+Yc,-N*12+Zc,N*12+Zc);
  
  
  //Cavanhaque
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putBox(N*8+Xc,N*10+Xc,N*38+Yc,N*42+1+Yc,N*4+Zc,N*6+Zc);
  s.putBox(N*8+Xc,N*10+Xc,N*36+Yc,N*43+1+Yc,N*2+Zc,N*4+Zc);
  s.putBox(N*8+Xc,N*10+Xc,N*34+Yc,N*44+1+Yc,N*0+Zc,N*2+Zc);
  s.putBox(N*8+Xc,N*10+Xc,N*36+Yc,N*43+1+Yc,-N*2+Zc,N*0+Zc);
  s.putBox(N*8+Xc,N*10+Xc,N*34+Yc,N*43+1+Yc,-N*4+Zc,-N*2+Zc);
  s.putBox(N*8+Xc,N*10+Xc,N*32+Yc,N*43+1+Yc,-N*6+Zc,-N*4+Zc);
  s.putBox(N*8+Xc,N*10+Xc,N*33+Yc,N*43+Yc,-N*8+Zc,-N*6+Zc);
  
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putBox(-N*8+Xc,-N*10+1+Xc,N*38+Yc,N*42+1+Yc,N*4+Zc,N*6+Zc);
  s.putBox(-N*8+Xc,-N*10+1+Xc,N*36+Yc,N*43+1+Yc,N*2+Zc,N*4+Zc);
  s.putBox(-N*8+Xc,-N*10+1+Xc,N*34+Yc,N*43+Yc,N*0+Zc,N*2+Zc);
  s.putBox(-N*8+Xc,-N*10+1+Xc,N*36+Yc,N*42+Yc,-N*2+Zc,N*0+Zc);
  s.putBox(-N*8+Xc,-N*10+1+Xc,N*34+Yc,N*42+Yc,-N*4+Zc,-N*2+Zc);
  s.putBox(-N*8+Xc,-N*10+1+Xc,N*32+Yc,N*42+Yc,-N*6+Zc,-N*4+Zc);
  s.putBox(-N*8+Xc,-N*10+1+Xc,N*33+Yc,N*42+Yc,-N*7-1+Zc,-N*6+Zc);
  
  
  
  //FACE
  
  //s.setColor(255.0,164.0,96.0,1.0);
  //s.putSphere(0, 29, 2, 9);
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putSphere(0+Xc, N*30+Yc, N*3+Zc, N*5);
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putSphere(N*5+Xc, N*32+Yc, N*4+Zc, N*5);
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putSphere(-N*5+Xc, N*32+Yc, N*4+Zc, N*5);
  
  
  //Olhos
  s.cutEllipsoid(N*3+Xc, N*39+Yc, N*7+Zc, N*2-1, N*3-1, N*2);
  s.cutEllipsoid(-N*3+Xc, N*39+Yc, N*7+Zc, N*2-1, N*3-1, N*2);    //CAVIDADE OCULAR
  
  s.setColor(1.0,1.0,1.0,1.0);
  s.putEllipsoid(N*3+Xc, N*39+Yc, N*6+Zc, N*2-1, N*3-1, N*1);
  s.putEllipsoid(-N*3+Xc, N*39+Yc, N*6+Zc, N*2-1, N*3-1, N*1);  //GLOBO OCULAR
  s.putVoxel(N*2+Xc, N*41+Yc, N*7+Zc);
  s.putVoxel(-N*2+Xc, N*41+Yc, N*7+Zc);
  
  s.setColor(30.0/255.0,144.0/255.0,1.0,1.0);
  s.putBox(N*2+Xc, N*4+Xc, N*38+Yc, N*41+Yc, N*8-1+Zc, N*8+Zc);    // IRIS
  s.putBox(-N*2+1+Xc, -N*4+1+Xc, N*38+Yc, N*41+Yc, N*8-1+Zc, N*8+Zc);
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putBox(N*2+Xc, N*4-1+Xc, N*38+Yc, N*41-1+Yc, N*8-1+Zc, N*8+Zc);
  s.putBox(-N*1+Xc, -N*2+Xc, N*38+Yc, N*41-1+Yc, N*8-1+Zc, N*8+Zc);   //PUPILA
  
  
  
  //NARIZ
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(0+Xc, N*36-1+Yc, N*11+Zc, N*3-1, N*3-1, N*3+1);
  
  //Bigode
  
  s.setColor(0.0,0.0,0.0,1.0);
  s.putRing(0+Xc, N*36+Yc, N*6+Zc, N*5+1, N*2-1, M_PI/3.0, 0.0, M_PI/2.0);
  //s.putRing(-3+Xc, N*35+Yc, N*4+Zc, N*5+1, N*2-1, M_PI/3.0, 0.0, M_PI/2.0);
  
  
  // ORELHAS
  
  s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(N*11+Xc, N*36-1+Yc, N*0+Zc, N*3-1, N*3+1, N*2-1, 0.0, 0.0, -M_PI/4.0);
  s.cutEllipsoid(N*11+Xc, N*36-1+Yc, N*2+Zc, N*1, N*3+1, N*2, 0.0, 0.0, -M_PI/4.0);
  
   s.setColor(1.0,164.0/255.0,96.0/255.0,1.0);
  s.putEllipsoid(-N*11+Xc, N*36-1+Yc, N*0+Zc, N*3-1, N*3+1, N*2-1, 0.0, 0.0, M_PI/4.0);
  s.cutEllipsoid(-N*11+Xc, N*36-1+Yc, N*2+Zc, N*1, N*3+1, N*2, 0.0, 0.0, M_PI/4.0);
  
  //CHAPEU MARIO
  
  s.setColor(0.0,1.0,0.0,1.0);
  s.putEllipsoid(0+Xc, N*46+Yc, 0+Zc, N*11, N*7, N*11, M_PI/5.0, 0.0, 0.0);
  s.putEllipsoid(0+Xc, N*43+Yc, -N*6+1+Zc, N*10, N*7, N*9, M_PI/6.0, 0.0, 0.0);
  s.putEllipsoid(0+Xc, N*44+1+Yc, N*8+Zc, N*10, N*2-1, N*8, M_PI/14.0, 0.0, 0.0);
  s.cutEllipsoid(0+Xc, N*43-1+Yc, N*11+Zc, N*10, N*2, N*3, M_PI/14.0, 0.0, 0.0);
  
  s.setColor(1.0,1.0,1.0,1.0);
  s.putCylinder(0+Xc, N*9+Zc, N*50+Yc, N*53+Yc, N*3+1, M_PI/1.8, M_PI/2.0, 0.0);
  s.getLastSolid().translate(0, -N*2, 0);
  
  //Letra L
  
  s.setColor(0.0, 1.0, 0.0, 1.0);
  s.putBox(N*0+Xc,N*1+Xc, N*49+Yc, N*53+Yc, N*10+Zc, N*12+Zc);
  s.putBox(N*1+Xc, N*3+Xc, N*49+Yc, N*50+Yc, N*10+Zc, N*12+Zc);
  
  
  

  
  //-------------------------------------------------------------

  
  //Barriga
  s.setColor(0.0,0.0,1.0,1.0);
  s.putEllipsoid(0+Xc, N*10+Yc, 0+Zc, N*11,N*13, N*10);
  //s.putSphere(0+Xc, N*10+Yc, 0+Zc, N*13);
  
  //Alça macacao
  
  s.putRing(N*7+Xc,N*20+Yc, 0+Zc, N*4, N*2, 0.0, -M_PI/2.0,-M_PI/2.0);
  s.putRing(-N*7+Xc,N*20+Yc, 0+Zc, N*4, N*2, 0.0, -M_PI/2.0,-M_PI/2.0);
  
  //Botões
  
  s.setColor(1.0, 1.0, 0.0, 1.0);
  s.putCylinder(-N*7+Xc,7+Zc,N*20+Yc, N*21+Yc, N*1, M_PI/2.0, 0.0, M_PI/12.0);
  s.putCylinder(N*7+Xc,7+Zc,N*20+Yc, N*21+Yc, N*1, M_PI/2.0, 0.0, M_PI/12.0);
  
  
  
  //Pernas
  s.setColor(0.0,0.0,1.0,1.0);
  s.putCylinder(-N*7+Xc, 0+Zc, N*2+Yc, -N*18+Yc, N*5, 0.0, M_PI/14.0, 0.0);
  s.putCylinder(N*7+Xc, 0+Zc, N*2+Yc, -N*18+Yc, N*5, 0.0, -M_PI/14.0, 0.0);
  
  
  
  // Sapato da esquerda
  s.setColor(64/255.0, 10/255.0, 0/255.0, 1.0);
  s.putEllipsoid(-N*10+Xc, -N*20+Yc, N*3+Zc,  N*4, -N*4 ,N*8, 0.0,0.0, M_PI/10.0);
  
  // Sapato da direita
  s.putEllipsoid(N*10+Xc, -N*20+Yc, N*3+Zc,  N*4, -N*4 ,N*8, 0.0, 0.0, -M_PI/10.0);
  
  // --------------------------------------------------------------------------- //
  
  
  
  // Salvar Arquivo
  s.write("ProjetoFinal.off");
  
  
}
