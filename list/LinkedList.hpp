#include <iostream>
#include <cstddef>

#include "Node.hpp"

template<typename K, typename T>
class LinkedList
{
private:
    /**
     * Первый элемент в связанном списке
     **/
    Node<K, T>* root;
    /**
     * Размер связанного списка
     **/
    size_t size;
public:
    LinkedList() :
    root(nullptr), size(0)
    {}

    ~LinkedList()
    {
        while (this->size)
        {
            pop();
        }
    }

    /**
     * Добавление элемента в начало связанного списка
     **/
    void push(K key, T value)
    {
        this->root = new Node<K, T>(key, value, this->root);
        this->size++;
    }

    /**
     * Получение и удаление первого элемента связанного списка
     **/
    T pop()
    {
        if(!this->size) return T();

        Node<K, T>* node = this->root;
        this->root = node->next;

        T value = node->value;
        delete node;
        this->size--;

        return value;
    }

    /**
     * Итерация по связанному списку
     **/
    Node<K, T>* iterator(K key)
    {
        Node<K, T>* current = this->root;

        for(int i = 0; i < this->getSize(); i++)
        {
            if(current->key == key) return current;
            current = current->next;
        }

        return nullptr;
    }

    /**
     * Получение элемента по ключу
     **/
    T operator[](K key)
    {
        Node<K, T>* node = this->iterator(key);

        if(node) return node->value;
        return T();
    }

    /**
     * Удаление узла с определенным ключом
     **/
    void remove(K key)
    {
        Node<K, T>* node = this->iterator(key);

        if(node->prev) node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;

        delete node;
        this->size--;
    }

    size_t getSize()
    {
        return this->size;
    }
};