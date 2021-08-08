



#ifndef Hexagon3D_HPP
#define Hexagon3D_HPP

class Hexagon3D {
   Hexagon proto;
   double inner;
   double outer;
   double depth;
   
   std::vector<ALLEGRO_VERTEX> verts;
   std::vector<ALLEGRO_VERTEX> faces;
   std::vector<ALLEGRO_VERTEX> triangles;
   
public :
   
   Hexagon3D(double iradius , double oradius , double zdepth);
   Hexagon3D(double iradius , double oradius , double zdepth) :
      proto(),
      inner(0.0),
      outer(0.0),
      depth(0.0),
      verts(4*6 , ALLEGRO_VERTEX()),/// [4 rings][6 vertices]
      faces(4*6*4 , ALLEGRO_VERTEX()),/// [4 sides][6 faces][4 vertices]
      triangles(4*6*5 , ALLEGRO_VERTEX())/// [4 sides][6 faces][5 vertices] (triangle fan)
   {
      BuildHexagon(iradius , oradius , zdepth);
   }
   
   void BuildHexagon(double iradius , double oradius , double zdepth);
   void BuildHexagon(double iradius , double oradius , double zdepth) {
      if (iradius < 0.0) {iradius = 0.0;}
      if (oradius < 1.0) {oradius = 1.0;}
      if (zdepth < 1.0) {zdepth = 1.0;}
      inner = iradius;
      outer = oradius;
      depth = zdepth;
      Hexagon hi(2.0*inner);
      Hexagon ho(2.0*outer);\
      std::vector iv = hi.GetVerts();
      std::vector ov = ho.GetVerts();
      for (unsigned int vertex = 0 ; vertex < 6 ; ++vertex) {
         ALLEGRO_VERTEX v1,v2,v3,v4,vi,vo;
         vi = iv[vertex];
         vo = ov[vertex];
         v1 = vi;
         v2 = vi;
         v3 = vo;
         v4 = vo;
         v1.z = -depth/2.0;
         v2.z = depth/2.0;
         v3.z = -depth/2.0;
         v4.z = depth/2.0;
         verts[4*vertex + 0] = v1;
         verts[4*vertex + 1] = v2;
         verts[4*vertex + 2] = v3;
         verts[4*vertex + 3] = v4;
      }
   }
   
      
   
   
   
   
};



#endif // Hexagon3D_HPP