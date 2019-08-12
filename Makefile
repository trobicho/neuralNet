MKDEP=$(CXX) -MM
SRCS=NeuralNet.cpp Layer.cpp ConvLayer.cpp
HDRS=NeuralNet.h Layer.h Sigmoide.h ConvLayer.h ActivFunc.h
OUTS=NeuralNet.o Layer.o ConvLayer.o
CFLAGS=-g
NAME = libneuralNet.a

all: $(NAME) Makefile

$(NAME): $(OUTS)
	ar rcs $(NAME) $(OUTS)

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

depend: .depend
.depend: $(SRCS) $(HDRS)
	$(MKDEP) $(CFLAGS) $(SRCS) > .depend
-include .depend
