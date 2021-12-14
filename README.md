# *IRIS*
*Iris* is a low-cost open hardware/open software telemedical robot platform, designed to be usable, accessible, robust, and well-situated in the emergency medicine ecosystem.

![The Iris System](https://user-images.githubusercontent.com/11902748/146089012-16246c8c-4e45-4cd3-8771-1f8935f4be47.jpg)
![logos](https://user-images.githubusercontent.com/11902748/146089237-e87e6488-366e-4980-b200-09360063f84c.JPG)

To learn more, please visit our wiki.

If you use any aspect of our work, we ask that you cite our paper:

S. Matsumoto, S. Moharana, N. Devanagondi, L. C. Oyama, and L. Riek. Iris: A Low-Cost Telemedicine Robot to Support Healthcare Safety and Equity During a Pandemic. EAI PervasiveHealth. EAI, 2021.

=== License ===

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.


_____________________________________________________________________________________________________________________________________________________________________

# *Iris* Hardware Guide

## Table of contents

1. Introduction
2. Basic Components
    2.1. Possible Add-Ons
3. Building the Robot
    3.1. Build the Robot to the Appropriate Height
    3.2. Mount the Laptop Box
    3.3. Mount the Tablet and Webcam
    3.4. Connect the Components
    3.5. Add the Banner Costume
4. Current Challenges/Future Improvements

## 1. Introduction

*Iris* is a low-cost open hardware/open software telemedical robot platform. We designed Iris to be easily customizable to different clinical contexts so others can adapt the system to their own local needs.

We developed *Iris* using low-cost hardware from our lab. We provide the specifications here, though many components can be interchanged with different alternatives. Additionally, the system can be customized for different needs (e.g., adding a light that can be turned on and off for pupillary response tests).

![diy](https://user-images.githubusercontent.com/11902748/146090486-9cc8523a-88a8-4404-a7de-6c6409abf0ac.png)
**Fig. 1** The basic hardware components of *Iris*, including a two-wheeled mobile robot with a computer, a local router, a tablet, and a wide-angle camera mounted four feet high on the robot.

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
