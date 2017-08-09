# Gaussian Naive Bayes classifier in C++

![Alt text](./naive-bayes.png?raw=true "Title")

Implementation of a Gaussian Naive Bayes classifier to predict the behavior of vehicles on a highway

In this exercise I have implemented a Gaussian Naive Bayes classifier to predict the behavior of vehicles on a highway. We are looking for 3 behaviours on a 3 lane highway (with lanes of 4 meter width). The dots represent the d (y axis) and s (x axis) coordinates of vehicles as they either...

change lanes left (shown in blue)
keep lane (shown in black)
or change lanes right (shown in red)

Your job is to write a classifier that can predict which of these three maneuvers a vehicle is engaged in given a single coordinate (sampled from the trajectories shown below).

Each coordinate contains 4 pieces of information:

s,d,s_dot,d_dot

which correspond to fernet coordinates.

Programming exercise is part of the UDACITY Self Driving Car Engineering Nanodegree.
