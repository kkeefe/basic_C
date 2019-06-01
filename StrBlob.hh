#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>

//define the class structure as well as all functions / definitions used therin..
class StrBlobPtr; // give the forward declaration so it's known in StrBlob..
class StrBlob
{
    typedef std::vector<std::string>::size_type size_type;

    // for exercise 12.19 stuff
    friend class StrBlobPtr;

    public:
        //include your constructors
        StrBlob(); //default
        // initializer_list is a template which tolds a comma separted list of type <T>
        StrBlob(std::initializer_list<std::string> il);

        //include your member functions
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        //add or remove stuff
        void push_back(const std::string &t) { data->push_back(t); }
        void pop_back();

        //element access - these functions should be const member functions, 
        std::string& front() const;
        std::string& back() const;

        // functions used to make StrBlobPtrs..
        StrBlobPtr begin();
        StrBlobPtr end();

    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i, const std::string &msg) const;
};

// lets define those constructors..
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { };
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };

// lets start defining some of the stuff you've created for this class..
void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    throw std::out_of_range(msg);
}

std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    // front is a vector method which returns the first element in the vector
    return data->front();
}

std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    // back is a vector method which returns the last element in the vector
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    // pop_back is a vector method which deletes the last element in the vector
    data->pop_back();
}

//////////////////// StrBlobPtr Stuff ////////////////////
class StrBlobPtr{

    typedef std::vector<std::string>::size_type size_type;

    public:
        StrBlobPtr(): curr(0) {  }
        StrBlobPtr(StrBlob &a , size_type sz = 0): wptr(a.data), curr(sz) {  }

        std::string& deref() const;
        StrBlobPtr& incr();
    private:
        std::shared_ptr<std::vector<std::string>> check(size_type, const std::string&) const;
        std::weak_ptr<std::vector<std::string>> wptr;
        size_type curr;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(size_type i, const std::string &msg) const
{
    // check to see if the wptr has expired or not
    auto ret = wptr.lock();

    // if it has, throw a runtime error
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");

    // if the range exceeds the ptr, say that's to big
    if( i >= ret->size() ) throw std::out_of_range(msg);

    // if everything is good, give the ptr back.
    return ret;
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr , "dereference past end");
    return (*p)[curr];
}

// prefix: return a reference to the incremented state
StrBlobPtr& StrBlobPtr::incr()
{
    // if curr already points past the end of the container, can't increment is
    auto p = check(curr , "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
