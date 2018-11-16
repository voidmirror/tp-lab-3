#include "gtest/gtest.h"

#include "task1.h"
#include "Circle.h"
#include "DateTime.h"
	
TEST(circle,circle_get_area)
{
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0,c.getArea());
}
