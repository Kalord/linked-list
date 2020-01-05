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
};