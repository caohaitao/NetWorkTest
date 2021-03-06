#pragma once
#include "Layer.h"
#include <vector>
using namespace std;
class Net
{
public:
        struct NetLayerData
        {
                Node::NodeType node_type;
                int node_size;
                Layer::LayerType layer_type;
        };
        Net(vector<NetLayerData> & layer_datas);
        ~Net();
        void SetInputData(float * datas, int data_size);
        void SetRealData(float * real_datas,int data_size);
        void cac_one();
        void bp_one();

        Layer * GetLastLayer();
        Layer * GetFirstLayer();
protected:
        void initLayer();
        Layer * m_layer;
        float * m_real_datas;
        int m_real_data_size;

        vector<NetLayerData> m_layer_construction;
};

