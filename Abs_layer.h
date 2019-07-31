#pragma once
#include <vector>
#include <iostream>
#include "Sigmoide.h"

typedef struct 
{
    std::vector<double> weight;
}s_neuron;

class Abs_layer
{
    public:
        explicit Abs_layer(double bias=0.0, double kFactor=1.0):m_bias(bias), m_kFactor(kFactor){;}
        
        virtual void set_nbNeuron(int n)=0;
        virtual void set_nbNeuronWeight(int n)=0;
        virtual int get_nbNeuron()=0;
        virtual int get_nbNeuronWeight()=0;
        
        virtual int get_max()=0;

        void set_bias(double bias){m_bias=bias;}
        void set_kFactor(double kFactor){m_kFactor=kFactor;}
        double get_bias(){return m_bias;}
        double get_kFactor(){return m_kFactor;}
        
        template <typename T>
        std::vector<double>& calc(const std::vector<T> &entrie){;}
        template <typename T>
        std::vector<double>& calc(T *entrie){;}
        template <typename T>
        void learn_oneLayer(T *entrie, int answer, double alpha){;}

    protected:
        Sigmoide m_activFunc; //doit etre une ActivFunc& mais la flemme la
        double m_kFactor=1.0;
        double m_bias;
};
