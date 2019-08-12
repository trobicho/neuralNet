#include "Layer.h"

Layer::Layer(const Layer &copy)
{
    m_neuron=copy.m_neuron;
    m_nbNeuron=copy.m_nbNeuron;
    m_nbNeuronWeight=copy.m_nbNeuron;
    m_bNeuronControl=copy.m_bNeuronControl;
    if(m_nbNeuron)
        set_nbNeuron(m_nbNeuron);
}

Layer::Layer(bool bNeuronControl):m_bNeuronControl(bNeuronControl), m_nbNeuron(0), m_nbNeuronWeight(0)
{
    if(m_bNeuronControl)
        m_neuron=std::make_shared<std::vector<s_neuron>>();
}

Layer::Layer(bool bNeuronControl, int nbNeuron, double bias, int nbNeuronWeight):m_bNeuronControl(bNeuronControl),\
Abs_layer(bias), m_nbNeuron(nbNeuron), m_nbNeuronWeight(nbNeuronWeight)
{
    if(m_bNeuronControl)
        m_neuron=std::make_shared<std::vector<s_neuron>>();
    if(nbNeuron)
        set_nbNeuron(nbNeuron);
}

Layer::~Layer()
{
}

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

void Layer::set_nbNeuron(int n)
{
    if(m_bNeuronControl)
    {
        int begin=m_neuron->size();
        m_neuron->resize(n);
        m_result.resize(n);
        for(int i=begin; i<n; ++i)
        {
            m_neuron->at(i).weight.resize(m_nbNeuronWeight);
            initNeuronWeight(i);
        }
    }
    m_nbNeuron=n;
}

void Layer::set_nbNeuronWeight(int n)
{
    m_nbNeuronWeight=n;
    if(m_bNeuronControl)
    {
        for(int i=0; i<m_nbNeuron; i++)
        {
            m_neuron->at(i).weight.resize(m_nbNeuronWeight);
        }
        initNeuronWeight();
    }
}

int f_rand(int min, int max);

void Layer::initNeuronWeight(int n)
{
    if(m_bNeuronControl)
    {
        for(int w=0; w<m_nbNeuronWeight; w++)
        {
            m_neuron->at(n).weight[w]=f_rand(-1000, 1000)/1000.0;
        }
    }
}

void Layer::initNeuronWeight(void)
{
    if(m_bNeuronControl)
    {
        for(int n=0; n<m_nbNeuron; n++)
        {
            for(int w=0; w<m_nbNeuronWeight; w++)
            {
				m_neuron->at(n).weight[w]=f_rand(-1000, 1000)/1000.0;
            }
        }
    }
}

int f_rand(int min, int max)
{
    return rand()%(max-min)+min;
}
