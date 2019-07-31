#pragma once
#include <vector>
#include <stdlib.h>
#include "Sigmoide.h"
#include <iostream>

class Neuron
{
    public:
        Neuron(){;}
        Neuron(int nbWeight);
        ~Neuron();
        void set_nbWeight(int n){m_weight.resize((m_nbWeight=n)), initWeight();}
        void initWeight(void);

        template <typename T>
        double calc(const std::vector<T> &entrie)
        {
            double r=0;
            for(int i=0; i<m_nbWeight; i++){r+=entrie[i]*m_weight[i];}
            r-=m_coef;
            return m_activFunc.f(r, m_k_factor);
        }
        template <typename T>
        double calc(T *entrie)
        {
            double r=0;
            for(int i=0; i<m_nbWeight; i++){r+=entrie[i]*m_weight[i];}
            r-=m_coef;
            return m_activFunc.f(r, m_k_factor);
        }
        template <typename T>
        void learn(T *entrie, double factor)
        {for(int i=0; i<m_nbWeight; ++i){m_weight[i]+=factor*entrie[i];}}

    private:
        std::vector<double> m_weight;
        int m_nbWeight=0;
        Sigmoide m_activFunc; //doit etre une ActivFunc& mais la flemme la
        static double m_k_factor;
        double m_coef=50000.0;
};
