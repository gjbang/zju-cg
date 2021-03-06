//wrap the file with the version
#local Temp_version = version;
#version 3.7;
//==================================================
//POV-Ray Main scene file
//==================================================
//This file has been created by PoseRay v3.13.29.645
//3D model to POV-Ray/Moray Converter.
//Author: FlyerX
//Email: flyerx_2000@yahoo.com
//Web: https://sites.google.com/site/poseray/
//==================================================
//Files needed to run the POV-Ray scene:
//porsche_POV_main.ini (initialization file - open this to render)
//porsche_POV_scene.pov (scene setup of cameras, lights and geometry)
//porsche_POV_geom.inc (geometry)
//porsche_POV_mat.inc (materials)
// 
//==================================================
//Model Statistics:
//Number of triangular faces..... 7322
//Number of vertices............. 4099
//Number of normals.............. 5380
//Number of UV coordinates....... 0
//Number of lines................ 0
//Number of materials............ 5
//Number of groups/meshes........ 18
//Number of subdivision faces.... 0
//Bounding Box....... from x,y,z=(-25.25757,-16.901169,-57.002853)
//                      to x,y,z=(25.25757,16.901169,57.002853)
//                 size dx,dy,dz=(50.51514,33.802338,114.005706)
//                  center x,y,z=(0,0,0)
//                       diagonal 129.196278677229
//Surface area................... 18019.5891567487
//             Smallest face area 0.00109635897341339
//              Largest face area 660.240116687143
//Memory allocated for geometry: 682 KBytes
// 
//==================================================
//IMPORTANT:
//This file was designed to run with the following command line options: 
// +W320 +H240 +FN +AM1 +A0.3 +r3 +Q9 +C -UA +MV3.7
//if you are not using an INI file copy and paste the text above to the command line box before rendering
 
 
global_settings {
  //This setting is for alpha transparency to work properly.
  //Increase by a small amount if transparent areas appear dark.
   max_trace_level 15
   adc_bailout 0.01
   assumed_gamma 1
 
}
#include "porsche_POV_geom.inc" //Geometry
 
//CAMERA PoseRayCAMERA
camera {
        perspective
        up <0,1,0>
        right -x*image_width/image_height
        location <0,0,151.392557354459>
        look_at <0,0,150.392557354459>
        angle 57.4526618640413 // horizontal FOV angle
        rotate <0,0,-6.83256911464139> //roll
        rotate <-28.2487991106262,0,0> //pitch
        rotate <0,-130.067584111011,0> //yaw
        translate <0,0,0>
        }
 
//PoseRay default Light attached to the camera
light_source {
              <0,0,258.392557354459> //light position
              color rgb <1,1,1>*1.6
              parallel
              point_at <0,0,0>
              rotate <0,0,-6.83256911464139> //roll
              rotate <-28.2487991106262,0,0> //elevation
              rotate <0,-130.067584111011,0> //rotation
             }
 
//Background
background { color srgb <1,1,1>  }
 
//Assembled object that is contained in porsche_POV_geom.inc with no SSLT components
object{
      porsche_
      }
 
//restore the version used outside this file
#version Temp_version;
//==================================================
