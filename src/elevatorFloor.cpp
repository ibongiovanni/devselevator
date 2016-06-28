#include "elevatorFloor.h"
//nextFloor
    int pf(double h) {
      if (h = 0) { return 0; }
      if (( 0 < h) && ( h <= 2)) { return 0; }
      if (( 2 < h) && ( h <= 4)) { return 2; }
      if (( 4 < h) && ( h <= 6)) { return 4; }
      if (( 6 < h) && ( h <= 8)) { return 6; }
      if (( 8 < h) && ( h <= 10)) { return 8; }
      if (( 10 < h) && ( h <= 12)) { return 10; }
      if (( 12 < h) && ( h <= 14)) { return 12; }
      if (( 14 < h) && ( h <= 16)) { return 14; }
      if (( 16 < h) && ( h <= 18)) { return 16; }
   }
//previousFloor
    int nf(double h) {
      if (( 0 <= h) && ( h < 2)) { return 2; }
      if (( 2 <= h) && ( h < 4)) { return 4; }
      if (( 4 <= h) && ( h < 6)) { return 6; }
      if (( 6 <= h) && ( h < 8)) { return 8; }
      if (( 8 <= h) && ( h < 10)) { return 10; }
      if (( 10 <= h) && ( h < 12)) { return 12; }
      if (( 12 <= h) && ( h < 14)) { return 14; }
      if (( 14 <= h) && ( h < 16)) { return 16; }
      if (( 16 <= h) && ( h < 18)) { return 18; }
      if (h = 18) { return 18; }   
   }   
  
