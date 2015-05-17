include <../../Lada/fabricate/lada.scad>
$fn = 50;
inch = 25.4;
module v1(){
  D = 54;
  difference(){
    union(){
      cylinder(d=D, h=10);
      rotate(v=[0, 0, 1], a=  0)translate([D/2, 0, 0])cylinder(r=6, h=10);
      rotate(v=[0, 0, 1], a=120)translate([D/2, 0, 0])cylinder(r=6, h=10);
      rotate(v=[0, 0, 1], a=240)translate([D/2, 0, 0])cylinder(r=6, h=10);
    }
    translate([0, 0, -.1])cylinder(d1=50, d2=35, h=8);
    translate([0, 0, -1])cylinder(d=35, h=12);
    rotate(v=[0, 0, 1], a=  0)translate([D/2, 0, -1])cylinder(d=3.5, h=12);
    rotate(v=[0, 0, 1], a=120)translate([D/2, 0, -1])cylinder(d=3.5, h=12);
    rotate(v=[0, 0, 1], a=240)translate([D/2, 0, -1])cylinder(d=3.5, h=12);
  }
}


module v2(){
  D = 54;
  d = 45;
  difference(){
    union(){
      cylinder(d=D, h=4);
      rotate(v=[0, 0, 1], a=  0)translate([D/2, 0, 0])cylinder(r=4, h=4);
      rotate(v=[0, 0, 1], a=180)translate([D/2, 0, 0])cylinder(r=4, h=4);
    }
    translate([0, 0, -1])cylinder(d=d, h=6);
    translate([0, 0, -1])cylinder(d=50, h=3);
    translate([0, 0, -1])rotate(v=[0, 0, 1], a=  0)translate([D/2, 0, 0])cylinder(d=3.5, h=6);
    translate([0, 0, -1])rotate(v=[0, 0, 1], a=180)translate([D/2, 0, 0])cylinder(d=3.5, h=6);
  }
}

D = 54;
d = 45;
S = 62.435/2;
  difference(){
    union(){
      cylinder(d=D, h=4);
      translate([-S, -S, 0])rotate(v=[0, 0, 1], a=0)inside_corner(LENGTH, THICKNESS, OFFSET);
      translate([ S, -S, 0])rotate(v=[0, 0, 1], a=90)inside_corner(LENGTH, THICKNESS, OFFSET);
      translate([ S,  S, 0])rotate(v=[0, 0, 1], a=180)inside_corner(LENGTH, THICKNESS, OFFSET);
      translate([-S,  S, 0])rotate(v=[0, 0, 1], a=270)inside_corner(LENGTH, THICKNESS, OFFSET);
    }    
    translate([0, 0, -1])cylinder(d=d, h=6);
    translate([0, 0, -1])cylinder(d=50, h=3);
  }
