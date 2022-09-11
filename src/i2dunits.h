#include <utility>
#ifndef I2DUNITS_H
#define I2DUNITS_H
class I2DUnits{
    public:
        virtual std::pair<int,int> getCoordinates2D(); 
        virtual std::pair<int,int> getPreviousNodeCoordinates2D(); 
        virtual void setPreviousUnit2D(int _valX,int _valY); 
        virtual void setUnitCoordinates2D(int _valX,int _valY);
};
#endif