
MaxPoolLayer::MaxPoolLayer(s_vol entryVol, int fW, int fH):m_entryVol(entryVol), m_fW(fW), m_fH(fH)
{
    m_outputVol.w=m_entryVol.w/m_fW;
    m_outputVol.h=m_entryVol.h/m_fH;
    m_outputVol.d=m_entryVol.d;
    m_output.resize(m_outputVol.w*m_outputVol.h*m_outputVol.d);
    std::cout << "(" << m_outputVol.w << ", " << m_outputVol.h << ", " << m_outputVol.d << ", " << m_output.size() << ")" << std::endl;
}
