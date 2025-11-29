#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <set>

template <typename T>
class Graph {
public:
    using vertex_type = T;
    using edge_type = std::pair<size_t, size_t>;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;

private:
    std::vector <vertex_type> vertices_;
    std::vector <edge_type> edges_;

    void check_vertex_index(size_t idx) const {
        if (idx >= vertices_.size()) {
            throw std::out_of_range("Vertex index out of range");
        }
    }

    static edge_type normalize(size_t u, size_t v) {
        return u < v ? edge_type(u, v) : edge_type(v, u);
    }

    bool edge_exists(size_t u, size_t v) const {
        edge_type e = normalize(u, v);
        auto it = std::lower_bound(edges_.begin(), edges_.end(), e);
        return (it != edges_.end() && *it == e);
    }

    size_type compute_degree(size_t v) const {
        size_type deg = 0;
        for (const auto& e : edges_) {
            if (e.first == v || e.second == v) ++deg;
        }
        return deg;
    }

public:
    Graph() = default;
    Graph(const Graph& other) : vertices_(other.vertices_), edges_(other.edges_) {}
    Graph& operator=(const Graph& other) {
        if (this != &other) {
            vertices_ = other.vertices_;
            edges_ = other.edges_;
        }
        return *this;
    }
    ~Graph() = default;

    bool empty() const noexcept {
        return vertices_.empty();
    }

    void clear() noexcept {
        vertices_.clear();
        edges_.clear();
    }

    size_type size() const noexcept {
        return vertices_.size();
    }

    size_type vertices_count() const noexcept {
        return vertices_.size();
    }

    size_type edges_count() const noexcept {
        return edges_.size();
    }

    void add_vertex(const vertex_type& val) {
        vertices_.push_back(val);
    }

    bool has_vertex(const vertex_type& val) const {
        return std::find(vertices_.begin(), vertices_.end(), val) != vertices_.end();
    }

    bool has_edge(size_t u, size_t v) const {
        check_vertex_index(u);
        check_vertex_index(v);
        if (u == v)
            return false;
        return edge_exists(u, v);
    }

    void add_edge(size_t u, size_t v) {
        check_vertex_index(u);
        check_vertex_index(v);
        if (u == v)
            return;
        edge_type e = normalize(u, v);

        auto it = std::lower_bound(edges_.begin(), edges_.end(), e);
        if (it == edges_.end() || *it != e) {
            edges_.insert(it, e);
        }
    }

    void remove_edge(size_t u, size_t v) {
        check_vertex_index(u);
        check_vertex_index(v);
        if (u == v)
            return;

        edge_type e = normalize(u, v);
        auto it = std::lower_bound(edges_.begin(), edges_.end(), e);
        if (it != edges_.end() && *it == e) {
            edges_.erase(it);
        }
    }

    size_type degree(size_t v) const {
        check_vertex_index(v);
        return compute_degree(v);
    }

    // Итераторы по вершинам
    class vertex_iterator {
        friend class Graph;
        using iter_type = typename std::vector<vertex_type>::iterator;
        iter_type it_;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type  = Graph::vertex_type;
        using reference = Graph::reference;
        using pointer = Graph::pointer;
        using difference_type = Graph::difference_type;

        explicit vertex_iterator(iter_type it) : it_(it) {}
        reference operator*() const {
            return *it_;
        }
        pointer operator->() const {
            return &(*it_);
        }
        vertex_iterator& operator++() {
            ++it_;
            return *this;
        }
        vertex_iterator& operator--() {
            --it_;
            return *this;
        }
        vertex_iterator operator++(int) {
            auto tmp = *this;
            ++(*this); return tmp;
        }
        vertex_iterator operator--(int) {
            auto tmp = *this;
            --(*this);
            return tmp; }
        bool operator==(const vertex_iterator& other) const {
            return it_ == other.it_;
        }
        bool operator!=(const vertex_iterator& other) const {
            return !(*this == other);
        }
    };

    class const_vertex_iterator {
        friend class Graph;
        using iter_type = typename std::vector<vertex_type>::const_iterator;
        iter_type it_;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = Graph::vertex_type;
        using reference         = Graph::const_reference;
        using pointer           = Graph::const_pointer;
        using difference_type   = Graph::difference_type;

        explicit const_vertex_iterator(iter_type it) : it_(it) {}
        reference operator*() const { return *it_; }
        pointer operator->() const { return &(*it_); }
        const_vertex_iterator& operator++() { ++it_; return *this; }
        const_vertex_iterator& operator--() { --it_; return *this; }
        const_vertex_iterator operator++(int) { auto tmp = *this; ++(*this); return tmp; }
        const_vertex_iterator operator--(int) { auto tmp = *this; --(*this); return tmp; }
        bool operator==(const const_vertex_iterator& other) const { return it_ == other.it_; }
        bool operator!=(const const_vertex_iterator& other) const { return !(*this == other); }
    };

    vertex_iterator vertex_begin() {
        return vertex_iterator(vertices_.begin());
    }
    vertex_iterator vertex_end() {
        return vertex_iterator(vertices_.end());
    }
    const_vertex_iterator vertex_cbegin() const {
        return const_vertex_iterator(vertices_.cbegin());
    }
    const_vertex_iterator vertex_cend() const {
        return const_vertex_iterator(vertices_.cend());
    }

    using reverse_vertex_iterator = std::reverse_iterator<vertex_iterator>;
    using const_reverse_vertex_iterator = std::reverse_iterator<const_vertex_iterator>;

    reverse_vertex_iterator vertex_rbegin() {
        return reverse_vertex_iterator(vertex_end());
    }
    reverse_vertex_iterator vertex_rend() {
        return reverse_vertex_iterator(vertex_begin());
    }
    const_reverse_vertex_iterator vertex_crbegin() const {
        return const_reverse_vertex_iterator(vertex_cend());
    }
    const_reverse_vertex_iterator vertex_crend() const {
        return const_reverse_vertex_iterator(vertex_cbegin());
    }

    class edge_iterator {
        typename std::vector<edge_type>::const_iterator it_;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = edge_type;
        using reference = const edge_type&;
        using pointer = const edge_type*;
        using difference_type = Graph::difference_type;

        explicit edge_iterator(typename std::vector<edge_type>::const_iterator it) : it_(it) {}
        reference operator*() const {
            return *it_;
        }
        pointer operator->() const {
            return &(*it_);
        }
        edge_iterator& operator++() {
            ++it_;
            return *this;
        }
        edge_iterator& operator--() {
            --it_;
            return *this;
        }
        edge_iterator operator++(int) {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }
        edge_iterator operator--(int) {
            auto tmp = *this;
            --(*this);
            return tmp;
        }
        bool operator==(const edge_iterator& other) const { return it_ == other.it_; }
        bool operator!=(const edge_iterator& other) const { return !(*this == other); }
        edge_iterator& operator+=(difference_type n) {
            it_ += n;
            return *this;
        }
        edge_iterator& operator-=(difference_type n) {
            it_ -= n;
            return *this;
        }
        edge_iterator operator+(difference_type n) const { return edge_iterator(it_ + n); }
        edge_iterator operator-(difference_type n) const { return edge_iterator(it_ - n); }
        difference_type operator-(const edge_iterator& other) const { return it_ - other.it_; }
        reference operator[](difference_type n) const { return *(it_ + n); }
    };

    edge_iterator edge_begin() const { return edge_iterator(edges_.begin()); }
    edge_iterator edge_end() const { return edge_iterator(edges_.end()); }

    vertex_iterator erase_vertex(vertex_iterator pos) {
        size_t idx = std::distance(vertices_.begin(), pos.it_);

        auto new_end = std::remove_if(edges_.begin(), edges_.end(),
                                      [idx](const edge_type& e) {
                                          return e.first == idx || e.second == idx;
                                      });
        edges_.erase(new_end, edges_.end());

        for (auto& e : edges_) {
            if (e.first > idx) --e.first;
            if (e.second > idx) --e.second;
        }

        vertices_.erase(pos.it_);
        return vertex_iterator(vertices_.begin() + std::min(idx, vertices_.size()));
    }

    void erase_edge(edge_iterator it) {
        edge_type e = *it;
        remove_edge(e.first, e.second);
    }

    //Итератор по соседям
    class neighbor_iterator {
        friend class Graph;
        const Graph* g_;
        size_t v_;
        mutable size_t current_index_;
        mutable bool valid_;
        mutable size_t cached_value_;

        bool find_next() const {
            while (current_index_ < g_->edges_.size()) {
                const auto& e = g_->edges_[current_index_];
                if (e.first == v_) {
                    cached_value_ = e.second;
                    ++current_index_;
                    return true;
                }
                if (e.second == v_) {
                    cached_value_ = e.first;
                    ++current_index_;
                    return true;
                }
                ++current_index_;
            }
            return false;
        }

    public:
        using iterator_category = std::input_iterator_tag;
        using value_type = Graph::vertex_type;
        using reference = Graph::const_reference;
        using pointer = Graph::const_pointer;
        using difference_type = void;

        neighbor_iterator(const Graph* g, size_t v, bool end = false)
                : g_(g), v_(v), current_index_(0), valid_(!end), cached_value_(0) {
            if (valid_ && !find_next()) {
                valid_ = false;
            }
        }

        const_reference operator*() const {
            if (!valid_) throw std::logic_error("Dereferencing end neighbor_iterator");
            return g_->vertices_[cached_value_];
        }

        pointer operator->() const {
            return &(**this);
        }

        neighbor_iterator& operator++() {
            if (!valid_) return *this;
            if (!find_next()) {
                valid_ = false;
            }
            return *this;
        }

        neighbor_iterator operator++(int) {
            neighbor_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const neighbor_iterator& other) const {
            if (g_ != other.g_ || v_ != other.v_) return false;
            if (!valid_ && !other.valid_) return true;
            if (valid_ != other.valid_) return false;
            return current_index_ == other.current_index_;
        }

        bool operator!=(const neighbor_iterator& other) const {
            return !(*this == other);
        }
    };

    neighbor_iterator neighbors_begin(size_t v) const {
        check_vertex_index(v);
        return neighbor_iterator(this, v, false);
    }

    neighbor_iterator neighbors_end(size_t v) const {
        check_vertex_index(v);
        return neighbor_iterator(this, v, true);
    }

    bool operator==(const Graph& other) const {
        return vertices_ == other.vertices_ && edges_ == other.edges_;
    }

    bool operator!=(const Graph& other) const {
        return !(*this == other);
    }

    bool operator<(const Graph& other) const {
        if (vertices_ != other.vertices_) return vertices_ < other.vertices_;
        return edges_ < other.edges_;
    }

    bool operator<=(const Graph& other) const { return !(other < *this); }
    bool operator>(const Graph& other) const { return other < *this; }
    bool operator>=(const Graph& other) const { return !(*this < other); }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& g) {
    os << "Vertices: ";
    std::for_each(g.vertex_cbegin(), g.vertex_cend(), [&os](const T& v) {
        os << v << " ";
    });
    os << "\nEdges: ";
    std::for_each(g.edge_begin(), g.edge_end(), [&os](const typename Graph<T>::edge_type& e) {
        os << "(" << e.first << "," << e.second << ") ";
    });
    return os;
}

#endif