#pragma once
#include <list>
#include "Layer.h"

class NeuralNet
{
    public:
        NeuralNet(int nbEntrie):m_nbEntrie(nbEntrie){};
        NeuralNet(int nbEntrie, int nbNeuronOut, unsigned int nbHLayer=0);
        ~NeuralNet();
        int addLayer(int pos, Layer layer);
        void addLayerFront(Layer layer);
        void addLayerBack(Layer layer);
        Layer& getLayer(int l);
        void init();

        template <typename T>
        int calc(const std::vector<T> &entrie)
        {
            std::list<Layer>::iterator it=m_layer.begin();
            std::vector<double> &result=it->calc(entrie);
            it++;
            for(int i=1; i<m_nbLayer && it!=m_layer.end(); ++i, ++it){result=it->calc(result);}
            std::list<Layer>::reverse_iterator ite=m_layer.rbegin();
            if(ite->get_nbNeuron()==1)
                return (result[0]<0.5)?0:1;
            return answer();
        }
        template <typename T>
        int calc(T *entrie)
        {
            std::list<Layer>::iterator it=m_layer.begin();
            std::vector<double> &result=it->calc(entrie);
            it++;
            for(int i=1; i<m_nbLayer && it!=m_layer.end(); ++i, ++it){result=it->calc(result);}
            std::list<Layer>::reverse_iterator ite=m_layer.rbegin();
            if(ite->get_nbNeuron()==1)
                return (result[0]<0.5)?0:1;
            return answer();
        }
        template <typename T>
        void learn(T *entrie, int answer)
        {
            if(m_nbLayer==1)
                m_layer.front().learn_oneLayer(entrie, answer, m_alpha);
        }

    protected:
        int answer();

        int m_nbEntrie, m_nbLayer=1;
        double m_alpha=0.001;
        std::list<Layer> m_layer;
};
