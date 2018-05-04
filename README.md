[![Build Status](https://travis-ci.org/epfl-lasa/ds_motion_generator.svg?branch=master)](https://travis-ci.org/epfl-lasa/ds_motion_generator)

# ds_motion_generator
---

This package provides a nodified version of DS motion generators. Type of DS:
- analytic point-to-point motion
- analytic limit cycle
- Learned non-linear DS with SEDS parametrization
- Learned non-linear DS with LPV-OPT parametrization
- Learned Locally Active Globally Stable (LAGS) DS with LPV-OPT parametrization

# Installation
Do the following steps:
* In your catkin src directory clone the repository
```
$ git clone https://github.com/epfl-lasa/ds_motion_generator.git
```
* wstool gets all other git repository dependencies, after the following steps you should see extra catkin 
  packages in your src directory.
```
$  wstool init
$  wstool merge ds_motion_generator/dependencies.rosinstall 
$  wstool up 
```
* Query and installs all libraries and packages 
```
$ rosdep install --from-paths . --ignore-src --rosdistro indigo 
```
# Usage
These are the components that you need to run a proper "DS motion generator":

1. Launch file: where you can define  
   1. the name of the input topic (potentially a position signal)
   1. the name of the output topic (potentially a desired velocity signal)
   1. the name of the topic for the filtered output.
   1. the location to the GMM paramaeters (i.e., a yaml file contating Prior, Mu, and Sigma)
   
1. DS config file (config folder)
   1. where you provide the conventional Prio, Mu, Sigma,
   1. In addition, K (number of guassian) and dim (the dimenstion input-output space)
   1. WARNING: There is a transpose compared the previous version. In this version, each row (in Priors and Mu) indicates a guassian, and each column indicates a dimension. 
   
1. Dyanamic parameters (cfg folder)
   1. Wn : speed of the filter
   1. fil_dx_lim : the limit on the velocity of the filter. (Note this is not the limit of the real velocity).
   1. fil_ddx_lim : the limit on the accelarion of the filter. (Same note)
   1. target_{x,y,z} : the position of the attractor.
   1. scaling : simply a multiplier to scale the computed velocities based on SED.
   1. trimmit : simply a threshold to limit the computed velocities based on SED.
   
   
