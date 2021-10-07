




void ToggleLight(bool on) {
   if (on) {
      glEnable(GL_LIGHTING);
   }
   else {
      glDisable(GL_LIGHTING);
   }
}


//         Vec3 lp = cam.Pos() + Vec3(2.0 , 0.0 , 0.0)
//         GLFloat lightpos[] = {lp.x , lp.y , lp.z , 0.0};
//         glLightfv(GL_LIGHT0 , GL_POSITION , lightpos);
