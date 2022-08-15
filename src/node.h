#ifndef NODE_H
#define NODE_H
class Node{
    private:
        int x;
        int y;
        int gValue;
        int hValue;
        int fValue;
        bool walkable;
        bool checked;
        bool added;
        int previousX;
        int previousY;
    public:
    
        void resetState();
    //setters
        void setX(int _val);
        void setY(int _val);
        void setGValue(int _val);
        void setHValue(int _val);
        void setFValue(int _val);
        bool equalNode(Node _node);
        void setPreviousX(int _val);
        void setPreviousY(int _val);
        void setPreviousNode(int _valX,int _valY);
        void setChecked(bool _val);
        void setAdded(bool _val);
        void setWalkable(bool _val);
    //constructor

    
    //getters
        int getX();
        int getY();
        int getGValue();
        int getHValue();
        int getFValue();
        int getPreviousX();
        int getPreviousY();
        bool isChecked();
        bool isWalkable();
        bool isAdded();
};
#endif