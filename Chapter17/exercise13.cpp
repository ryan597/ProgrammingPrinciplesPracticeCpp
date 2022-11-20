#include <iostream>
#include <string>


struct God
{
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;

    God(const std::string& n, const std::string&m, const std::string& v, const std::string& w)
        : name(n), mythology(m), vehicle(v), weapon(w) {}
};

auto operator<< (std::ostream& os, God& g) -> std::ostream&
{
    os << "Name: " << g.name << ", Mythology: " << g.mythology << ", Vehicle: " << g.vehicle << ", Weapon: " << g.weapon << '\n';
    return os;
}

class Link
{

public:
    God value;

    Link(const std::string& n, const std::string& m, const std::string& v, const std::string& w, Link* p=nullptr, Link* s=nullptr)
        : value(n, m, v, w), prev(p), succ(s) {}

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
        if (curr->value.name == s)
            return curr;
        curr = succ;
    }
    return nullptr;
}

// Exercise 12 - two finds are defined to handle the case where a const Link*
// calls the find and when a non-const does
auto Link::find(const std::string& s) const -> const Link*
{
    if (value.name == s)
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
    std::cout << "{\n";
    while(p)
    {
        std::cout << p->value;
        p = p->next();
    }
    std::cout << "}\n";
}

auto main() -> int
{
    Link* gods = new Link{"Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"};
    gods = gods->insert(new Link{"Zeus", "Greek", "", "Lightning"});


    print_all(gods);
}