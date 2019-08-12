#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Abs_layer.h"

class Layer: public Abs_layer
{
    public:
        Layer(const Layer &copy);
        Layer():m_bNeuronControl(false){};
        Layer(bool bNeuronControl);
        Layer(int nbNeuron, int nbNeuronWeight=0):Layer(true, nbNeuron, 0.0, nbNeuronWeight){;}
        Layer(bool bNeuronControl, int nbNeuron, int nbNeuronWeight=0):Layer(bNeuronControl, nbNeuron, 0.0, nbNeuronWeight){;}
        Layer(bool bNeuronControl, int nbNeuron, double bias, int nbNeuronWeight=0);
        ~Layer();
        void init();
        void initNeuronWeight(int n);
        void initNeuronWeight(void);

        void set_nbNeuron(int n);
        void set_nbNeuronWeight(int n);
        void set_neuronVector(std::shared_ptr<std::vector<s_neuron> > neuron){m_neuron=neuron;}
        std::shared_ptr<std::vector<s_neuron> > get_neuronVector(){return m_neuron;}

        int get_nbNeuron(){return m_nbNeuron;}
        int get_nbNeuronWeight(){return m_nbNeuronWeight;}
        int get_max();
        std::vector<double>& get_result(){return m_result;}

		s_neuron&	get_neuron_at_n(int n){return (m_neuron->at(n));}
        
        template <typename T>
        std::vector<double>& calc(const std::vector<T> &entrie)
        {
            double r;
            for(int n=0; n<m_neuron->size(); n++)
            {
                r=0.0;
                for(int w=0; w<m_neuron->at(n).weight.size(); w++){r+=entrie[w]*m_neuron->at(n).weight[w];}
                r-=m_bias;
                m_result[n]=m_activFunc.f(r, m_kFactor);
            }
            return m_result;
        }
        template <typename T>
        std::vector<double>& calc(T *entrie)
        {
            double r;
            for(int n=0; n<m_neuron->size(); n++)
            {
                r=0.0;
                for(int w=0; w<m_neuron->at(n).weight.size(); w++){r+=entrie[w]*m_neuron->at(n).weight[w];}
                r-=m_bias;
                m_result[n]=m_activFunc.f(r, m_kFactor);
            }
            return m_result;
        }
        template <typename T>
        void learn_oneLayer(T *entrie, int answer, double alpha)
        {
            for(int n=0; n<m_neuron->size(); n++)
            {
                for(int w=0; w<m_neuron->at(n).weight.size(); w++)
                {
                    m_neuron->at(n).weight[w]+=alpha*((n==answer)-m_result[n])*entrie[w];
                }
            }
        }

    private:
        std::shared_ptr<std::vector<s_neuron> > m_neuron=nullptr;
        std::vector<double> m_result;
        int m_nbNeuron;
        int m_nbNeuronWeight;
        bool m_bNeuronControl;
};
