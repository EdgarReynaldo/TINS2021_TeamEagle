

#include "Eagle.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"
#include "allegro5/allegro.h"
#include "allegro5/allegro_windows.h"



#include "Hexagon3D.hpp"
#include "SpatialInfo.hpp"
#include "Orient.hpp"
#include "Vec3.hpp"
#include "Camera.hpp"

#include <dwmapi.h>
#include <windows.h>
#include "GL/gl.h"


HRESULT Blur(EagleGraphicsContext* win , bool do_blur);

int main(int argc , char** argv) {
   
   (void)argc;
   (void)argv;
   
   Allegro5System* a5sys = GetAllegro5System();
   int sw = 800;
   int sh = 600;
   
   int flags = EAGLE_FULL_SETUP;
   int ret = a5sys->Initialize(flags);
   if (ret != flags) {
      EagleWarn() << "Failed to initialize some subsystems. Proceeding anyway." << std::endl;
   }
   
   EagleGraphicsContext* splashwin = a5sys->CreateGraphicsContext("Main window" , sw , sh , EAGLE_OPENGL | EAGLE_WINDOWED | EAGLE_NOFRAME);
   
   EAGLE_ASSERT(splashwin && splashwin->Valid());
   
   Blur(splashwin , true);
   
   
   splashwin->Clear(EagleColor(0,0,0,0));
   
   Hexagon3D h1(2 , 3 , 2);
   
   
   Camera cam(Vec3(0.0 ,  0.0 , -5.0) , Orient(Vec3(0 , 0 , 1)) , 90.0 , 4.0/3.0);
   
   bool redraw = true;
   bool quit = false;
   
   
   
   while (!quit) {
      if (redraw) {
         splashwin->DrawToBackBuffer();

         glClearColor(0.0f,0.0f,0.0f,0.0f);
         glClear(GL_COLOR_BUFFER_BIT);

         cam.Setup3D(false);

         glEnable(GL_LIGHTING);
         glEnable(GL_LIGHT0);


         h1.DrawHexagon();

         splashwin->FlipDisplay();

         redraw = false;
      }
      do {
         EagleEvent e = a5sys->WaitForSystemEventAndUpdateState();
         if (e.type == EAGLE_EVENT_TIMER) {
            redraw = true;
         }
         if (e.type == EAGLE_EVENT_DISPLAY_CLOSE) {
            quit = true;
         }
         if (e.type == EAGLE_EVENT_KEY_DOWN && e.keyboard.keycode == EAGLE_KEY_ESCAPE) {
            quit = true;
         }
      } while (!a5sys->UpToDate());
   }
   
   return 0;
};




HRESULT Blur(EagleGraphicsContext* win , bool do_blur) {
   
    
    ALLEGRO_DISPLAY* a5display = dynamic_cast<Allegro5GraphicsContext*>(win)->AllegroDisplay();
    HWND hwnd = al_get_win_window_handle(a5display);
   
    HRESULT hr = S_OK;

    // Create and populate the blur-behind structure.
    DWM_BLURBEHIND bb = {0};

    // Specify blur-behind and blur region.
    bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
    bb.fEnable = do_blur;
    bb.hRgnBlur = NULL;

     hr = DwmEnableBlurBehindWindow(hwnd, &bb);
     if (SUCCEEDED(hr))
     {}
     return hr;
}
