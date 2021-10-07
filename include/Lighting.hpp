



#ifndef Lighting_HPP
#define Lighting_HPP

#include "Eagle.hpp"
#include "GL/gl.h"

void ToggleLighting(bool on);

class Light {
   GLEnum lnum;
   Vec3 pos;
   EagleColor lcol;
   
   void Toggle(bool on);
   void Toggle(bool on) {
      if (on) {
         glEnable(lnum);
      }
      else {
         glDisable(lnum);
      }
   }
}

#endif // Lighting_HPP
