### Running the demo
1. Build the package
    ```sh
    $ cd catkin_ws
    $ catkin_make
    ```
2. Run the master.
    ```sh
    $ roscore
    ```
3. Run fake odometry data.
    ```sh
    $ rosrun fastrtps_ros odom_pub
    ```
4. Run ROS-DDS node.
    ```sh
    $ rosrun fastrtps_ros dds_bridge r2d
    ```
5. Run DDS-ROS node.
    ```sh
    $ rosrun fastrtps_ros dds_bridge d2r
    ```
6. Check if odom is republished to odom2.
    ```sh
    $ rostopic echo odom2
    ```


### Developing your own DDS-ROS package using the code generator

1. Change the IDL file based on the message you want to pub-sub

2. Generate the codes.
    ```sh
    $ ./gencodes.sh
    ```
3. Build the package.
    ```sh
    $ cd catkin_ws
    $ catkin_make
    ```
4. Code!
