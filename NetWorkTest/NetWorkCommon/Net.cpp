#include "stdafx.h"
#include "Net.h"


Net::Net(vector<NetLayerData> & layer_datas)
        :m_layer(NULL)
        ,m_real_datas(NULL)
        ,m_real_data_size(0)
{
        m_layer_construction = layer_datas;
        initLayer();
}


Net::~Net()
{
        if (m_layer){
                delete m_layer;
        }
}

void Net::SetInputData(float * datas, int data_size)
{
        m_layer->SetNodeData(datas, data_size);
}

void Net::SetRealData(float * real_datas, int data_size)
{
        m_real_data_size = data_size;
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
                now_layer = next_layer;
                next_layer = next_layer->GetNextLayer();
        }
}

void Net::bp_one()
{
        Layer * last_layer = GetLastLayer();
        for (int i = 0; i < m_real_data_size;i++) {
                float y = last_layer->GetNode(i)->GetNodeData();
                float delt = /*y*(1-y)**/(m_real_datas[i] - y);
                last_layer->GetNode(i)->SetDelta(delt);
        }
        Layer * now_layer = last_layer;
        Layer * pre_layer = now_layer->GetPreLayer();
        while (pre_layer){
                if (pre_layer->GetPreLayer()){
                        int p_bp_node_size = pre_layer->GetBPNodeSize();
                        float * temp_delts = new float[p_bp_node_size];
                        memset(temp_delts, 0, sizeof(float)*p_bp_node_size);
                        for (int i = 0; i < now_layer->GetNodeSize(); i++) {
                                Node * n = now_layer->GetNode(i);
                                for (int j = 0; j < p_bp_node_size; j++) {
                                        Node * pre_n = pre_layer->GetNode(j);
                                        temp_delts[j] += (n->GetParam(i)*n->GetDelta())/**pre_n->GetNodeData()*(1 - pre_n->GetNodeData())*/;
                                }
                        }
                        for (int i = 0; i < p_bp_node_size; i++) {
                                pre_layer->GetNode(i)->SetDelta(temp_delts[i]);
                        }
                        delete[] temp_delts;
                }

                float * inputs = new float[pre_layer->GetNodeSize()];
                for (int i = 0; i < pre_layer->GetNodeSize();i++) {
                        inputs[i] = pre_layer->GetNode(i)->GetNodeData();
                }
                for (int i = 0; i < now_layer->GetNodeSize(); i++) {
                        Node * n = now_layer->GetNode(i);
                        n->bp(n->GetDelta(),inputs);
                }

                now_layer = pre_layer;
                pre_layer = pre_layer->GetPreLayer();
                delete[] inputs;
                
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

Layer * Net::GetFirstLayer()
{
        return m_layer;
}

void Net::initLayer()
{
        if (m_layer_construction.size()<2){
                return;
        }

        m_layer = LayerProducer::CreateALayer(m_layer_construction[0].layer_type, m_layer_construction[0].node_size, 0, Node::SIGMOD_NODE);

        Layer * pre_layer = m_layer;
        for (int i = 1; i < m_layer_construction.size();i++) {
                Layer * temp_layer = LayerProducer::CreateALayer(m_layer_construction[i].layer_type, m_layer_construction[i].node_size, pre_layer->GetNodeSize(), m_layer_construction[i].node_type);
                pre_layer->SetNextLayer(temp_layer);
                temp_layer->SetPreLayer(pre_layer);
                pre_layer = temp_layer;
        }
}
