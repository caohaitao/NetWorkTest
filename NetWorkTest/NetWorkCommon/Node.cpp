#include "stdafx.h"
#include "Node.h"
#include "NetWorkMath.h"
#include <vcruntime_string.h>

#define speed 0.1

Node::Node(int input_size)
        :m_input_size(input_size)
        ,m_params(0)
{
        init();
}


Node::~Node()
{
        if (m_params){
                delete [] m_params;
        }
        m_input_size = 0;
}

float Node::cac(float * datas)
{
        return -1;
}

float Node::bp(float delta)
{
        return -1;
}

float Node::GetParam(int index)
{
        return m_params[index];
}

void Node::AutoChangeParam(float * datas)
{

}

void Node::SetNodeData(float d)
{
        m_cac_data = d;
}

float Node::GetNodeData()
{
        return m_cac_data;
}

void Node::SetDelta(float f)
{
        m_delta = f;
}

void Node::init()
{
        m_params = new float[m_input_size];
        memset(m_params, 0, sizeof(float)*m_input_size);
        //for (int i = 0; i < m_input_size;i++) {
        //        m_params[i] = 1.0;
        //}
        
}

SigmodeNode::SigmodeNode(int input_size)
        :Node(input_size)
{

}

SigmodeNode::~SigmodeNode()
{

}

float SigmodeNode::cac(float * datas)
{
        m_cac_data = 0.0;
        for (int i = 0; i < m_input_size; i++) {
                m_cac_data += m_params[i] * datas[i];
        }
        m_cac_data = NetWorkMath::SigMode(m_cac_data);
        return m_cac_data;
}

float SigmodeNode::bp(float delta)
{
        m_delta = m_cac_data*(1 - m_cac_data)*delta;
        return m_delta;
}

void SigmodeNode::AutoChangeParam(float * datas)
{
        for (int i = 0; i < m_input_size; i++) {
                m_params[i] += speed*m_delta*datas[i];
        }
}

NormalNode::~NormalNode()
{

}

NormalNode::NormalNode(int input_size)
        :Node(input_size)
{

}

float NormalNode::cac(float * datas)
{
        m_cac_data = 0.0;
        for (int i = 0; i < m_input_size; i++) {
                m_cac_data += m_params[i] * datas[i];
        }
        return m_cac_data;
}

float NormalNode::bp(float delta)
{
        m_delta = delta;
        return m_delta;
}

void NormalNode::AutoChangeParam(float * datas)
{
        for (int i = 0; i < m_input_size; i++) {
                m_params[i] += speed*m_delta*datas[i];
        }
}

Node * NodeProducer::CreateANode(Node::NodeType n_type, int input_size)
{
        if (n_type == Node::SIGMOD_NODE) {
                return new SigmodeNode(input_size);
        }
        else if (n_type == Node::NORMAL_NODE) {
                return new NormalNode(input_size);
        }
        return NULL;
}