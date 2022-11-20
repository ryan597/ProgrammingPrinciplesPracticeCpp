#include <iostream>
#include <string>


class Link
{

public:
    std::string value;

    Link(std::string v, Link* p=nullptr, Link* s=nullptr)
        : value(std::move(v)), prev(p), succ(s) {}

    auto insert(Link* n) -> Link*;                          // insert n before this
    auto add(Link* n) -> Link*;                             // insert n after this
    auto erase() -> Link*;                                  // remove this from list
    auto find(const std::string& s) -> Link*;               // find s in list
    auto find(const std::string& s) const -> const Link*;   // find s in const list

    auto advance(int n) const -> const Link*;               // move n positions in list

    auto next() const -> Link* {return succ;}
    auto previous() const -> Link* {return prev;}

private:
    Link* prev;
    Link* succ;
};

auto Link::insert(Link* n) -> Link*  // insert n before this, return n
{
    if (n == nullptr) return this;  // nothing to insert  (use "this" to refer to the whole object)
    n->succ = this;  // this after n
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;  // n infront of p
    return n;
}

auto Link::add(Link* n) -> Link*
{
    if (n == nullptr) return this;
    if (succ)
    {
        n->succ = succ;
        succ->prev = n;
    }
    succ = n;
    n->prev = this;
    return this;
}


auto Link::erase() -> Link*
{
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

auto Link::find(const std::string& s) -> Link*
{
    Link* curr = this;
    //while(curr)
    //{
    //    if (curr->value == s)
    //        return curr;
    //    curr = prev;
    //}
    //curr = this->succ;
    while (curr)
    {
        if (curr->value == s)
            return curr;
        curr = succ;
    }
    return nullptr;
}

// Exercise 12 - two finds are defined to handle the case where a const Link*
// calls the find and when a non-const does
auto Link::find(const std::string& s) const -> const Link*
{
    if (value == s)
        return this;
    else if (succ)
        return succ->find(s);

    return nullptr;
}

auto Link::advance(int n) const -> const Link*
{
    if (0 < n) {
        if (succ == nullptr) return nullptr;

        return succ->advance(--n);
    }
    else if (n < 0) {
        if (prev == nullptr) return nullptr;

        return prev->advance(++n);
    }
    return this;
}

auto print_all(Link* p) -> void
{
    std::cout << '{';
    while(p)
    {
        std::cout << p->value;
        if (p = p->next())
        {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

auto main() -> int
{
    Link* norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});


    Link* p = greek_gods->find("Mars");
    if (p)
    {
        p->value = "Ares";
    }

    Link* p2 = norse_gods->find("Zeus");
    if (p2)
    {
        if (p2 == norse_gods)
            norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    print_all(greek_gods);
}