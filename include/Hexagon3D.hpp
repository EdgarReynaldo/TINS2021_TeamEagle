



#ifndef Hexagon3D_HPP
#define Hexagon3D_HPP


#include "Hexagon.hpp"



class Hexagon3D {
   Hexagon proto;
   double inner;
   double outer;
   double depth;
   
   std::vector<ALLEGRO_VERTEX> verts;
   std::vector<ALLEGRO_VERTEX> faces;
///   std::vector<ALLEGRO_VERTEX> triangles;
   
public :
   
   Hexagon3D(double iradius , double oradius , double zdepth);
   void BuildHexagon(double iradius , double oradius , double zdepth);
   void DrawHexagon();

   
   
   
};



#endif // Hexagon3D_HPP
