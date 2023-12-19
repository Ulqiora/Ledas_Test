#include <gtest/gtest.h>
#include <Segment3D.h>

TEST(TestGroupName, Subtest_1) {
    Segment3D   segment1(Vector3D{3,0,0},Vector3D{1,2,0}),
            segment2(Vector3D{1,1,0},Vector3D{1,2,0});
    auto result = Intersect(segment1,segment2);
    ASSERT_DOUBLE_EQ(result.getX(),1);
    ASSERT_DOUBLE_EQ(result.getY(),2);
    ASSERT_DOUBLE_EQ(result.getZ(),0);
}
TEST(TestGroupName, Subtest_2) {
    Segment3D   segment1(Vector3D{3,0,0},Vector3D{1,2,0}),
            segment2(Vector3D{1,1,0},Vector3D{3,1,0});
    auto result = Intersect(segment1,segment2);
    ASSERT_DOUBLE_EQ(result.getX(),2);
    ASSERT_DOUBLE_EQ(result.getY(),1);
    ASSERT_DOUBLE_EQ(result.getZ(),0);
}

TEST(TestGroupName, Subtest_3) {
    Segment3D   segment1(Vector3D{2,2,2},Vector3D{-2,-2,-2}),
            segment2(Vector3D{2,2,-2},Vector3D{-2,-2,2});
    auto result = Intersect(segment1,segment2);
    ASSERT_DOUBLE_EQ(result.getX(),0);
    ASSERT_DOUBLE_EQ(result.getY(),0);
    ASSERT_DOUBLE_EQ(result.getZ(),0);
}
TEST(TestGroupName, Subtest_4) {
    Segment3D   segment1(Vector3D{2,2,2},Vector3D{-2,-2,-2}),
            segment2(Vector3D{2,2,-2},Vector3D{-2,-2,-2});
    auto result = Intersect(segment1,segment2);
    ASSERT_DOUBLE_EQ(result.getX(),-2);
    ASSERT_DOUBLE_EQ(result.getY(),-2);
    ASSERT_DOUBLE_EQ(result.getZ(),-2);
}
TEST(TestGroupName, Subtest_5) {
    Segment3D   segment1(Vector3D{2,2,2},Vector3D{0,0,0}),
            segment2(Vector3D{2,2,2},Vector3D{0,0,1});
    auto result = Intersect(segment1,segment2);
    ASSERT_DOUBLE_EQ(result.getX(),2);
    ASSERT_DOUBLE_EQ(result.getY(),2);
    ASSERT_DOUBLE_EQ(result.getZ(),2);
}

TEST(TestGroupName, Subtest_10) {
    Segment3D   segment1(Vector3D{3,0,0},Vector3D{1,2,0}),
            segment2(Vector3D{1,1,0},Vector3D{1,0,0});
    ASSERT_THROW({ Intersect(segment1, segment2); },std::invalid_argument);
}
TEST(TestGroupName, Subtest_11) {
    Segment3D   segment1(Vector3D{3,0,0},Vector3D{1,2,0}),
            segment2(Vector3D{1,1,0},Vector3D{1,0,0});
    ASSERT_THROW({ Intersect(segment1, segment2); },std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}