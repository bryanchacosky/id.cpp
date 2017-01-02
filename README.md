# id.cpp
id class to remove ambiguous string parameters

## problem
It's common to use a `std::string` as a weak id type but this can cause ambigous problems and extra management for the caller:
```c++
object & create (std::string const & id) { ... }
```
`create` can be called with a valid id, a valid id of a different object, or any arbitrary string. And the compiler will be happy.

## solution
`object` needs to define a strongly typed id so invalid ids can be caught at compile time.
```c++
object & create (object::id_type const & id) { ... }
```
Now an `object::id_type` needs to be created to satisfy the compiler.

## example
```c++
class Foo {
public:
    using id_type = id<Foo>; // strongly typed for Foo
    Foo (std::string const & id) : m_id(id) {}
    id_type const & id () const { return m_id; }
private:
    id_type const m_id;
};

struct Bar {
};

int main () {
    Foo foo { "Foo" };
    Foo::id_type const & foo_id = foo.id();
    std::cout << foo_id << std::endl; // prints Foo

    id<Bar> const bar_id = { "Bar" };
    // (foo_id == bar_id); // does not compile

    auto foo_method = [](Foo::id_type const & id) {};
    foo_method(foo_id); // OK
    // foo_method(bar_id); // does not compile
}
```
