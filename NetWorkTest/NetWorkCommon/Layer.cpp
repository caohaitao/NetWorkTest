#include "stdafx.h"
#include "Layer.h"


Layer::Layer(int node_size, int input_size, Node::NodeType n_type)
        :m_pre_layer(NULL)
        ,m_next_layer(NULL)
        ,m_input_size(input_size)
{
        init(node_size, n_type);
}


Layer::~Layer()
{
        for (int i = 0; i < m_nodes.size();i++) {
                delete m_nodes[i];
        }
        m_nodes.clear();
        if (m_next_layer){
                delete m_next_layer;
                m_next_layer = NULL;
        }
}

Layer * Layer::GetPreLayer()
{
        return m_pre_layer;
}

Layer * Layer::GetNextLayer()
{
        return m_next_layer;
}

void Layer::SetNextLayer(Layer * l)
{
        m_next_layer = l;
}

void Layer::SetPreLayer(Layer * l)
{
        m_pre_layer = l;
}

int Layer::GetNodeSize()
{
        return m_nodes.size();
}

Node * Layer::GetNode(int index)
{
        return m_nodes[index];
}

float * Layer::GetLayerVector()
{
        float * res = new float[m_nodes.size()];
        for (int i = 0; i < m_nodes.size();i++) {
                res[i] = m_nodes[i]->GetNodeData();
        }
        return res;
}

void Layer::Cac(float * datas)
{
        for (int i = 0; i < m_nodes.size();i++) {
                m_nodes[i]->cac(datas);
        }
}

void Layer::init(int node_size, Node::NodeType n_type)
{
        for (int i = 0; i < node_size;i++) {
                Node * n = NodeProducer::CreateANode(n_type, m_input_size);
                m_nodes.push_back(n);
        }
}
