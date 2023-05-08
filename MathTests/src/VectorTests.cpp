#include <gtest/gtest.h>
#include <Vector3.hpp>

TEST(Vector2F, AddVectorsIsCorrect) {
    Vector2F one(0.0, 1.0);
    Vector2F two(1.0, 0.0);
    Vector2F sum = one + two;
    Vector2F expected_sum(1.0, 1.0);

    EXPECT_TRUE(sum == expected_sum);
}

TEST(Vector2F, AddToVectorIsCorrect) {
    Vector2F one(0.0, 1.0);
    Vector2F two(1.0, 0.0);
    one += two;
    Vector2F expected_sum(1.0, 1.0);

    EXPECT_TRUE(one == expected_sum);
}

TEST(Vector2F, SubVectorsIsCorrect) {
    Vector2F one(10.0, 1.0);
    Vector2F two(20.0, 0.0);
    Vector2F diff = one - two;
    Vector2F expected_diff(-10.0, 1.0);

    EXPECT_TRUE(diff == expected_diff);
}

TEST(Vector2F, SubOfVectorIsCorrect) {
    Vector2F one(10.0, 1.0);
    Vector2F two(20.0, 0.0);
    one -= two;
    Vector2F expected_diff(-10.0, 1.0);

    EXPECT_TRUE(one == expected_diff);
}

TEST(Vector3F, AddVectorsIsCorrect) {
    Vector3F one(0.0, 1.0, 0.0);
    Vector3F two(1.0, 0.0, 0.0);
    Vector3F sum = one + two;
    Vector3F expected_sum(1.0, 1.0, 0.0);

    EXPECT_TRUE(sum == expected_sum);
}

TEST(Vector3F, AddToVectorIsCorrect) {
    Vector3F one(0.0, 1.0, 0.0);
    Vector3F two(1.0, 0.0, 0.0);
    one += two;
    Vector3F expected_sum(1.0, 1.0, 0.0);

    EXPECT_TRUE(one == expected_sum);
}

TEST(Vector3F, SubVectorsIsCorrect) {
    Vector3F one(10.0, 1.0, 0.0);
    Vector3F two(20.0, 0.0, 10.0);
    Vector3F diff = one - two;
    Vector3F expected_diff(-10.0, 1.0, -10.0);

    EXPECT_TRUE(diff == expected_diff);
}

TEST(Vector3F, SubOfVectorIsCorrect) {
    Vector3F one(10.0, 1.0, 0.0);
    Vector3F two(20.0, 0.0, 10.0);
    one -= two;
    Vector3F expected_diff(-10.0, 1.0, -10.0);

    EXPECT_TRUE(one == expected_diff);
}