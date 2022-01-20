#!/bin/bash
# See https://askubuntu.com/questions/730701/how-do-i-capture-a-screenshot-of-a-window-and-all-the-windows-on-top-of-it
# rviz window name changes from default.rviz to default.rviz* after clicking on it; need to make sure this will work on turtlebot

while true; do
    import -window "navigation.rviz* - RViz" rviz_image.jpg
    convert rviz_image.jpg -crop 1259x653+20+30 rviz_image.jpg
    sleep 1
done
