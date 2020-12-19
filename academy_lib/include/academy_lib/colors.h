/* Copyright (C) 1883 Thomas Edison - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */
#ifndef ACADEMY_LIB_COLORS_H
#define ACADEMY_LIB_COLORS_H

#include <std_msgs/msg/color_rgba.hpp>


namespace academy {

std_msgs::msg::ColorRGBA getColor(double value);

};

#endif // ACADEMY_LIB_COLORS_H
