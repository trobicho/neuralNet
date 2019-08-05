CC = g++
CFLAGS = -std=c++11 -g
SRCS = Neuron.cpp NeuralNet.cpp ConvLayer.cpp Layer.cpp
HDRS = Neuron.h PoolLayer.h NeuralNet.h ConvLayer.h Gen_layer.h Layer.h Abs_layer.hd ActivFunc.h Sigmoide.h
OUTS = $(SRCS:.cpp=.o)
NAME = libneuralNet.a

all: $(NAME)

$(NAME): $(OUTS)
	ar sucr $(NAME) $(OUTS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
