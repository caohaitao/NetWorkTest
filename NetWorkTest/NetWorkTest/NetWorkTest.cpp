// NetWorkTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest\gtest.h>
#include "NetWorkMath.h"
#include <vector>
#include "Node.h"
using namespace std;

void TestSigMod()
{
        float f = NetWorkMath::SigMode(0.0);
        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(f, 0.5));
        f = NetWorkMath::SigMode(1000000000);
        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(f, 1.0));
        f = NetWorkMath::SigMode(-1000000000);
        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(f, 0.0));
}

TEST(TEST1, MATHTEST)
{
        TestSigMod();
}

TEST(test_one_node, node_bp_test)
{
        //test y=sigmode(2*x+3)
        vector<pair<float, float>> datas;
        datas.push_back(pair<float, float>(-1.5, 0.5));
		datas.push_back(pair<float, float>(-1, 0.731));
		datas.push_back(pair<float, float>(-0.5, 0.88));
        datas.push_back(pair<float, float>(0, 0.952));
        datas.push_back(pair<float, float>(0.3, 0.973));
        datas.push_back(pair<float, float>(0.5, 0.982));
        datas.push_back(pair<float, float>(1, 0.993));

        Node n(2);
        typedef float d2[2];
        d2 * d2s = new d2[datas.size()];
        for (int i = 0; i < datas.size();i++) {
                d2s[i][0] = datas[i].first;
                d2s[i][1] = 1.0;
        }

        for (int k = 0; k < 100000;k++) {
                for (int i = 0; i < datas.size(); i++) {
                        float cac_y = n.cac((float*)d2s[i]);
                        double delt = datas[i].second - cac_y;
                        n.bp(delt);
                        n.AutoChangeParam((float*)d2s[i]);
                }
        }
        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n.GetParam(0), 2));
        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n.GetParam(1), 3));
}

int main(int argc,char ** argv)
{
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

