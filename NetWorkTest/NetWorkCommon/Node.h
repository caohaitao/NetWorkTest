#pragma once

class NodeProducer;
class Node
{
public:
        enum NodeType
        {
                SIGMOD_NODE = 0,
                NORMAL_NODE = 1
        };
        
        virtual ~Node();
        virtual float cac(float * datas);
        virtual void bp(float delta, float * datas);
        float GetParam(int index);
        void SetNodeData(float d);
        float GetNodeData();
        void SetDelta(float f);
        float GetDelta();
protected:
        Node(int input_size);
        void init();
        int m_input_size;
        float * m_params;
        float m_cac_data;
        float m_delta;

        friend NodeProducer;
};

class SigmodeNode :public Node
{
public:
        
        virtual ~SigmodeNode();

        virtual float cac(float * datas) override;

        virtual void bp(float delta, float * datas) override;

protected:
        SigmodeNode(int input_size);
        friend NodeProducer;
};

class NormalNode :public Node
{
public:
        virtual ~NormalNode();

        virtual float cac(float * datas) override;

        virtual void bp(float delta, float * datas) override;
protected:
        NormalNode(int input_size);
        friend NodeProducer;
};

class NodeProducer
{
public:
        static Node * CreateANode(Node::NodeType n_type,int input_size);
};
