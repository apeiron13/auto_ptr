#ifndef STRING_PTR_H
#define STRING_PTR_H

#include<string>

class string_ptr
{
public:
    typedef std::string element_type;
       
    explicit
        string_ptr(std::string* p = 0):
        m_ptr(p)
    {}

    ~string_ptr()
    {
        delete m_ptr;
    }
 	
    string_ptr(string_ptr& r):
        m_ptr(r.m_ptr)
        {
        r.release();
        }

    string_ptr& operator=(string_ptr& r)
    {
        string_ptr temp(r);
        temp.swap(*this);
        return *this;
        //r.release();
    }

    const std::string& operator*()  const
    {
        return *m_ptr;
    }

    std::string& operator*()
    {
        return *m_ptr;
    }
	
    const std::string* operator->() const
    {
        return m_ptr;
    }

    std::string* operator->()
    {
        return m_ptr;
    }
	
    const std::string* get() const
    {
        return m_ptr;
    }

    std::string* get()
    {
        return m_ptr;
    }
	
    std::string* release()
    {
        std::string* temp = m_ptr;
        m_ptr = nullptr;
        return temp;
    }

    private:
    std::string* m_ptr;

    void swap(string_ptr& r)
    {
        string_ptr temp(r);
        r.m_ptr = this->m_ptr;
        this->m_ptr = temp.m_ptr;
        //r.m_ptr = temp.m_ptr;
    }
};

#endif // STRING_PTR_H