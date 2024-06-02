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
    *this = list;
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
    std::swap(head_, list.head_);
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
        std::cout << "V " << temp->vertex.vertex_id << " / " << temp->vertex.key << " -> ";
        temp = temp->next.get();
    }
    std::cout << "nullptr\n";
}

/**
 * Funkcja znajdująca klucz zadanego elementu
 * 
 * @param vertex_id Indeks wierzchołka [int]
 * @return key - Klucz wierzchołka     [int]
*/
int LinkedList::find_key(const int &vertex_id)
{
    auto temp = head_.get();
    while (temp)
    {
        if (temp->vertex.vertex_id == vertex_id)
        {
            return temp->vertex.key;
        }
        temp = temp->next.get();
    }
    return -1;
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