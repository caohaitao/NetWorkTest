#include "stdafx.h"
#include "Layer.h"
#include "BiasLayer.h"


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

int Layer::GetBPNodeSize()
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

void Layer::SetNodeData(float * datas, int data_size)
{
        if (data_size!=m_nodes.size()){
                return;
        }
        for (int i = 0; i < data_size;i++) {
                m_nodes[i]->SetNodeData(datas[i]);
        }
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

Layer * LayerProducer::CreateALayer(Layer::LayerType lt, int node_size, int input_size, Node::NodeType n_type)
{
        if (lt == Layer::NORMAL){
                return new Layer(node_size, input_size, n_type);
        }
        else if (lt == Layer::BIAS){
                return new BiasLayer(node_size, input_size, n_type);
        }
        return NULL;
}
