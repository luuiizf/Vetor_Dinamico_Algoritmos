#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
#include <stdexcept>


class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() {
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() {
        return this->size_;
    }
    unsigned int capacitty() {
         return this->size_;
    }
    double percent_occupied() {
        return 100.0;
    }
    bool insert_at(unsigned int index, int value) {
        if (index > this->size_) {
            return false; // Índice fora do intervalo
        }

        int_node* new_node = new int_node;
        new_node->value = value;

        if (index == 0) {
            // Inserir no início
            new_node->next = this->head;
            new_node->prev = nullptr;
            if (this->head != nullptr) {
                this->head->prev = new_node;
            }
            this->head = new_node;
            if (this->tail == nullptr) {
                this->tail = new_node;
            }
        } else if (index == this->size_) {
            // Inserir no final
            new_node->next = nullptr;
            new_node->prev = this->tail;
            if (this->tail != nullptr) {
                this->tail->next = new_node;
            }
            this->tail = new_node;
            if (this->head == nullptr) {
                this->head = new_node;
            }
        } else {
            // Inserir no meio
            int_node* current = this->head;
            for (unsigned int i = 0; i < index; ++i) {
                current = current->next;
            }
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }

        this->size_++;
        return true;
    }
    bool remove_at(unsigned int index) {
    if (index >= this->size_)
        return false; // Não removeu

    int_node* to_remove = this->head;

    for (unsigned int i = 0; i < index; ++i)
        to_remove = to_remove->next;

    if (to_remove->prev != nullptr)
        to_remove->prev->next = to_remove->next;
    else
        this->head = to_remove->next; // Atualiza a cabeça se o primeiro nó está sendo removido

    if (to_remove->next != nullptr)
        to_remove->next->prev = to_remove->prev;
    else
        this->tail = to_remove->prev; // Atualiza a cauda se o último nó está sendo removido

    delete to_remove;
    --this->size_; // Decrementa o tamanho da lista

    return true; // Removeu
}

int get_at(unsigned int index) {
    // Verifica se o índice está fora dos limites
    if (index >= this->size_) {
        throw std::out_of_range("error");
    }
    int_node* current = this->head;

    // Percorre a lista até o índice especificado
    for (unsigned int i = 0; i < index; ++i) {
        if (current == nullptr) {
            throw std::out_of_range("error");
        }
        current = current->next;
    }

    // Retorna o valor no índice especificado
    return current->value;
}

    void clear() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    void push_back(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;

        if (this->tail != nullptr) {
            this->tail->next = new_node;
        }
        this->tail = new_node;

        if (this->head == nullptr) {
            this->head = new_node;
        }

        this->size_++;
    }
    void push_front(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
        this->size_++;
    }
    bool pop_back() {
        if (this->tail == nullptr) {
            return false;
        }

        int_node* to_remove = this->tail;
        if (this->tail->prev != nullptr) {
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
        } else {
            this->head = nullptr;
            this->tail = nullptr;
        }

        delete to_remove;
        this->size_--;
        return true;
    }
    bool pop_front() {
        if (this->head == nullptr) {
            return false;
        }

        int_node* to_remove = this->head;
        if (this->head->next != nullptr) {
            this->head = this->head->next;
            this->head->prev = nullptr;
        } else {
            this->head = nullptr;
            this->tail = nullptr;
        }

        delete to_remove;
        this->size_--;
        return true;
    }
    int front() {
        if (this->head == nullptr) {
            throw std::out_of_range("A lista está vazia.");
        }
        return this->head->value;
    }
    int back() {
        if (this->tail == nullptr) {
            throw std::out_of_range("A lista está vazia.");
        }
        return this->tail->value;
    }
    bool remove(int value) {
        int_node* current = this->head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                if (current->next != nullptr)
                    current->next->prev = current->prev;
                if (current == this->head)
                    this->head = current->next;
                if (current == this->tail)
                    this->tail = current->prev;
                delete current;
                this->size_--;
                return true; // Removeu
            }
            current = current->next;
        }
        return false;
    }
    int find(int value) {
        int_node* current = this->head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    int count(int value) {
        int_node* current = this->head;
        int conta = 0;
        while (current != nullptr) {
            if (current->value == value) {
                conta++;
            }
            current = current->next;
        }
        return conta;
    }
    int sum() {
        int_node* current = this->head;
        int soma = 0;
        while (current != nullptr) {
            soma += current->value;
            current = current->next;
        }
        return soma;
    }
};

#endif // __LINKED_LIST_IFRN__