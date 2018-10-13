#include <gtest/gtest.h>
#include <cocos2d.h>


class SampleSuite: public ::testing::Test
{
public:
    cocos2d::Node* sampleNode;
    
    
    virtual void SetUp()
    {
         sampleNode = cocos2d::Node::create();
    }
    
    virtual void TearDown()
    {
        delete sampleNode;
    }
    
};

TEST_F(SampleSuite, nullity)
{
    ASSERT_TRUE(sampleNode!=NULL);
}

TEST_F(SampleSuite, visibility)
{
    ASSERT_TRUE(sampleNode->isVisible()==true);
}
