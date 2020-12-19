/* Copyright (C) 1883 Thomas Edison - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */
#include <academy_lib/colors.h>
#include <gtest/gtest.h>

#include <math.h>

TEST(TestGetColor, Zero)
{
  std_msgs::msg::ColorRGBA color = academy::getColor(0);
  ASSERT_FLOAT_EQ(1.0, color.r);
  ASSERT_FLOAT_EQ(0.0, color.g);
  ASSERT_FLOAT_EQ(0.0, color.b);
  ASSERT_FLOAT_EQ(0.0, color.a);
}

TEST(TestGetColor, UpperBound)
{
  std_msgs::msg::ColorRGBA color = academy::getColor(2*M_PI);
  ASSERT_FLOAT_EQ(1.0, color.r);
  ASSERT_FLOAT_EQ(0.0, color.g);
  ASSERT_FLOAT_EQ(0.0, color.b);
  ASSERT_FLOAT_EQ(1.0, color.a);
}

TEST(TestGetColor, LowerBound)
{
  std_msgs::msg::ColorRGBA color = academy::getColor(-2*M_PI);
  ASSERT_FLOAT_EQ(1.0, color.r);
  ASSERT_FLOAT_EQ(0.0, color.g);
  ASSERT_FLOAT_EQ(0.0, color.b);
  ASSERT_FLOAT_EQ(1.0, color.a);
}

TEST(TestGetColor, Half)
{
  std_msgs::msg::ColorRGBA color = academy::getColor(M_PI);
  ASSERT_FLOAT_EQ(0.0, color.r);
  ASSERT_FLOAT_EQ(1.0, color.g);
  ASSERT_FLOAT_EQ(1.0, color.b);
  ASSERT_FLOAT_EQ(1.0, color.a);
}

TEST(TestGetColor, WrapUpper)
{
  std_msgs::msg::ColorRGBA color = academy::getColor(M_PI + 2*M_PI);
  ASSERT_FLOAT_EQ(0.0, color.r);
  ASSERT_FLOAT_EQ(1.0, color.g);
  ASSERT_FLOAT_EQ(1.0, color.b);
  ASSERT_FLOAT_EQ(1.0, color.a);
}

TEST(TestGetColor, WrapLower)
{
  std_msgs::msg::ColorRGBA color = academy::getColor(M_PI - 2*M_PI);
  ASSERT_FLOAT_EQ(0.0, color.r);
  ASSERT_FLOAT_EQ(1.0, color.g);
  ASSERT_FLOAT_EQ(1.0, color.b);
  ASSERT_FLOAT_EQ(1.0, color.a);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
