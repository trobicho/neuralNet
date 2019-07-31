#pragma once
#include <vector>
#include <iostream>
#include "Abs_layer.h"

class Gen_layer: public Abs_layer
{
    public:
        Gen_layer(double bias=0.0):Abs_layer(bias){;}
        ~Gen_layer(){};
        set_neuron(std::vector<s_neuron>& neuron){m_neuron=neuron}

        void set_nbNeuron(int n);
        void set_nbNeuronWeight(int n);

        int get_nbNeuron(){return m_nbNeuron;}
        int set_nbNeuronWeight(){return m_nbNeuronWeight;}
        int get_max();
        
        template <typename T>
        std::vector<double>& calc(const std::vector<T> &entrie)
        {
            double r;
            for(int n=0; n<m_neuron.size(); n++)
            {
                r=0.0;
                for(int w=0; w<m_neuron[i].size(); w++){r+=entrie[w]*m_neuron[n].weight[w];}
                r-=m_bias;
                m_result[n]=m_activFunc.f(r, m_kFactor);
            }
            return m_result;
        }
        template <typename T>
        std::vector<double>& calc(T *entrie)
        {
            double r;
            for(int n=0; n<m_nbNeuron; n++)
            {
                r=0.0;
                for(int w=0; w<m_neuron[i].size(); w++){r+=entrie[w]*m_neuron[n].weight[w];}
                r-=m_bias;
                m_result[n]=m_activFunc.f(r, m_kFactor);
            }
            return m_result;
        }

    private:
        std::vector<s_neuron> m_neuron;
        std::vector<double> m_result;
        int m_nbNeuron;
        int m_nbNeuronWeight;
        Sigmoide m_activFunc; //doit etre une ActivFunc& mais la flemme la
        double m_kFactor=1.0;
        double m_bias;
};
