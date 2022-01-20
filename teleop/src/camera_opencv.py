import os
import cv2
from base_camera import BaseCamera
import numpy as np


class Camera(BaseCamera):
    #You may need to change the source depending on
    #how many cameras are attached to your computer
    video_source = 1

    def __init__(self):
        if os.environ.get('OPENCV_CAMERA_SOURCE'):
            Camera.set_video_source(int(os.environ['OPENCV_CAMERA_SOURCE']))
        super(Camera, self).__init__()

    @staticmethod
    def set_video_source(source):
        Camera.video_source = source

    @staticmethod
    def frames():
        camera = cv2.VideoCapture(Camera.video_source)
        if not camera.isOpened():
            raise RuntimeError('Could not start camera.')
        camera.set(3, 1280)
        camera.set(4, 720)

        while True:
            # read current frame
            _, img = camera.read()

            #Trying to reduce image quality
            #cv2.CV_IMWRITE_JPEG_QUALITY = 10
            #imparams = [cv2.CV_IMWRITE_JPEG_QUALITY, 10]
            # encode as a jpeg image and return it
            #h, w, _ = img.shape
            #M = cv2.getRotationMatrix2D((w/2, h/2), 90, 1)
            #img = cv2.warpAffine(img, M, (h,w))
            img = np.rot90(img)
            yield cv2.imencode('.jpg', img)[1].tobytes()
