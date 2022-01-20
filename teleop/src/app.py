#!/usr/bin/env python

"""
* This file runs the Flask web interface for Iris teleoperation.
"""

from flask import Flask, render_template, request, Response
from importlib import import_module
import os
from autobot_msgs.msg import Command
from std_msgs.msg import Bool
import json
import rospy

#You may need to change the module being imported
#depending on your camera
Camera_vid = import_module('camera_' + 'opencv').Camera

app = Flask(__name__)

# Create all commands ahead of time to send when an /action POST is received
command_accel = Command()
command_accel.throttle = 1
command_accel.set_throttle = True

command_reverse = Command()
command_reverse.throttle = -1
command_reverse.set_throttle = True

command_stop_throttle = Command()
command_stop_throttle.throttle = 0
command_stop_throttle.set_throttle = True

command_left = Command()
command_left.steering = .25
command_left.set_steering = True

command_right = Command()
command_right.steering = -.25
command_right.set_steering = True

command_stop_steering = Command()
command_stop_steering.steering = 0
command_stop_steering.set_steering = True

command_brake = Command()
command_brake.brake = True

command_start = Command()
command_start.brake = False

# Map the command messages to the message sent by the web client
command_map = {
    "up" : command_accel,
    "stop-up" : command_stop_throttle,
    "left" : command_left,
    "stop-left" : command_stop_steering,
    "right" : command_right,
    "stop-right" : command_stop_steering,
    "down" :  command_reverse,
    "stop-down" : command_stop_throttle,
    "stop" : command_brake,
    "stop-stop" : command_start
}

pubCmd = rospy.Publisher('autobot/commands', Command, queue_size = 1)
pubTimer = rospy.Publisher('web_teleop/timer', Bool, queue_size = 1)
rospy.init_node('web_teleop')

@app.route("/")
def home():
    return render_template("index.html")

#Generate camera stream
def gen(camera):
    while True:
        frame = camera.get_frame()
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

#Display camera feed
@app.route('/video_feed')
def video_feed():
    return Response(gen(Camera_vid()),
            mimetype='multipart/x-mixed-replace; boundary=frame')

#Button functions for turning the video on and off
@app.route('/button', methods=['GET', 'POST'])
def button_press():
    button = request.form['button']
    if button == 'Turn off video':
        return render_template('no_video.html')
    elif button == 'Turn on video':
        return render_template('index.html')

#Send control commands
@app.route("/action", methods=['POST'])
def action():
    action = request.form['action']
    pubCmd.publish(command_map[action])
    return json.dumps({'success':True}), 200, {'ContentType':'application/json'}

if __name__ == "__main__":
    #Note that ssl_context='adhoc' will cause a warning to
    #appear in the browser before reaching the interface screen.
    #To run on http instead of https, remove the ssl_context argument.
    #See more at
    #https://blog.miguelgrinberg.com/post/running-your-flask-application-over-https
    app.run(host="0.0.0.0", port=5002, ssl_context='adhoc', debug=True)
