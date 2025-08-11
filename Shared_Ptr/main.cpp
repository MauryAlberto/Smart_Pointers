#include <iostream>

template <typename T>
class SharedPtr
{
    public:
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}
    
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count)
    {
        ++(*ref_count);
    }

    SharedPtr& operator=(const SharedPtr& other)
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }

        return *this;
    }

    ~SharedPtr()
    {
        release();
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    int use_count() const { return *ref_count; }


    private:
    T* ptr;
    int* ref_count;

    void release()
    {
        if(--(*ref_count) == 0)
        {
            delete ptr;
            delete ref_count;
        }
    }
};

int main()
{
    SharedPtr<int> sp1(new int(100));
    SharedPtr<int> sp2 = sp1;
    SharedPtr<int> sp3 = sp2;

    std::cout << "sp1 count: " << sp1.use_count() << "\n";
    std::cout << "sp2 value: " << *sp2 << "\n";

    return 0;
}