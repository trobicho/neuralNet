#include "Layer.h"

int Layer::get_max()
{
    double max=m_result[0];
    int n=0;
    for(int i=1; i<m_nbNeuron; ++i)
    {
        if(max<m_result[i])
        {
            max=m_result[i];
            n=i;
        }
    }
    return n;
}


void Layer::initNeuronWeight(int n)
{
    for(int w=0; w<m_nbNeuronWeight; w++)
    {
        m_neuron[n].weight[w]=f_rand(0, 100)/10.0;
    }
}

void Layer::initNeuronWeight(void)
{
    for(int n=0; n<m_nbNeuron; n++)
    {
        for(int w=0; w<m_nbNeuronWeight; w++)
        {
            m_neuron[n].weight[w]=f_rand(0, 100)/10.0;
        }
    }
}
