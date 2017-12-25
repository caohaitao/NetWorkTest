#pragma once
#include "Node.h"
#include <vector>
using namespace std;

class Layer
{
public:
        Layer(int node_size,int input_size,Node::NodeType n_type);
        virtual ~Layer();
        Layer * GetPreLayer();
        Layer * GetNextLayer();
        void SetNextLayer(Layer * l);
        void SetPreLayer(Layer * l);
        int GetNodeSize();
        Node * GetNode(int index);
        float * GetLayerVector();
        void Cac(float * datas);
protected:
        void init(int node_size, Node::NodeType n_type);
        Layer * m_pre_layer;
        Layer * m_next_layer;
        vector<Node*> m_nodes;
        int m_input_size;
};

