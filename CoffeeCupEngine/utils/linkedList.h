#pragma once

class Node
{
    public: 
        Node *next = nullptr;
};


class LinkedList
{
    public:
        virtual ~LinkedList() = default;
    
        Node *head = nullptr;

        void add(Node *newNode)
        {
            if(head == nullptr)
            {
                head = newNode;
                return;
            };

            newNode.next = head;
            head = newNode;
        };

        void insertAfterNode(Node *node, Node *newNode)
        {  
            newNode->next = node->next;
            node->next = newNode;
        };

        void remove(Node *node)
        {
            Node *i = node->next;
            
            while(i != nullptr)
            {   
                if(i->next = node)
                {
                    // deletion here
                    i->next = node->next;
                    return;
                }

                i = i->next;
            };

            std::cout << "Node in linked list not found for deletion" << std::endl;
            return;
        };
};