CXX = g++
SRCS=NeuralNet.cpp Layer.cpp ConvLayer.cpp
HDRS=NeuralNet.h Layer.h Sigmoide.h ConvLayer.h ActivFunc.h
OUTS=NeuralNet.o Layer.o ConvLayer.o
CFLAGS = -std=c++11 -g
NAME = libneuralNet.a

all: $(NAME) Makefile

$(NAME): $(OUTS)
	ar rcs $(NAME) $(OUTS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
