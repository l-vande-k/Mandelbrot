import os
import matplotlib as plt
import numpy as np

xmin = -1.5
xmax = 0.5
ymin = -1.2
ymax = 1.2
domain = [xmin, xmax, ymin, ymax]

while True:
    np.savetxt("domain.txt", domain) # C:\Users\vande_2\OneDrive - Kennesaw State University\Fall 2023\Intermediate Programming Lab\Mandelbrot\
    os.system("Mandelbrot.exe")
    n = np.log(np.log(np.loadtxt("nFile.txt") + 1)) # C:\Users\vande_2\OneDrive - Kennesaw State University\Fall 2023\Intermediate Programming Lab\Mandelbrot\
    dReal = domain[1] - domain[0]
    dImag = domain[3] - domain[2]
    plt.pyplot.figure(1)
    plt.pyplot.clf()
    plt.pyplot.imshow(n)
    plt.pyplot.gca().set_aspect(dImag/dReal)
    plt.pyplot.pause(0.001)
    p = plt.pyplot.ginput(2) # get user inputs (the clicks on the graph)
    p = np.array(p)
    domain = [min(p[:,0]*dReal/(n.shape[1]-1+domain[0])),
              max(p[:,0]*dReal/(n.shape[1]-1+domain[0])),
              min(p[:,1]*dImag/(n.shape[0]-1+domain[2])),
              max(p[:,1]*dImag/(n.shape[0]-1+domain[2]))]