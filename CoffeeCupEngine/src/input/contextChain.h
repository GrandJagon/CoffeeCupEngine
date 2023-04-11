#pragma once

#include "inputContext.h"

// Node holding an input context
typedef struct Node
{
    std::shared_ptr<InputContext> data;
    Node *next;

    Node(std::shared_ptr<InputContext> context)
    {
        data = context;
        next = nullptr;
    };
};

// Chain of responsability 
typedef struct ContextChain
{
    Node *head;

    ContextChain() {head = nullptr};

    void insertNode(Node *newNode)
    {
        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode.next = head;
        head = newNode;
    };

    void insertAfter(Node *node, Node *newNode)
    {  
        newNode->next = node->next;
        node->next = newNode;
    };

    void deleteNode(Node *node)
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

        std::cout << "Node item in context chain not found for deletion" << std::endl;
        return;
    };
};