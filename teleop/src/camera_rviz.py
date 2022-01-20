import time
from base_camera import BaseCamera


class RvizCamera(BaseCamera):
    
    @staticmethod
    def frames():
        while True:
            time.sleep(0.873)
            with open('/home/turtlebot/final_project/hri-final-ws/src/web_teleop/rviz_image.jpg', 'rb') as f:
                img = f.read()
            yield img
