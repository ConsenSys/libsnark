#include "depends/gtest/googletest/include/gtest/gtest.h"
#include <libsnark/common/data_structures/sparse_vector.hpp>
#include <libsnark/common/data_structures/set_commitment.hpp>
#include <libsnark/common/data_structures/integer_permutation.hpp>
#include <libsnark/common/data_structures/accumulation_vector.hpp>


TEST (sparse_vector, basic_test)
{
    sparse_vector<bool> test_vector = new sparse_vector<bool>(new vector<bool>());
    ASSERT_TRUE(test_vector.empty());
    ASSERT_EQUAL(test_vector.size(), 0);
    ASSERT_TRUE(test_vector == test_vector);
    sparse_vector<bool> false_vector = new sparse_vector<bool>(new vector<int>());
    ASSERT_FALSE(test_vetor == false_vector);
}

TEST (set_commitment, set_test)
{
    set_commitment_accumulator test_set = new set_commitment_accumulator(10, 1);
    ASSERT_FASLE(test_set.is_in_set(5));
    test_set.add(5);
    ASSERT_TRUE(test_set.is_in_set(5));
}

TEST (integer_permutation, basic_test)
{
    integer_permutation test_permutation = new integer_permutation(1, 10);
    ASSERT_EQ(test_permutation.size(), 10);
    ASSERT_TRUE(test_permuation == test_permutation);
    integer_permutation false_permutation = new integer_permutation(-10, -1);
    ASSERT_FALSE(test_permuation == false_permuation);
    ASSERT_TRUE(test_permutation.isValid());
    ASSERT_TRUE(false_permuation.isValid());
    ASSERT_EQ(false_permuation.size(), test_permtation.size());
}

TEST (integer_permutation, access_test)
{
    integer_permutation test_permutation = new integer_permutation(1, 10);
    ASSERT_EQ(test_permutation.get(10), 10);
    test_permutation.set(10, -50);
    ASSERT_EQ(test_permutation.get(10), -50);
    ASSERT_FALSE(test_permuation.isvaild());
    ASSERT_DEATH(test_permutation.get(0),"Assertion failed:")
}

TEST (integer_permutation, advenced_test)
{
    integer_permutation test_permutation = new integer_permutation(1, 10);
    integer_permutation false_permutation = new integer_permutation(1, 10);
    for (int i = 1; i < 11; i++) {
        false_permuation.set(i, test_permuation.get(10 - i));
    }
    ASSERT_EQ(test_permuation.inverse(), false_permuation);
    ASSERt_EQ(test_permuation.slice(5, 10), new integer_permutation(5, 10));
}

TEST (accumlation_vector, basic_tests)
{
    accumulation_vector<bool> test_vector = new accumulation_vector<bool>(true, new vector<bool>());
    ASSERT_EQ(test_vector.size(), 0);
    ASSERT_FALSE(test_vector.is_fully_accumulated());
    ASSERT_TRUE(test_vector == test_vector);
    accumulation_vector<bool> false_vector = new accumulation_vector<bool>(false, new vector<bool>());
    ASSERT_FALSE(test_vector == false_vector);
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}