#ifndef PROJECT1LEXER_GRAPH_H
#define PROJECT1LEXER_GRAPH_H

class Graph {
private:
    map<unsigned int, set<unsigned int>> graph;
    map<unsigned int, set<unsigned int>> reverseGraph;
    vector<unsigned int> postOrder;
    map<unsigned int, bool> visited;
    vector<set<int>> sCCs;
    set<int> scc;

public:
    Graph() {}

    string toString() {
        stringstream ss;
        map<unsigned int, set<unsigned int>>::iterator it;
        for (it = graph.begin(); it != graph.end(); it++) {
            ss << "R" << it->first << ":";
            string sep = "";
            for (unsigned int i : it->second) {
                ss << sep << "R" << i;
                sep = ",";
            }
            ss << endl;
        }
        return ss.str();
    }

    const vector<set<int>> &getScCs() const {
        return sCCs;
    }

    vector<unsigned int> getReversePostOrder() {
        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }

    void addToGraph(unsigned int index, set<unsigned int> mySet) {
        graph[index] = mySet;
    }

    void addToReverseGraph(unsigned int index, set<unsigned int> mySet) {
        reverseGraph[index] = mySet;
    }

    void dfsReverse() {
        // set all to false
        for (unsigned int i = 0; i < visited.size(); ++i) {
            visited[i] = false;
        }
        map<unsigned int, set<unsigned int>>::iterator it;
        for (it = reverseGraph.begin(); it != reverseGraph.end(); it++) {
            if (!visited[it->first]) {
                dfsPostOrder(it->first);
            }
        }
    }

    void dfs() {
        // set all to false
        for (unsigned int i = 0; i < visited.size(); ++i) {
            visited[i] = false;
        }
        postOrder = getReversePostOrder();
        if (postOrder.size() <= 1) {
            scc.insert(postOrder[0]);
            sCCs.push_back(scc);
        }
        else {
            for (unsigned int i = 0; i < postOrder.size(); ++i) {
                if (!visited[postOrder[i]]) {
                    dfsSCC(postOrder[i]);
                    sCCs.push_back(scc);
                }
                scc.clear();
            }
        }
    }

    void dfsPostOrder(unsigned int val) {
        visited[val] = true;
        set<unsigned int>::iterator it;
        for (it = reverseGraph[val].begin(); it != reverseGraph[val].end(); ++it) {
            if (!visited[*it]) {
                dfsPostOrder(*it);
            }
        }
        postOrder.push_back(val);
    }

    void dfsSCC(unsigned int val) {
        scc.insert(val);
        visited[val] = true;
        set<unsigned int>::iterator it;
        for (it = graph[val].begin(); it != graph[val].end(); ++it) {
            if (!visited[*it]) {
                dfsSCC(*it);
            }
        }
    }

//    Create a graph class
//    Adjacency list implementation (not adjacency matrix)
//    Graph stores all edges/adjacencies as a map<int,set<int>>
//    Also store a boolean 'visited' flag for each node
//    Make all of the functions dfs, dfsForest, etc. in the graph class
//    You should have a two different dfsForest functions:
//    one for finding the post-order, and one for finding SCCs
//    create a toString method early to test each step
};

#endif //PROJECT1LEXER_GRAPH_H
