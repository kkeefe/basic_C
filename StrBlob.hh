#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>

//define the class structure as well as all functions / definitions used therin..
class StrBlob 
{
    typedef std::vector<std::string>::size_type size_type;
    
    public:
        //include your constructors
        StrBlob(); //default
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
    return data->front();
}

std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}