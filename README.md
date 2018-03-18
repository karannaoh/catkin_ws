# To execute the code(linux)
**Important**- Sourcing the setup file in all terminals which you use
 ` directory_To_workspace/catkin_ws/devel/setup.bash`.

-> Install ROS (http://wiki.ros.org/kinetic/Installation)
--> Either you can create your own catkin_ws and follow
- `cd ~`
- `git clone https://github.com/karannaoh/catkin_ws`
- `. ~/catkin_ws/devel/setup.bash`
- `cd catkin_ws`
- `catkin_make`
- `roslaunch intern_task/launch/intern_task.launch`

-->  Else clone the whole workspace from git
- create catkin workspace following http://wiki.ros.org/catkin/Tutorials/create_a_workspace
- create ros pakage http://wiki.ros.org/ROS/Tutorials/CreatingPackage add std_msgs rospy roscpp as dependencies.
- download all cpp file from https://github.com/karannaoh/catkin_ws/tree/master/src/intern_task/src and mv them to workspace/src/pakage_you_created/scr
- download file form 
- download https://github.com/karannaoh/catkin_ws/blob/master/intern_task/launch/intern_task.launch in folder workspace/pakage_name/launch
- in workspace ` catkin_make`
- then `roslaunch pakage_name inten_task.launcher`

# note:- 
 - To se messages from server type `rostopic echo /server_said` in new terminal
 - To se messages from bots type `rostopic echo /bot_said` in new terminal
