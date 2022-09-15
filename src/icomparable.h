#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H
template <class T> 
class IComparable {

    public:
        virtual bool compare(T _toCompare) =0;
};
#endif