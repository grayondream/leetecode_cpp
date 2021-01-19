#pragma once
#ifndef __LECODE_GRAPH_HPP__
#define __LECODE_GRAPH_HPP__

#include <string>
#include <unordered_map>
#include <unordered_set>

using std::hash;
using std::string;
using std::unordered_map;
using std::unordered_set;

namespace lecode {
class wedage {
public:
    int from;
    int to;
    int weight;

    wedage(int f, int t, int w) : from(f), to(t), weight(w) {}
    int another(int node) { return node == from ? from : to; }
    bool operator==(const wedage &w) { return from == w.from && to == w.to; }
    string to_string() const { return std::to_string(from) + "----" + std::to_string(weight) + "---->" + std::to_string(to); }
};

bool operator==(const wedage &rst, const wedage &snd) { return rst.from == snd.to && snd.from == snd.to; }

class wedage_hash {
public:
    int operator()(const wedage &w) const { return std::hash<int>()(w.from) + std::hash<int>()(w.to); }
};

/*
 * @brief 有向图
 */
class wgraph {
public:
    wgraph() {}

    wgraph &add_node(int node) {
        if (gmap.find(node) == gmap.end()) {
            gmap[node] = unordered_set<wedage, wedage_hash>();
            node_sz++;
        }

        return *this;
    }

    wgraph &remove_node(int node) {
        if (gmap.find(node) != gmap.end() && !gmap[node].empty()) {
            gmap.erase(node);
        }

        return *this;
    }

    wgraph &add_edage(wedage e) {
        add_node(e.from);
        edage_sz -= gmap[e.from].size(); //防止出现重复边
        gmap[e.from].insert(e);
        edage_sz += gmap[e.from].size();
        add_node(e.to);

        return *this;
    }

    /*
     * @brief 仅仅删除边，但是并不会删除节点
     */
    wgraph &remove_edage(const wedage &e) {
        if (gmap.find(e.from) != gmap.end() && gmap.find(e.to) != gmap.end()) {
            for (const wedage &edage : gmap[e.from]) {
                if (edage.to == e.to) {
                    gmap[e.from].erase(edage);
                    edage_sz--;
                    break;
                }
            }
        }

        return *this;
    }

    string to_string() {
        string ret;
        for (auto it = gmap.begin(); it != gmap.end(); it++) {
            ret += std::to_string(it->first) + string(" :");
            for (const wedage &w : it->second) {
                ret += w.to_string() + " ";
            }

            ret += "\n";
        }

        return ret;
    }

private:
    unordered_map<int, unordered_set<wedage, wedage_hash>> gmap;

    size_t node_sz;
    size_t edage_sz;
}; // namespace lecode
} // namespace lecode

#include <iostream>

void test_graph() {
    lecode::wgraph g;
    g.add_edage(lecode::wedage(1, 2, 3));
    g.add_edage(lecode::wedage(1, 5, 2));
    g.add_edage(lecode::wedage(2, 3, 1));
    g.add_edage(lecode::wedage(2, 4, 1));
    g.add_edage(lecode::wedage(3, 4, 3));
    g.add_edage(lecode::wedage(4, 5, 3));

    string ret = g.to_string();
    std::cout << ret << std::endl;
}

#endif