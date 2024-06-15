/**
 * Lista jednokierunkowa
*/

#include "linked_list.h"

/**
 * Konstruktor klasy LinkedList
*/
LinkedList::LinkedList()
    : head_(nullptr)
{ }

/**
 * Konstruktor kopiujący klasy LinkedList
*/
LinkedList::LinkedList(const LinkedList& list)
    : head_(nullptr)
{
    auto temp = list.head_.get();
    while (temp)
    {
        head_ = std::make_unique<Node>(Structures::Vertex(temp->vertex.vertex_id, temp->vertex.key), std::move(head_));
        temp = temp->next.get();
    }
}

/**
 * Konstruktor przenoszenia klasy LinkedList
*/
LinkedList::LinkedList(LinkedList&& list)
    : head_(nullptr)
{
    head_ = std::move(list.head_);
}

/**
 * Operator kopiowania
*/
LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if (this == &list) { return *this; }

    auto temp = list.head_.get();
    while (temp)
    {
        head_ = std::make_unique<Node>(Structures::Vertex(temp->vertex.vertex_id, temp->vertex.key), std::move(head_));
        temp = temp->next.get();
    }

    return *this;
}

/**
 * Operator przenoszenia
*/
LinkedList& LinkedList::operator=(LinkedList&& list)
{
    head_ = std::move(list.head_);
    return *this;
}

/**
 * Destruktor klasy LinkedList
*/
LinkedList::~LinkedList()
{
    while (head_)
    {
        auto next = std::move(head_->next);
        head_ = std::move(next);
    }
}

/**
 * Funkcja wyświetlająca listę
*/
void LinkedList::print() const
{
    auto temp = head_.get();
    while (temp)
    {
        std::cout << temp->vertex.vertex_id << " / " << temp->vertex.key << " -> ";
        temp = temp->next.get();
    }
    std::cout << "nullptr\n";
}

/**
 * Funkcja dodająca element na początku listy
*/
void LinkedList::push_front(const int &vertex_id, const int &weight)
{
    head_ = std::make_unique<Node>(Structures::Vertex(vertex_id, weight), std::move(head_));
}

/**
 * Funkcja usuwająca element z początka listy
*/
void LinkedList::pop_front()
{
    head_ = std::move(head_->next);
}

/**
 * Konstruktory domyślny klasy Iterator
*/
LinkedList::Iterator::Iterator()
    : current_node_(nullptr)
{ }

/**
 * Konstruktor z zainicjalizowanym wskaźnikiem
*/
LinkedList::Iterator::Iterator(const std::unique_ptr<Node> &node)
    :current_node_(node.get())
{ }

/**
 * Operator dereferencji
*/
Structures::Vertex & LinkedList::Iterator::operator*() const
{
    return this->current_node_->vertex;
}

/**
 * Operator inkrementacji
*/
LinkedList::Iterator& LinkedList::Iterator::operator++()
{
    if (current_node_ != nullptr)
    {
        previous_node = current_node_;
        current_node_ = current_node_->next.get();
    }
    return *this;
}

/**
 * Operator równości
*/
bool LinkedList::Iterator::operator==(Iterator iterator) const
{
    return this->current_node_ == iterator.current_node_;
}

/**
 * Operator nierówności
*/
bool LinkedList::Iterator::operator!=(Iterator iterator) const
{
    return this->current_node_ != iterator.current_node_;
}

/**
 * Iterator zwracający wskaźnik na początek listy
*/
LinkedList::Iterator LinkedList::begin() const
{
    return LinkedList::Iterator(this->head_);
}

/**
 * Iterator zwracający wskaźnik na koniec listy
*/
LinkedList::Iterator LinkedList::end() const
{
    return Iterator();
}