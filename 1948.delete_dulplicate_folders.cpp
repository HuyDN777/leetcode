class Solution {
public:
    struct Node {
        unordered_map<string, Node*> children;
        string name;
        bool isDuplicate = false;
    };
    Node* root = new Node();
    void buildTree(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            Node* cur = root;
            for (auto& folder : path) {
                if (cur->children.find(folder) == cur->children.end()) {
                    cur->children[folder] = new Node();
                    cur->children[folder]->name = folder;
                }
                cur = cur->children[folder];
            }
        }
    }
    string serialize(Node* node, unordered_map<string, vector<Node*>>& dupMap) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> serializedChildren;
        for (auto& [name, child] : node->children) {
            serializedChildren.push_back({name, serialize(child, dupMap)});
        }
        sort(serializedChildren.begin(), serializedChildren.end());
        string serial;
        for (auto& [name, sub] : serializedChildren) {
            serial += "(" + name + sub + ")";
        }

        dupMap[serial].push_back(node);
        return serial;
    }
    void markDuplicates(unordered_map<string, vector<Node*>>& dupMap) {
        for (auto& [serial, nodes] : dupMap) {
            if (nodes.size() >= 2) {
                for (auto& node : nodes) {
                    node->isDuplicate = true;
                }
            }
        }
    }
    void collect(Node* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (child->isDuplicate) continue;
            path.push_back(name);
            result.push_back(path);
            collect(child, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        buildTree(paths); 

        unordered_map<string, vector<Node*>> dupMap;
        serialize(root, dupMap); 

        markDuplicates(dupMap);  

        vector<vector<string>> result;
        vector<string> path;
        collect(root, path, result); 
        return result;
    }
};
