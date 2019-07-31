MKDEP=$(CXX) -MM
SRCS=NeuralNet.cpp Layer.cpp ConvLayer.cpp
HDRS=NeuralNet.h Layer.h Sigmoide.h ConvLayer.h ActivFunc.h
OUTS=NeuralNet.o Layer.o ConvLayer.o
CFLAGS=-g

neuralNet: $(OUTS)
	ar rcs libneuralNet.a $(OUTS)

depend: .depend
.depend: $(SRCS) $(HDRS)
	$(MKDEP) $(CFLAGS) $(SRCS) > .depend
-include .depend
