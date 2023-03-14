# ds_motion_generator
---
This package provides a nodified version of DS motion generators. Type of DS:
- **Analytically parameterized DS** for simple motions used in [1], such as
  - linear motions, point-to-point oscillatory motions and swiping as below
  <p align="center"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/linearMotion.gif" width="250"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/PPOscilateMotion.gif" width="250"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/SwipeMotion.gif" width="250"></>
    
- **Non-linear DS learned from demonstrations** with the following approaches  
  - **se-DS parametrization [2]**. For testing, we provide a couple of pre-learned models of curvilinear motion with different targets as used in [1]; e.g. Push-Down Motion, Curve-Left Motion, Curve-Right Motion and Free WS (workspace) motion
 <p align="center"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/seDS_pushDown.gif" width="200"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/seDS_curveLeft.gif" width="200"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/seDS_curveRight.gif" width="200"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/seDS_freeWS.gif" width="200"></>
  
  - **lpv-DS parametrization [3]**.  For testing, we provide a couple of pre-learned models of non-linear, non-monotic motions used in a variety of tasks in [3]; e.g. sink motion, via-point motion, CShape motion  
<p align="center"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/sink-DS.gif" width="250"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/viapoint-DS.gif" width="250"><img src="https://github.com/epfl-lasa/ds_motion_generator/blob/nadia/img/cshape-DS.gif" width="250"></>
  
- TODO
