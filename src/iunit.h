#ifndef UNIT_H
#define UNIT_H

    
template <class T> class IUnit { 
    protected:
        int GValue;
        int HValue;
        int FValue;
        bool checked;
        bool walkable;
        bool added;


        virtual void resetstate();

        virtual void setGValue(int _val);
        virtual void setHValue(int _val);
        virtual void setFValue(int _val);
        virtual bool equalUnit(T _unit);

        //Indication that setPreviousUnit() (Node) should be implemented
        virtual void setPreviousUnit();
        virtual void setChecked();
        virtual void setAdded();
        virtual void setWalkable();
        
        virtual int getGValue();
        virtual int getHValue();
        virtual int getFValue();
        virtual bool isChecked();
        virtual bool isWalkable();
        virtual bool isAdded();
};

#endif