#include "node.h"
#include <list>
#ifndef BOARD_H
#define BOARD_H
class Board{
    private:
        int height;
        int width;
        Node *board = nullptr; 
        Node *currentNode;
        std::list<Node*> nodesToAnalyze;
        std::list<Node> path;
        Node *startingNode;
        void setNodes();
        Node *endingNode;
    public:
        Board(int height,int width); 
        ~Board();
        void setBoard(int _height, int _width);
        void clearNodeToAnalyze();
        void setStartingNode(Node *_node);
        void setEndingNode(Node *_node);
        void findPath(Node _startingNode,Node _endingNode);
        Node getBoard(int i);
        Node *getNode(int x,int y); 
        int getHeight();
        int getWidth();
        void printPath();
        void addNodeToAnalyze(Node _currentNode);
        void analyzeNode(Node &_nodesToAnalyze, Node _startingNode,Node _endingNode);
        void setCurrentNode(Node *_node);
        void setPath();
        std::list<Node*> getNodesToAnalyze();
};
#endif