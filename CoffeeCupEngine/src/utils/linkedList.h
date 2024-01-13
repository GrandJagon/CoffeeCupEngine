#pragma once

class Node
{
public:
    std::shared_ptr<Node> next = nullptr;
    virtual ~Node() = default;
};

class LinkedList
{
public:
    virtual ~LinkedList() = default;

    std::shared_ptr<Node> head = nullptr;

    void add(std::shared_ptr<Node> newNode)
    {
        if (head == nullptr)
        {
            printf("LinkedList.add() : Adding new node as head");
            head = newNode;
            return;
        };

        printf("LinkedList.add() : Adding new node");
        newNode->next = head;
        head = newNode;
    };

    void insertAfterNode(std::shared_ptr<Node> node, std::shared_ptr<Node> newNode)
    {
        newNode->next = node->next;
        node->next = newNode;
    };

    void remove(std::shared_ptr<Node> node)
    {
        std::shared_ptr<Node> i = node->next;

        while (i != nullptr)
        {
            if (i->next == node)
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