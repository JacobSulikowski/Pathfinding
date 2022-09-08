#include "icomparable.h"
#ifndef UNIT_H
#define UNIT_H

    
class IUnit : public IComparable<IUnit>{ 

    public:
        virtual void resetstate();

        virtual void setGValue(int _val);
        virtual void setHValue(int _val);
        virtual void setFValue(int _val);

        //Indication that setPreviousUnit() (Node) should be implemented
        virtual void setPreviousUnit();
        virtual void setChecked();
        virtual void setAdded();
        virtual void setWalkable();
        virtual bool compare(IUnit _toCompare) override;
        
        virtual int getGValue();
        virtual int getHValue();
        virtual int getFValue();
        virtual bool isChecked();
        virtual bool isWalkable();
        virtual bool isAdded();
};

#endif