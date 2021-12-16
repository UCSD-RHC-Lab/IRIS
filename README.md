# *IRIS*
*Iris* is a low-cost open hardware/open software telemedical robot platform, designed to be usable, accessible, robust, and well-situated in the emergency medicine ecosystem.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146089012-16246c8c-4e45-4cd3-8771-1f8935f4be47.jpg" />
 <img src="https://user-images.githubusercontent.com/11902748/146089237-e87e6488-366e-4980-b200-09360063f84c.JPG" />
</p>

To learn more, please visit our wiki.

If you use any aspect of our work, we ask that you cite our paper:

S. Matsumoto, S. Moharana, N. Devanagondi, L. C. Oyama, and L. Riek. Iris: A Low-Cost Telemedicine Robot to Support Healthcare Safety and Equity During a Pandemic. EAI PervasiveHealth. EAI, 2021.

Bibtex format:

@inproceedings{matsumoto2021iris,
  title={Iris: A Low-Cost Telemedicine Robot to Support Healthcare Safety and Equity During a Pandemic},
  author={Matsumoto, Sachiko and Moharana, Sanika and Devanagondi, Nimisha and Oyama, Leslie C. and Riek, Laurel D.},
  booktitle={EAI PervasiveHealth},
  year={2021}
}

=== License ===

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.


_____________________________________________________________________________________________________________________________________________________________________

# *Iris* Hardware Guide

## Table of contents

1. Introduction
2. Basic Components
    1. Possible Add-Ons
3. Building the Robot
    1. Build the Robot to the Appropriate Height
    2. Mount the Laptop Box
    3. Mount the Tablet and Webcam
    4. Connect the Components
    5. Add the Banner Costume
4. Current Challenges/Future Improvements

## 1. Introduction

*Iris* is a low-cost open hardware/open software telemedical robot platform. We designed Iris to be easily customizable to different clinical contexts so others can adapt the system to their own local needs.

We developed *Iris* using low-cost hardware from our lab. We provide the specifications here, though many components can be interchanged with different alternatives. Additionally, the system can be customized for different needs (e.g., adding a light that can be turned on and off for pupillary response tests).

<p align=center>
 <img src="https://user-images.githubusercontent.com/11902748/146090486-9cc8523a-88a8-4404-a7de-6c6409abf0ac.png" />
</p>
<p align="center">
 <b>Fig. 1</b> The basic hardware components of <em>Iris</em>, including a two-wheeled mobile robot with a computer, a local router, a tablet, and a wide-angle camera mounted four feet high on the robot.
</p>

## 2. Basic Components

*Iris's* basic components are shown in Fig. 1. It consists of a two-wheeled mobile robot base with a computer, a local router, tablets with a mount, and a wide angle camera with a mount. It is helpful if the tablet of the robot (e.g., the remote user's "head") is at the height of the person interacting with the robot (e.g., a patient) to enable the interactant to see the operator's face and to enable the operator to easily see the interactant.

This table shows each of the components, their motivation, and the specific hardware we used (as of 2020).

| Component | Required/Optional | Estimated Cost (as of 2020) | Why Needed | What We Used |
| --------- | ----------------- | --------------------------- | ---------- | ------------ |
| Two-wheeled mobile robot + structure to make the robot taller| Required | $700 | Mobility | Turtlebot 2 with a Kobuki base + platforms to make the robot taller ([link](https://dabit.industries/collections/turtlebot-parts)) |
| Depth sensor | Optional | $150 | Mapping and autonomous navigation | Astra Pro depth sensor (not yet implemented) ([link](https://shop.orbbec3d.com/Astra-Pro)) |
| Computer running Ubuntu 18.04 with ROS Melodic | Required | $380 | Running the robot base | Lenovo ThinkPad 11e running Ubuntu 18.04 with ROS Melodic ([link](https://www.lenovo.com/ao/en/laptops/thinkpad/11e-series/c/11e-series)) |
| Portable router | Required | $62 | 1) In case your robot will be somewhere without internet access or 2) you prefer to keep your robot on a private network to help improve security | GL-AR750S-Ext portable router ([link](https://store.gl-inet.com/products/gl-ar750s-ext-gigabit-travel-router)) |
| Control tablet | Required | $\geq$ $50 | Control the robot through the interface | Samsung Galaxy Tab A ([link](https://www.samsung.com/us/mobile/tablets/galaxy-tab-a/)) |
| Tablet case | Required | ~$20 | Protect the tablet | Durable case on Amazon.com |
| Tablets for video call | Optional | Varies | Communicate with the interactants | Provided by our emergency department (control tablet may double as one of these) |
| Tablet mount | Required | $35 | Hold the tablet | Arkon TAB188L22 tablet mount ([link](https://www.arkon.com/product/TAB188L22-car-mount-ipad-tablet-seat-bolt.html)) |
| Wide angle webcam | Required | ~$30 | Provide video and situational awareness to operator | 1080p wide angle webcam on Amazon.com |
| Webcam mount | Required | $21 | Hold the webcam | Acetaken C920WM-001 webcam wall mount ([link](https://www.amazon.com/Webcam-Mount-Logitech-Stand-C922x/dp/B07GVJMWFF)) |
| Nuts/bolts/washers for mounting | Required | ~$5-10 | Mount everything to the robot | M4 hex nuts/bolts/washers |
| Laminated instruction cards | Optional | ~$5-10 | Provide instructions for robot use and cleaning| Laminated printed paper cards |
| Plastic resin box | Optional | ~$4/box | Secure and protect the laptop | Whitmore plastic document boxes ([link](https://www.amazon.com/gp/product/B004S6QSB2/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)) |
| Laminate | Optional | ~$0.19/sheet | Make the Turtlebot platforms easier to clean by covering holes | Amazon Basics plastic laminating sheets ([link](https://www.amazon.com/gp/product/B01LZUEX07/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&th=1)) |
| Costume | Optional | ~$37 | Convey robot's purpose to interactants and bystanders | Printed vinyl banner ([link](48HourPrint.com)) |

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146093309-7ceb6120-1670-44e1-a5e6-541f8546ac18.jpg" />
</p> 
<p align="center"> 
 <b>Fig. 2</b> <em>Iris</em> robot with banner and laptop in the box.
</p>

### 2.i. Possible Add-Ons

#### Costume (Vinyl Banner)
 
Beyond the basic components listed above, we added a few extra components. We printed a vinyl banner and secured it around the robot with zip ties (see Fig. 2). We designed the banner to look like scrubs, with a stethoscope on the front. We printed "Tele-Medicine Robot" in large letters across the back, along with the UCSD Health Systems logo and our lab logo, to make the purpose of the robot clear (Fig. 3).

We ordered the banner from 48HourPrint.com. The banner's dimensions were 38"x22".

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146093449-c52c92ec-4e2c-4113-a9e2-37ca8b7f5997.png" />
</p>
<p align="center">
 <b>Fig. 3</b> Image for the banner we made for <em>Iris</em>. We designed the banner to have a stethoscope and to look similar to the scrubs healthcare workers in our emergency department wear to indicate to patients what the robot's purpose was. We also wrote "Tele-Medicine Robot" in large letters on the back to indicate its purpose.
</p>

Furthermore, we attached laminated cards with basic start-up and shut-down procedures and cleaning procedures, so users would have easy access to instructions if they were unfamiliar with the system or forgot how to do something.

#### Resin Box for Laptop

We also put the laptop in a plastic resin box lined with foam (except where the laptop vents were located) with cut-outs for the necessary ports. The box also held the portable router and a USB hub we used, since our laptop did not have as many USB ports as we needed. This made the system easier to clean and enabled us to secure the laptop on the robot by mounting the box with bolts.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146093582-63495d26-cb5f-4489-b399-58bb50a5c77c.JPG" />
</p>
<p align="center">
 <b>Fig. 4</b> The plastic resin box we used to house the laptop. Laminated cards instructed clinicians where to plug things in.
</p>

#### Laminate for cleaning

We put laminate over the Turtlebot platforms to cover the small holes in them. The infection control department at our hospital suggested we do this to make the robot easier to clean.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146093792-98a6b5cd-0a89-4446-b5d7-f80699154180.JPG" />
</p>
<p align="center">
 <b>Fig. 5</b> We laminated the Turtlebot platforms to make cleaning the robot easier.
</p>

#### Additional Sensors

While we did not use this in our study, we also mounted a Asus Xtion Pro depth sensor near the base of the robot. In the future, we plan to use this to help localize the robot so we can show a map with the robot's location on the interface. It also could be used to assist users in avoiding obstacles or for autonomous navigation.

## 3. Building the Robot

These instructions assume you are using the same components we did.

### 3.i. Build the Robot to the Appropriate Height

Use extra (possibly laminated) Turtlebot platforms and aluminum rods to build the robot up to the approximate height of beds in your hospital. Note that if you make it too tall, it may become unstable and more likely to tip over. Our highest platform was approximately 30 inches high.

If using laminated platforms, you will need to cut the laminate over the holes in the platform where you want to mount other components, such as the webcam and tablet. Simply cutting a small "X" in the laminate should be sufficient.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146094712-15f0b8b0-1575-4850-9e30-145736ae90c7.JPG" />
</p>
<p align="center">
 <b>Fig. 6</b> Use the Turtlebot poles and (laminated) platforms to build up the robot to the appropriate height.
</p>

### 3.ii. Mount the Laptop Box

If using a box to hold the laptop, cut holes in the bottom that align with holes in the Turtlebot platform where you will mount it. We recommend mounting it on one of the bottom platforms to make the robot more stable. The more weight there is towards the top of the robot, the easier it will be to tip it over.

Also cut holes in the sides of the box that align with the laptop ports (including USB ports, the charging port, power button, etc.). We needed to use a USB hub, so we cut an extra hole in the side of the box to enable us to feed cords to the hub. Cut a hole in the back or bottom of the box where the laptop vent is.

Mount the box to the Turtlebot platform with M4 nuts, bolts, and washers. You may also glue some foam or other material to the box to give the laptop some padding, but make sure not to block the laptop's vents.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146101591-0af5b97d-e7b2-4ef1-8696-61cf00bded1f.JPG" />
</p>
<p align="center">
 <b>Fig. 7</b> Plastic resin box with foam for padding and holes cut for laptop ports and vents.
</p>

### 3.iii. Mount the Tablet and Webcam

Mount the tablet and webcam mounts to the top Turtlebot platform with M4 nuts, bolts, and washers. We mounted the tablet towards the back of the platform and the webcam near the front. Note that the mounting holes may not all align with the holes in the Turtlebot platforms, but you should be able to get at least two to align. Both mounts we used can be adjusted to optimize the angle of the webcam and tablet for different purposes.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146101943-c0a18e0f-681f-4b1f-ace2-bb57cc9968e1.JPG" />
</p>
<p align="center">
 <b>Fig. 8</b> We put the camera mount near the front of the robot and the tablet mount near the back.
</p>

### 3.iv. Connect the Components

Place the laptop in the box and plug in the Turtlebot base and webcam cords to the appropriate ports. Plug in the portable router (to power it) and place it in the box along with the laptop.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146102058-776944f0-8306-4518-8ed2-e38efd832c40.JPG" />
</p>
<p align="center">
 <b>Fig. 9</b> Connect components. We also added labels on the cords to clearly indicate which port each cable should be plugged into.
</p>

### 3.v. Add the Banner Costume

If using a banner to indicate the robot's purpose, wrap the banner around the Turtlebot platforms and secure it with grommets and zip ties.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146102134-f3458de9-0f60-46a8-a422-07e1e6dbd7cf.JPG" />
</p>
<p align="center">
 <b>Fig. 10</b> We used grommets and zip ties to secure the banner to the robot.
</p>

## 4. Current Challenges/Future Improvements

Using a local router that is not connected to the internet makes the connection more secure and helps protect patient privacy. However, the local router signal is somewhat limited. In our ED, the signal still worked about 20-30 feet away from the operator, around a corner and through a door. However, beyond this, the signal deteriorated, and the controls became very laggy, making it difficult to control the robot. We are exploring other options for future deployments, such as integrating the robot into the hospital's existing WiFi infrastructure, to enable Iris to be operated from further away.


_____________________________________________________________________________________________________________________________________________________________________

# *Iris* Software Guide

## 1. Getting Started

*Iris* runs on [Ubuntu 18.04](https://old-releases.ubuntu.com/releases/18.04.5/) with [ROS Melodic](http://wiki.ros.org/melodic). It uses Flask with Python for the web interface.

To run *Iris's* interface, download the ROS package in this repo into a [ROS workspace](http://wiki.ros.org/catkin/Tutorials/create_a_workspace).

Make sure the robot's laptop and control tablet are on the same WiFi network (see [hardware guide](TODO_HARDWARE_GUIDE_HERE)).

## 2. Running the robot's teleoperation and interface programs (manual)

Turn on the robot, and on the robot's laptop, run the following commands:

```
roscore
roslaunch turtlebot_bringup minimal.launch
roslaunch autobot_main main.launch
rosrun web_teleop app.py
```

This will start the teleoperation and interface programs.

## 3. Running the robot's teleoperation and interface programs (automatic)

If you would like the robot to automatically start up whenever someone logs into the laptop, you can make a [launch file](http://wiki.ros.org/catkin/Tutorials/create_a_workspace) with the above commands in the web_teleop package in the *Iris* workspace. A launch file is an easy way to run multiple ROS nodes.

At the end of the `.bashrc` file in the home directory, add the following code to source the ROS workspace where the Iris package is and launch the launch file:

```
source <path_to_ROS_workspace>/Iris_workspace/devel/setup.bash
roslaunch web_teleop <launch_file_name>
```
<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146137291-4734af5c-e940-49a2-a0aa-900d37081366.JPG" />
</p>

You also need the terminal to come up automatically. To do this, on the robot laptop:

1. Search the applications for "Startup Applications," and click on the Startup Applications option.
<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146137472-4a5d140c-1ce7-428c-ab80-2aff802461c4.JPG" />
</p>

2. Click "Add."
<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146137676-ecd4bc13-36d6-4677-b5cc-1af29d9a5c0a.png" />
</p>

3. Type "Terminal" in the name field, and type "gnome-terminal" in the command field.
<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146137858-fce7b28d-b991-4a08-bacb-474c472265a0.JPG" />
</p>

4. Click "Add." You should see the terminal listed in the "Additional startup programs" list, as shown below.
<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146138010-11c25379-d4c1-4809-ad41-aea6155a9fbd.JPG" />
</p>

## 4. Accessing the control interface

To access the interface, open Firefox on the control tablet.

Go to https://0.0.0.0:5002/ 

You should see the interface in the window and be able to control the robot.

<p align="center">
 <img src="https://user-images.githubusercontent.com/11902748/146138270-46eb01c7-70c9-4625-8c53-e3f0469f64d2.png" />
</p>
