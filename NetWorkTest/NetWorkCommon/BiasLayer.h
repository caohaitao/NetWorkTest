#pragma once
#include "Layer.h"

class LayerProducer;

class BiasLayer :
        public Layer
{
public:
        
        virtual ~BiasLayer();
        virtual void Cac(float * datas) override;
        virtual int GetBPNodeSize() override;
        virtual void SetNodeData(float * datas, int data_size) override;
protected:
        BiasLayer(int node_size, int input_size, Node::NodeType n_type);
        void init(Node::NodeType n_type);
        friend LayerProducer;
};

