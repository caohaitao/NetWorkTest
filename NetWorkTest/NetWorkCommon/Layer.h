#pragma once
#include "Node.h"
#include <vector>
using namespace std;

class LayerProducer;

class Layer
{
public:
        enum LayerType
        {
                NORMAL = 0,
                BIAS = 1
        };
        
        virtual ~Layer();
        Layer * GetPreLayer();
        Layer * GetNextLayer();
        void SetNextLayer(Layer * l);
        void SetPreLayer(Layer * l);
        int GetNodeSize();
        virtual int GetBPNodeSize();
        Node * GetNode(int index);
        float * GetLayerVector();
        virtual void SetNodeData(float * datas, int data_size);
        virtual void Cac(float * datas);
protected:
        Layer(int node_size, int input_size, Node::NodeType n_type);
        void init(int node_size, Node::NodeType n_type);
        Layer * m_pre_layer;
        Layer * m_next_layer;
        vector<Node*> m_nodes;
        int m_input_size;
        friend LayerProducer;
};

class LayerProducer
{
public:
        static Layer * CreateALayer(Layer::LayerType lt, int node_size, int input_size, Node::NodeType n_type);
};
