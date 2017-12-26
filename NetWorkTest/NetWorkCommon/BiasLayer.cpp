#include "stdafx.h"
#include "BiasLayer.h"


BiasLayer::BiasLayer(int node_size, int input_size, Node::NodeType n_type)
        :Layer(node_size,input_size,n_type)
{
        init(n_type);
}


BiasLayer::~BiasLayer()
{
}

void BiasLayer::init(Node::NodeType n_type)
{
        Node * n = NodeProducer::CreateANode(n_type, 0);
        m_nodes.push_back(n);
        
}

void BiasLayer::SetNodeData(float * datas, int data_size)
{
        if (data_size != m_nodes.size()-1){
                return;
        }
        for (int i = 0; i < data_size;i++) {
                m_nodes[i]->SetNodeData(datas[i]);
        }
        (*m_nodes.rbegin())->SetNodeData(1.0);
}

int BiasLayer::GetBPNodeSize()
{
        return m_nodes.size() - 1;
}

void BiasLayer::Cac(float * datas)
{
        for (int i = 0; i < m_nodes.size() - 1;i++) {
                m_nodes[i]->cac(datas);
        }
        (*m_nodes.rbegin())->SetNodeData(1.0);
}
