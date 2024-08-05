#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
  int *data;
  unsigned int size_, capacity_;
  void increase_capacity() {
    capacity_ += 2;
    int *new_data = new int[capacity_];
    for (unsigned int i = 0; i < size_; ++i) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
  }

public:
  array_list() {
    data = new int[100];
    this->size_ = 0;
    this->capacity_ = 100;
  }
  ~array_list() { delete[] data; }
  unsigned int size() { return this->size_; }

  unsigned int capacity() { return this->capacity_; }

  double percent_occupied() {
    return (static_cast<double>(this->size_) / this->capacity_) * 100;
  }

  bool insert_at(unsigned int index, int value) {
    if (index > this->size_) {
      return false;
    }
    if (this->size_ == this->capacity_) {
      increase_capacity();
    }
    for (unsigned int i = this->size_; i > index; --i) {
      data[i] = data[i - 1];
    }
    data[index] = value;
    ++this->size_;
    return true;
  }

  bool remove_at(unsigned int index) {
    if (index >= this->size_)
      return false; // Não removeu
    for (unsigned int i = index + 1; i < this->size_; ++i) {
      this->data[i - 1] = this->data[i];
    }
    this->size_--;
    return true; // Removeu
  }

  int get_at(unsigned int index) {
    // TODO: Check if index is valid
    return this->data[index];
  }x

  void clear() {
    this->size_ = 0;
    this->capacity_ = 0;
    delete[] data;
    data = new int[capacity_];
  }

  void push_back(int value) {
    if (this->size_ == this->capacity_)
      increase_capacity();
    this->data[size_++] = value;
  }

  void push_front(int value) {
    if (this->size_ == this->capacity_)
      increase_capacity();
    for (int i = this->size_; i > 0; --i) {
      data[i] = data[i - 1];
    }
    data[0] = value;
    ++this->size_;
  }

  bool pop_back() {
    if (this->size_ == 0) {
      return false; // Lista vazia
    }
    --this->size_;
    return true;
  }

  bool pop_front() {
    if (this->size_ == 0) {
      return false; // Lista vazia
    }
    for (unsigned int i = 1; i < size_; ++i) {
      data[i - 1] = data[i];
    }
    --this->size_;
    return true;
  }

  int front() {
    if (this->size_ > 0)
      return this->data[0];
    return -1;
  }

  int back() {
    if (this->size_ > 0)
      return this->data[this->size_ - 1];
    return -1;
  }

  bool remove(int value) {
    int index = find(value);
    if (index != -1) {
      remove_at(index);
      return true;
    }
    return false;
  }

  int find(int value) {
    for (unsigned int i = 0; i < this->size_; ++i) {
      if (this->data[i] == value) {
        return i;
      }
    }
    return -1;
  }

  int count(int value) {
    int conta = 0;
    for (unsigned int i = 0; i < this->size_; ++i) {
      if (this->data[i] == value) {
        conta++;
      }
    }
    return conta;
  }

  int sum() {
    int soma = 0;
    for (unsigned int i = 0; i < this->size_; ++i) {
      soma += this->data[i];
    }
    return soma;
  }
};

#endif // __ARRAY_LIST_IFRN__                                                                                                  