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
                delete m_params;
        }
        m_input_size = 0;
}

float Node::cac(float * datas)
{
        m_cac_data = 0.0;
        for (int i = 0; i < m_input_size;i++) {
                m_cac_data += m_params[i] * datas[i];
        }
        m_cac_data = NetWorkMath::SigMode(m_cac_data);
        return m_cac_data;
}

float Node::bp(float delta)
{
        m_delta = m_cac_data*(1 - m_cac_data)*delta;
        return m_delta;
}

float Node::GetParam(int index)
{
        return m_params[index];
}

void Node::AutoChangeParam(float * datas)
{
        for (int i = 0; i < m_input_size;i++) {
                m_params[i] += speed*m_delta*datas[i];
        }
}

void Node::init()
{
        m_params = new float[m_input_size];
        //memset(m_params, 0, sizeof(float)*m_input_size);
        for (int i = 0; i < m_input_size;i++) {
                m_params[i] = 1.0;
        }
        
}
