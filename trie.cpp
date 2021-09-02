/*
	* File     : trie.cpp
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2021年09月03日 星期五 01时29分44秒
*/

#include <iostream>
#include <vector>

#define BASE 'a'
#define BASE_LEN 26

class Trie {
private:
    bool flag;
    std::vector<Trie*> next;
public:
    Trie();
    ~Trie();
public: 
    bool insert(const std::string&);
    bool search(const std::string&);
    void clear();
};

Trie::Trie() {
    this->flag = false;
    this->next.reserve(BASE_LEN);
    std::vector<Trie*> &n_arr = this->next;
    std::vector<Trie*>::iterator i = n_arr.begin();
    for (; i != n_arr.end(); i++) {
        *i = nullptr;
    }
}

Trie::~Trie() {
    this->clear();
}

bool Trie::insert(const std::string &ins_str) {
    Trie *root = this;

    for (int i = 0; i < ins_str.size(); i++) {
        Trie* &n_node = root->next[ins_str[i] - BASE];
        if (n_node == nullptr)
            n_node = new Trie();
        root = n_node;
    }

    root->flag = true;

    return true;
}

bool Trie::search(const std::string &srh_str) {
    Trie *root = this;

    for (int i = 0; i < srh_str.size(); i++) {
        Trie* &n_node = root->next[srh_str[i] - BASE];
        if (n_node == nullptr)
            return false;
        root = n_node;
    }

    return root->flag;
}

void Trie::clear() {
    std::vector<Trie*> &n_arr = this->next;
    std::vector<Trie*>::iterator i = n_arr.begin();
    for(; i != n_arr.end(); i++) {
        delete *i;
    }
    return ;
}

int main() {
    Trie *root = new Trie;
    char str[100];
    int op;
    while (scanf("%d%s", &op, str) != EOF) {
        switch (op) {
            case 1 : {
                printf("insert %s to trie\n", str);
                root->insert(str);
            }break;
            case 2 : {
                printf("search %s from trie = %d\n", str, root->search(str));
            }break;
        }
    }

    root->clear();
    delete root;

    return 0;
}

