#include "stdafx.h"
#include "Net.h"


Net::Net()
        :m_layer(NULL)
        , m_real_datas(NULL)
        ,m_real_data_size(NULL)
{
}


Net::~Net()
{
}

void Net::SetInputData(float * datas, int data_size)
{
        if (data_size != m_layer->GetNodeSize()){
                return;
        }
        for (int i = 0; i < data_size;i++) {
                m_layer->GetNode(i)->SetNodeData(datas[i]);
        }
}

void Net::SetRealData(float * real_datas, int data_size)
{
        m_real_datas = new float[data_size];
        for (int i = 0; i < data_size;i++) {
                m_real_datas[i] = real_datas[i];
        }
}

void Net::cac_one()
{
        Layer * now_layer = m_layer;
        Layer * next_layer = now_layer->GetNextLayer();
        while (next_layer){
                float * ds = now_layer->GetLayerVector();
                next_layer->Cac(ds);
                delete[] ds;
        }
}

void Net::bp_one()
{
        Layer * last_layer = GetLastLayer();
        for (int i = 0; i < m_real_data_size;i++) {
                last_layer->GetNode(i)->SetDelta(m_real_datas[i]);
        }

}

Layer * Net::GetLastLayer()
{
        Layer * res = m_layer;
        while (res->GetNextLayer()){
                res = res->GetNextLayer();
        }
        return res;
}

void Net::initLayer()
{
        m_layer = new Layer(2, Node::SIGMOD_NODE);
        Layer * layer2 = new Layer(2, Node::SIGMOD_NODE);
        m_layer->SetNextLayer(layer2);
        layer2->SetPreLayer(m_layer);

        Layer * layer3 = new Layer(1, Node::NORMAL_NODE);
        layer2->SetNextLayer(layer3);
        layer3->SetPreLayer(layer2);
}
