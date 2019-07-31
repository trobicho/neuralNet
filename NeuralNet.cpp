#include "NeuralNet.h"
#include <functional>

NeuralNet::NeuralNet(int nbEntrie, int nbNeuronOut, unsigned int nbHLayer):m_nbEntrie(nbEntrie), m_nbLayer(nbHLayer+1)
{
    if(!nbHLayer)
        m_layer.push_front(Layer(nbNeuronOut, nbEntrie));
    else
    {
        m_layer.push_front(Layer(nbNeuronOut));
        for(int i=1; i<nbHLayer; i++)
        {
            m_layer.push_front(Layer());
        }
        m_layer.push_front(Layer(0, nbEntrie));
    }
}

int NeuralNet::answer()
{
    return m_layer.back().get_max();
}

int NeuralNet::addLayer(int pos, Layer layer)
{
    if(pos>m_nbLayer)
        return -1;
    std::list<Layer>::iterator it=m_layer.begin();
    for(int i=0; i<pos && it!=m_layer.end(); i++, it++){;}
    m_layer.insert(it, layer);
    m_nbLayer++;
    return 0;
}

void NeuralNet::addLayerFront(Layer layer)
{
    m_layer.push_front(layer);
    m_nbLayer++;
}

void NeuralNet::addLayerBack(Layer layer)
{
    m_layer.push_back(layer);
    m_nbLayer++;
}

void NeuralNet::init()
{
    std::list<Layer>::iterator it=m_layer.begin();
    it->set_nbNeuronWeight(m_nbEntrie);
    int nbNeuron=it->get_nbNeuron();
    for(it++; it!=m_layer.end(); it++)
    {
        it->set_nbNeuronWeight(nbNeuron);
        nbNeuron=it->get_nbNeuron();
    }
}

Layer& NeuralNet::getLayer(int l)
{
    std::list<Layer>::iterator it=m_layer.begin();
    if(l<m_nbLayer)
    {
        if(!l)
            return std::ref(*it);
        for(int i=1; i<l && it!=m_layer.end(); ++i, ++it){;}
        return std::ref(*it);
    }
    return std::ref(*it);
}

NeuralNet::~NeuralNet()
{
}
