template <typename T> class Vector {
  public:
    Vector() {}
    ~Vector() {
        if (m_data) {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    void push_back(const T &value) {
        if (m_size == m_capacity) {
            int newCapacity = static_cast<int>(m_capacity * 1.5f);
            if (newCapacity == m_capacity) {
                ++newCapacity;
            }
            reserve(newCapacity);
        }

        m_data[m_size++] = value;
    }

    void reserve(int capacity) {
        if (m_capacity >= capacity)
            return;
        m_capacity = capacity;
        T *newData = new T[m_capacity];

        for (int i = 0; i < m_size; ++i) {
            newData[i] = m_data[i];
        }

        if (m_data)
            delete[] m_data;
        m_data = newData;
    }

    T &operator[](const int pos) { return m_data[pos]; }
    int size() const { return m_size; }
    int capacity() const { return m_capacity; }
    void clear() {
        if (m_data) {
            delete[] m_data;
            m_data = new T[m_capacity];
        }

        m_size = 0;
    }

    void resize(int sz) {
        if (m_size > m_capacity) {
            reserve(sz);
        } else {

            for (int i = sz - 1; i < m_size; ++i) {
                m_data[i] = 0;
            }

            m_size = sz;
        }
    }

  private:
    T *m_data = nullptr;
    int m_size = 0;
    int m_capacity = 0;
};

//Vector<int> v;
//v.reserve(400);
//
//for (int i = 0; i < 100; ++i) {
//    v.push_back(i);
//    cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
//}
//cout << endl;
//v.resize(10);
//for (int i = 0; i < 100; ++i) {
//    cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
//}
//
//cout << v.size() << " " << v.capacity() << endl;