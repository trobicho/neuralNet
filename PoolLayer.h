#include <vector>
#include <iostream>

typedef struct
{
    int w, h, d;
}s_vol;

class MaxPoolLayer
{
    public:
        MaxPoolLayer(s_vol entryVol, int wF, int hF);
        
        template <typename T>
        std::vector<double>& calc(const std::vector<T> &entry)
        {
            double max, tmp;
            for(int x=0; x<m_entryVol.w/m_fW; x++)
            {
                for(int y=0; y<m_entryVol.h/m_fH; y++)
                {
                    for(int d=0; d<m_entryVol.d; d++)
                    {
                        max=0.0;
                        for(int fX=0; fX<m_fW; fX++)
                        {
                            for(int fY=0; fY<m_fH; fY++)
                            {
                                tmp=entry[x*m_fW+y*m_fH*m_entryVol.w+m_entryVol.w*m_entryVol.h*d];
                                if(max<tmp)
                                    max=tmp;
                            }
                        }
                        m_output[x+y*m_outputVol.w+m_outputVol.w*m_outputVol.h*d]=max;
                    }
                }
            }
            return m_output;
        }

        template <typename T>
        std::vector<double>& calc(const T *entry)
        {
            double max, tmp;
            for(int x=0; x<m_entryVol.w/m_fW; x++)
            {
                for(int y=0; y<m_entryVol.h/m_fH; y++)
                {
                    for(int d=0; d<m_entryVol.d; d++)
                    {
                        max=0.0;
                        for(int fX=0; fX<m_fW; fX++)
                        {
                            for(int fY=0; fY<m_fH; fY++)
                            {
                                tmp=entry[x*m_fW+y*m_fH*m_entryVol.w+m_entryVol.w*m_entryVol.h*d];
                                if(max<tmp)
                                    max=tmp;
                            }
                        }
                        m_output[x+y*m_outputVol.w+m_outputVol.w*m_outputVol.h*d]=max;
                    }
                }
            }
            return m_output;
        }


    protected:
        std::vector<double> m_output;
        s_vol m_entryVol, m_outputVol;
        int m_fW, m_fH;
};
