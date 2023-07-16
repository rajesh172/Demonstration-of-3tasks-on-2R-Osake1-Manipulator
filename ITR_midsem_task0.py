import numpy as np
from math import sin, cos
import math


##### Important : For remotely driven jacobian can not be computed by D-H parameters as in assignment #############

def Jac(p1,p2):
    
    J =np.array([[-0.1*sin(p1),-0.1*sin(p2)],
    [0.1*cos(p1),0.1*cos(p2)],
    [0,0],[0,0],[0,0],[1,1]])
    return J
    
p1 = float(input("Enter the angle p1 in degrees: "))*math.pi/180
p2 = float(input("Enter the angle p2 in degrees: "))*math.pi/180
Jacobian = Jac(p1,p2)
print(f"This is the jacobian matrix: {Jacobian}")



def vel(p1,p2):
    J =np.array([[-0.1*sin(p1),-0.1*sin(p2)],
    [0.1*cos(p1),0.1*cos(p2)],
    [0,0],[0,0],[0,0],[1,1]])
    q=np.array([[p1],[p2]])
    end_velo=J@q
    return end_velo
print(f"This is the velocity of end effector: {vel(p1,p2)}")

def pos(p1,p2):
    p = np.array([[0.1*cos(p2)+0.1*cos(p1)],[0.1*sin(p2)+0.1*sin(p1)],[0]])
    return p

print(f"This is the position of end effector: {pos(p1,p2)}")
