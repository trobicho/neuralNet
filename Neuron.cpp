#include "Neuron.h"

using namespace std;

int f_rand(int min, int max);

double Neuron::m_k_factor=1.0;

Neuron::Neuron(int nbWeight):m_nbWeight(nbWeight)
{
    if(nbWeight)
    {
        m_weight.resize(nbWeight);
        initWeight();
    }
}

Neuron::~Neuron()
{
    //delete m_activFunc;
}

void Neuron::initWeight(void)
{
    for(int i=0; i<m_nbWeight; i++)
    {
        m_weight[i]=f_rand(0, 100)/10.0;
    }
}

int f_rand(int min, int max)
{
    return rand()%(max-min)+min;
}
