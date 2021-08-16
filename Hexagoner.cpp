



#include "Eagle/backends/Allegro5Backend.hpp"
#include "Eagle.hpp"
#include "allegro5/allegro.h"


#include "Hexagon3D.hpp"
#include "SpatialInfo.hpp"
#include "Orient.hpp"
#include "Vec3.hpp"
#include "Camera.hpp"

int main(int argc , char** argv) {
   
   Allegro5System* a5sys = GetAllegro5System();
   
   int flags = EAGLE_FULL_SETUP;
   int ret = a5sys->Initialize(flags);
   if (ret != flags) {
      EagleWarn() << "Failed to initialize some subsystems. Proceeding anyway." << std::endl;
   }
   
   EagleGraphicsContext* splashwin = a5sys->CreateGraphicsContext("Main window" , 1024 , 768 , EAGLE_OPENGL | EAGLE_WINDOWED | EAGLE_NOFRAME);
   
   
   
   return 0;
};