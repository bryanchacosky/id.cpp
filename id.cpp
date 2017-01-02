template <typename T>
class id {
public:
    id (std::string const & string) : m_value { string } {}
    id (const char * c_string) : m_value { c_string } {}

    // comparison operators
    bool operator <  (id const & rhs) const { return m_value <  rhs.m_value; }
    bool operator >  (id const & rhs) const { return m_value >  rhs.m_value; }
    bool operator <= (id const & rhs) const { return m_value <= rhs.m_value; }
    bool operator >= (id const & rhs) const { return m_value >= rhs.m_value; }
    bool operator == (id const & rhs) const { return m_value == rhs.m_value; }
    bool operator != (id const & rhs) const { return m_value != rhs.m_value; }

private:
    template <typename U>
    friend std::ostream & operator << (std::ostream & stream, id<U> const & id);

private:
    std::string const m_value;
};

template <typename T>
std::ostream & operator << (std::ostream & stream, id<T> const & id) {
    stream << id.m_value;
    return stream;
}
