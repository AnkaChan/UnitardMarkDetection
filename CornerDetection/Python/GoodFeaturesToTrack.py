import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread('corner1.png')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

cv2.imshow('img', img)
cv2.waitKey(0)
img=cv2.bilateralFilter(img, 10, 75, 75)
cv2.imshow('img_blured', img)
cv2.waitKey(0)


corners = cv2.goodFeaturesToTrack(gray, 0, 0.05, 20, useHarrisDetector=True)
corners = np.int0(corners)

for i in corners:
    x,y = i.ravel()
    cv2.circle(img,(x,y),3,255,-1)

plt.imshow(img),plt.show()