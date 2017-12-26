#include "stdafx.h"
#include "Node.h"
#include "NetWorkMath.h"
#include <vcruntime_string.h>
#include "TRander.h"

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

void Node::bp(float delta, float * datas)
{
        
}

float Node::GetParam(int index)
{
        if (index>(m_input_size-1)){
                return 0.0;
        }
        return m_params[index];
}


void Node::SetParam(int index, float p)
{
        m_params[index] = p;
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

float Node::GetDelta()
{
        return m_delta;
}

int Node::GetInputSize()
{
        return m_input_size;
}

void Node::init()
{
        m_params = new float[m_input_size];
        //memset(m_params, 0, sizeof(float)*m_input_size);
        for (int i = 0; i < m_input_size; i++) {
                m_params[i] = TRander::GetControl()->GetAFBetwen0To1();
        }
        
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

void SigmodeNode::bp(float delta, float * datas)
{
        delta = m_cac_data*(1 - m_cac_data)*delta;
        for (int i = 0; i < m_input_size; i++) {
                m_params[i] += speed*delta*datas[i];
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

void NormalNode::bp(float delta, float * datas)
{
        for (int i = 0; i < m_input_size; i++) {
                m_params[i] += speed*delta*datas[i];
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