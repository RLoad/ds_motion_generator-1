/*
 * Copyright (C) 2018 Learning Algorithms and Systems Laboratory, EPFL, Switzerland
 * Authors: Mahdi Khoramshahi and Nadia Figueroa
 * email:   {mahdi.khoramshahi,nadia.figueroafernandez}@epfl.ch
 * website: lasa.epfl.ch
 *
 * This work was supported by the European Communitys Horizon 2020 Research and Innovation 
 * programme ICT-23-2014, grant agreement 644727-Cogimon and 643950-SecondHands.
 *
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
 */

#include "ros/ros.h"
#include "test_mini_code.h"


#include <vector>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_mini_code_node");

  ros::NodeHandle nh;
  double frequency = 100.0;

  //--- Parameters in launch
    std::string input_pose_name;
    std::string input_vel_name;
    std::string input_force_name;
    std::string input_joint_state_name;
    std::string output_vel_name;
    std::string output_filtered_vel_name;
    std::string output_damping_eig_topic_name;
    std::string output_joint_position_name;
    bool brecord_or_not(false);
    bool record_1_robotdemo_0_humandemo(false);

  //---- parameters in yaml
    std::vector<double> target;


  //---- input output and paremeter in launch
    if (!nh.getParam("input_pose_name", input_pose_name))   {
      ROS_ERROR("Couldn't retrieve the topic name for the input. ");
      // return -1;
    }

    if (!nh.getParam("input_vel_name", input_vel_name))   {
      ROS_ERROR("Couldn't retrieve the topic name for the input. ");
      // return -1;
    }

    if (!nh.getParam("input_force_name", input_force_name))   {
      ROS_ERROR("Couldn't retrieve the topic name for the input force. ");
      // return -1;
    }

    if (!nh.getParam("input_joint_state_name", input_joint_state_name))   {
      ROS_ERROR("Couldn't retrieve the topic name for the input force. ");
      // return -1;
    }

    if (!nh.getParam("output_vel_name", output_vel_name))   {
      ROS_ERROR("Couldn't retrieve the vel name for the orign output. ");
      // return -1;
    }

    if (!nh.getParam("output_filtered_vel_name", output_filtered_vel_name))   {
      ROS_ERROR("Couldn't retrieve the vel name for the filtered output. ");
      // return -1;
    }

    if (!nh.getParam("output_damping_eig_topic_name", output_damping_eig_topic_name))   {
      ROS_ERROR("Couldn't retrieve the damping eig name for the output. ");
      // return -1;
    }

    if (!nh.getParam("output_joint_position_name", output_joint_position_name))   {
      ROS_ERROR("Couldn't retrieve the damping eig name for the output. ");
      // return -1;
    }

    if (!nh.getParam("record_or_not", brecord_or_not))   {
      ROS_ERROR("Couldn't retrieve the record or not command. ");
      // return -1;
    }

    if (!nh.getParam("record_1_robotdemo_0_humandemo", record_1_robotdemo_0_humandemo))   {
      ROS_ERROR("Couldn't retrieve the record_1_robotdemo_0_humandemo. ");
      // return -1;
    }

  //---- parameter in yaml
    if (!nh.getParam("target", target))   {
      ROS_ERROR("Couldn't retrieve the target. ");
      // return -1;
    }
 

  test_mini_code test_mini_code(
                      //--- parem in node
                        nh, frequency,
                      //--- param in lanuch
                        input_pose_name,
                        input_vel_name,
                        input_force_name,
                        input_joint_state_name,
                        output_vel_name,
                        output_filtered_vel_name,
                        output_damping_eig_topic_name,
                        output_joint_position_name,
                        brecord_or_not,
                        record_1_robotdemo_0_humandemo,
                      //--- param in yaml
                        target);
  if (!test_mini_code.Init()) {
    return -1;
  }
  else {
    test_mini_code.Run();
  }

  return 0;
}
