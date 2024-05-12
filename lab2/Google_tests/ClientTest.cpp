#include "gtest/gtest.h"
#include "Client.h"

using namespace bank;

class ClientFixture : public ::testing::Test {
protected:
    void TearDown() override
    {
        delete client;
    }

    Client *client{};
};

TEST_F(ClientFixture, InitWorksCorrectly)
{
    client = new Client(0, "John");
    EXPECT_EQ(client->GetId(), 0);
    EXPECT_EQ(client->GetName(), "John");
    EXPECT_EQ(client->IsCorporate(), false);
}

TEST_F(ClientFixture, InitWithIsCorporateWorksCorrectly)
{
    client = new Client(1, "John", true);
    EXPECT_EQ(client->GetId(), 1);
    EXPECT_EQ(client->GetName(), "John");
    EXPECT_EQ(client->IsCorporate(), true);
}
