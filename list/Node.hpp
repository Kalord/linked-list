template<typename K, typename T>
class Node
{
public:
    /**
     * Ключ узла
     **/
    K key;
    /**
     * Значение узла
     **/
    T value;
    /**
     * Следующий узел
     **/
    Node<K, T>* next;
    /**
     * Предыдущий узел
     **/
    Node<K, T>* prev;

    Node(K key = K(), T value = T(), Node<K, T>* next = nullptr, Node<K, T>* prev = nullptr) :
    key(key), value(value), next(next), prev(prev)
    {}
};