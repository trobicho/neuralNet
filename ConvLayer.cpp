#include "ConvLayer.h"
#include <stdlib.h>

int f_randI(int min, int max);
double f_randD(int min, int max);

ConvLayer::ConvLayer(s_vol entryVol, int wF, int hF, int depth, int stride, int zeroPad):m_entryVol(entryVol),\
m_depth(depth), m_stride(stride), m_zeroPad(zeroPad)
{
    m_filter.resize(m_depth);
    for(int i=0; i<m_depth; i++)
    {
        m_filter[i].w=wF;
        m_filter[i].h=hF;
        m_filter[i].d=m_entryVol.d;
        initFilterRand(-1, 1);
    }
    m_outputVol.w=(m_entryVol.w-wF+2*m_zeroPad)/m_stride+1;
    m_outputVol.h=(m_entryVol.h-hF+2*m_zeroPad)/m_stride+1;
    m_outputVol.d=depth;
    m_output.resize(m_outputVol.w*m_outputVol.h*m_outputVol.d);
    std::cout << "(" << m_outputVol.w << ", " << m_outputVol.h << ", " << m_outputVol.d << ", " << m_output.size() << ")" << std::endl;
}

void ConvLayer::initFilterRand(int min, int max)
{
    for(int i=0; i<m_depth; i++)
    {
        m_filter[i].weight.resize(m_filter[i].w*m_filter[i].h*m_filter[i].d);
        for(int w=0; w<m_filter[i].weight.size(); w++)
        {
            m_filter[i].weight[w]=f_randD(min, max);
        }
    }
}

int f_randI(int min, int max)
{
    return rand()%(max-min+1)+min;
}

double f_randD(int min, int max)
{
    return (rand()%(max*1000-min*1000+1)+min*1000)/1000.0;
}
