#include <vector>
#include <iostream>

typedef struct
{
    int w, h, d;
}s_vol;

typedef struct 
{
    std::vector<double> weight;
    int w, h, d;
}s_filter;

class ConvLayer
{
    public:
        ConvLayer(s_vol entryVol, int wF, int hF, int depth, int stride=1, int zeroPad=0);
        void initFilterRand(int min, int max);
        
        template <typename T>
        std::vector<double>& calc(const std::vector<T> &entry)
        {
            double r;
            for(int f=0; f<m_depth; f++)
            {
                for(int x=m_filter[f].w/2-m_zeroPad; x<m_entryVol.w-m_filter[f].w/2+m_zeroPad; x++)
                {
                    for(int y=m_filter[f].h/2-m_zeroPad; y<m_entryVol.h-m_filter[f].h/2+m_zeroPad; y++)
                    {
                        r=0.0;
                        for(int d=0; d<m_entryVol.d; d++)
                        {
                            for(int fX=0; fX<m_filter[f].w; fX++)
                            {
                                for(int fY=0; fY<m_filter[f].h; fY++)
                                {
                                    r+=m_filter[f].weight[fX+fY*m_filter[f].w+m_filter[f].w*m_filter[f].h*d]\
                                       *entry[(x+fX-m_filter[f].w/2)+(y+fX-m_filter[f].h/2)*m_entryVol.w+m_entryVol.w*m_entryVol.h*d];
                                }
                            }
                        }
                        if(m_relu)
                            m_output[x-m_filter[f].w/2+(y-m_filter[f].h/2)*m_outputVol.w]=(r<0)?0:r;
                        else
                            m_output[x-m_filter[f].w/2+(y-m_filter[f].h/2)*m_outputVol.w]=r;
                    }
                }
            }
            return m_output;
        }

        template <typename T>
        std::vector<double>& calc(const T *entry)
        {
            double r;
            for(int f=0; f<m_depth; f++)
            {
                for(int x=m_filter[f].w/2-m_zeroPad; x<m_entryVol.w-m_filter[f].w/2+m_zeroPad; x++)
                {
                    for(int y=m_filter[f].h/2-m_zeroPad; y<m_entryVol.h-m_filter[f].h/2+m_zeroPad; y++)
                    {
                        r=0.0;
                        for(int d=0; d<m_entryVol.d; d++)
                        {
                            for(int fX=0; fX<m_filter[f].w; fX++)
                            {
                                for(int fY=0; fY<m_filter[f].h; fY++)
                                {
                                    r+=m_filter[f].weight[fX+fY*m_filter[f].w+m_filter[f].w*m_filter[f].h*d]\
                                       *entry[(x+fX-m_filter[f].w/2)+(y+fY-m_filter[f].h/2)*m_entryVol.w+m_entryVol.w*m_entryVol.h*d];
                                }
                            }
                        }
                        if(m_relu)
                            m_output[x-m_filter[f].w/2+(y-m_filter[f].h/2)*m_outputVol.w]=(r<0)?0:r;
                        else
                            m_output[x-m_filter[f].w/2+(y-m_filter[f].h/2)*m_outputVol.w]=r;
                    }
                }
            }
            return m_output;
        }


    protected:
        int m_depth, m_stride, m_zeroPad;
        std::vector<s_filter> m_filter;
        std::vector<double> m_output;
        s_vol m_entryVol, m_outputVol;
        bool m_relu=true;
};
