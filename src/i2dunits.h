#include <utility>
#ifndef I2DUNITS_H
#define I2DUNITS_H
class I2DUnits{
    public:
        I2DUnits() = default;
        virtual ~I2DUnits() {};
        virtual std::pair<int,int> getCoordinates2D()=0; 
        virtual std::pair<int,int> getPreviousNodeCoordinates2D()=0; 
        virtual void initializeUnit2D(int _valX,int _valY)=0;
        virtual void setPreviousUnit2D(int _valX,int _valY)=0; 
        virtual void setUnitCoordinates2D(int _valX,int _valY)=0;
};
#endif