#ifndef container_h
#define container_h

template <typename T>
class Container
{
  public:
    virtual T& operator[](int i) = 0;
    virtual int size() const = 0;
    virtual ~Container() {};
};

template class Container<double>;
// TODO not quite sure how to organize this code properly, but not in a mood right now to think deep about this

// the point is i am experimenting with keeping template definitions separately, but the question is how to allow make to compile specialization efficiently, and how this related to class hierarchies

#endif

