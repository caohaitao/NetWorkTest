#pragma once
class Node
{
public:
        Node(int input_size);
        virtual ~Node();
        float cac(float * datas);
        float bp(float delta);
        float GetParam(int index);
        void AutoChangeParam(float * datas);
protected:
        void init();
        int m_input_size;
        float * m_params;
        float m_cac_data;
        float m_delta;
};

