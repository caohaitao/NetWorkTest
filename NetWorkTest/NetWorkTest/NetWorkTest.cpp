// NetWorkTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest\gtest.h>
#include "NetWorkMath.h"
#include <vector>
#include "Node.h"
#include "Net.h"
#include "TRander.h"
using namespace std;

//void TestSigMod()
//{
//        float f = NetWorkMath::SigMode(0.0);
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(f, 0.5));
//        f = NetWorkMath::SigMode(1000000000);
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(f, 1.0));
//        f = NetWorkMath::SigMode(-1000000000);
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(f, 0.0));
//}
//
//TEST(TEST1, MATHTEST)
//{
//        TestSigMod();
//}
//
//TEST(test_SIGMOD_node, sigmode_node_bp_test)
//{
//        //test y=sigmode(2*x+3)
//        vector<pair<float, float>> datas;
//        datas.push_back(pair<float, float>(-1.5, 0.5));
//		datas.push_back(pair<float, float>(-1, 0.731));
//		datas.push_back(pair<float, float>(-0.5, 0.88));
//        datas.push_back(pair<float, float>(0, 0.952));
//        datas.push_back(pair<float, float>(0.3, 0.973));
//        datas.push_back(pair<float, float>(0.5, 0.982));
//        datas.push_back(pair<float, float>(1, 0.993));
//
//        Node * n = NodeProducer::CreateANode(Node::SIGMOD_NODE,2);
//        typedef float d2[2];
//        d2 * d2s = new d2[datas.size()];
//        for (int i = 0; i < datas.size();i++) {
//                d2s[i][0] = datas[i].first;
//                d2s[i][1] = 1.0;
//        }
//
//        for (int k = 0; k < 100000;k++) {
//                for (int i = 0; i < datas.size(); i++) {
//                        float cac_y = n->cac((float*)d2s[i]);
//                        double delt = datas[i].second - cac_y;
//                        n->bp(delt, d2s[i]);
//                }
//        }
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n->GetParam(0), 2));
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n->GetParam(1), 3));
//        delete[] d2s;
//        delete n;
//}
//
//TEST(test_NORMAL_node, normal_node_bp_test1)
//{
//        //test y = 2 * x + 3
//        vector<pair<float, float>> datas;
//        datas.push_back(pair<float, float>(-1, 1));
//        datas.push_back(pair<float, float>(0, 3));
//        datas.push_back(pair<float, float>(1, 5));
//        datas.push_back(pair<float, float>(2, 7));
//        datas.push_back(pair<float, float>(3, 9));
//
//        Node * n = NodeProducer::CreateANode(Node::NORMAL_NODE, 2);
//        typedef float d2[2];
//        d2 * d2s = new d2[datas.size()];
//        for (int i = 0; i < datas.size(); i++) {
//                d2s[i][0] = datas[i].first;
//                d2s[i][1] = 1.0;
//        }
//
//        for (int k = 0; k < 1000; k++) {
//                for (int i = 0; i < datas.size(); i++) {
//                        float cac_y = n->cac((float*)d2s[i]);
//                        double delt = datas[i].second - cac_y;
//                        n->bp(delt, d2s[i]);
//                }
//        }
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n->GetParam(0), 2));
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n->GetParam(1), 3));
//        delete[] d2s;
//        delete n;
//}
//
//TEST(test_NORMAL_node, normal_node_bp_test2)
//{
//        //y=2x1-3x2+4
//        typedef float d3[3];
//        d3 d3s[8] = {
//                { 0,0,1 },
//                { 0,1,1 },
//                { 1,1,1 },
//                { 2,1,1 },
//                { 2,2,1 },
//                { 3,1,1 },
//                { 3,2,1 },
//                { 3,3,1 }
//        };
//
//        Node * n = NodeProducer::CreateANode(Node::NORMAL_NODE, 3);
//        float result[8] = { 4,1,3,5,2,7,4,1 };
//        for (int k = 0; k < 1000; k++) {
//                for (int i = 0; i < 8; i++) {
//                        float cac_y = n->cac(d3s[i]);
//                        float delt = result[i] - cac_y;
//                        n->bp(delt, d3s[i]);
//                }
//        }
//
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n->GetParam(0), 2));
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n->GetParam(1), -3));
//        EXPECT_TRUE(NetWorkMath::IsTwoFloatNear(n->GetParam(2), 4));
//
//        delete n;
//}
//TEST(test_net, test_net_two_level)
//{
//        //test y = 2 * x + 3
//        vector<pair<float, float>> datas;
//        datas.push_back(pair<float, float>(-1, 1));
//        datas.push_back(pair<float, float>(0, 3));
//        datas.push_back(pair<float, float>(1, 5));
//        datas.push_back(pair<float, float>(2, 7));
//        datas.push_back(pair<float, float>(3, 9));
//
//        typedef float d2[2];
//        d2 * d2s = new d2[datas.size()];
//        for (int i = 0; i < datas.size(); i++) {
//                d2s[i][0] = datas[i].first;
//                d2s[i][1] = 1.0;
//        }
//
//        vector<Net::NetLayerData>  layer_datas;
//        Net::NetLayerData nd1;
//        nd1.node_type = Node::SIGMOD_NODE;
//        nd1.node_size = 2;
//        nd1.layer_type = Layer::NORMAL;
//        layer_datas.push_back(nd1);
//
//        Net::NetLayerData nd2;
//        nd2.node_type = Node::NORMAL_NODE;
//        nd2.node_size = 1;
//        nd2.layer_type = Layer::NORMAL;
//        layer_datas.push_back(nd2);
//        Net * net = new Net(layer_datas);
//        for (int k = 0; k < 1000;k++) {
//                for (int i = 0; i < datas.size(); i++) {
//                        net->SetInputData(d2s[i], 2);
//                        net->SetRealData(&datas[i].second, 1);
//                        net->cac_one();
//                        net->bp_one();
//                }
//        }
//
//        delete net;
//        delete []d2s;
//}
//TEST(test_logistic, test_logistic)
//{
//        //test 0,1 fenlei
//        
//        typedef float d3[3];
//        d3 * d3s = new d3[4];
//
//        d3s[0][0] = 0;
//        d3s[0][1] = 0;
//        d3s[0][2] = 1;
//
//        d3s[1][0] = 0;
//        d3s[1][1] = 1;
//        d3s[1][2] = 1;
//
//        d3s[2][0] = 1;
//        d3s[2][1] = 0;
//        d3s[2][2] = 1;
//
//        d3s[3][0] = 1;
//        d3s[3][1] = 1;
//        d3s[3][2] = 1;
//
//        float * results = new float[4];
//        results[0] = 0;
//        results[1] = 0;
//        results[2] = 0;
//        results[3] = 1;
//        
//
//        Node * n = NodeProducer::CreateANode(Node::SIGMOD_NODE, 3);
//
//
//        for (int k = 0; k < 10000; k++) {
//                for (int i = 0; i < 4; i++) {
//                        float cac_y = n->cac((float*)d3s[i]);
//                        double delt = results[i] - cac_y;
//                        n->bp(delt, d3s[i]);
//                }
//        }
//
//        float d = n->cac(d3s[0]);
//        d = n->cac(d3s[1]);
//        d = n->cac(d3s[2]);
//        d = n->cac(d3s[3]);
//
//        delete[] d3s;
//        delete n;
//}
//TEST(test_net, section1)
//{
//        typedef float d3[3];
//        d3 * d3s = new d3[4];
//        d3s[0][0] = 0;
//        d3s[0][1] = 0;
//        d3s[0][2] = 1;
//
//        d3s[1][0] = 0;
//        d3s[1][1] = 1;
//        d3s[1][2] = 1;
//
//        d3s[2][0] = 1;
//        d3s[2][1] = 0;
//        d3s[2][2] = 1;
//
//        d3s[3][0] = 1;
//        d3s[3][1] = 1;
//        d3s[3][2] = 1;
//
//        float * rs = new float[4];
//        rs[0] = 1;
//        rs[1] = 0;
//        rs[2] = 0;
//        rs[3] = 1;
//
//        vector<Net::NetLayerData>  layer_datas;
//        Net::NetLayerData nd1;
//        nd1.node_type = Node::SIGMOD_NODE;
//        nd1.node_size = 3;
//        nd1.layer_type = Layer::NORMAL;
//        layer_datas.push_back(nd1);
//
//        Net::NetLayerData nd2;
//        nd2.node_type = Node::SIGMOD_NODE;
//        nd2.node_size = 1;
//        nd2.layer_type = Layer::NORMAL;
//        layer_datas.push_back(nd2);
//
//
//        Net * net = new Net(layer_datas);
//        for (int k = 0; k < 10000; k++) {
//                for (int i = 0; i < 4; i++) {
//                        net->SetInputData(d3s[i], 3);
//                        net->SetRealData(&rs[i], 1);
//                        net->cac_one();
//                        net->bp_one();
//                }
//        }
//
//        Layer * last_layer = net->GetLastLayer();
//
//        net->SetInputData(d3s[0], 3);
//        net->cac_one();
//
//        float d = last_layer->GetNode(0)->GetNodeData();
//
//        net->SetInputData(d3s[1], 3);
//        net->cac_one();
//
//        d = last_layer->GetNode(0)->GetNodeData();
//
//        net->SetInputData(d3s[2], 3);
//        net->cac_one();
//
//        d = last_layer->GetNode(0)->GetNodeData();
//
//        net->SetInputData(d3s[3], 3);
//        net->cac_one();
//
//        d = last_layer->GetNode(0)->GetNodeData();
//
//        delete net;
//        delete[]d3s;
//}
TEST(test_net, section2)
{
        typedef float d2[2];
        d2 * d2s = new d2[4];
        d2s[0][0] = 0;
        d2s[0][1] = 0;

        d2s[1][0] = 0;
        d2s[1][1] = 1;

        d2s[2][0] = 1;
        d2s[2][1] = 0;

        d2s[3][0] = 1;
        d2s[3][1] = 1;

        float * rs = new float[4];
        rs[0] = 1;
        rs[1] = 0;
        rs[2] = 0;
        rs[3] = 1;

        int input_size = 2;

        vector<Net::NetLayerData>  layer_datas;
        Net::NetLayerData nd1;
        nd1.node_type = Node::SIGMOD_NODE;
        nd1.node_size = input_size;
        nd1.layer_type = Layer::BIAS;
        layer_datas.push_back(nd1);

        Net::NetLayerData nd2;
        nd2.node_type = Node::SIGMOD_NODE;
        nd2.node_size = 2;
        nd2.layer_type = Layer::BIAS;
        layer_datas.push_back(nd2);

        Net::NetLayerData nd3;
        nd3.node_type = Node::SIGMOD_NODE;
        nd3.node_size = 1;
        nd3.layer_type = Layer::NORMAL;
        layer_datas.push_back(nd3);

        Net * net = new Net(layer_datas);
        //net->GetFirstLayer()->GetNextLayer()->GetNode(0)->SetParam(0, -0.59);
        //net->GetFirstLayer()->GetNextLayer()->GetNode(0)->SetParam(1, -0.33);
        //net->GetFirstLayer()->GetNextLayer()->GetNode(0)->SetParam(2, 0.34);

        //net->GetFirstLayer()->GetNextLayer()->GetNode(1)->SetParam(0, 0.59);
        //net->GetFirstLayer()->GetNextLayer()->GetNode(1)->SetParam(1, 0.33);
        //net->GetFirstLayer()->GetNextLayer()->GetNode(1)->SetParam(2, -0.34);

        for (int k = 0; k < 100000; k++) {
                for (int i = 0; i < 4; i++) {
                        net->SetInputData(d2s[i], input_size);
                        net->SetRealData(&rs[i], 1);
                        net->cac_one();
                        net->bp_one();
                }
        }

        Layer * last_layer = net->GetLastLayer();

        net->SetInputData(d2s[0], input_size);
        net->cac_one();

        float d = last_layer->GetNode(0)->GetNodeData();

        net->SetInputData(d2s[1], input_size);
        net->cac_one();

        d = last_layer->GetNode(0)->GetNodeData();

        net->SetInputData(d2s[2], input_size);
        net->cac_one();

        d = last_layer->GetNode(0)->GetNodeData();

        net->SetInputData(d2s[3], input_size);
        net->cac_one();

        d = last_layer->GetNode(0)->GetNodeData();

        delete net;
        delete[]d2s;
}
TEST(test_rander, tr)
{
        int a = TRander::GetControl()->GetARandNumber(0, 10);
        int b = TRander::GetControl()->GetARandNumber(0, 10);
        EXPECT_TRUE(a != b);
}
int main(int argc,char ** argv)
{
        //float fs[10];
        //NetWorkMath::randn(fs, 10);
        //return 1;
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

