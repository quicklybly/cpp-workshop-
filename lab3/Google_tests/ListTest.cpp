#include "gtest/gtest.h"
#include "List.h"

using namespace list;

class ListFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        list = new List<int>();
    }

    void TearDown() override
    {
        delete list;
    }

    List<int> *list{};
};

TEST_F(ListFixture, AppendAndGetTest)
{
    list->append(1);
    list->append(2);
    list->append(3);

    EXPECT_EQ(list->getFirst(), 1);
    EXPECT_EQ((*list)[1], 2);
    EXPECT_EQ(list->getLast(), 3);
}

TEST_F(ListFixture, RemoveInTheMiddleTest) {
    list->append(1);
    list->append(2);
    list->append(3);

    list->removeAt(1);
    EXPECT_EQ(list->getSize(), 2);
    EXPECT_EQ(list->getFirst(), 1);
    EXPECT_EQ(list->getLast(), 3);
}

TEST_F(ListFixture, RemoveFirstTest) {
    list->append(1);
    list->append(2);
    list->append(3);

    list->removeAt(0);
    EXPECT_EQ(list->getSize(), 2);
    EXPECT_EQ(list->getFirst(), 2);
    EXPECT_EQ(list->getLast(), 3);
}

TEST_F(ListFixture, RemoveLastTest) {
    list->append(1);
    list->append(2);
    list->append(3);

    list->removeAt(2);
    EXPECT_EQ(list->getSize(), 2);
    EXPECT_EQ(list->getFirst(), 1);
    EXPECT_EQ(list->getLast(), 2);
}

TEST_F(ListFixture, ExceptionOnEmptyListTest) {
    try {
        list->removeAt(0);
        FAIL();
    } catch (std::out_of_range &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}

TEST_F(ListFixture, ExceptionOnOutOfRangeIndexTest) {
    list->append(1);
    try {
        list->removeAt(1);
        FAIL();
    } catch (std::out_of_range &e) {
        SUCCEED();
    } catch(...) {
        FAIL();
    }
}