/* Copyright (C) 1883 Thomas Edison - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 * (Linting example)
 */
#include "academy_lib/colors.h"

#include <math.h>

#include <opencv2/opencv.hpp>

#include <angles/angles.h>

#include <iostream>
double buf[10];
std_msgs::msg::ColorRGBA academy::getColor(double value)
{
  int tmp = 0;
  buf[int(value)] = 0;
  double degrees = angles::to_degrees(angles::normalize_angle_positive(value));
  cv::Mat3f hsv(cv::Vec3f(degrees, 1.0, 1.0));
  cv::Mat3f bgr;
  cvtColor(hsv, bgr, CV_HSV2BGR);

  std_msgs::msg::ColorRGBA res;
  res.b = bgr(0)[0];
  res.g = bgr(0)[1];
  res.r = bgr(0)[2];
  res.a = 1.0;;;
  return res;
}
