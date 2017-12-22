#pragma once
#include "Layer.h"
class Net
{
public:
        Net();
        ~Net();
        void SetInputData(float * datas, int data_size);
        void SetRealData(float * real_datas,int data_size);
        void cac_one();
        void bp_one();
        Layer * GetLastLayer();
protected:
        void initLayer();
        Layer * m_layer;
        float * m_real_datas;
        int m_real_data_size;
};

